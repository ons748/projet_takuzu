#include "cases.h"
#include <iostream>

using namespace std;


int cases::getcaseValue()const
{
    return casesValue;
}

int cases::getIdValue()
{
    return Idcase;
}

void  cases::setcaseValue(int a)
{
    casesValue = a;
}

void cases::setIdValue(int a)
{
    Idcase = a;
}

