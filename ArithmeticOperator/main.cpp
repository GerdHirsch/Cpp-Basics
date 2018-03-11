/*
 * main.cpp
 *
 *  Created on: 05.10.2015
 *      Author: Gerd
 */

#include<iostream>
using namespace std;
class Widget{
	int i;
public:
	//explicit
	Widget(int i=0):i(i){}
	Widget& operator+=(Widget const& rhs){
		i += rhs.i;
		return *this;
	}
	friend Widget operator+(Widget const& lhs, Widget const& rhs){
		Widget retVal(lhs);
		retVal += rhs;
		return retVal;
	}
	friend std::ostream& operator<<(ostream& o, Widget const& rhs){
		return o << rhs.i;
	}
};
int main(){
	cout << "ArithmeticOperator" << endl;
	Widget rhs(41), lhs(1);

	Widget r1 = lhs + rhs;
	Widget r2 = lhs + 42;
	Widget r3 = 3 + rhs;

	cout << "r1:" << r1 << endl;
	cout << "r2:" << r2 << endl;
	cout << "r3:" << r3 << endl;
}


