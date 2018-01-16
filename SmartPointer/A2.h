#ifndef A2_H_
#define A2_H_

#include <ostream>

class A
{
public:
	A() { std::cout << "A::A()" << std::endl; }

	//explicit
	A(A const& src): i(src.i) { std::cout << "A::A(A const& src)" << std::endl; }

	//explicit
	A(A && src): i(src.i) {
		src.i = 0;
		std::cout << "A::A(A && src)" << std::endl;
	}

	~A() { std::cout << "A::~A()" << std::endl; }

	A& operator=(A const& src){
		i = src.i;
		std::cout << "A& A::operator=(A const& src)" << std::endl;
		return *this;
	}
	A& operator=(A && src){
		i = src.i;
		src.i = 0;
		std::cout << "A& A::operator=(A && src)" << std::endl;
		return *this;
	}
	virtual void operation() {
		std::cout << "A::operation() i: " << i << std::endl;
	}

	int i = 42;

	friend std::ostream& operator<<(std::ostream& os, A const& a){
		os << a.i; return os;
	}
};
#endif /* A2_H_ */
