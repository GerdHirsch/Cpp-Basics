/*
 * SharedPointer.h
 *
 *  Created on: 05.07.2013
 *      Author: Gerd
 */

#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_

// für bad_alloc
#include <new>

// Demo für bad_alloc_exception in Memberinitialisierung
class Counter{
public:
	Counter() : counter(1) {
		if(throwBadAlloc())
			throw std::bad_alloc();
	}

	std::size_t operator++(){ return ++counter; }
	std::size_t operator--(){ return --counter; }
	operator std::size_t(){ return counter; }

	static bool& throwBadAlloc(){
		static bool throwException = false;
		return throwException;
	}
private:
	std::size_t counter;
};

template<class T>
class SharedPointer{
public:
	//Initialisierung mit Resource
	SharedPointer(T* pT) // ctor mit try block um initialisierungsliste
	try
	: resource(pT), counter(new Counter)
	{
		std::cout << "SharedPointer(T* pT)" << std::endl;
	}
	catch(std::bad_alloc& e){
		std::cout << "bad_alloc SharedPointer(T* pT)" << std::endl;
		delete resource;
	}

	// Copy -----------------------------------------
	SharedPointer(SharedPointer<T> const& src) noexcept
	: resource(src.resource), counter(src.counter)
	{
		std::cout << "SharedPointer(SharedPointer<T> const& src)" << std::endl;
		if(counter) ++*counter;
	}

	SharedPointer& operator=(SharedPointer<T> const& src) noexcept {

		if(this == &src) return *this;

		Delete();
		resource = src.resource;
		counter = src.counter;
		if(counter) ++*counter;

		return *this;
	}

	/**
	 * Zugriff in SharedPointer<T>
	 * auf private Member in SharedPointer<U>
	 * zulassen.
	 * Für jeden SmartPointer<T> ist jeder andere SmartPointer<Z> friend!
	 * Damit wird SmartPointer<T> friend von SmartPointer<U>
	 * und kann auf die privaten Member  von SmartPointer<U> zugreifen
	 */
	template<class Z>
	friend class SharedPointer<T>;
	/**
	 * konvertierungskonstruktor von Derived nach Base
	 * nur zuweisungskompatible Typen sind möglich
	 * this->resource = rhs.resource
	 * Derived* pD = ...
	 * Base* pB = pD upcast ist implizit möglich
	 */
	template<class U>
	SharedPointer(SharedPointer<U> const& rhs) noexcept
	: resource(rhs.resource),
	  counter(rhs.counter)
	{
		std::cout << "SharedPointer(SharedPointer<U> const& src)" << std::endl;
		++*counter;
	}
	template<class U>
	SharedPointer<T>& operator=(SharedPointer<U> const& rhs){
		std::cout << "SharedPointer<T>& operator=(SharedPointer<U> const& rhs)" << std::endl;

		// selfassignment not possible
		// if(this == &src) return *this;

		// already the same Resource
		if(this->resource == rhs.resource)	return *this;

		Delete();
		resource = rhs.resource;
		counter = rhs.counter;
		++*counter;

		return *this;
	}

	// Move -----------------------------------------------
	//explicit
	SharedPointer(SharedPointer<T> && rhs) :
	resource(rhs.resource), counter(rhs.counter)
	{
		std::cout << "SharedPointer(SharedPointer<T>&& rhs)" << std::endl;
		rhs.counter = nullptr;
		rhs.resource = nullptr;
	}
	SharedPointer& operator=(SharedPointer<T> && rhs){
		std::cout << "SharedPointer& operator=(SharedPointer<T> && src)" << std::endl;

		if(this == &rhs) return *this;

		Delete();
		resource = rhs.resource;
		counter = rhs.counter;
		rhs.resource = nullptr;
		rhs.counter = nullptr;
		return *this;
	}


	template<class U>
	SharedPointer(SharedPointer<U> && rhs) :
	resource(rhs.resource), counter(rhs.counter)
	{
		std::cout << "SharedPointer(SharedPointer<U>&& rhs)" << std::endl;
		rhs.counter = nullptr;
		rhs.resource = nullptr;
	}

	template<class U>
	SharedPointer& operator=(SharedPointer<U> && rhs){
		std::cout << "SharedPointer<T>& operator=(SharedPointer<U> && rhs)" << std::endl;

		// selfassignment not possible
		// if(this == &src) return *this;

		// standard handle the same Resource

		Delete();
		resource = rhs.resource;
		counter = rhs.counter;
		rhs.resource = nullptr;
		rhs.counter = nullptr;
		return *this;
	}

	~SharedPointer(){
		std::cout << "~SharedPointer()" << std::endl;
		Delete();
	}

	// Pointer Interface
	T* operator->() const { return resource; }
	T& operator*(){ return *resource; }
	explicit
	operator bool(){ return resource != nullptr; }

	T* release() {
		T* retVal = resource;
		resource = nullptr;
		Delete();
		counter = nullptr;
		return retVal;
	}
	Counter* getCounter() const {return counter;}
private:
	void Delete(){
		if(!counter) return;

		--*counter;
		if(*counter == 0){
			delete resource;
			delete counter;
			resource = nullptr;
			counter = nullptr;
		}

	}
	T* resource;
	Counter *counter;
};
template<class T, class ...ParamTypes>
auto makeShared(ParamTypes&& ...params) //-> UniquePointer<T> // C++11/ohne C++14
{
	std::cout << "makeShared(ParamTypes&& ...params)" << std::endl;
	// RVO
	return SharedPointer<T>(new T(std::forward<ParamTypes>(params)...) );
}
#endif /* SHAREDPOINTER_H_ */
