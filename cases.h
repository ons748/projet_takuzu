#pragma once
class cases 
{
private:
    int casesValue;
    int Idcase;
public:
    cases() { Idcase = 0; casesValue = 0; }
    cases(int a, int b) { Idcase = a; casesValue = b; }
    ~cases() {}
    int getcaseValue()const;
    int getIdValue();
    void setcaseValue(int);
    void setIdValue(int);
};
