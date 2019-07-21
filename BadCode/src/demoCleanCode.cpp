/*
 * demoCleanCode.cpp
 *
 *  Created on: 21.07.2019
 *      Author: Gerd
 */

#include "Ampel.h"
#include "Lampe.h"

#include <iostream>
using namespace std;

void demoCleanCode(){
	cout << "demoCleanCode()" << endl;

	Lampe rot("a1.rot");
	Lampe gelb("a1.gelb");
	Lampe gruen("a1.gruen");

	Ampel a1(&rot, &gelb, &gruen);

	a1.warne();
	a1.umschalten();
}




