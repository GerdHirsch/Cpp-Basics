///////////////////////////////////////////////////////////
//  Lampe.cpp
//  Implementation of the Class IPLampe
//  Created on:      18-Okt-2008 23:29:23
//  Original author: Gerd
///////////////////////////////////////////////////////////
#include <string>
#include <iostream>

#include "DemoSocket.h"
using namespace std;

DemoSocket::DemoSocket(const std::string&  ipAddresse):ipAddresse(ipAddresse)
{}


void DemoSocket::send(unsigned int message){
	an = message;
	cout << ipAddresse <<".send(" << message << ")\tSocket" << endl;
	//hier die IP Kommunikation etablieren
}
