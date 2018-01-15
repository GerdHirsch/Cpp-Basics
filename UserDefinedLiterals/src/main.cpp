/*
 * main.cpp
 *
 *  Created on: 22.02.2016
 *      Author: Gerd
 */

#include "UserLiterals.h"
#include "Basis3Literal.h"

#include<iostream>

using namespace std;

void demoRawStringDelimiter();
void demoMyInt();
void demoDistance();
void demoB3();
int main(){
	cout << "BenutzerdefinierteLiterale" << endl;

//	demoDistance();
//	demoMyInt();
	demoB3();
	demoRawStringDelimiter();
}
void demoRawStringDelimiter(){
	cout << R"mydelim(Raw \ String } ? () "textinhochkomma")mydelim" << endl;
}
void demoB3(){
	std::cout << "demoB3()" << std::endl;
	std::cout << "122_b3: " << 122_b3 << std::endl;
	std::cout << "200_b3: " << 200_b3 << std::endl;
	std::cout << "201_b3: " << 201_b3 << std::endl;
//	std::cout << "2031_b3: " << 2031_b3 << std::endl;

//	std::cout << "410_b3: " << 401_b3 << std::endl;
}

void demoDistance(){
	cout << "demoDistance()" << endl;

	cout << 5.0_Km << endl;
	cout << 5.2_cm << endl;
}
void demoMyInt(){
	cout << "demoMyInt()" << endl;
	MyInt i{42};
	cout << i << endl;

	cout << 43_i << endl;

	MyComplex c(5, 4);
	cout << c << endl;
	cout << 6.0+3.0_i << endl;
}


