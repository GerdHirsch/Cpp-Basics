/*
 * main.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Gerd
 */

#include<iostream>
using namespace std;

class Widget {
public:
	explicit Widget(int i):i(i) {}

	Widget() = default;
	Widget(Widget const&) = default;

	//assignment only for l-values
	Widget& operator=(Widget const&) & = default;
	Widget& operator=(Widget &&) & = default;


	Widget& operator++() { // ++Präfix
		++i;
		return *this;
	}

	Widget operator++(int) { // Postfix++
		Widget temp(*this);
		++i;
		return temp;
	}

//	Widget& operator--() { /*dto.*/ } // Präfix
//
//	Widget operator--(int){ /*dto.*/ } // Postfix
private:
	int i;
};

void f(Widget&& rW){
	cout << "void f(Widget&& rW)" << endl;
}
void f(Widget & w){
	cout << "void f(Widget & w)" << endl;
}

int main(){
	cout << "IncrementDecrementOperatoren" << endl;

	Widget w, w2;
	f(w);
	f(++w);
	f(w++);
	++w = w2;
//	w++ = w2; // no assignment to temporaries possible with L-Value qualified operator=()&
}


