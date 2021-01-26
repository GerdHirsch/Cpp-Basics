/*
 * TemplateMethodGoF.hpp
 *
 *  Created on: Jan 14, 2021
 *      Author: user
 */

#ifndef TEMPLATEMETHODGOF_HPP_
#define TEMPLATEMETHODGOF_HPP_

#include <iostream>

class Base{
public:
	void templateMethod(){
		this->hookMethod();
	}
private:
	virtual void hookMethod(){
		std::cout << "doSomething default" << std::endl;
	}
};

class Derived : public Base{
private:
	void hookMethod() override {
		std::cout << "doSomething special" << std::endl;
	}
};




#endif /* TEMPLATEMETHODGOF_HPP_ */
