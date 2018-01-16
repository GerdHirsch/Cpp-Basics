#ifndef B_H_
#define B_H_
#include <iostream>
class B
{
public:
	B() : i() { std::cout << "B::B()" << std::endl; }

	explicit
	B(int i) : i(i){ std::cout << "B::B(int "<< i <<")" << std::endl; }

	B(B const& src): i(src.i) { std::cout << "B::B(B const& src)" << std::endl; }

	B(B && src): i(src.i) {
		src.i = 0;
		std::cout << "B::B(B && src)" << std::endl;
	}

	virtual ~B() { std::cout << "B::~B()" << std::endl; }

	B& operator=(B const& src){
		i = src.i;
		std::cout << "B& B::operator=(B const& src)" << std::endl;
		return *this;
	}
	B& operator=(B && src){
		i = src.i;
		src.i = 0;
		std::cout << "B& B::operator=(B && src)" << std::endl;
		return *this;
	}
	virtual void operation() { std::cout << "B::operation() i: " << i << std::endl; }
	virtual void opConst() const { std::cout << "B::opConst() i: " << i << std::endl; }

	int i;
};
#endif /* B_H_ */
