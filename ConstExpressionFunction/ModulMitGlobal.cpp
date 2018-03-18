/*
 * ModulMitGloabal.cpp
 *
 *  Created on: 07.12.2013
 *      Author: Gerd
 */


constexpr int global{42};
int nonConstGlobal{12};


constexpr int f(){
	return global;
}

