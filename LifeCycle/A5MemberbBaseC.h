#ifndef A5_MEMBER_B_BASE_C_H_
#define A5_MEMBER_B_BASE_C_H_

#include "C.h"
#include "B.h"

#include <iostream>

class A : public C
{
public:
	A() : C{} {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::cout << "A::A()" << std::endl;
	}

//	explicit
	A(A const& src) : C{src}, b{src.b}, i{src.i}{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::cout << "A::A(A const& src)" << std::endl;
	}

	//explicit
	A(A && src) : C(std::move(src)), b(std::move(src.b)), i{src.i}
	{
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}

	~A() { std::cout << "A::~A()" << std::endl; }

	A& operator=(A const& src){
		C::operator =(src);
		b = src.b;
		i = src.i;
		std::cout << "A& A::operator=(A const& src)" << std::endl;
		return *this;
	}
	A& operator=(A && src){
		C::operator =(std::move(src));
		b = std::move(src.b);
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)" << std::endl;
		return *this;
	}
	B b = B(50);
	int i = 42;
};
#endif /* A5_MEMBER_B_BASE_C_H_ */
