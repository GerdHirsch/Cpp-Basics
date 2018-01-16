#ifndef A3MemberBC_H_
#define A3MemberBC_H_

#include "C.h"
#include "B.h"

class A
{
public:
	A() : c{}, b{} { std::cout << "A::A()" << std::endl; }

	//explicit
	A(A const& src) : c{src.c}, b{src.b}, i{src.i}
		{ std::cout << "A::A(A const& src)" << std::endl; }

	//explicit
	A(A && src) : c(std::move(src.c)), b(std::move(src.b)), i{src.i}
	{
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}

	~A() { std::cout << "A::~A()" << std::endl; }

	A& operator=(A const& src){
		c = src.c;
		b = src.b;
		i = src.i;
		std::cout << "A& A::operator=(A const& src)" << std::endl;
		return *this;
	}
	A& operator=(A && src){
		c = std::move(src.c);
		b = std::move(src.b);
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)" << std::endl;
		return *this;
	}
	C c;
	B b;
	int i = 42;
};

#endif /* A3MemberBC_H_ */
