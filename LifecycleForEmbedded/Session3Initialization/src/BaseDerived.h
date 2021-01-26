/*
 * BaseDerived.h
 *
 *  Created on: Dec 14, 2020
 *      Author: user
 */

#ifndef BASEDERIVED_H_
#define BASEDERIVED_H_

#include <iostream>

class Base;
class Member{
	Member(Base* base);
};

// no declared non-static members / attributes
class Base{
public:
	Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->Operation1();
		OperationPure();
	}
	virtual ~Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->Operation1();
	}
	virtual void Operation1(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual void Operation2(){

	}
	virtual void OperationPure() = 0;
};
// no declared non-static members / attributes
class Derived : public Base{
public:
	Derived(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->Operation1();
	}
	~Derived(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		this->Operation1();
	}
	void Operation1()override{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual void Operation3(){

	}
	virtual void OperationPure(){ };
};

#endif /* BASEDERIVED_H_ */
