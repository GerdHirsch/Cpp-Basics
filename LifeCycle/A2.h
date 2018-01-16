#ifndef A2_H_
#define A2_H_

#include <iostream>

class A
{
public:
	~A() { std::cout << "A::~A()" << std::endl; }

	A() { std::cout << "A::A()" << std::endl; }

	// Copy -----------------------------------------------------------
//	explicit
	A(A const& src): i(src.i) { std::cout << "A::A(A const& src)" << std::endl; }

	A& operator=(A const& src){
		i = src.i;
		std::cout << "A& A::operator=(A const& src)" << std::endl;
		return *this;
	}

	// Move -----------------------------------------------------------
	//explicit
	A(A && src): i(src.i) {
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}

	A& operator=(A && src){
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)" << std::endl;
		return *this;
	}

	int i = 42;

	friend std::ostream& operator<<(std::ostream& os, A const& a){
		os << a.i; return os;
	}
};
#endif /* A2_H_ */
