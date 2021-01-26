#ifndef C_H_
#define C_H_

#include <iostream>

class C
{
public:
	C() : i{} { std::cout << "C::C()" << std::endl; }
	~C() { std::cout << "C::~C()" << std::endl; }

	// copy
	C(C const& src): i(src.i) { std::cout << "C::C(C const& src)" << std::endl; }
	C& operator=(C const& src)&{
		i = src.i;
		std::cout << "C& C::operator=(C const& src)&" << std::endl;
		return *this;
	}
	// move
	C(C && src): i(src.i) {
		src.i = 0;
		std::cout << "C::C(C && src)" << std::endl;
	}
	C& operator=(C && src)&{
		i = src.i;
		src.i = 0;
		std::cout << "C& C::operator=(C && src)&" << std::endl;
		return *this;
	}

	int i;
};
#endif /* C_H_ */
