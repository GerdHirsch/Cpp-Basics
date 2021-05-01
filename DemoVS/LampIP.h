/*
 * Lampe.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef LAMPEIP_H_
#define LAMPEIP_H_
#include "Lampe.h"

#include <string>
#include <iostream>

class LampeIP : public Lampe {
public:
	LampeIP(std::string const& name) : Lampe(name){}
	~LampeIP(){}
	void ein(){
		Lampe::ein();
		std::cout << name << ".ein() IP" << std::endl; }
	void aus(){
		Lampe::aus();
		std::cout << name << ".aus() IP" << std::endl; }
};

#endif /* LAMPEIP_H_ */
