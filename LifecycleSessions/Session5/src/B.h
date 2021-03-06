#ifndef B_H_
#define B_H_


#include <iostream>

class B
{
public:
	B() : i() { std::cout << "B::B()" << std::endl; }
	~B() { std::cout << "B::~B()" << std::endl; }

	explicit
	B(int i) : i(i){ std::cout << "B::B(int "<< i <<")" << std::endl; }
// copy
	B(B const& src): i(src.i) { std::cout << "B::B(B const& src)" << std::endl; }
	B& operator=(B const& src)&{
		i = src.i;
		std::cout << "B& B::operator=(B const& src)&" << std::endl;
		return *this;
	}
	// move
	B(B && src): i(src.i) {
		src.i = 0;
		std::cout << "B::B(B && src)" << std::endl;
	}
	B& operator=(B && src)&{
		i = src.i;
		src.i = 0;
		std::cout << "B& B::operator=(B && src)&" << std::endl;
		return *this;
	}

	int i;
};
#endif /* B_H_ */
