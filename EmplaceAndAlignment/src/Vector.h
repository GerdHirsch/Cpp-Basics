/*
 *
 *
 *  Created on: 30.03.2016
 *      Author: Gerd
 *  Demo emplace construction
 *  in new aquired memory
 *
 *  http://stackoverflow.com/questions/506518/is-there-any-guarantee-of-alignment-of-address-return-by-cs-new-operation
 *  http://en.cppreference.com/w/c/memory/aligned_alloc
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h> // alligned_alloc
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstddef>

template<class T>
class Vector{

public:
	using iterator = T*;
	Vector(std::size_t firstCapacity = 10)
	:
	capacity(firstCapacity),
	sizeInBytes(sizeof(T) * firstCapacity),
	data(nullptr),
	first(nullptr),
	nextIdx(0)
	{
		sizeInBytes += sizeInBytes % alignof(T); // muss ganzzahliges vielfaches sein
		data = aligned_alloc(alignof(T), sizeInBytes);
		first = reinterpret_cast<T*>(data);

		std::cout << "sizeInBytes: " << sizeInBytes << std::endl;
		std::cout << "alignof(T): " << alignof(T) << std::endl;
		std::cout << "sizeof(T): " << sizeof(T) << std::endl;

	}

	template<class ...Params>
	iterator emplace(Params...params){

		if(size() >= capacity){
			resize();
		}
		T* location = &first[nextIdx++];
		return new(location) T(std::forward<Params>(params)...);
	}
	~Vector(){
		for(T* last = &first[nextIdx]; first < last; ++first)
			first->~T();
		free(data);
	}
	std::size_t size(){
		return nextIdx;
	}
private:
	void resize(){
		// Übung: hier die vergrößerung implementieren
		throw std::out_of_range("resize not implemented yet");
	}
	std::size_t capacity;
	std::size_t sizeInBytes;
	void* data;
	T* first;
	int nextIdx = 0;
};

#endif /* VECTOR_H_ */
