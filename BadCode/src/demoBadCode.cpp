/*
 * demoBadCode.cpp
 *
 *  Created on: 21.07.2019
 *      Author: Gerd
 */
#include "MessageController.h"
#include "DemoSocket.h"

#include <iostream>
using namespace std;

void demoBadCode(){
	cout << "demoBadCode()" << endl;

	DemoSocket socket0("127.0.0.001/2010");
	DemoSocket socket1("127.0.0.001/2011");
	DemoSocket socket2("127.0.0.001/2012");

	MessageController controller(&socket0, &socket1, &socket2);

	controller.init();
	controller.sendIPMessages();

}




