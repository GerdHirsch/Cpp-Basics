///////////////////////////////////////////////////////////
//  MessageController.cpp
//  Implementation of the Class MessageController
//  Created on:      30-Sep-2008 14:54:02
///////////////////////////////////////////////////////////
#include <exception>
#include <iostream>

using namespace std;

#include "MessageController.h"
#include "DemoSocket.h"

void MessageController::aus(){
	if (state != CASE0 && state != CASE5)
		throw std::logic_error("MessageController.aus() in wrong State");

	state = CASE0;
	socket1->send(0);
	socket2->send(0);
	socket3->send(0);
}
void MessageController::sendIPMessages(){
	cout << "MessageController::sendIPMessages()" << endl;
	switch(state){
		case CASE1:
			state = CASE2;
			socket1->send(1);
			socket2->send(1);
			socket3->send(0);
		break;
		case CASE2:
			state = CASE3;
			socket1->send(0);
			socket2->send(0);
			socket3->send(1);
		break;
		case CASE3:
			state = CASE4;
			socket1->send(0);
			socket2->send(1);
			socket3->send(0);
		break;
		case CASE4:
   			state = CASE1;
			socket1->send(1);
			socket2->send(0);
			socket3->send(0);
		break;
		case CASE5:
			state = CASE3;
			socket1->send(0);
			socket2->send(1);
			socket3->send(0);
		break;

		case CASE0:
		default:
			throw std::logic_error("MessageController.sendIPMessage() in wrong State");
	};
}
MessageController::MessageController(DemoSocket* socket1, DemoSocket* socket2, DemoSocket* socket3)
	:socket1(socket1), socket2(socket2), socket3(socket3), state(CASE0)
	{}


void MessageController::warne(){
/*
	Alles Ausschalten und blinken Thread starten
*/
        cout << "MessageController::warne()" << endl;

	state = CASE5;
	socket1->send(0);
	socket2->send(1);
	socket3->send(0);
}
