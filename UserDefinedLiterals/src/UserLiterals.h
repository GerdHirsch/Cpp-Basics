/*
 * UserLiterals.h
 *
 *  Created on: 22.02.2016
 *      Author: Gerd
 */

#ifndef USERLITERALS_H_
#define USERLITERALS_H_

#include <cstdlib>
#include <iostream>
#include <string>

/**
 * Script Example
 */
class Distance{
	constexpr static char const*  units[] = { "km", "m", "cm"};
public:

	enum class Unit : std::size_t { km, m, cm };
	constexpr Distance(long double d, Unit u):d(d), unit(u){}

	constexpr char const* getUnit() const
	{
//		return units[0];
//		std::size_t idx = static_cast<std::size_t>(unit);
		return Distance::units[static_cast<std::size_t>(unit)];
	}

	friend
	std::ostream& operator<<(std::ostream& out, Distance const& distance){
		out << distance.d << " " << distance.getUnit();
		return out;
	}
private:
	long double d;
	Unit unit;
};
constexpr char const*  Distance::units[];// = { "km", "m", "cm"};

constexpr Distance operator""_Km(long double d){
	return Distance(d, Distance::Unit::km);
}
Distance operator""_cm(char const* dc){
	using Unit = Distance::Unit;
	std::cout << "operator\"\"_cm(char const* dc): " << dc << std::endl;
	return Distance(std::atof(dc), Unit::cm);
}
// Script Example ende
/**
 * Experimente
 */
class MyInt{
public:
	int i;
	constexpr MyInt(int i):i(i){}
	friend
	std::ostream& operator<<(std::ostream& out, MyInt const& myInt){
		out << myInt.i;
		return out;
	}
};
MyInt operator""_i(char const* ic){
	return MyInt(std::atoi(ic));
}


class MyComplex{
	long double real;
	long double imag;
public:
	MyComplex(long double real, long double imag):real(real), imag(imag){}
	friend
	std::ostream& operator<<(std::ostream& out, MyComplex c){
		out << c.real << "+" << c.imag <<"i";
		return out;
	}
	friend MyComplex operator+(long double r, MyComplex c){
		return MyComplex(r + c.real, c.imag);
	}
};

MyComplex operator""_i(long double imag){
	return MyComplex(0, imag);
}

#endif /* USERLITERALS_H_ */
