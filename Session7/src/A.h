#ifndef C_H_
#define C_H_

#include <iostream>

class A
{
public:
	A() : i{} { std::cout << "A::A()" << std::endl; }
	~A() { std::cout << "A::~A()" << std::endl; }

	// copy
	A(A const& src): i(src.i) { std::cout << "A::A(A const& src)" << std::endl; }
	A& operator=(A const& src)&{
		i = src.i;
		std::cout << "A& A::operator=(A const& src)&" << std::endl;
		return *this;
	}
	// move
	A(A && src): i(src.i) {
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}
	A& operator=(A && src)&{
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)&" << std::endl;
		return *this;
	}
	// conversions
	explicit
	A(int i):i(i){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	explicit
	operator int()const {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return i;
	}

	int i;
};
#endif /* C_H_ */
