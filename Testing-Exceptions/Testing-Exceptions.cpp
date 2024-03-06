// Testing-Exceptions.cpp 

int getValidValue();



#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include "Couple.h"

using namespace std;
void experiment01();
void experiment02();


int main()
{
    //experiment01();
    experiment02();
}

//void showVector(vector<int> v) {
//    cout << endl;
//    for (int i = 0; i < v.size(); i++) {
//        cout << i << ":" << v[i] << ", ";
//    }
//    cout << endl;
//}
//
//
//void showVector(vector<string> v) {
//    cout << endl;
//    for (int i = 0; i < v.size(); i++) {
//        cout << i << ":" << v[i] << ", ";
//    }
//    cout << endl;
//}
//
//
//void showVector(vector<double> v) {
//    cout << endl;
//    for (int i = 0; i < v.size(); i++) {
//        cout << i << ":" << v[i] << ", ";
//    }
//    cout << endl;
//}


template <class T>
void showVector(vector<T> v) {
    cout << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i << ":" << v[i] << ", ";
    }
    cout << endl;
}

template <class T>
T findLargest(vector<T> v) {
    //largest value is the first! 
    int pos = 0;
    T maxValue = v[pos];
    //explore the rest and validate hypothesis
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maxValue) {
            maxValue = v[i];
            pos = i;
        }
    }
    return maxValue;

}

//-------------------------------------------------------

void experiment02() {
    vector<int> v1{ 11, 22, 33, 44 };
    showVector(v1);

    vector<string> v2{ "aaa", "bbb", "ccc" };
    showVector(v2);

    vector<double> v3{ 11.11, 22.22, 33.33 };
    showVector(v3);

    cout << "largest of v1 is " << findLargest(v1) << endl;
    cout << "largest of v2 is " << findLargest(v2) << endl;
    cout << "largest of v3 is " << findLargest(v3) << endl;

    Couple<int, string> c1(1234567, "Bart Simpson");
    cout << "c1 " << c1.toString() << endl;

    Couple<int, double> c2(1234567, 2.0);
    cout << "c2 " << c2.toString() << endl;
}


void experiment01() {
    int n = 0;

    try
    {
        n = getValidValue();
    }
    catch (const std::exception& e)
    {
        cout << "MAIN " << e.what() << endl;
    }

    cout << "Main n " << n << endl;

    cout << "All done!\n";
}

int getValidValue() {
    int n;
    string s;

    cout << "Enter an integer [1..200] ";
    //cin >> s;
    getline(cin, s);

    //Rule1: can the input be converted into a number?
    try
    {
        n = stoi(s);
        cout << "s " << s << ", n " << n << endl;
    }
    catch (const std::exception& e)
    {
        string emsg = "ERROR - Invalid numeric format";
        throw exception(emsg.c_str());
    }

    //Rule2. Does input and its 'equivalent numeric' value agree?
    if (s != to_string(n)) {
        throw exception("ERROR - Data rejected, unkown token");
    }

    //Rule3. Is data inside valid  range?
    if (n < 0 || n > 200) {
        throw exception("ERROR - Data out of range");
    }


    return n;
}