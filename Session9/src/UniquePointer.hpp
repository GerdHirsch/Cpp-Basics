/*
 * ResourceHandler.hpp
 *
 *  Created on: Oct 27, 2020
 *      Author: user
 */

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

#include <iostream>

template<class Resource>
class UniquePointer{
public:
	// default constructor creates invalid UniquePointer
	UniquePointer() = default;
	UniquePointer(Resource* resource = nullptr):resource(resource){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~UniquePointer(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		Delete();
	}
	// no copy operations just for documentation
	// will not be synthesized because of the rules
	UniquePointer(UniquePointer const&) = delete;
	UniquePointer& operator=(UniquePointer const&) = delete;
	//move Operations
	UniquePointer(UniquePointer&& rhs)
	: resource(rhs.resource){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		rhs.resource = nullptr; // take over ownership
	}
	UniquePointer& operator=(UniquePointer&& rhs){
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		if (this == &rhs) return *this; // selfassignment guard

		Delete();
		this->resource = rhs.resource;
		rhs.resource = nullptr;
		return *this;
	}
	// conversion Operations
	template<class OtherType>
	explicit
	UniquePointer(UniquePointer<OtherType>&& src)
	: resource(src.release()) {
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;
	}
	template<class OtherType>
	UniquePointer& operator=(UniquePointer<OtherType> && src){
		std::cout <<  __PRETTY_FUNCTION__  << std::endl;

		Delete();
		resource = src.release();
		return *this;
	}
	// releases the responsibility for the resource
	Resource* release() {
		Resource* retVal = resource;
		resource = nullptr;
		return retVal;
	}

	// Pointer Interface
	Resource* operator->()const noexcept {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return resource; }
	Resource& operator*()const{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *resource; }
	explicit operator bool()const noexcept {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return resource != nullptr;}
private:
	// deletes the resource
	void Delete(){
		// delete nullptr has no effect
		delete resource;
	}
	Resource *resource = nullptr;
};



#endif /* UNIQUEPOINTER_HPP_ */
