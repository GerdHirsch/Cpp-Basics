/*
 * Exercises.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: user
 */
#include <iostream>

#include "AEmpty.hpp"
using namespace std;



void lifecycle(){
	cout << "=== begin lifecycle()" << endl;
	{
		cout << "{\n=== begin Block" << endl;
		cout << "=== A a1;" << endl;
		A a1;
		cout << "a1.i: " << a1.i << endl;
		a1.i = 42;
		cout << "a1.i=42: " << a1.i << endl;
		cout << "=== A a2 = a1;" << endl;
		A a2 = a1;
		cout << "a2.i: " << a2.i << endl;
		cout << "=== A a3(a1);" << endl;
		A a3(a1);
		cout << "a3.i: " << a3.i << endl;
		a1.i = 43;
		cout << "=== a1.i = 43: " << a1.i << endl;

		cout << "=== a2 = a1" << endl;
		a2 = a1;
		cout << "a2.i: " << a2.i << endl;

		cout << "=== A a4(std::move(a1));" << endl;
		A a4(std::move(a1));
		cout << "a1.i: " << a1.i << endl;
		cout << "a4.i: " << a4.i << endl;

		cout << "a4 = std::move(a3);" << endl;
		a4 = std::move(a3);
		cout << "a3.i: " << a3.i << endl;
		cout << "a4.i: " << a4.i << endl;

		cout << "=== end Block \n}" << endl;
	}
	cout << "=== end lifecycle()" << endl;
}



