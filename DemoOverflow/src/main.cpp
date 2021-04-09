/*
 * main.cpp
 *
 *  Created on: 28.04.2019
 *      Author: Gerd
 * https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow
 * https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap
 */


#include <iostream>
using namespace std;

int main(){
	cout << "DemoOverflow" << endl;

	using FundamentalType = std::size_t;
//	using FundamentalType = signed int;
	// overflow not defined for signed integers
	constexpr FundamentalType value = static_cast<FundamentalType>(-1) << 4;
	cout << hex << "value: " << value << endl;


	FundamentalType ui{0};
	cout
	<< " ui: " << ui << endl
	<< " ui - 1                             : " << ui - 1 << endl
	<< " numeric_limits<decltype(ui)>::max(): " << numeric_limits<decltype(ui)>::max()
	<< endl;

	ui = numeric_limits<decltype(ui)>::max();
	cout
	<< " ui : " << ui << endl
	<< " ui + 1: " << ui + 1
	<< endl;

}

