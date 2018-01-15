/*
 * Base3Struct.h
 *
 *  Created on: 23.02.2016
 *      Author: Gerd
 */

#ifndef BASE3STRUCT_H_
#define BASE3STRUCT_H_


constexpr
int ipow(int x, char n)		// x to the power of n
{
	return n > 0 ? x * ipow(x, n-1) : 1;
}

template<char...> struct helper;		// primary template declaration;

template<char c>
struct helper<c> {						// handle one digit
	static_assert('0' <= c && c < '3', "not a ternary digit");

	static constexpr int value() { return c-'0'; }
};

template<char c, char... tail>
struct helper<c, tail...> {				// handle several digits
	static_assert('0' <= c && c < '3', "not a ternary digit");

	static constexpr int value() {
		return (c - '0') * ipow(3, sizeof...(tail))
				+ helper<tail...>::value();
	}
};

template<char... chars>
constexpr int operator"" _b3()
{
	return helper<chars...>::value();
}
//------------------------------------------------------------------------



#endif /* BASE3STRUCT_H_ */
