/*
 * Ampel.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef AMPEL_H_
#define AMPEL_H_

#include "Lampe.h"

#include <memory>

class Ampel {
public:
	typedef std::auto_ptr<Lampe> Lampe_ptr;
	Ampel(Lampe_ptr rot, Lampe_ptr gelb, Lampe_ptr gruen);
	~Ampel();
	void blinke();
	void umschalten();
	void aus();
private:
	struct AmpelState{
		enum  State{ AUS, ROT, GELB, ROTGELB, GRUEN, BLINKEND};
	};
	AmpelState::State state;
	Lampe_ptr rot, gelb, gruen;

	void lampenAusschalten();
	void blinken(); // wird vom BlinkenTimer gerufen
};

#endif /* AMPEL_H_ */
