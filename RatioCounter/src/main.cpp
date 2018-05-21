/*
 * main.cpp
 *
 *  Created on: 20.05.2018
 *      Author: Gerd
 */

#include "RatioCounter.h"

constexpr size_t Precision{3};
using Counter = RatioCounter<Precision>;

#include<iostream>
using namespace std;

int main(){
	cout << "RatioCounter" << endl;

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

