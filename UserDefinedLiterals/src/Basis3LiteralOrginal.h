/*
 * Basis3Literal.h
 *
 *  Created on: 23.02.2016
 *      Author: Gerd
 *      Das Orginal funktioniert nicht
 *      From
 *      The C++ Programming Language Fourth Edition Bjarne Stroustrup
 *      S. 560
 */

#ifndef BASIS3LITERAL_H_
#define BASIS3LITERAL_H_
#include <iostream>

void demoB3();
//------------------------------------------------------------------------
// Berechnet den Wert einer Stelle: Basis hoch Ziffer
constexpr int ipow(int base, int exponent){
	return (exponent>0) ? base * ipow(base, exponent-1) : 1;
}
//------------------------------------------------------------------------
template<char c>
constexpr int b3_helper()
{
	static_assert(c < '3', "not a ternary digit");
	return c;
}
//------------------------------------------------------------------------
template<char c, char... tail>
constexpr int b3_helper()
{
	static_assert(c < '3', "not a ternary digit");
	return ( ipow(3, sizeof...(tail)) * (c - '0') );// + b3_helper<tail...>() );
}
//------------------------------------------------------------------------
template<char...chars>
constexpr
int operator""_b3(){
	return b3_helper<chars...>();
}
//------------------------------------------------------------------------

void demoB3(){
	std::cout << "demoB3()" << std::endl;
	std::cout << "201_b3: " << 201_b3 << std::endl;
//	std::cout << "410_b3: " << 401_b3 << std::endl;
}

#endif /* BASIS3LITERAL_H_ */
