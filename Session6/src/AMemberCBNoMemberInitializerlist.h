#ifndef AMEMBERCBNOMEMBERINITIALIZERLIST_H_
#define AMEMBERCBNOMEMBERINITIALIZERLIST_H_

#include "B.h"
#include "C.h"

#include <iostream>

class A
{
public:
	~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	A():i(0) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	// Copy -----------------------------------------------------------
	A(A const& src): i(src.i)
	{ std::cout << __PRETTY_FUNCTION__ << std::endl;}

	A& operator=(A const& src)&{
		i = src.i;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	// Move -----------------------------------------------------------
	A(A && src): i(std::move(src.i)) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A& operator=(A && src)&{
		i = std::move(src.i);
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	int i;
private:
	C c;
	B b;
};
#endif /* AMEMBERCBNOMEMBERINITIALIZERLIST_H_ */
