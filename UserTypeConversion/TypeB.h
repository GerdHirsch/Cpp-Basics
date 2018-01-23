/*
 * TypeA.h
 *
 *  Created on: 16.11.2015
 *      Author: Gerd
 */

#ifndef TYPEB_H_
#define TYPEB_H_

#include <iostream>

class TypeC;

class TypeB{
public:
	TypeB(TypeC& rhs){
		std::cout << "TypeB(TypeC& rhs)" << std::endl;
	}

	// NonConst Copy Ctor !!!
//	TypeB(TypeB &rhs){
//		std::cout << "TypeB(TypeB const& rhs)" << std::endl;
//	}
	TypeB(TypeB const& rhs){
		std::cout << "TypeB(TypeB const& rhs)" << std::endl;
	}
	TypeB(){
		std::cout << "TypeB()" << std::endl;
	}
};

class TypeC{
public:
	operator TypeB(){
		std::cout << "TypeC::operator TypeB()" << std::endl;
		return TypeB();
	}
	TypeC(){
		std::cout << "TypeC()" << std::endl;
	}
};

#endif /* TYPEB_H_ */
