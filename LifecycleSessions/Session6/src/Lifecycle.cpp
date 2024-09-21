/*
 * Exercises.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: user
 */
#include <iostream>
#include "AMemberCBNoMemberInitializerlist.h"
// #include "AMemberBC.h"
//#include "AMemberbBaseC.h"
//#include "ABaseCB.h"

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

// don't use std::move for return values!
// cause (N)RVO can not be applied
//A createA() { return A();} //RVO
A createA() { A a; return a;} //NRVO
//A createA() { return std::move(A());}
void demoCopyElision(){
	cout << "demoCopyElision" << endl;
	A a = createA();
}

