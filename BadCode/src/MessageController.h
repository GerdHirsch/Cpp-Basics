///////////////////////////////////////////////////////////
//  MESSAGE_CONTROLLER_H.h
//  Implementation of the Class MESSAGE_CONTROLLER_H
//  Created on:      30-Sep-2008 14:54:01
///////////////////////////////////////////////////////////

#ifndef MESSAGE_CONTROLLER_H
#define MESSAGE_CONTROLLER_H

//forward declaration
class DemoSocket;

class MessageController
{
public:
	MessageController(DemoSocket* s1, DemoSocket* s2, DemoSocket* s3);

	virtual void off();
	virtual void sendIPMessages();
	virtual void init();

	enum ControllerStates
	{
		CASE0,
		CASE1,
		CASE4,
		CASE2,
		CASE3,
		CASE5
	};

private:
	DemoSocket *socket1;
	DemoSocket *socket2;
	DemoSocket *socket3;
	ControllerStates state;

};


#endif // (MESSAGE_CONTROLLER_H)
