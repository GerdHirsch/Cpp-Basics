#ifndef C_H_
#define C_H_

class C
{
public:
	C() : i{} { std::cout << "C::C()" << std::endl; }

	C(C const& src): i(src.i) { std::cout << "C::C(C const& src)" << std::endl; }

	C(C && src): i(src.i) {
		src.i = 0;
		std::cout << "C::C(C && src)" << std::endl;
	}

	virtual ~C() { std::cout << "C::~C()" << std::endl; }

	C& operator=(C const& src){
		i = src.i;
		std::cout << "C& C::operator=(C const& src)" << std::endl;
		return *this;
	}
	C& operator=(C && src){
		i = src.i;
		src.i = 0;
		std::cout << "C& C::operator=(C && src)" << std::endl;
		return *this;
	}
	virtual void operation() { std::cout << "C::operation() i: " << i << std::endl; }

	int i;
};
#endif /* C_H_ */
