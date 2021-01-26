#include <iostream>

template<class Derived>
class Base{
public:
	void templateMethod(){
		This()->hookMethod();
	}
private:
	void hookMethod(){
		std::cout << "doSomething default" << std::endl;
	}
	Derived* This() { return static_cast<Derived*>(this);}
};

class Derived : public Base<Derived>{
	using base_type = Base<Derived>;
	friend base_type;

	void hookMethod(){
		std::cout << "doSomething special" << std::endl;
	}
};
