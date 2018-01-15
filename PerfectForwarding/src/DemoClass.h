/*
 * DemoClass.h
 *
 *  Created on: 06.02.2016
 *      Author: Gerd
 */

#ifndef DEMOCLASS_H_
#define DEMOCLASS_H_

#include <iostream>

class Base{
public:
	virtual ~Base() = default;
	virtual
	void rqOp() &&;
	virtual void rqOp() &;

	// error: 'virtual void Base::rqOp()' cannot be overloaded
	// with 'virtual void Base::rqOp() &'
	// virtual void rqOp();

	 virtual void op();

};
class Derived : public Base{
public:
	//virtual
	void rqOp() &&; //override;
	virtual void rqOp() & override;
	virtual void op() override;
};

void Base::rqOp() &&{
	std::cout << "Base::rqOp() &&" << std::endl;
}
void Base::rqOp() &{
	std::cout << "Base::rqOp() &" << std::endl;
}
void Base::op(){
	std::cout << "Base::op()" << std::endl;
}

void Derived::rqOp() && {
	std::cout << "Derived::rqOp() &&" << std::endl;
}
void Derived::rqOp() & {
	std::cout << "Derived::rqOp() &" << std::endl;
}
void Derived::op(){
	std::cout << "Derived::op()" << std::endl;
}

#endif /* DEMOCLASS_H_ */
