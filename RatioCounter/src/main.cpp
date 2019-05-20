/*
 * main.cpp
 *
 *  Created on: 20.05.2018
 *      Author: Gerd
 */

#include "RatioCounter.h"
#include "IsPowerOf2.h"

constexpr size_t Precision{3};
using Counter = RatioCounter;

#include<iostream>
using namespace std;
void demo(){
	static constexpr size_t mask{1u<<((sizeof(size_t)*8)-1)};
	cout << hex << "mask: " << mask << endl;
}
int main(){
	cout << "RatioCounter" << endl;
	cout << "sizeof(long long)" << sizeof(long long) << endl;
	demo();

	cout << "1: " << countOnes<1>::value << endl;
//	cout << "2: " << countOnes<2>::value << endl;
//	cout << "3: " << countOnes<3>::value << endl;
//	cout << "8: " << countOnes<8>::value << endl;
//
//	for(int i=2; i<1025; i*=2){
//		cout << "countNumberOfOnes i: " << i << " " << countNumberOfOnes(i) << endl;
//	}

	return 0;

	Counter skippedValues(0);
	cout << "skipped: " << skippedValues  << endl;



	while(skippedValues.getValue() != Precision ){
		++skippedValues;
		cout << "skipped: " << skippedValues << endl;
		--skippedValues;
		cout << "skipped: " << skippedValues << endl;
		++skippedValues;
		cout << "skipped: " << skippedValues << endl;
	}
	++skippedValues;
	cout << "skipped: " << skippedValues << endl;
	while(skippedValues.getValue() != 0){
		--skippedValues;
		cout << "skipped: " << skippedValues << endl;
		++skippedValues;
		cout << "skipped: " << skippedValues << endl;
		--skippedValues;
		cout << "skipped: " << skippedValues << endl;
	}
	--skippedValues;
	cout << "skipped: " << skippedValues << endl;
}

