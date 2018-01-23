/*
 * TypeA.h
 *
 *  Created on: 16.11.2015
 *      Author: Gerd
 */

#ifndef TYPEA_H_
#define TYPEA_H_

#include <iostream>

#include "TypeB.h"

class TypeA{
public:

	TypeA(){
		std::cout << "TypeA()" << std::endl;
	}
	TypeA(TypeB rhs){
		std::cout << "TypeA(TypeB rhs)" << std::endl;
	}
//	operator TypeB(){
//		std::cout << "TypeB()" << std::endl;
//		return TypeB();
//	}
};


#endif /* TYPEA_H_ */
