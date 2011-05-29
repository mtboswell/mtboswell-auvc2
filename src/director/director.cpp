#include "director.h"
#include "TransitionComparator.h"
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <QVector4D>
#include <QVariant>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QColorDialog>

director::director()
    : Module()
{
    loadStateFile();
    if (!states.isEmpty())
        setInitialState();
    connect (&signalMapper, SIGNAL(mapped(int)), this, SLOT(enableTransition(int)));
    connect (&signalMapper, SIGNAL(mapped(QString)), this, SLOT(setStateData(QString)));

    // debug
    canLoad = true; // for dynamically loading script files
    debugTimer = new QTimer(this);
    connect (debugTimer, SIGNAL(timeout()), this, SLOT(debugToStateData()));

    // for some reason,  I can't put stateData variables during initilization...
    //  I created a timer to do that after 2 seconds
    debugTimer->setSingleShot(true);
    debugTimer->setInterval(2000);    // after two seconds
    debugTimer->start();
}

void director::setInitialState()
{
    currentState = states.at(0).stateName;   // set the current state to the first entry
    updateEnableList(currentState);
    startTriggerTimers(currentState);
    startAutoTimers(currentState);
    setData("Director.Debug.State", currentState);    // might want to just call setState(currentState) instead of these
}

// prints out debug data in the state data
void director::debugToStateData()
{
    setData("Director.Debug.State", currentState);    // might want to just call setState(currentState) instead of these
    canLoad = false;
    setData("Director.scriptFile", lastScriptLoaded);
    canLoad = true;
    delete debugTimer;
}

// @param int t     the index of the currentState's transition object.
void director::enableTransition(int t)
{
    if (t > enableList.size() - 1)
        return;
    enableList[t] = true;
}

director::~director()
{
    // delete pending timers
    for (int i = 0; i < triggerTimers.size(); ++i)
        delete triggerTimers[i];

    for (int i = 0; i < autoTimers.size(); ++i)
        delete autoTimers[i];
}

/* The enableList is a parallel boolean array to determine if
   a triggerTransition object is valid
   */
void director::updateEnableList(QString stateName)
{
    enableList.clear();
    QList<TriggerTransition> transition = getTriggerTransitions(stateName);
    for (int i = 0; i < transition.size(); ++i)
    {
        int timeEnable = transition[i].timeEnable;
        if (timeEnable != 0)
            enableList.append(false);
        enableList.append(true);
    }
}

// After timeEnable seconds, a TriggerTransition becomes legal.
// QTimers are created dynamically to determine which TriggerTransition objects are legal
//      A TriggerTransition object is legal if timeEnable seconds have elapsed where t = 0
//      corresponds to the time the state was set.
void director::startTriggerTimers(QString stateName)
{
    // delete all timers
    for (int i = 0; i < triggerTimers.size(); ++i)
        delete triggerTimers[i];
    triggerTimers.clear();

    QList<TriggerTransition> transition = getTriggerTransitions(stateName);
    for (int i = 0; i < transition.size(); ++i)
    {
        int timeEnable = transition[i].timeEnable;

        if (timeEnable != 0)
        {
            QTimer *timer = new QTimer(this);
            timer->setSingleShot(true);
            timer->start(transition[i].timeEnable);
            triggerTimers.append(timer);   // add to the list of timers

            connect(timer, SIGNAL(timeout()), &signalMapper, SLOT(map()));
            signalMapper.setMapping(timer, i);  // associate this timer to the index value
            if(debug) qDebug() << "       Started a Timer with time: " << transition[i].timeEnable;
        }
    }
}

// TimerTransition objects automatically transitions to a new state after time seconds
void director::startAutoTimers(QString stateName)
{
    // delete old timers
    for (int i = 0; i < autoTimers.size(); ++i)
        delete autoTimers[i];
    autoTimers.clear();

    QList<TimerTransition> autoTransition = getTimerTransitions(stateName);
    for (int j = 0; j < autoTransition.size(); ++j)
    {
        int time = autoTransition[j].time;
        QString toState = autoTransition[j].to;

        QTimer *timer = new QTimer(this);
        timer->setSingleShot(true);
        timer->start(time);
        autoTimers.append(timer);   // add to the list of timers
        connect(timer, SIGNAL(timeout()), &signalMapper, SLOT(map()));
        signalMapper.setMapping(timer, toState);
        if(debug) qDebug() << "       Started an AutoTimer with time: " << time;
    }
}

// Attempts to load the file from a variety of locations
void director::loadStateFile()
{
    QStringList candidates;
    QFile f;
    QString match = "";

    candidates << "../src/director/auv.lua"
            << "src/director/auv.lua"
            << "../auv.lua"
            << "auv.lua";
    for (int i = 0; i < candidates.size(); ++i)
    {
        if (f.exists(candidates[i]))
        {
            match = candidates[i];
            break;
        }
    }

    load(match);
}

