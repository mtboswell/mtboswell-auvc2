#include "director.h"
#include "TransitionComparator.h"
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <QVector4D>
#include <QVariant>

director::director(QMap<QString, QString> *configIn, AUVC_State_Data *stateIn, QObject *parent)
		: Module(configIn, stateIn, parent)
{
    loadStateFile();
    if (!states.isEmpty())
        currentState = states.at(0).stateName;   // set the current state to the first entry
}

// Loads the states from auv.lua
void director::loadStateFile()
{
    QueryLua *l = new QueryLua();
    char filename[256] = "auv.lua";
    l->init(filename);
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

    if (hasTransition(datum))
    {
        setStateData(nextTransition());
    }
}


// Calls setData, the parameters in setData are a state's Option objects
void director::setStateData(QString stateName)
{
    qDebug() << "Transition to State: " << stateName;
    QList<Option> opts = getOptions(stateName);
    for (int i = 0; i < opts.size(); ++i)
    {
        qDebug() << "Attempting to Set: " << opts[i].label << " with " << opts[i].value;
        QString label = opts[i].label;
        QVariant value = opts[i].value;
        setData(label, value);
    }
}

/*  Retrieves the reference to stateName
 */
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
            qDebug() << "ERROR. Could not find a state with name: " + stateName;
            exit(1);
            break;
        default:
                break;
        }
    }
}

const QList<Transition>& director::getTransitions(QString stateName)
{
    State currState = getState(stateName);
    return currState.transitions;
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
    QString transitionID = datum.id;
    QList<Transition> tList = getTransitions(currentState);

    for (int i = 0; i < tList.size(); ++i)
    {
        if (transitionID == tList[i].label) // match, now test if the condition has been triggered
            if (isConditionTriggered(datum, tList[i]))  // static function in TransitionComparator
            {
                transitionTo = tList[i].to;
                return true;
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
