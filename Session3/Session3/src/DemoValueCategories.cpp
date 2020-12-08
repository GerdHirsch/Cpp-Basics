/*
 * DemoValueCategories.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: Gerd Hirsch
 */

#include <iostream>
using namespace std;

class T{};

void f(T & t){
	cout << __PRETTY_FUNCTION__ << endl;
}
void f(T && t){
	cout << __PRETTY_FUNCTION__ << endl;
}
void f1(T&& t1){
	cout << __PRETTY_FUNCTION__ << endl;
	cout << "=== f(t1);" << endl;
	f(t1); // f(T&) is called
	cout << "=== f(std::move(t1));" << endl;
	f(std::move(t1)); // f(T&&) is called
	cout << "=== f(T{});" << endl;
	f(T{}); // f(T&&) is called
}
void demoValueCategories(){
	cout << __PRETTY_FUNCTION__ << endl;
	f1(T{});
}

