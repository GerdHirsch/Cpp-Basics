/*
 * main.cpp
 *
 *  Created on: 22.09.2015
 *      Author: Gerd
 */

#include "classes.h"

#include<iostream>
using namespace std;


void standardNew(){
	cout << "== == standard new" << endl;

	cout << "==== Widget* pW = new Widget(\"pW\");" << endl;
	Widget* pW = new Widget("pW");


	cout << "==== delete pW;" << endl;
	delete pW;
}
void customizedPlacementNew(){
	cout << "== == customized placement new" << endl;

	cout << "==== Widget* pLogW1 = new(std::cout) Widget(\"pLogW1\");" << endl;
	Widget* pLogW1 = new(std::cout) Widget("pLogW1");
	Widget* pLogW2 = nullptr;

	try{
		cout << "==== pLogW2 = new(std::cout) Widget(\"pLogW2\", true);" << endl;
		pLogW2 = new(std::cout) Widget("pLogW2", true);
	}catch(std::exception& e)
	{
		cout << "=== catch what:" << e.what() << endl;
	}

	cout << "==== delete pLogW1;" << endl;
	delete pLogW1;
	cout << "==== delete pLogW2;" << endl;
	delete pLogW2;
}
void standardPlacementNew(){
	cout << "== == standard placement new" << endl;

	constexpr int numWidgets = 3;
	void *rawMemory = operator new[](numWidgets * sizeof(Widget));
	Widget *widgetsPlace = static_cast<Widget*>(rawMemory);


	Widget *begin = &widgetsPlace[0];
	Widget *end = &widgetsPlace[numWidgets];
	for(Widget* place = begin; place != end; ++place)
	{
		try{
			cout << "==== new(place) Widget(\"pPlaceW\");" << endl;
			new(place) Widget("pPlaceW", place == begin);
		}catch(exception& e){
			cout << "=== catch() what: " << e.what() << endl;
		}
	}


	//nur die letzten zerstören
	for(Widget* place = end-1; place != begin; --place)
	{
		cout << "==== place->~Widget();" << endl;
		place->~Widget();
	}
	::operator delete[](rawMemory);
}
int main(){
	cout << "CustomizingNew" << boolalpha << endl;
	//standardNew();
	customizedPlacementNew();
	//standardPlacementNew();


}


