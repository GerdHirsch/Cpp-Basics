/*
 * NewHandlerSupport.h
 *
 *  Created on: 25.09.2015
 *      Author: Gerd
 *  Chapter 8 Customizing new and delete
 */

#ifndef NEWHANDLERSUPPORT_H_
#define NEWHANDLERSUPPORT_H_

#include<new>

class NewHandlerHolder{
public:
	NewHandlerHolder(std::new_handler h):handler(h){}
	~NewHandlerHolder(){ std::set_new_handler(handler);}

	//prevent Copying
	NewHandlerHolder(NewHandlerHolder const&) = delete;
	NewHandlerHolder& operator=(NewHandlerHolder const&) = delete;
private:
	std::new_handler handler;
};

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

class OnlyDeleteOperator{
public:
	static void operator delete(void* memory){ ::operator delete(memory);}
protected:
	static void* operator new(size_t);
};

template<class SupportedClass, class NewDeleteOperatorPolicy=OnlyDeleteOperator>
class NewHandlerSupport : public NewDeleteOperatorPolicy{
public:
	using NewDeleteOperatorPolicy::operator new;
	using NewDeleteOperatorPolicy::operator delete;

	static std::new_handler set_new_handler(std::new_handler p) noexcept
	{
		std::new_handler oldHandler = currentHandler;
		currentHandler = p;
		return oldHandler;
	}

	static void* operator new(std::size_t size){
		std::cout << "NewHandlerSupport::operator new(std::size_t)" << std::endl;
		NewHandlerHolder h(std::set_new_handler(currentHandler));
		return ::operator new(size);
	}
	//ohne class spezific delete memory leak!
	static void operator delete(void* p, std::size_t){
		std::cout << "NewHandlerSupport::operator delete(void*, std::size_t)" << std::endl;
		::operator delete(p);
	}
private:
	static std::new_handler currentHandler;
};

template<class SupportedClass, class NewDeleteOperatorPolicy>
std::new_handler NewHandlerSupport<SupportedClass, NewDeleteOperatorPolicy>::currentHandler = nullptr;




#endif /* NEWHANDLERSUPPORT_H_ */
