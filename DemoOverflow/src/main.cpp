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

	using NativeType = std::size_t;
//	using NativeType = signed int;
	// overflow not defined for signed integers
	constexpr NativeType value = static_cast<NativeType>(-1) << 4;
	cout << hex << "value: " << value << endl;
}

