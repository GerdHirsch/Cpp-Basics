/*
 * BaseDerived.h
 *
 *  Created on: Dec 14, 2020
 *      Author: user
 */

#ifndef BASEDERIVED_H_
#define BASEDERIVED_H_

#include <iostream>

class Base{
public:
	Base(){
//		this->operation();
	}
	virtual
	~Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
//		this->operation();
	}
	virtual
	void operation(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};
class Derived : public Base{
public:
	Derived(){
//		this->operation();
	}
	~Derived(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
//		this->operation();
	}
	virtual
	void operation(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

#endif /* BASEDERIVED_H_ */
