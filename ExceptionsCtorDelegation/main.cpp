/*
 * main.cpp
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#include<iostream>
using namespace std;

#include "A.h"

int main(){
	cout << "ExceptionsKonstruktoren" << endl;

	cout << endl << "### main: A a;" << endl;
	try {
		A a;
	}
	catch (exception& e) {
		cout << "main catch exception from: " << e.what() << endl;
	}

	cout << endl << "### main: A a(int);" << endl;
	try {
		A a(23);
	}
	catch (exception& e) {
		cout << "main catch exception from: " << e.what() << endl;
	}


	cout << endl << "### main: A a(char);" << endl;
	try {
		A a('c');
	}
	catch (exception& e) {
		cout << "main catch exception from: " << e.what() << endl;
	}
}

