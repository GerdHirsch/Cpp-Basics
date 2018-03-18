/*
 * Ring.h
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 */

#ifndef INCLUDE_RING_H_
#define INCLUDE_RING_H_

#include <ostream>

class Ring{
public:
	Ring(unsigned int value):value(value){}

	friend bool operator>=(Ring const& lhs, Ring const& rhs){
		return lhs.value >= rhs.value;
	}
	friend bool operator>(Ring const& lhs, Ring const& rhs){
		return lhs.value > rhs.value;
	}
	friend bool operator==(Ring const& lhs, Ring const& rhs){
		return lhs.value == rhs.value;
	}
	friend Ring operator-(Ring const& lhs, Ring const& rhs){
		return Ring(lhs.value - rhs.value);
	}

	friend std::ostream& operator<<(std::ostream& ostream, Ring rhs){
		ostream << rhs.value;
		return ostream;
	}
	Ring& operator--(){
		--value;
		return *this;
	}
//	inline static Ring null(0); // C++17
//	inline static Ring one(1); // C++17

	unsigned int getValue() const {return value;}
private:
	unsigned int value;
};



#endif /* INCLUDE_RING_H_ */
