/*
 * T.hpp
 *
 *  Created on: Nov 30, 2020
 *      Author: user
 */

#ifndef T_HPP_
#define T_HPP_

template<class Type>
class T{
public:
	T(); 		// default constructor
	~T(); 		// destructor
	T(T const &); // copy constructor
	T& operator=(T const &); // copy assignment
	T(T&&); 	// move constructor
	T& operator=(T&&); // move assignment

	template<class OtherType>
	T(T<OtherType> const &);// copy conversion Constructor
	template<class OtherType>
	T& operator=(T<OtherType> const &);// copy conversion assignment

	template<class OtherType>
	T(T<OtherType> &&);// move conversion Constructor
	template<class OtherType>
	T& operator=(T<OtherType> &&);// move conversion assignment
};



#endif /* T_HPP_ */
