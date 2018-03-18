/*
 * Lampe.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef LAMPECAN_H_
#define LAMPECAN_H_
#include "Lampe.h"

#include <string>
#include <iostream>

class LampeCAN : public Lampe {
public:
	LampeCAN(std::string const& name) : Lampe(name){}
	~LampeCAN(){}
	void ein(){
		Lampe::ein();
		std::cout << name << ".ein() CAN" << std::endl; }
	void aus(){
		Lampe::aus();
		std::cout << name << ".aus() CAN" << std::endl; }
};

#endif /* LAMPECAN_H_ */
