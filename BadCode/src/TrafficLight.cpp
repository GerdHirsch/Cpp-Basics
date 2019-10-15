///////////////////////////////////////////////////////////
//  Ampel.cpp
//  Implementation of the Class Ampel
//  Created on:      30-Sep-2008 14:54:02
///////////////////////////////////////////////////////////
#include <exception>
#include <iostream>

using namespace std;
#include "TrafficLight.h"
#include "LightBulb.h"
#include "ProtocolViolationException.h"

void TrafficLight::off(){
	if (state != OFF && state != TWINKLING)
		throw ProtocolViolationException("Ampel.aus() in falschem State");
        cout << "Ampel::aus() in State: Blinkend" << endl;
	state = OFF;
	red->off();
	yellow->off();
	green->off();	
}
void TrafficLight::switchOver(){
	switch(state){
		case RED:
            cout << "TrafficLight::switchOver() in State: RED" << endl;
			state = REDYELLOW;
			//entry Action
			red->on();
			yellow->on();
			green->off();
		break;
		case REDYELLOW:
			state = GREEN;
            cout << "TrafficLight::switchOver() in State: REDYELLOW" << endl;
			//entry Action
			red->off();
			yellow->off();
			green->on();
		break;
		case GREEN:
            cout << "TrafficLight::switchOver() in State: GREEN" << endl;
			//entry Action
			state = YELLOW;
			red->off();
			yellow->on();
			green->off();
		break;
		case YELLOW:
            cout << "TrafficLight::switchOver() in State: YELLOW" << endl;
			//entry Action
   			state = RED;
			red->on();
			yellow->off();
			green->off();
		break;
		case TWINKLING:
            cout << "TrafficLight::switchOver() in State: TWINKLING" << endl;

			//TODO exit Action: stop TWINKLINGThread
			state = YELLOW;
			//Entry Action
			red->off();
			yellow->on();
			green->off();
		break;

		case OFF:
		default:
			throw ProtocolViolationException("TrafficLight::switchOver() in State OFF");
	};
}
TrafficLight::TrafficLight(LightBulb* rot, LightBulb* gelb, LightBulb* gruen)
	:red(rot), yellow(gelb), green(gruen), state(OFF)
	{}


void TrafficLight::warn(){
/*
	Alles Ausschalten und blinken Thread starten
*/
        cout << "Ampel::warne()" << endl;

	state = TWINKLING;
	red->off();
	yellow->on(); // symbolisch f�r blinkend
	green->off();
}
