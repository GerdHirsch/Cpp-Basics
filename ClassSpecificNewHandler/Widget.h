/*
 * Widget.h
 *
 *  Created on: 25.09.2015
 *      Author: Gerd
 */

#ifndef WIDGET_H_
#define WIDGET_H_

#include "NewHandlerSupport.h"

#include <iostream>
#include <stdexcept>
#include <limits>

class Widget : public NewHandlerSupport<Widget, StandardNewDeleteForms>{
//class Widget : public NewHandlerSupport<Widget>{
	// class uses own NewHandler
	typedef NewHandlerSupport<Widget> base_class;
public:
	Widget(bool throwException=false) :
		//bigDataPointer(new char[std::numeric_limits<int>::max()])
		bigDataPointer(nullptr)
	{
		std::cout << boolalpha;
		std::cout << "Widget::Widget() throwException: " << throwException << std::endl;
		if(throwException) throw std::logic_error("Exception in Ctor");
	}
	~Widget(){
		std::cout << "Widget::~Widget()" << std::endl;
	}
//	static void* operator new(std::size_t size)
//	{
//		return base_class::operator new(size);
//	}
//	static void operator delete(void* p, std::size_t size){
//		base_class::operator delete(p, size);
//	}
private:
	//char bigDate[std::numeric_limits<int>::max()];
	char* bigDataPointer;
};



#endif /* WIDGET_H_ */
