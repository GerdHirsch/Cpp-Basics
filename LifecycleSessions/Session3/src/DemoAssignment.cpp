/*
 * DemoAssignment.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: user
 */
#include "ACustomized.h"

A operator+(A const &, A const &){
		return A();
}

void demoAssignment(){
//	int a, b=1, c=2;
//	a = b + c;
//	(b+c) = a;

	A a1, a2;
	A a3 = a1 + a2;
//	(a1 + a2) = a3;
}


