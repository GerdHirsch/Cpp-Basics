#ifndef A4_BASE_BC_H_
#define A4_BASE_BC_H_

#include "C.h"
#include "B.h"

class A : public C, public B
{
public:
	A() : C{}, B{} { std::cout << "A::A()" << std::endl; }

	//explicit
	A(A const& src) : C{src}, B{src}, i{src.i}
		{ std::cout << "A::A(A const& src)" << std::endl; }

	//explicit
	A(A && src) : C(std::move(src)), B(std::move(src)), i{src.i}
	{
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}

	~A() { std::cout << "A::~A()" << std::endl; }

	A& operator=(A const& src){
		C::operator =(src);
		B::operator =(src);
		i = src.i;
		std::cout << "A& A::operator=(A const& src)" << std::endl;
		return *this;
	}
	A& operator=(A && src){
		C::operator =(std::move(src));
		B::operator =(std::move(src));
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)" << std::endl;
		return *this;
	}
	int i = 42;
};

#endif /* A4_BASE_BC_H_ */
