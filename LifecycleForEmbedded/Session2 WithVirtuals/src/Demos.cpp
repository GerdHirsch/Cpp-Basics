

#include <iostream>

#include "BaseDerived.h"
using namespace std;
void demoVirtualFunctionCall(Base &b){
	b.Operation1();
}

void demo(){
	Derived d;
	demoVirtualFunctionCall(d);
}
