/*
 * main.cpp
 *
 *  Created on: 01.02.2016
 *      Author: Gerd
 *      Demo perfect forward mit templates und lambda auto&&
 */

#include "DemoClass.h"

#include<utility> //std::forward

#include<iostream>
using namespace std;


//---------------------------------------------------------------------
//Überladene Funktion f
void f(Base const&){	// 1
	cout << "f(Base const&)" << endl;
}
void f(Base&&){		//2
	cout << "f(Base&&)" << endl;
}
//---------------------------------------------------------------------
// Überladene Funktion die f und Widget::referenceQualifiedOverload
// aufruft
// Item 25 Use move on rvalue references, std::forward on universal references
void callF(Base&& t){	// 3
	f(std::move(t));
	std::move(t).rqOp();
	std::move(t).op();
}
void callF(Base& t){	// 4
	f(t);
	t.rqOp();
	t.op();
}
// template mit universal Reference
template<class T>
void callFT(T&& t){	// 5
	f(std::forward<T>(t));
	std::forward<T>(t).rqOp();
	std::forward<T>(t).op();
}
// lambda mit universal Reference
auto callFL = [](auto&& t){ // 6
	f(std::forward<decltype(t)>(t));
	std::forward<decltype(t)>(t).rqOp();
	std::forward<decltype(t)>(t).op();
};

Derived rValue(){ return Derived(); }

int main(){
	cout << "PerfectForwarding" << endl;

	int no = 0;
	Derived widget;
	Base& w = widget;
	Base&& baseRValueReference = rValue();

	cout << "----------------------" << endl;
	cout << "callF(w); //" << ++no << endl;
	callF(w);
	cout << "----------------------" << endl;
	cout << "callF(rValue()); //" << ++no << endl;
	callF(rValue());
	cout << "----------------------" << endl;
	cout << "callF(std::forward<Base&&>(baseRValueReference)); //" << ++no  << endl;
	callF(std::forward<Base&&>(baseRValueReference));
	cout << "----------------------" << endl;
	cout << "callFL(w); //" << ++no << endl;
	callFL(w);
	cout << "----------------------" << endl;
	cout << "callFL(rValue()); //" << ++no<< endl;
	callFL(rValue());
	cout << "----------------------" << endl;
	cout << "callFT(w); //" << ++no << endl;
	callFT(w);
	cout << "----------------------" << endl;
	cout << "callFT(rValue()); //" << ++no << endl;
	callFT(rValue());
	cout << "----------------------" << endl;
}


