/*
 * BitFiddleFunctions.cpp
 *
 *  Created on: 21.08.2016
 *      Author: Gerd
 */

#include "BitFiddleFunctions.h"

bool isSame(unsigned int target, unsigned int mask, unsigned int excludedBits){
	return (target & ~excludedBits) == (mask & ~excludedBits);
}

bool isBitSet(unsigned int target, unsigned int mask){
	return (target & mask) != 0;
}

void setBit(unsigned int& target, unsigned int mask){
	target |= mask;
}
void clearBit(unsigned int& target, unsigned int mask){
	target &= ~mask;
}
void toggleBit(unsigned int& target, unsigned int mask){
	target ^= mask;
}


