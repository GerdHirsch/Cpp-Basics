///////////////////////////////////////////////////////////
//  Ampel.h
//  Implementation of the Class Ampel
//  Created on:      30-Sep-2008 14:54:01
///////////////////////////////////////////////////////////

#ifndef AMPEL
#define AMPEL

//forward declaration
class DemoSocket;

class MessageController
{
public:
	MessageController(DemoSocket* rot, DemoSocket* gelb, DemoSocket* gruen);

	virtual void aus();
	virtual void sendIPMessages();
	virtual void warne();

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


#endif // (AMPEL)
