///////////////////////////////////////////////////////////
//  Lampe.cpp
//  Implementation of the Class IPLampe
//  Created on:      18-Okt-2008 23:29:23
//  Original author: Gerd
///////////////////////////////////////////////////////////
#include <string>
#include <iostream>

#include "IPLightBulb.h"
using namespace std;

IPLightBulb::IPLightBulb(const std::string&  ipAddress):ipAddress(ipAddress)
{}

void IPLightBulb::off(){
	an = false;
	cout << ipAddress <<".off()\tIPLightBulb" << endl;
	//hier die IP Kommunikation etablieren
}

void IPLightBulb::on(){
	an = true;
	cout << ipAddress <<".on()\tIPLightBulb" << endl;
	//hier die IP Kommunikation etagblieren
}
