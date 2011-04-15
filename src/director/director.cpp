#include "director.h"
#include <QDebug>
#include <QTimer>
#include <iostream>

director::director(QMap<QString, QString> *configIn, AUVC_State_Data *stateIn, QObject *parent)
		: Module(configIn, stateIn, parent)
{
//    QTimer *t = new QTimer(this);
//    connect(t, SIGNAL(timeout()), this, SLOT(process()));
//    t->start(1000);
//    currentState = new DefaultState();
    currentState = NULL;
    start();
}

void director::dataIn(VDatum datum) {}

// TODO: FSM Design Pattern based on sensors and/or time duration
// TODO: State Interface
    //  exit()
    //  setState()
    //  entry()

void director::process()
{
    changeState(new DefaultState);
//    std::cout << "HERE" << std::endl;
    while (currentState)
    {
        currentState->execute(*this);
    }
}

// add module.addModule() ... module.initalizeAndLaunch...()
// implement init()
// use event loops



// BAD -- don't implement run()
// Inherited from QThread ... this is what is executed after start() is invoked
//void director::run()
//{
//    process();
//}

void director::changeState(BaseState *newState)
{
    if (currentState != NULL)
           delete currentState;
    currentState = newState;
}
