/*
 * BitFiddleFunctions.h
 *
 *  Created on: 21.08.2016
 *      Author: Gerd
 */

#ifndef BITFIDDLEFUNCTIONS_H_
#define BITFIDDLEFUNCTIONS_H_

bool isBitSet(unsigned int target, unsigned int mask);
bool isSame(unsigned int target, unsigned int mask, unsigned int excludedmask);

void setBit(unsigned int& target, unsigned int mask);
void clearBit(unsigned int& target, unsigned int mask);
void toggleBit(unsigned int& target, unsigned int mask);




#endif /* BITFIDDLEFUNCTIONS_H_ */
