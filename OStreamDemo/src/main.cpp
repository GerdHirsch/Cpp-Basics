/*
 * main.cpp
 *
 *  Created on: 31.03.2021
 *      Author: Gerd
 */


#include "../include/MyOstream.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyClass{
	friend ostream& operator<<(ostream& out, MyClass const&);
};
ostream& operator<<(ostream& out, MyClass const&){
	out << "MyClass";
	return out;
}

int main(){
	cout << "OStreamDemo" << endl;

	MyClass myClass;
	{
	fstream outPutFile("demo.txt", ios::out);

	using Out = MyOstream<char>;

	Out standardOut(cout);
	Out fileOut(outPutFile);

	string myOstream("MyOstream");

	standardOut << myOstream << string(" something else") << " C-String" << endl;
	standardOut << "pi: " << 3.14 << " the answer: "<< 42 << " hex: " << hex  << 16 << endl;
	standardOut << myClass << endl;

	fileOut << myOstream << string(" something else") << " C-String" << endl;
	fileOut << "pi: " << 3.14 << " the answer: "<< 42 << " hex: " << hex  << 16 << endl;
	fileOut << myClass << endl;

	}

	cout << "end" << endl;
}


