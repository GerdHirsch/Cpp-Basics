/*
 * Common.h
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 */

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <iostream>

template<class Ring, class Turm>
inline
void print(Ring number, Turm& target, Turm& source, Turm& t){
	std::cout << "move( number: "
		<< number << ") " << std::endl;

	std::cout << "tgt: ";
	target.print(std::cout);
	std::cout << "src: ";
	source.print(std::cout);
	std::cout << "tmp: ";
	t.print(std::cout);

	std::cout << std::endl;
}

#endif /* INCLUDE_COMMON_H_ */
