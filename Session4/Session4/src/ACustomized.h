#ifndef A2_H_
#define A2_H_

#include <iostream>
class A
{
public:
	~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	A():i(0) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	A(int i):i(i){std::cout << __PRETTY_FUNCTION__ << std::endl;}
	// Copy -----------------------------------------------------------
	A(A const& src): i(src.i)
	{ std::cout << "A(A const& src)" << std::endl;}

	A& operator=(A const& src)&{
		i = src.i;
		std::cout << "A& operator=(A const& src)&" << std::endl;
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
};
#endif /* A2_H_ */
