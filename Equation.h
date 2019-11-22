#ifndef EQUATION
#define EQUATION
#include<bits/stdc++.h>

using namespace std;

class Equation
{
    private:
        string equt;

    public:
        Equation(string s);
        virtual void solve() = 0;
        virtual ostream& operator<<(ostream& os, Equation& eq)=0;
}

#endif
