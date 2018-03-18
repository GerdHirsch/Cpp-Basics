/*
 * main.cpp
 *
 *  Created on: 05.02.2016
 *      Author: Gerd
 */

#include "DemoCtorInitializerList.h"

#include<iostream>
#include <iterator>
#include <vector>
#include <memory>

using namespace std;



void demoMakeUnique();
void demoInitList();

int main(){
	cout << "InitialisierungsListe" << endl;
	demoMakeUnique();
//	demoInitList();
}

void demoMakeUnique(){
	cout << "demoMakeUnique" << endl;
//	auto initListArgs{1, 2, 3, 4, 5};
	std::initializer_list<int> initListArgs{1, 2, 3, 4, 5};

//	error: assignment of read-only reference 'val'
//	for(auto &val : initListArgs){
//		val += 1;
//	}

	auto demoV0 = std::make_unique<std::vector<int>>(5, 2);

	for(auto i : *demoV0)
		cout << " demoV0::i: "<< i;
	cout << endl;

	demoV0 = std::make_unique<std::vector<int>>(initListArgs);
	for(auto i : *demoV0)
		cout << " demoV0::i: "<< i;
	cout << endl;

//	error: no matching function for call to 'make_unique(<brace-enclosed initializer list>)'
//	demoV0 = std::make_unique<std::vector<int>>({1, 2, 3});
	demoV0 = std::make_unique<std::vector<int>>(std::initializer_list<int>{1, 2, 3});
	for(auto i : *demoV0)
		cout << " demoV0::i: "<< i;
	cout << endl;

	auto demo0 = std::make_shared<DemoCtor>();
	auto demo2 = std::make_shared<DemoCtor>(1, 2);
	auto demo4 = std::make_unique<DemoCtor>(initListArgs);

	DemoCtor demo1{1, 2, 3, 4};
	DemoCtor demo5(initListArgs);

	cout << *demo0 << endl;
	cout << demo1 << endl;
	cout << *demo2 << endl;
	cout << *demo4 << endl;
	cout << demo5 << endl;

}

/**
 * Anforderung an Iterable:
 * begin(it) und end(it)
 * liefern entsprechende Iteratoren
 */
template<class Iterable>
void print(std::string const& message, Iterable& it){
//	cout << __PRETTY_FUNCTION__ << endl;

	std::cout << message;
	std::cout << '{';
	for(auto element : it)
		std::cout << element << " ";
	std::cout << '}' << std::endl;
}

void demoInitList(){
	int ai[]{1, 2, 3};
	print("ai: ", ai);

	vector<string> cities{"Berlin", "Washington"};

	vector<int> vi{1, 2, 3, 4};
	print("vi{1, 2, 3, 4}: ", vi);

	vector<int> v2(2, 3);
	print("v2(2, 3): ", v2);

//	auto initList{1}; // wird als int deduced, nicht mehr als initializer_list<int>
	std::initializer_list<int> initList{1};
	print("initList{1}: ", initList);

}
