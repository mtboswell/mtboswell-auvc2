#include "director.h"
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <QVector4D>
#include <QVariant>

director::director(QMap<QString, QString> *configIn, AUVC_State_Data *stateIn, QObject *parent)
		: Module(configIn, stateIn, parent)
{
    loadStateFile();
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
        qDebug() << "A condition was hit... !!!";   // should transition to next state
}

void director::setStateData(QString stateName)
{
    for (int i = 0; i < states.size(); ++i)
    {
        if (states.at(i).stateName == stateName)
        {
            qDebug() << "found a state with that name: " + stateName;
            return;
        }
    }

    qDebug() << "NOT FOUND a state with that name: " + stateName;
}

/*  Retrieves the reference to stateName
 */
const State& director::getState(QString stateName)
{
    for (int i = 0; i < states.size(); ++i)
    {
        if (stateName == states[i].stateName)
            return states[i];
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
 *
 */
bool director::hasTransition(VDatum datum)
{
    QString transitionID = datum.id;
    QList<Transition> tList = getTransitions(currentState);
    qDebug() << "DIRECTOR HAS TRANSITION: " << transitionID;

    for (int i = 0; i < tList.size(); ++i)
    {
        if (transitionID == tList[i].label) // match, now test if the condition has been triggered
        {
            qDebug() << "FOUND A POSSIBLE MATCH";

            if (isConditionTriggered(datum, tList[i]))
            {
                qDebug() << "FOUND A MATCH INDEED! YESSS!";
                // transition
            }
//            qDebug() << tList[i].label << tList[i].cOperator << tList[i].value << tList[i].to;
            qDebug();
        }
    }

    return false;
}

bool director::isConditionTriggered(VDatum datum, Transition t)
{
    QVariant::Type dType = datum.value.type();
    QVariant::Type tType = t.value.type();

    // Hackish solution for QVariant comparisons
    if (tType != dType)
    {
        if (tType == QVariant::Double)
            datum.value = datum.value.toDouble();
        else if (tType == QVariant::Int)
            datum.value = datum.value.toInt();
        else if (tType == QVariant::String)
            datum.value = datum.value.toString();
    }

    if (t.cOperator == ">")
    {
        if (t.value > datum.value)
            return true;
    }
    else if (t.cOperator == "<")
    {
        if (t.value < datum.value)
            return true;
    }
    else if (t.cOperator == "==")
    {
        if (t.value == datum.value)
            return true;
    }
    else if (t.cOperator == ">=")
    {
        if (t.value >= datum.value)
            return true;
    }
    else if (t.cOperator == "<=")
    {
        if (t.value <= datum.value)
            return true;
    }
    else if (t.cOperator == "!=")
    {
        if (t.value != datum.value)
            return true;
    }

    return false;
}

QString director::nextTransition()
{

}

void director::setTransitions(QString stateName)
{

}

void director::transitionToState(QString stateName)
{

}

void director::step()
{

}

void director::init()
{
    setData("Module.director", 1);
    qDebug("director thread id: %d", (int) QThread::currentThreadId());
}
