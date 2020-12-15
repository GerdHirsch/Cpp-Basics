

#include <iostream>

#include "Virtuals.h"
using namespace std;

void demoSizeofVirtuals(){
	cout << endl << __PRETTY_FUNCTION__ << endl;
	{
	EmptyClass empty;
	cout << "=== EmptyBaseWithNonVirtuals emptyBaseWithNonVirtuals;" << endl;
	EmptyBaseWithNonVirtuals emptyBaseWithNonVirtuals;
	cout << "=== DerivedFromNonVirtuals derivedFromNonVirtuals;" << endl;
	DerivedFromNonVirtuals derivedFromNonVirtuals;

	cout << endl
		<< "sizeof(empty): " 			<< sizeof(empty)
		<< " == sizeof(EmptyClass): " 	<< sizeof(EmptyClass)
		<< endl;

	cout << endl
		<< "sizeof(emptyBaseWithNonVirtuals): " 	<< sizeof(emptyBaseWithNonVirtuals)
		<< " == sizeof(EmptyBaseWithNonVirtuals): " << sizeof(EmptyBaseWithNonVirtuals)
		<< endl;

	cout << endl
		<< "sizeof(derivedFromNonVirtuals): " 	<< sizeof(derivedFromNonVirtuals)
		<< " == sizeof(DerivedFromNonVirtuals): " << sizeof(DerivedFromNonVirtuals)
		<< endl;
	}
	cout << "=== end of " << __PRETTY_FUNCTION__ << endl;
}


void demoCallOfVirtuals(){
	cout << endl << __PRETTY_FUNCTION__ << endl;
	{
		cout << "=== DerivedFromNonVirtuals derived;" << endl;
		DerivedFromNonVirtuals derived;
		EmptyBaseWithNonVirtuals &base = derived;

		cout << "=== derived.operation();" << endl;
		derived.operation();
		cout << "=== base.operation();" << endl;
		base.operation();
	}
	cout << endl;
	{
		cout << "=== DerivedFromNonVirtuals *derived = new DerivedFromNonVirtuals;" << endl;
		DerivedFromNonVirtuals *derived = new DerivedFromNonVirtuals;
		EmptyBaseWithNonVirtuals *base = derived;

		cout << "=== derived->operation();" << endl;
		derived->operation();
		cout << "=== base->operation();" << endl;
		base->operation();

		cout << "=== delete base;" << endl;
		delete base;
	}
	cout << "=== end of " << __PRETTY_FUNCTION__ << endl;
}
