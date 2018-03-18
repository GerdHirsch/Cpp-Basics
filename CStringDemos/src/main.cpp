/*
 * main.cpp
 *
 *  Created on: 20.08.2016
 *      Author: Gerd
 */

#include "MyFunctions.h"

#include<iostream>
using namespace std;

int main(){
	char prjName[] = "CStringDemo";
	cout << prjName << endl;

	cout << revert(prjName) << endl;

	char buffer[sizeof(int)*8 + 1] = "";

	int value = 10, base = 2;
	cout << "Value: " << value << " base: " << base << " " << dec2Base(buffer, value, base) << endl;

	value = 31; base = 16;
	cout << "Value: " << value << " base: " << base << " " << dec2Base(buffer, value, base) << endl;
	value = -31; base = 16;
	cout << "Value: " << value << " base: " << base << " " << dec2Base(buffer, value, base) << endl;
	value = 0; base = 16;
	cout << "Value: " << value << " base: " << base << " " << dec2Base(buffer, value, base) << endl;

	try{
		dec2Base(buffer, 1, 1);
	}catch(exception& e){
		cout << "catch: " << e.what() << endl;
	}

	// Demo 2er Komplement
	int value1 = 1;
	int value2 = ~value1 + 1;
	cout << "value1: " << value1 << " value2: " << value2 << endl;
}


