///////////////////////////////////////////////////////////
//  Ampel.h
//  Implementation of the Class Ampel
//  Created on:      30-Sep-2008 14:54:01
///////////////////////////////////////////////////////////

#ifndef AMPEL
#define AMPEL

//forward declaration
class Lampe;
/**
 * Realisierung der StateMachine mit Switch Statements und einer
 * enum {AUS, BLINKEND, ROT, ROTGELB, GELB, GRUEN}
 */
class Ampel
{
public:
	Ampel(Lampe* rot, Lampe* gelb, Lampe* gruen);

	virtual void aus();
	virtual void umschalten();
	virtual void warne();

	enum AmpelState
	{
		AUS,
		ROT,
		GELB,
		ROTGELB,
		GRUEN,
		BLINKEND
	};

private:
	Lampe *rot;
	Lampe *gelb;
	Lampe *gruen;
	AmpelState state;

};


#endif // (AMPEL)
