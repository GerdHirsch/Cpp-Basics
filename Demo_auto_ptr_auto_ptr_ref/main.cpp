/*
 * main.cpp
 *
 *  Created on: 15.11.2015
 *      Author: Gerd
 */

#include "DemoAutoPtr.h"

#include<iostream>
using namespace std;

void callByValue(AutoPtr p){
	cout << "f(AutoPtr p): " << p.getName() << endl;

}
AutoPtr returnAndCallByValue(AutoPtr p){
	cout << "returnAndCallByValue(AutoPtr p): " << p.getName() << endl;
	return p;
}

AutoPtr returnAutoPtr(){
	cout << "== returnAutoPtr()" << endl;
	AutoPtr p("p demoReturnAutoPtr");

	cout << "return p;" << endl;
	return p;
}
void demoCallByValue(){
	cout << endl << "=== demoCallByValue()" << endl;
	cout << "=== AutoPtr p(\"p byValue\");" << endl;
	AutoPtr p("p byValue");
	cout << "=== " << endl;
	cout << "=== p = returnAndCallByValue(p);" << endl;
	p = returnAndCallByValue(p);
	cout << "=== p.name: " << p.getName() << endl;
	cout << "=== " << endl;

//	cout << "=== f(p);" << endl;
//	f(p);
//	cout << "=== " << endl;
//	cout << "=== p.name: " << p.getName() << endl;
	cout << endl << "=== end of demoCallByValue()" << endl;
}
void demoReturnAutoPtr(){
	cout << endl << "=== demoReturnAutoPtr()" << endl;
	cout << "=== AutoPtr p = returnAutoPtr();" << endl;
	AutoPtr p = returnAutoPtr();
	cout << "=== p.name: " << p.getName() << endl;
	cout << endl << "=== end of demoReturnAutoPtr()" << endl;
}
void demoExplizitAutoPtrRef(){
	cout << endl << "=== demoExplizitAutoPtrRef()" << endl;
//	//innere Klasse AutoPtrRef muss dazu public sein
//
//		// merkwürdig, dass nur auf AutoPtr const& zugewiesen werden kann
//		// der ctor von AutoPtrRef aber AutoPtr& deklariert ist
//		cout << "AutoPtr::AutoPtrRef ref = returnAutoPtr();" << endl;
//		AutoPtr::AutoPtrRef ref = returnAutoPtr();
////		AutoPtr const& ref = demoReturnAutoPtr();
//
//		AutoPtr p(ref);
//
//		cout << "p.name: " << p.getName() << endl;
////		cout << "ref.name: " << ref.getName() << endl;
}
int main(){
	cout << "Demo_auto_ptr_auto_ptr_ref" << endl;
	demoCallByValue();
	demoReturnAutoPtr();
//	demoExplizitAutoPtrRef();
}


