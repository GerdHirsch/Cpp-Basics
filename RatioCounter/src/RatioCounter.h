/*
 * RatioCounter.h
 *
 *  Created on: 20.05.2018
 *      Author: Gerd
 */

#include <cstddef>
#include <iostream>

#ifndef RATIOCOUNTER_H_
#define RATIOCOUNTER_H_


/**
 * e.g.
 * push to pop
 * skipped to pushed
 * empty to pop ratio
 *
 * an object of this class ensures that
 * value is in the range between 0 and Precision
 * if you choose the value 100 as precision
 * getValue() delivers percentage
 *
 * Precision: e.g. 100% 1.000, 10.000
 * the more values are considered, the less meaning have local extrema
 * e.g. if you consider only 10 values, after 10 skips you have 100%
 * it´s also a kind of sensitivity: the lower Precision is, the
 * more reaktiv is the measurement
 */

//template<size_t Precision>
class RatioCounter{
	std::size_t value{0};
	static constexpr size_t Precision{64};
	struct Bits{
		unsigned char bits[Precision/8];
	};
	unsigned long long bits{0};
	unsigned long long mask{1};
	unsigned long long MAX{0x8000000000000000};
public:
	RatioCounter(std::size_t startValue=Precision): value(startValue){}

	std::size_t getValue() const { return value; }
	RatioCounter& operator++(){
		if(value < Precision){
			++value;
		}
		return *this;
	}
	RatioCounter& operator--(){
		if(value > 0){
			--value;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, RatioCounter const& counter);
};
std::ostream & operator<<(std::ostream& out, RatioCounter  const& counter){
	out << counter.getValue();
	return out;
}


#endif /* RATIOCOUNTER_H_ */
