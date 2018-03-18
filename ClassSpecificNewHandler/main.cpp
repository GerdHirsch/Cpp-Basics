/*
 * main.cpp
 *
 *  Created on: 25.09.2015
 *      Author: Gerd
 */

#include<iostream>
using namespace std;


#include "Widget.h"
#include "NewHandlerSupport.h"

void outOfMemory(){
	cout << "outOfMemory() called" << endl;
	std::set_new_handler(nullptr);
}
int main(){
	cout << "ClassSpecificNewHandler" << endl;

	Widget::set_new_handler(outOfMemory);
	Widget* pW = nullptr;
	try{
		cout << "=== main: pW = new Widget(true);" << endl;
		pW = new Widget(true);
//		pW = new Widget();
	}catch(std::logic_error& e){
		cout << "=== main catch(logic_error& e): " << e.what() << endl;
	}catch(std::bad_alloc& e){
		cout << "=== main catch(bad_alloc& e): " << e.what() << endl;
	}
	delete pW;

//	cout << "standard Placement new nur möglich, wenn StandardNewDeleteForms als NewDeletePolicy verwendet wird!" << endl;
//
//	void *rawMemory = ::operator new(sizeof(Widget));
//	pW = new(rawMemory) Widget;
//
//	pW->~Widget();
//	::operator delete(rawMemory);
}


