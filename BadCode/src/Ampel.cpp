///////////////////////////////////////////////////////////
//  Ampel.cpp
//  Implementation of the Class Ampel
//  Created on:      30-Sep-2008 14:54:02
///////////////////////////////////////////////////////////
#include <exception>
#include <iostream>

using namespace std;
#include "Ampel.h"
#include "Lampe.h"
#include "ProtocolViolationException.h"

void Ampel::aus(){
	if (state != AUS && state != BLINKEND)
		throw ProtocolViolationException("Ampel.aus() in falschem State");
        cout << "Ampel::aus() in State: Blinkend" << endl;
	state = AUS;
	rot->aus();
	gelb->aus();
	gruen->aus();	
}
void Ampel::umschalten(){
	switch(state){
		case ROT:
            cout << "Ampel::umschalten() in State: ROT" << endl;
			state = ROTGELB;
			//entry Action
			rot->ein();
			gelb->ein();
			gruen->aus();
		break;
		case ROTGELB:
			state = GRUEN;
            cout << "Ampel::umschalten() in State: GRUEN" << endl;
			//entry Action
			rot->aus();
			gelb->aus();
			gruen->ein();
		break;
		case GRUEN:
            cout << "Ampel::umschalten() in State: GRUEN" << endl;
			//entry Action
			state = GELB;
			rot->aus();
			gelb->ein();
			gruen->aus();
		break;
		case GELB:
            cout << "Ampel::umschalten() in State: GELB" << endl;
			//entry Action
   			state = ROT;
			rot->ein();
			gelb->aus();
			gruen->aus();
		break;
		case BLINKEND:
            cout << "Ampel::umschalten() in State: BLINKEND" << endl;

			//TODO exit Action: BlinkenThread stoppen
			state = GELB;
			//Entry Action
			rot->aus();
			gelb->ein();
			gruen->aus();
		break;

		case AUS:
		default:
			throw ProtocolViolationException("Ampel.umschalten() in State AUS");
	};
}
Ampel::Ampel(Lampe* rot, Lampe* gelb, Lampe* gruen)
	:rot(rot), gelb(gelb), gruen(gruen), state(AUS)
	{}


void Ampel::warne(){
/*
	Alles Ausschalten und blinken Thread starten
*/
        cout << "Ampel::warne()" << endl;

	state = BLINKEND;
	rot->aus();
	gelb->ein(); // symbolisch für blinkend
	gruen->aus();
}
