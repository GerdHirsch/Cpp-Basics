/*
 * demoCleanCode.cpp
 *
 *  Created on: 21.07.2019
 *      Author: Gerd
 */

#include <iostream>

#include "IPLightBulb.h"
#include "TrafficLight.h"
using namespace std;

void demoCleanCode(){
	cout << "demoCleanCode()" << endl;

	IPLightBulb red("a1.red");
	IPLightBulb yellow("a1.yellow");
	IPLightBulb green("a1.green");

	TrafficLight a1(&red, &yellow, &green);

	a1.warn();
	a1.switchOver();
}




