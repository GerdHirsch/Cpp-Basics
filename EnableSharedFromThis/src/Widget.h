/*
 * Widget.h
 *
 *  Created on: 03.03.2016
 *      Author: Gerd
 *      demo der anwendung der base class
 *      std::enable_shared_from_this<..>
 */

#ifndef WIDGET_H_
#define WIDGET_H_
#include <memory>
#include <iostream>

class Widget : public std::enable_shared_from_this<Widget>
{
public:
	using SharedThis =   std::shared_ptr<Widget>;

	Widget(){
		std::cout << "Widget()" << std::endl;
//		SharedThis p(shared_from_this()); // kann nicht im Ctor verwendet werden
		// Exception what():  bad_weak_ptr
	}
	~Widget(){
		std::cout << "~Widget()" << std::endl;
	}
	// darf nur auf Objekte die auf dem Heap erzeugt wurden
	// angewendet werden
	SharedThis getShared(){
		return shared_from_this();
	}
	SharedThis getFirst(){
		SharedThis temp(this);
		return shared_from_this();
	}
	SharedThis getWorse(){
		return SharedThis(this);
	}
};



#endif /* WIDGET_H_ */
