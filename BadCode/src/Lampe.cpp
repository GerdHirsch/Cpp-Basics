///////////////////////////////////////////////////////////
//  Lampe.cpp
//  Implementation of the Class IPLampe
//  Created on:      18-Okt-2008 23:29:23
//  Original author: Gerd
///////////////////////////////////////////////////////////
#include "Lampe.h"

#include <string>
#include <iostream>
using namespace std;

Lampe::Lampe(const std::string&  ipAddresse):ipAddresse(ipAddresse)
{}

void Lampe::aus(){
	an = false;
	cout << ipAddresse <<".aus()\tLampe" << endl;
	//hier die IP Kommunikation etablieren
}

void Lampe::ein(){
	an = true;
	cout << ipAddresse <<".ein()\tLampe" << endl;
	//hier die IP Kommunikation etagblieren
}