#ifndef TRANSITIONCOMPARATOR_H
#define TRANSITIONCOMPARATOR_H

#endif // TRANSITIONCOMPARATOR_H

#include "director.h"

bool static isConditionTriggered(VDatum, Transition);   // function header

bool static isConditionTriggered(VDatum datum, Transition t)
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
