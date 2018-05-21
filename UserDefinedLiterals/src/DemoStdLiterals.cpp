/*
 * DemoStdLiterals.cpp
 *
 *  Created on: 09.04.2018
 *      Author: Gerd
 */


#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono_literals;

void demoStdLiterals(){
	cout << __PRETTY_FUNCTION__ << endl;

	auto millis = 5'00ms;

	cout << "before this_thread::sleep_for(millis);" << endl;
	this_thread::sleep_for(millis);
	cout << "after this_thread::sleep_for(millis);" << endl;
}
