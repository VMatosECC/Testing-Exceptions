#pragma once
#include <sstream>
using namespace std;

template <class T1, class T2>
class Couple
{
private:
    //data members
    T1 first;
    T2 second;

public:
    //constructor
    Couple(T1 t1Value, T2 t2Value) {
        first = t1Value;
        second = t2Value;
    }

    //User-defined methods
    string toString() {
        stringstream sout;
        sout << this << " Couple [First: " << first
            << ", Second: " << second << "]";
        return sout.str();
    }
};

