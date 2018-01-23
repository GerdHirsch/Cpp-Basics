/*
 * main.cpp
 *
 *  Created on: 16.11.2015
 *      Author: Gerd
 */

#include<iostream>
using namespace std;

#include "TypeA.h"
#include "TypeB.h"

TypeB returnTypeB(){
	cout << "TypeB returnTypeB()" << endl;
	return TypeC();
}
TypeC returnTypeC(){
	cout << "TypeC returnTypeC()" << endl;
	return TypeC();
}
void f(TypeB  b){
	cout << "f(TypeB b)" << endl;
}
//void f(TypeB  const& b){
//	cout << "f(TypeB const&)" << endl;
//}

int main(){
	cout << "UserTypeConversion" << endl;

	cout << "TypeX x;" << endl;
	TypeB x;
	cout << "f(x);" << endl;
	f(x);


	{
		cout << "== Begin Block" << endl;
		cout << "TypeA a = returnTypeB();" << endl;
		TypeA a = returnTypeB();
		cout << "== end Block" << endl;
	}

	cout << endl;
	{
		cout << "== Begin Block" << endl;
		cout << "TypeB b = returnTypeC();" << endl;
		TypeB b = returnTypeC();
		cout << "TypeA a(b);" << endl;
		TypeA a(b);
		cout << "== end Block" << endl;
	}

}


