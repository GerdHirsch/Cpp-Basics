/*
 * exercises.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: user
 */

#include "AMemberbBaseC.h"

#include <iostream>
using namespace std;

void demoTypeSlicing(){
	double d{};
	int i(d);
	d = 3.14;
	i = d;
	++i;
}

void exercise1(){
	cout << "exercise1" << endl;
	cout << "=== A a1;" << endl;
	A a1;
	cout << "=== A a2;" << endl;
	A a2;
	cout << "=== C c;" << endl;
	C c;
	{
		cout << "begin block 1" << endl;
		cout << "=== C c1(a1);" << endl;
		C c1(a1);
		cout << "end block 1" << endl;
	}
	{
		cout << "begin block 2" << endl;
		cout << "=== c = a2;" << endl;
		c = a2;
		cout << "end block 2" << endl;
	}
	cout << "end exercise1" << endl;
}
void exercise2(){
	cout << "exercise2" << endl;
	cout << "=== A a1;" << endl;
	A a1;
	cout << "=== A a2;" << endl;
	A a2;
	cout << "=== C c;" << endl;
	C c;
	{
		cout << "begin block 1" << endl;
		cout << "=== C c2(std::move(a1));" << endl;
		C c2(std::move(a1));
		cout << "end block 1" << endl;
	}
	{
		cout << "begin block 2" << endl;
		cout << "=== c = std::move(a2);" << endl;
		c = std::move(a2);
		cout << "end block 2" << endl;
	}
	cout << "end exercise2" << endl;
}

void demoCallByValue(C parameter){
	cout <<__PRETTY_FUNCTION__ << endl;
	parameter.operation();
}
void demoCallByReference(C & parameter){
	cout <<__PRETTY_FUNCTION__ << endl;
	parameter.operation();
}
void demoCallByReferenceToConst(C const& parameter){
	cout <<__PRETTY_FUNCTION__ << endl;
	parameter.operation();
}

void exercise3(){
	cout << "=== A a;" << endl;
	A a;
	cout << "=== demoCallByValue(a);" << endl;
	demoCallByValue(a);
	cout << "=== demoCallByReference(a);" << endl;
	demoCallByReference(a);
	cout << "=== demoCallByReferenceToConst(a);" << endl;
	demoCallByReferenceToConst(a);
}
