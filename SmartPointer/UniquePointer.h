/*
 * UniquePointer.h
 *
 *  Created on: 04.07.2013
 *      Author: Gerd
 */

#ifndef UNIQUEPOINTER_H_
#define UNIQUEPOINTER_H_

#include <iostream>

template<class T>
class UniquePointer{
public:
	UniquePointer(T* pT):resource(pT){
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;
	}
	~UniquePointer(){
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;
		Delete();
	}
	// Copy illegal
	// copy operations werden nicht generiert wenn
	// move operations vorhanden sind
	// => delete ist überflüssig
//	UniquePointer(UniquePointer<T> const&) = delete;
//	UniquePointer& operator=(UniquePointer<T> const&) = delete;

	// Move
	UniquePointer(UniquePointer<T> && src) : resource(src.release()) {
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;
	}
	UniquePointer& operator=(UniquePointer<T> && src){
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;

		if(this == &src) return *this;

		Delete();
		resource = src.release();
		return *this;
	}

	template<class U>
	explicit
	UniquePointer(UniquePointer<U>&& src) : resource(src.release()) {
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;
	}
	template<class U>
	UniquePointer& operator=(UniquePointer<U> && src){
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;

		Delete();
		resource = src.release();
		return *this;
	}

	// Pointer Interface
	T* operator->(){ return resource; }
	T& operator*(){ return *resource; }
	explicit
	operator bool(){ return resource != nullptr; }

	T* release() {
		T* retVal = resource;
		resource = nullptr;
		return retVal;
	}

private:
	void Delete(){
		// delete nullptr has no effect!
		delete resource;
	}
	T* resource;
};

template<class T, class ...ParamTypes>
auto makeUnique(ParamTypes&& ...params) //-> UniquePointer<T> // C++11/ohne C++14
{
	std::cout <<  __PRETTY_FUNCTION__  << std::endl;
	//RVO
	return UniquePointer<T> (new T(std::forward<ParamTypes>(params)...));
}
#endif /* UNIQUEPOINTER_H_ */
