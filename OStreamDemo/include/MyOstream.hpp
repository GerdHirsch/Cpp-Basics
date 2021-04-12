/*
 * MyOstream.hpp
 *
 *  Created on: 31.03.2021
 *      Author: Gerd
 */

#ifndef INCLUDE_MYOSTREAM_HPP_
#define INCLUDE_MYOSTREAM_HPP_

#include <ostream>

template<
	class CharT,
	class Traits = std::char_traits<CharT>
>
class MyOstream : public std::basic_ostream<CharT, Traits>{
	using base_type = std::basic_ostream<CharT, Traits>;
	base_type *ostream;

public:
	MyOstream( base_type& ostream) : ostream(&ostream)
	{}

	// doesn´t work because the original functions don´t delegate
	//	using base_type::operator<<;

	// delegates almost everything to *ostream member
	template<class T>
	MyOstream& operator<<(T const &value){
		*ostream << value;
		return *this;
	}
	// needed overloads
	MyOstream& operator<<(base_type& (*func)(base_type&) ){ // for endl
		func(*ostream);
		return *this;
	}
	MyOstream& operator<<(std::ios_base& (*func)(std::ios_base&) ){ // for hex, ...
		func(*ostream);
		return *this;
	}

};



#endif /* INCLUDE_MYOSTREAM_HPP_ */
