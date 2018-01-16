/*
 * main.cpp
 *
 *  Created on: 30.03.2016
 *      Author: Gerd
 */


#include "Vector.h"
#include "A4BaseBC.h"
#include "Array.h"

#include<iostream>
#include<memory>

using namespace std;

void demoAlignment();
void demoVector();
void demoArray();

int main(){
	cout << "EmplaceAndAlignment" << endl;
//	demoAlignment();
	demoVector();
//	demoArray();
}
void demoArray(){
	cout << "demoArray" << endl;

//	A a1[]{A(41), A(44)};


	cout << "Array<A> aA;" << endl;
	Array<A, 3> aA;
	(*aA.emplace()).opConst();
	(*aA.emplace(43)).operation();

	cout << "aA.size(): " << aA.size() << endl;

	// throws out_of_range
//	(*vA.emplace(44)).operation();

//	cout << "Vector<Byte3> aA;" << endl;
//	Vector<Byte3> vB3;
//	cout << "vB3.size(): " << vB3.size() << endl;
}

struct ToAlignType{
	float val;
};

struct
//alignas(8)
alignas(ToAlignType)
Byte3{
	char c1;
	char data[2];
};
void demoAlignment(){
	cout << "demoAlignment" << endl;

	cout << "alignof(A): " << alignof(A) << " sizeof(A): " << sizeof(A) << endl;
	cout << "alignof(Byte3): " << alignof(Byte3) << " sizeof(Byte3): " << sizeof(Byte3) << endl;

	constexpr std::size_t ALIGN{2};// Experimente mit 4, 8, 16, ... 2er potenzen
	constexpr std::size_t SIZE{6};

	char buffer[2 * SIZE + ALIGN - 1];
	std::size_t space = sizeof(buffer);// 15

	void* p = &buffer[0];
	void* result = nullptr;


	 //void* align( std::size_t alignment, std::size_t size, void*& ptr, std::size_t& space );
	cout
			<< " ALIGN: " << ALIGN
			<< " SIZE: " << SIZE
			<< endl << "p:" << p
			<< " space: " << space
			<< endl;

	cout 	<< "p:" << p
			<< " % " << ALIGN << " = "
			<< reinterpret_cast<unsigned int>( p )% ALIGN
			<< endl;
	cout << endl;

	char* p1 = nullptr;

	for(size_t i{0}; i < sizeof(buffer); ++i){
		p = p1 = &buffer[i];
		space = sizeof(buffer) - i;
		cout	<< "p1: " << p
				<< " space: " << space
				<< endl;
		result = std::align(ALIGN,
					SIZE,
					p,
					space);

		cout	<< "p = :\t" << p
				<< " p - p1: " << reinterpret_cast<char*>(p) - p1
				<< " space: " << space
				<< " SIZE: " << SIZE
				<< " ALIGN: " << ALIGN
				<< endl << "result:\t" << result
				<< endl;
	}
}
void demoVector(){
	cout << "demoVector" << endl;
//	A a1[]{A(41), A(44)};
	cout << "Vector<A> aA(2);" << endl;
	Vector<A> vA(2);
	(*vA.emplace()).opConst();
	(*vA.emplace(43)).operation();

//	 throws out_of_range
//	(*vA.emplace(44)).operation();

	cout << "Vector<Byte3> aA;" << endl;
	Vector<Byte3> vB3;


	cout << "vB3.size(): " << vB3.size() << endl;
}
