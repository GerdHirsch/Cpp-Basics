/*
 * RVO.cpp
 *
 *  Created on: 28.01.2018
 *      Author: Gerd
 */

#include "A2.h"

#include <iostream>
using namespace std;

A f1() {
	cout << "A f1() return A() // RVO" << endl;
	return A();
}
A f2() { // named RVO
	cout << "A f2() A tmp; return tmp; // nRVO" << endl;
	A tmp;
	return tmp;
}
A f3() {
	cout << "A f3() A tmp; return std::move(tmp);" << endl;
	A tmp;
	return std::move(tmp);
}
A f4(A& ra) {
	cout << "A f4(A& ra) return ra;" << endl;
	return ra;
}
A f5(A& ra) {
	cout << "A f5(A& ra) return std::move(ra);" << endl;
	return std::move(ra);
}
A f6(A a) {
	cout << "A f6(A a) return a;" << endl;
	return a;
}

void rvo(){
	cout << "=== rvo return valaue optimization" << endl;
	cout << "=== f1" << endl;
	A a1 = f1();
	cout << "=== f2" << endl;
	A a2 = f2();
	cout << "=== f3" << endl;
	A a3 = f3();
	cout << "=== f4" << endl;
	A a4 = f4(a1);
	cout << "=== f5" << endl;
	A a5 = f5(a2);
	cout << "=== f6" << endl;
	A a6 = f6(a3);

	cout << "=== end rvo return valaue optimization" << endl;

}