// actually performs the load from .lua file to C++ objects (see QueryLua.h)
void director::load(QString filename)
{
    QueryLua *l = new QueryLua();
    qDebug() <<  "director::director.cpp PWD: " << QDir::currentPath();
    qDebug() <<  "director::director.cpp Attempting to load lua file in " << filename;
    l->init(qPrintable(filename));

    lastScriptLoaded = filename;
    states = l->queryStates();
    delete l;
}

/*  VERY IMPORTANT METHOD ...
 *  Subscribed objects are parsed in here, if they are updated
 *  aka seminal Publish/Subscribe pattern
 */
void director::dataIn(VDatum datum)
{
    if (datum.id == "Thrusters")
        return;

    // Determine if we need to reload a script file
    if (datum.id == "Director.scriptFile" && canLoad)
    {
        QString filename = datum.value.toString();
        QFile file;

        if (file.exists(filename))
        {
            director::load(filename);
            setInitialState();
        }
        else
            std::cerr << "director::director.cpp Cannot load Lua file (does not exist): " << qPrintable(filename) << std::endl;

        return;
    }

    // Determines if this datum causes a transition
    if(debug) qDebug() << "Datum came in: " << datum.id << "  " << datum.value;
    if(debug) qDebug() << "Current State: " << currentState;
    if (hasTransition(datum))
        setStateData(nextTransition());
}


// Calls setData, the parameters in setData are a state's Option objects
void director::setStateData(QString stateName)
{
    currentState = stateName;

    setData("Director.Debug.State", currentState);
    setData("Command", getState(currentState).command);

    if(debug) qDebug() << "Transition to State: " << currentState;
    if(debug) qDebug() << "Max Time Enable: " << determineLongestTimeEnable(currentState);

    director::setOptions();

    updateEnableList(currentState);
    startTriggerTimers(currentState);
    startAutoTimers(currentState);
}

/**
 *  Sets the current state's options into the AUVT state data
 *  Called by: setStateData(QString stateName)
 */
void director::setOptions()
{
    QList<Option> opts = getOptions(currentState);
    for (int i = 0; i < opts.size(); ++i)
    {
        if(debug) qDebug() << "director:: Attempting to Set: " << opts[i].label << " with " << opts[i].value;
        QString label = opts[i].label;
        QVariant value = opts[i].value;
        int mode = opts[i].mode;

        if (mode == ABSOLUTE)   // see QueryLua.h for enumerations
            setData(label, value);
        else    // relative mode
        {   // most likely this will be Orientation.Heading or some periodic variable
            double curValue = doubleValue(label);   // might want to do type-checking here
            curValue += value.toDouble();   // add "value" to the current value in AUVT state data
            setData(label, curValue);   // set the incremented value
        }
    }
}

//  Retrieves the reference variable given QString stateName
const State& director::getState(QString stateName)
{
    try
    {
        for (int i = 0; i < states.size(); ++i)
        {
            if (stateName == states[i].stateName)
                return states[i];
        }
        throw (0); // should not hit
    }
    catch (int i)
    {
        switch (i)
        {
        case 0:
            qDebug() << "director:: ERROR. Could not find a state with name: " + stateName;
            exit(1);
            break;
        default:
                break;
        }
    }
}

const QList<TriggerTransition>& director::getTriggerTransitions(QString stateName)
{
    State currState = getState(stateName);
    return currState.triggerTransitions;
}

const QList<TimerTransition>& director::getTimerTransitions(QString stateName)
{
    State currState = getState(stateName);
    return currState.timerTransitions;
}

// Determines the longest "timeEnable" value in all Transition objects of the given state
const int director::determineLongestTimeEnable(QString stateName)
{
    QList<TriggerTransition> list = getTriggerTransitions(stateName);
    int max = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        if (max < list[i].timeEnable)
            max = list[i].timeEnable;
    }

    return max;
}

const QList<Option>& director::getOptions(QString stateName)
{
    State currState = getState(stateName);
    return currState.options;
}

/*  Determines if the current vDatum has triggered a transition
 *  If TRUE:
 *      Variable: QString transitionTo points to the next transition state
 */
bool director::hasTransition(VDatum datum)
{
    QList<TriggerTransition> tList = getTriggerTransitions(currentState);

    for (int i = 0; i < tList.size(); ++i)
    {
        if (datum.id == tList[i].label) // match, now test if the condition has been triggered
        {
            // timeEnable == 0 is a check to see if this Transition is enabled
            if (tList[i].timeEnable != 0 && !enableList[i])
                if(debug) qDebug() << "       Time enable " << tList[i].timeEnable << " for : " << tList[i].label;
            if (enableList[i] && isConditionTriggered(datum, tList[i]))  // static function in TransitionComparator
            {
                transitionTo = tList[i].to;
                return true;
            }
        }
    }
    return false;
}

// Returns the next state, assuming hasTransition() returned true
QString director::nextTransition()
{
    if (!transitionTo.isEmpty() || transitionTo != NULL)
        return transitionTo;
    return NULL;
}

void director::step()
{

}

void director::init()
{
    setData("Module.director", 1);
    qDebug("director thread id: %d", (int) QThread::currentThreadId());
}
