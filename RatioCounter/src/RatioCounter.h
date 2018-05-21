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
 * Precision: e.g. 100% 1.000, 10.000
 * the more values are considered, the less meaning have local extrema
 * e.g. if you consider only 10 values, after 10 skips you have 100%
 * it´s also a kind of sensitivity: the lower Precision is, the
 * more reaktiv is the measurement
 */
template<size_t Precision>
class RatioCounter{
	std::size_t value{0};

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
//	void transferOneTo(RatioCounter<Precision>& counter){
//		if(value > 0){
//			--value;
//			++counter.value;
//		}
//	}
	template<std::size_t P>
	friend std::ostream& operator<<(std::ostream& out, RatioCounter<P> const& counter);
};
template<std::size_t Precision>
std::ostream & operator<<(std::ostream& out, RatioCounter<Precision>  const& counter){
	out << counter.getValue();
	return out;
}


#endif /* RATIOCOUNTER_H_ */
