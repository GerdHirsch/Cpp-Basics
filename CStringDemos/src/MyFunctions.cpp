/*
 * MyFunctions.cpp
 *
 *  Created on: 20.08.2016
 *      Author: Gerd
 */

#ifndef MYFUNCTIONS_CPP_
#define MYFUNCTIONS_CPP_

#include "MyFunctions.h"

#include <stdexcept>

char* revert(char buffer[]){

	char *pS = buffer, *pE = buffer;

	while(*pE) ++pE;
	--pE;

	while(pS < pE){
		char c = *pE;
		*pE = *pS;
		*pS = c;
		++pS; --pE;
	}
	return buffer;
}

char* dec2Base(char buffer[], int value, int base){
	//Precondition
	if(base < 2) throw std::invalid_argument("base must be 2 or greater!");

	int result = value;
	int pos = 0;

	if(value == 0)
		buffer[pos++] = '0';
	else if(value < 0) // negativ numbers
		result = -result;

	while(result > 0){
		int rest = result % base;
		result /= base;
		if(rest < 10)
			buffer[pos] = rest + '0'; // Calculate ASCII
		else
			buffer[pos] = rest - 10 + 'A';
		++pos;
	}

	if(value < 0) // negativ numbers
		buffer[pos++] = '-';

	buffer[pos] = 0; // zero terminated C-String convention

	return revert(buffer);
}


#endif /* MYFUNCTIONS_CPP_ */
