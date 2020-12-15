/*
 * EmptyClass.h
 *
 *  Created on: Dec 14, 2020
 *      Author: user
 */

#ifndef EMPTYCLASS_H_
#define EMPTYCLASS_H_

#include <iostream>

class EmptyClass{};

class EmptyBaseWithNonVirtuals{
public:
	EmptyBaseWithNonVirtuals(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~EmptyBaseWithNonVirtuals(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	void operation(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};
class DerivedFromNonVirtuals : public EmptyBaseWithNonVirtuals{
public:
	DerivedFromNonVirtuals(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~DerivedFromNonVirtuals(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	void operation(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};


#endif /* EMPTYCLASS_H_ */
