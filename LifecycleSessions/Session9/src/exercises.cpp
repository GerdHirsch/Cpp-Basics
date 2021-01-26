/*
 * exercises.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: user
 */

#include "UniquePointer.hpp"
#include "AMemberbBaseC.h"

#include <iostream>
using namespace std;

void callFunctionMayThrowAnException(C* pC){
	// may throw an exception
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "=== pA->operation();" << endl;
	pC->operation();
}

void demoLostResource(){
	cout << "demoLostResource()" << endl;
	cout << "=== auto pA = new A;" << endl;
	auto pA = new A;

	if(!pA) return;

	cout << "=== pA->operation();" << endl;

	pA->operation();

	(*pA).operation();

	// here we have some code for maintenance
	// and we put a return statement into the function
	bool condition = true;
	if(condition)
		return;
	else
		callFunctionMayThrowAnException(pA);
	// we may never come to the following statement
	cout << "=== delete pA;" << endl;
	delete pA;
}

using Handler = UniquePointer<C>;

void callFunctionMayThrowAnException(Handler handler){
	// may throw an exception
	cout << __PRETTY_FUNCTION__ << endl;
	handler->operation();
}
Handler createResource(){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "=== return Handler(new A);" << endl;
	return Handler(new A); // A is a C ;-)
}
void demoRAII(){

	cout << "demoRAII()" << endl;
	cout << "=== Handler handler = createResource();" << endl;
	Handler handler = createResource(); // RVO

	cout << "=== if(!handler)" << endl;
	if(!handler) return; // return resource != nullptr

	cout << "=== handler->operation();" << endl;

	handler->operation();
//	handler.operator->()->operation();
//
//	(*handler).operation();

	// here we have some code for maintenance
	// and we put a return statement into the function
	bool condition = true;
	if(condition)
		return;
	else
		callFunctionMayThrowAnException(std::move(handler));

	// we may never come to the following statement
	// but all local variables will be destroyed nevertheless
	// when the scope is left
	cout << "=== end demoRAII" << endl;
}

void demoConversions(){
	cout << "demoConversions()" << endl;
	{
		cout << "{" << endl << " === begin block" << endl;
		cout << "=== UniquePointer xHandler(new X)" << endl;
		UniquePointer<A> aHandler(new A);
		UniquePointer<A> a1Handler(new A);
		UniquePointer<B> bHandler(new B);
		UniquePointer<C> c1Handler(new C);
		cout << "=== UniquePointer c2Handler(std::move(a1Handler))" << endl;
		UniquePointer<C> c2Handler(std::move(a1Handler));
		cout << "=== c1Handler->operation();" << endl;
		c1Handler->operation();
		cout << "=== c2Handler->operation();" << endl;
		c2Handler->operation();
		cout << "=== c1Handler = std::move(aHandler);" << endl;
		c1Handler = std::move(aHandler);
		cout << "=== c1Handler->operation();" << endl;
		c1Handler->operation();

//		cout << "c1Handler = std::move(bHandler);" << endl;
//		c1Handler = std::move(bHandler);
		cout << "}" << endl << " === end block" << endl;
	}
}
