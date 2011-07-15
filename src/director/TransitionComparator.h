#ifndef TRANSITIONCOMPARATOR_H
#define TRANSITIONCOMPARATOR_H

#endif // TRANSITIONCOMPARATOR_H

#include "director.h"

/*
 *  TransitionComparator
 *
 *  Compares two QVariants by casting them to Transition.value.type().
 *  The comparison operator is stored in the Transition object.
 *
 *  There might be a more elegant way to do this.
 */
bool static isConditionTriggered(VDatum, TriggerTransition);   // function header

bool static isConditionTriggered(VDatum datum, TriggerTransition t)
{
    QVariant::Type tType = t.value.type();

    if (tType == QVariant::String)
    {
        QString dVar = datum.value.toString();
        QString tVar = t.value.toString();

        if (t.cOperator == ">")
        {
            if (dVar > tVar)
                return true;
        }
        else if (t.cOperator == "<")
        {
            if (dVar < tVar)
                return true;
        }
        else if (t.cOperator == "==")
        {
            if (dVar == tVar)
                return true;
        }
        else if (t.cOperator == ">=")
        {
            if (dVar >= tVar)
                return true;
        }
        else if (t.cOperator == "<=")
        {
            if (dVar <= tVar)
                return true;
        }
        else if (t.cOperator == "!=")
        {
            if (dVar != tVar)
                return true;
        }
    }
    else if (tType == QVariant::Double)
    {
        double dVar = datum.value.toDouble();
        double tVar = t.value.toDouble();

        if (t.cOperator == ">")
        {
            if (dVar > tVar)
                return true;
        }
        else if (t.cOperator == "<")
        {
            if (dVar < tVar)
                return true;
        }
        else if (t.cOperator == "==")
        {
            if (dVar == tVar)
                return true;
        }
        else if (t.cOperator == ">=")
        {
            if (dVar >= tVar)
                return true;
        }
        else if (t.cOperator == "<=")
        {
            if (dVar <= tVar)
                return true;
        }
        else if (t.cOperator == "!=")
        {
            if (dVar != tVar)
                return true;
        }
    }
    else if (tType == QVariant::Int)
    {
        int tVar = t.value.toInt();
        int dVar = datum.value.toInt();

        if (t.cOperator == ">")
        {
            if (dVar > tVar)
                return true;
        }
        else if (t.cOperator == "<")
        {
            if (dVar < tVar)
                return true;
        }
        else if (t.cOperator == "==")
        {
            if (dVar == tVar)
                return true;
        }
        else if (t.cOperator == ">=")
        {
            if (dVar >= tVar)
                return true;
        }
        else if (t.cOperator == "<=")
        {
            if (dVar <= tVar)
                return true;
        }
        else if (t.cOperator == "!=")
        {
            if (dVar != tVar)
                return true;
        }
    }
    return false;
}
