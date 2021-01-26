/*
 * DemoPaddingAndAlignment.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: user
 */
#include <iostream>
using namespace std;

struct alignas(16) DemoAlignedClass{
	char member;
};

void demoAlignment(){
	cout << "=== demoAlignment" << endl;

	cout << "char:\t" 	<< alignof(char) << endl;
	cout << "short:\t" 	<< alignof(short) << endl;
	cout << "int:\t" 	<< alignof(int) << endl;
	cout << "long:\t"	<< alignof(long) << endl;
	cout << "long long:\t" << alignof(long long) << endl;
	cout << endl;
	cout << "float:\t" 	<< alignof(float) << endl;
	cout << "double:\t"	<< alignof(double) << endl;
	cout << endl;
	cout << "alignof(DemoAlignedClass):\t"
			<< alignof(DemoAlignedClass) << endl;
	cout << "sizeof(DemoAlignedClass):\t"
			<< sizeof(DemoAlignedClass) << endl;
}


struct DemoPaddedClass{
	char member_1;
	double member_2;
	short member_3;
};
struct DemoNonPaddedClass{
	double member_2;
	short member_3;
	char member_1;
};
void demoPadding(){
	cout << "=== demoPadding" << endl;
	cout << "alignof(DemoPaddedClass):\t"
			<< alignof(DemoPaddedClass) << endl;
	cout << "sizeof(DemoPaddedClass):\t"
			<< sizeof(DemoPaddedClass) << endl;
	cout << "alignof(DemoNonPaddedClass):\t"
			<< alignof(DemoNonPaddedClass) << endl;
	cout << "sizeof(DemoNonPaddedClass):\t"
			<< sizeof(DemoNonPaddedClass) << endl;
}


