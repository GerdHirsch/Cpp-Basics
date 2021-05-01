/*
 * Ampel.cpp
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#include "ProtocolViolation.h"
#include "Ampel.h"

Ampel::Ampel(Lampe_ptr rot, Lampe_ptr gelb, Lampe_ptr gruen)
: state(AmpelState::AUS),
  rot(rot), gelb(gelb), gruen(gruen)
{
	// TODO Auto-generated constructor stub
}

Ampel::~Ampel() {
}

void Ampel::umschalten(){
	switch(state){
	case AmpelState::ROT:
		state = AmpelState::ROTGELB;
		rot->ein();
		gelb->ein();
		gruen->aus();
		break;
	case AmpelState::ROTGELB:
		state = AmpelState::GRUEN;
		rot->aus();
		gelb->aus();
		gruen->ein();
		break;
	case AmpelState::GELB:
		state = AmpelState::ROT;
		rot->ein();
		gelb->aus();
		gruen->aus();
		break;
	case AmpelState::BLINKEND:
	case AmpelState::GRUEN:
		state = AmpelState::GELB;
		rot->aus();
		gelb->ein();
		gruen->aus();
		break;
	case AmpelState::AUS:
	default:
		throw ProtocolViolation("umschalten() in AUS");
	}

}
void Ampel::blinke(){
	// degenerierter switch!
	if(state != AmpelState::BLINKEND){
		state = AmpelState::BLINKEND;
		lampenAusschalten();
		//Todo hier BlinkenTimer starten
		gelb->ein();
	}
}
void Ampel::aus(){
	// degenerierter switch!
	if(!(state == AmpelState::AUS || state == AmpelState::BLINKEND))
		throw ProtocolViolation("aus() in Betrieb");
	else if(state == AmpelState::BLINKEND){
		state = AmpelState::AUS;
		lampenAusschalten();
	}
}
void Ampel::lampenAusschalten(){
	rot->aus();
	gelb->aus();
	gruen->aus();
}
