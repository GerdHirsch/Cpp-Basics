/*
 * HanoiTurm.h
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 */

#ifndef INCLUDE_HANOITURM_H_
#define INCLUDE_HANOITURM_H_
#include <iostream>
#include <deque>

template<class Ring>
class HanoiTurm{
	std::deque<Ring> turm;
	std::string name;
private:
	void checkInvariant(Ring push){
		if(!turm.empty() && push >= turm.back())
			throw std::logic_error("Invariant violation: ring bigger than top()");
	}
public:
	HanoiTurm(std::string name):name(name){}
	HanoiTurm(Ring biggest, std::string name) : name(name) {
		Ring null(0);
		for(Ring ring = biggest; ring > null; --ring)
			turm.push_back(ring);
	}
	HanoiTurm(std::initializer_list<int> list):turm(list){}

	void push(Ring ring){
		checkInvariant(ring);
		turm.push_back(ring);
	}
	void pop(){ turm.pop_back(); }
	Ring top() const { return turm.back(); }

	bool empty() const { return turm.empty(); }
	std::size_t size() const { return turm.size(); }

	template<class Stream>
	void print(Stream const& stream) const {
		std::cout << name << ": ";
		for(auto ring : turm){
			std::cout << ring << " ";
		}
		std::cout << std::endl;
	}
};



#endif /* INCLUDE_HANOITURM_H_ */
