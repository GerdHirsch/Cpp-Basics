/*
 * DemoAutoPtr.h
 *
 *  Created on: 15.11.2015
 *      Author: Gerd
 */

#ifndef DEMOAUTOPTR_H_
#define DEMOAUTOPTR_H_
#include <iostream>
/**
 * demo der probleme mit C++03 und davor und
 * einem non const copy ctor AutoPtr(AutoPtr& rhs)
 * der das rhs verändert
 *
 * zeigt das zusammenspiel von AutoPtr und AutoPtrRef
 * um einen std::auto_ptr aus einer funktion zurückgeben
 * zu können, was mit einem copy ctor der eine non-const
 * Referenz erwartet nicht geht
 *
 * Die innere Klasse AutoPtrRef muss private sein,
 * damit sie nicht außerhalb von AutoPtr explizit
 * genutzt werden kann, (siehe demoExplizitAutoPtrRef)
 * der Member AutoPtr& p kann daher public sein
 * die deklaration friend AutoPtr wird damit überflüssig
 */
class AutoPtr{
//public:
	class AutoPtrRef{
	public:
		AutoPtrRef(AutoPtr& p):p(p){
			std::cout << "AutoPtrRef(AutoPtr& p) p.name: " << p.name << std::endl;
		}
		AutoPtrRef(AutoPtrRef const& rhs):p(rhs.p){
			std::cout << "AutoPtrRef(AutoPtrRef const& rhs) rhs.p.name: " << rhs.p.name << std::endl;
		}
		~AutoPtrRef(){
			std::cout << "~AutoPtrRef() p.name: " << p.name << std::endl;
		}
//		friend class AutoPtr;
//	private:
		AutoPtr& p;
	};
public:
	operator AutoPtrRef(){
		std::cout << "AutoPtr::operator AutoPtrRef() name: " << name << std::endl;
		return AutoPtrRef(*this);
	}
	AutoPtr(AutoPtrRef rhs):name(rhs.p.name){
		std::cout << "AutoPtr(AutoPtrRef r) " << name << std::endl;
		removeOwnership(rhs.p);
	}

	AutoPtr(AutoPtr& rhs):name(rhs.name){
		std::cout << "AutoPtr(AutoPtr& rhs) " << name << std::endl;
		removeOwnership(rhs);
	}
	AutoPtr(std::string name):name(name){
		this->name += " Owner";
		std::cout << "AutoPtr(std::string " << this->name <<")" << std::endl;
	}
	~AutoPtr(){
		std::cout << "~AutoPtr() name: " << this->name << std::endl;
		name = "Dangling Pointer";
	}
	std::string const& getName()const{ return name; }
private:
	void removeOwnership(AutoPtr& rhs){
		std::size_t length = rhs.name.length();
		length -= 6;
		rhs.name.resize(length);
	}

	std::string name;
};


#endif /* DEMOAUTOPTR_H_ */
