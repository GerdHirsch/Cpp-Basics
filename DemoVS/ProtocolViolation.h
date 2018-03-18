/*
 * ProtocolViolation.h
 *
 *  Created on: 14.10.2015
 *      Author: Gerd
 */

#ifndef PROTOCOLVIOLATION_H_
#define PROTOCOLVIOLATION_H_

#include <stdexcept>

class ProtocolViolation : public std::logic_error{
public:
	ProtocolViolation(char const* message) : std::logic_error(message){}
};



#endif /* PROTOCOLVIOLATION_H_ */
