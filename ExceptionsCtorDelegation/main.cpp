/*
 * main.cpp
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */
#include "A.h"

#include <memory>
#include<iostream>
using namespace std;


void demoAonStack();
void demoAonHeap();

int main(){
	cout << "ExceptionsKonstruktoren" << endl;

//	demoAonStack();
	demoAonHeap();
}
void demoAonHeap(){
	cout << endl << "demoAonHeap" << endl;

	cout << endl << "### A on Heap: make_unique<A>();" << endl;
	try {
//		auto a = std::make_unique<A>();
		auto a = new A;
	}
	catch (exception& e) {
		cout << "A on Heap: catch exception from: " << e.what() << endl;
	}

	cout << endl << "### A on Heap:  make_unique<A>(int);" << endl;
	try {
		auto a = std::make_unique<A>(23);
	}
	catch (exception& e) {
		cout << "A on Heap: catch exception from: " << e.what() << endl;
	}


	cout << endl << "### A on Heap:  make_unique<A>(char);" << endl;
	try {
		auto a = std::make_unique<A>('c');
	}
	catch (exception& e) {
		cout << "A on Heap catch exception from: " << e.what() << endl;
	}
}
void demoAonStack(){
	cout << endl << "demoAonStack" << endl;

	cout << endl << "### A on Stack: A a;" << endl;
	try {
		A a;
	}
	catch (exception& e) {
		cout << "A on Stack: catch exception from: " << e.what() << endl;
	}

	cout << endl << "### A on Stack: A a(int);" << endl;
	try {
		A a(23);
	}
	catch (exception& e) {
		cout << "A on Stack: catch exception from: " << e.what() << endl;
	}


	cout << endl << "### A on Stack: A a(char);" << endl;
	try {
		A a('c');
	}
	catch (exception& e) {
		cout << "A on Stack: catch exception from: " << e.what() << endl;
	}
}

