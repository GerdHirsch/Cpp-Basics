/*
 * classes.h
 *
 *  Created on: 22.09.2015
 *  From Effective C++ 55 Ways Chapter 8
 */

#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>
#include <stdexcept>

class StandardNewDeleteForms{
public:
	//normal new/delete
	static void* operator new(std::size_t size){
		void *pRetVal = ::operator new(size);
		std::cout << "void* operator new(std::size_t: " << size << ") this: " << pRetVal << std::endl;
		return pRetVal;
	}
	static void operator delete(void *pMemory) noexcept {
		std::cout << "void operator delete(void*: " << pMemory<< ")" << std::endl;
		::operator delete(pMemory);
	}
	//placement new/delete
	static void* operator new(std::size_t size, void *location) noexcept
	{
		void *pRetVal = ::operator new(size, location);
		std::cout << "void* operator new(std::size_t: " << size << " location: " << location << ") this: " << pRetVal << std::endl;
		return pRetVal;
	}
	static void operator delete(void *pMemory, void* location) noexcept {
		std::cout << "void operator delete(void*: " << pMemory << " location: " << location << ")" << std::endl;
		::operator delete(pMemory, location);
	}
	//nothrow new/delete
	static void* operator new(std::size_t size, std::nothrow_t const& nt)
		{ return ::operator new(size, nt);}
	static void operator delete(void *pMemory, std::nothrow_t const& nt)
		{ ::operator delete(pMemory, nt);}
};

class Widget  : public StandardNewDeleteForms
{
public:
	using StandardNewDeleteForms::operator new;
	using StandardNewDeleteForms::operator delete;

	static void* operator new(std::size_t size, std::ostream& logStream)
	{
		void* pRetVal = ::operator new(size);
		logStream << "Widget::operator new(size: " << size << ", logStream) this:" << pRetVal << std::endl;
		return pRetVal;
	}
	static void operator delete(void* pMemory, std::ostream& logStream)
	{
		logStream << "Widget::operator delete( " << pMemory << " logStream)" << std::endl;
		::operator delete(pMemory);
	}
	Widget(std::string const& name, bool demoThrow=false):name(name){
		std::cout << "Widget::Widget(" << name << ", throw: " << demoThrow << ") this: " << this << std::endl;
		if(demoThrow)
			throw std::logic_error("demoThrow in Ctor");
	}
	~Widget(){
		std::cout << "Widget::~Widget(): " << name << " this: " << this << std::endl;
	}
private:
	std::string name;
};

Widget* begin(Widget*& p){
	return p;
}
Widget* end(Widget*& p){
	return p;
}

#endif /* CLASSES_H_ */
