/*
 * exercises.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: user
 */

#include "A.h"
#include "B.h"

#include <iostream>
using namespace std;


void exercise1(){
	cout << "exercise 1" << endl;
	// implicit conversions
	cout << "=== A a1 = 42;" << endl;
//	A a1 = 42;
	cout << "=== int i1 = a1;" << endl;
//	int i1 = a1;

	// explicit conversions
	cout << "=== A a(42);" << endl;
	A a2(42);
	cout << "=== i2 = static_cast<int>(a2);" << endl;
	int i2 = static_cast<int>(a2);
	cout << "=== i2 = a2.operator int();" << endl;
	i2 = a2.operator int();
}

void fa(A){
	cout << __PRETTY_FUNCTION__ << endl;
}
void facr(A const&){
	cout << __PRETTY_FUNCTION__ << endl;
}
void far(A &){
	cout << __PRETTY_FUNCTION__ << endl;
}
void fint(int i){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "i: " << i << endl;
}

void exercise2(){
	cout << "exercise1" << endl;
	cout << "=== A a;" << endl;
	A a;
	cout << "=== fa(42);" << endl;
//	fa(42);
	cout << "=== facr(42);" << endl;
//	facr(42);
	cout << "=== fint(a);" << endl;
//	fint(a);
//	cout << "=== far(42);" << endl;
//	far(42);
}

void exercise3(){
	cout << "exercise3" << endl;
	cout << "=== B b;" << endl;
	B b;
	cout << "=== fa(b);" << endl;
//	fa(b);
	fa(static_cast<A>(b));
	cout << "=== fint(b);" << endl;
//	fint(b);
	fint(static_cast<int>(A(static_cast<A>(b))));
//	if(b){
//		cout << "b is true :-)" << endl;
//	}else{
//		cout << "b is false :-(" << endl;
//	}
}

void exercise4(){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "=== B b;" << endl;
		B b;
		cout << "=== fint(b);" << endl;
		// fint(b);
		fint(static_cast<int>(A(static_cast<A>(b))));
}
