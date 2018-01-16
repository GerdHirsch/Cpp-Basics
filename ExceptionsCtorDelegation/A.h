/*
 * A.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef A_H_
#define A_H_

#include <stdexcept>

class B {
public:
	B() { std::cout << "B::B()" << std::endl; }

	~B() { std::cout << "B::~B()" << std::endl; }
};

class C {
public:
	C(bool throwException = true) {
		std::cout
			<< "C::C(bool throwException = "
			<< std::boolalpha << throwException
			<< std::noboolalpha << ")" << std::endl;
		if(throwException)
			throw std::runtime_error("C(bool throwException)");
	}

	~C() { std::cout << "C::~C()" << std::endl; }
};


class A {
	B b;
	C c;

public:
	A(bool throwException = true) : b(), c(throwException) {
		std::cout << "A::A(bool throwException = "
				<< std::boolalpha << throwException
				<< std::noboolalpha << ")" << std::endl;
	}
	// after ctor delegation A(false), A is completely constructed, hence it's dtor will be called
	A(int i) : A(false) {
		std::cout << "A::A(int i)" << std::endl;
		throw std::runtime_error("A(int i)");
	}

	A(char)
	try
	: A()
	{
		std::cout << "A(char) try : A()" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "A(char c) catch exception from: " << e.what() << std::endl;
		throw std::logic_error("replaced in catch Block");
	}

	~A() { std::cout << "A::~A()" << std::endl; }
};



#endif /* A_H_ */
