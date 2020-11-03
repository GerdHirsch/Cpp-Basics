/*
 * RVO.cpp
 *
 *  Created on: 28.01.2018
 *      Author: Gerd
 */

#include "ACustomized.h"

#include <iostream>
using namespace std;

A f1(A a) {
	cout << "A f1(A a) return a;" << endl;
	return a;
}
A f2(A& ra) {
	cout << "A f2(A& ra) return ra;" << endl;
	return ra;
}
A f3(A& ra) {
	cout << "A f3(A& ra) return std::move(ra);" << endl;
	return std::move(ra);
}
A f4(A const& rca){
	cout << "A f4(A const& ra) return rca;" << endl;
	return rca;
//	return std::move(rca);
}
A f5(A&& ra){
	cout << "A f5(A&& ra) return ra;" << endl;
	return ra;
}
A f6(A&& ra){
	cout << "A f6(A&& ra) return std::move(ra);" << endl;
	return std::move(ra);
}
void parameterAndReturnExpressions(){
	cout << "=== parameterAndReturnExpressions" << endl;
	cout << "=== A a1 = f1(A());" << endl;
	A a1 = f1(A());
//	{
//	cout << "=== A a11 = f1(a1);" << endl;
//	A a11 = f1(a1);
//	}
	cout << "=== A a2 = f2(a1);" << endl;
	A a2 = f2(a1);
	cout << "=== A a3 = f3(a1);" << endl;
	A a3 = f3(a1);
//	A a3 = f3(A());
	cout << "=== A a4 = f4(a1);" << endl;
	A a4 = f4(a1);
//	A a4 = f4(A());
	cout << "=== A a5 = f5(A());" << endl;
	A a5 = f5(A());
	cout << "=== A a6 = f6(A());" << endl;
	A a6 = f6(A());
//	A a6 = f6(a1);
//	A a6 = f6(std::move(a1));
	cout << "=== parameterAndReturnExpressions" << endl;
}
