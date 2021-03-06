/*
 * BaseDerived.h
 *
 *  Created on: Dec 14, 2020
 *      Author: user
 */

#ifndef BASEDERIVED_H_
#define BASEDERIVED_H_

#include <iostream>

// no declared non-static members / attributes
class Base{
public:
	Base(){
//		this->operation();
	}
	virtual ~Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
//		this->operation();
	}
	virtual void Operation1(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual void Operation2(){

	}
};
// no declared non-static members / attributes
class Derived : public Base{
public:
	Derived(){
//		this->operation();
	}
	~Derived(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
//		this->operation();
	}
	void Operation1()override{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual void Operation3(){

	}
};

#endif /* BASEDERIVED_H_ */
