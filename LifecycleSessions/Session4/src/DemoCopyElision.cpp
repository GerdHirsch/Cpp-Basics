/*
 * DemoCopyElision.cpp
 *
 *  Created on: Oct 22, 2020
 *      Author: user
 */
#include <iostream>

#include "ACustomized.h"
using namespace std;

// A createA(){ return A(); } // RVO
// A createA(){ return A(42); } // RVO
A createA(){ A a; return a; } // NRVO
// don't use std::move for return expiring objects!
// cause (N)RVO can not be applied
// A createA(){ return std::move(A()); } // move


void demoCopyElision(){
	cout << "demoCopyElision" << endl;

	A a = createA();

}
