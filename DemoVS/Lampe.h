/*
 * Lampe.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef LAMPE_H_
#define LAMPE_H_

#include <string>
#include <iostream>

class Lampe {
public:
	Lampe(std::string const& name)
	: name(name), on(false){}
	virtual ~Lampe() = 0;
	virtual void ein() { on = true; }
	virtual void aus() = 0;
	bool isOn(){ return on;}
protected:
	std::string name;
private:
	bool on;

};
inline
Lampe::~Lampe(){} // Definition zur Verfügung stellen, sonst Linker Error
inline
void Lampe::aus(){ on = false; }

#endif /* LAMPE_H_ */
