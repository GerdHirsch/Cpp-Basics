/*
 * main.cpp
 *
 *  Created on: 18.08.2017
 *      Author: Gerd
 */

#include<iostream>
using namespace std;

#include "DeadBeef.h"

int main()
{
    cout << endl<< "MyClass *ok = new MyClass;" << endl;
    MyClass *ok = new MyClass;
    cout << endl<< "MyClass *underflow = new MyClass(true);" << endl;
    MyClass *underflow = new MyClass(true);
    cout << endl<< "MyClass *overflow = new MyClass(true);" << endl;
    MyClass *overflow = new MyClass(false, true);
    cout << endl<< "MyClass *underOverflow = new MyClass(true, true);" << endl;
    MyClass *underOverflow = new MyClass(true, true);

    cout << endl<< "delete ok;" << endl;
    delete ok;

    cout << endl<< "delete overflow;" << endl;
    delete overflow;
    //char* p = reinterpret_cast<char*>(overflow);
    //p -= sizeof(unsigned int);
    //delete p;

    cout << endl<< "delete underflow;" << endl;
    delete underflow;

    cout << endl<< "delete underOverflow;" << endl;
    delete underOverflow;

    cout << endl<< "end main" << endl;
}


