///////////////////////////////////////////////////////////
//  TrafficLight.h
//  Implementation of the Class TrafficLight
//  Created on:      30-Sep-2008 14:54:01
///////////////////////////////////////////////////////////

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

//forward declaration
class LightBulb;
/**
 * Realisierung der StateMachine mit Switch Statements und einer
 * enum {AUS, BLINKEND, ROT, ROTGELB, YELLOW, GREEN}
 */
class TrafficLight
{
public:
	TrafficLight(LightBulb* rot, LightBulb* gelb, LightBulb* gruen);

	virtual void off();
	virtual void switchOver();
	virtual void warn();

	enum TrafficLightState
	{
		OFF,
		RED,
		YELLOW,
		REDYELLOW,
		GREEN,
		TWINKLING
	};

private:
	LightBulb *red;
	LightBulb *yellow;
	LightBulb *green;
	TrafficLightState state;

};


#endif //TRAFFICLIGHT_H
