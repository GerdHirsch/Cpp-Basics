/*
 * main.cpp
 *
 *  Created on: Jan 14, 2021
 *      Author: user
 */

//#include "TemplateMethodWithCRTP.hpp"
#include "TemplateMethodGoF.hpp"

#include <iostream>
using namespace std;

int main(){
	cout << "Session4 TemplateMethodPatternWithCRTP" << endl;
	Derived d;
	d.templateMethod();
}


