/*
 * RVO.cpp
 *
 *  Created on: 28.01.2018
 *      Author: Gerd
 */
//#include "A1Empty.h"
#include "A1EmptyMemberBC.h"
//#include "A1EmptyMemberbBaseC.h"
//#include "A2.h"
//#include "A3MemberBC.h"
//#include "A4BaseBC.h"
//#include "A5MemberbBaseC.h"

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

void parameterAndReturnExpressions(){
	cout << "=== rvo return value optimization" << endl;
		{
		cout << "=== begin of block" << endl;
	//	cout << "=== A a1 = f1();" << endl;
	//	A a1 = f1();
		cout << "=== A a2 = f2();" << endl;
		A a2 = f2();
	//	cout << "=== A a3 = f3();" << endl;
	//	A a3 = f3();
	//	cout << "=== A a4 = f4(a1);" << endl;
	//	A a4 = f4(a1);
	//	cout << "=== A a5 = f5(a2);" << endl;
	//	A a5 = f5(a2);
	//	cout << "=== A a6 = f6(a3);" << endl;
	//	A a6 = f6(a3);
		cout << "=== end of block" << endl;
	}

	cout << "=== end rvo return valaue optimization" << endl;

}
