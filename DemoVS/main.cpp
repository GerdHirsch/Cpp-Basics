/*
 * main.cpp
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#include "Ampel.h"
#include "ProtocolViolation.h"
#include "LampeCan.h"
#include "LampeIP.h"

#include<iostream>
using namespace std;

void demoStandard();
void demoException();


int main(){
	cout << "DemoVS" << endl;

	demoStandard();
	demoException();
}

typedef Ampel::Lampe_ptr Lampe_ptr;

void demoStandard(){
	cout << "=== demoStandard()" << endl;
	cout << "=== Ampel a;" << endl;

	Lampe_ptr rot(new LampeCAN("rot"));
	Lampe_ptr gelb(new LampeCAN("gelb"));
	Lampe_ptr gruen(new LampeCAN("gruen"));

	Ampel a(rot, gelb, gruen);

	cout << "=== a.blinke();" << endl;
	a.blinke();
	cout << "=== a.umschalten();" << endl;
	a.umschalten();
	cout << "=== a.umschalten();" << endl;
	a.umschalten();
	cout << "=== a.umschalten();" << endl;
	a.umschalten();
	cout << "=== a.umschalten();" << endl;
	a.umschalten();
	cout << "=== a.umschalten();" << endl;
	a.umschalten();
	cout << "=== a.blinke();" << endl;
	a.blinke();
	cout << "=== a.blinke();" << endl;
	a.blinke();
	cout << "=== a.aus();" << endl;
	a.aus();
	cout << "=== a.aus();" << endl;
	a.aus();
}
void demoException(){
	cout << "=== demoException()" << endl;
	cout << "=== Ampel a;" << endl;
	Lampe_ptr rot(new LampeIP("rot"));
	Lampe_ptr gelb(new LampeIP("gelb"));
	Lampe_ptr gruen(new LampeIP("gruen"));
	Ampel a(rot, gelb, gruen);

	try{
		a.umschalten();
	}catch(ProtocolViolation& e){
		cout << "catched: " << e.what() << endl;
	}

	try{
		cout << "=== a.blinke();" << endl;
		a.blinke();
		cout << "=== a.umschalten();" << endl;
		a.umschalten();

		a.aus();
	}catch(ProtocolViolation& e){
		cout << "catched: " << e.what() << endl;
	}
}


