/*
 * main.cpp
 *
 *  Created on: 21.08.2016
 *      Author: Gerd
 */

#include "BitFiddleFunctions.h"

#include<iostream>
using namespace std;


int main(){
	cout << "BitwiseOperators" << endl;
	unsigned int property = 0x1 << 1;
	unsigned int properties = 0xFFFFFFFC;
	unsigned int original = 0xFFFFFFFC;

	cout << boolalpha;

	cout << "isBitSet: " << isBitSet(properties, property) << endl;
	cout << "isSame: " << isSame(properties, original, property) << endl;


	toggleBit(properties, property);
	cout << "toggle isBitSet: " << isBitSet(properties, property) << endl;
	cout << "isSame: " << isSame(properties, original, property) << endl;


	clearBit(properties, property);
	cout << "clear isBitSet: " << isBitSet(properties, property) << endl;
	cout << "isSame: " << isSame(properties, original, property) << endl;

	setBit(properties, property);
	cout << "set isBitSet: " << isBitSet(properties, property) << endl;
	cout << "isSame: " << isSame(properties, original, property) << endl;

	toggleBit(properties, property);
	cout << "toggle isBitSet: " << isBitSet(properties, property) << endl;
	cout << "isSame: " << isSame(properties, original, property) << endl;
}
