/*
 * ResourceHandler.hpp
 *
 *  Created on: Oct 27, 2020
 *      Author: user
 */

#ifndef RESOURCEHANDLER_HPP_
#define RESOURCEHANDLER_HPP_

#include <iostream>

#include "C.h"
class ResourceHandler{
	using Resource = C;
public:
	ResourceHandler(Resource* resource):resource(resource){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~ResourceHandler(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		delete resource;
	}
	// no copy operations
	ResourceHandler(ResourceHandler const&) = delete;
	ResourceHandler& operator=(ResourceHandler const&) = delete;
	//move
	ResourceHandler(ResourceHandler&& rhs):resource(rhs.resource){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		rhs.resource = nullptr; // take over ownership
	}
	ResourceHandler& operator=(ResourceHandler&& rhs){
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		if(this == &rhs) return; // selfassignment guard

		delete this->resource;
		this->resource = rhs.resource;
		rhs.resource = nullptr;
		return *this;
	}
	explicit operator bool()const noexcept {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return resource != nullptr;}
	Resource* operator->()const noexcept {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return resource; }
	Resource& operator*()const{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *resource; }

private:
	Resource *resource=nullptr;
};



#endif /* RESOURCEHANDLER_HPP_ */
