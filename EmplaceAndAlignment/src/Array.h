/*
 * Array.h
 *
 *  Created on: 31.03.2016
 *      Author: Gerd
 */

#ifndef ARRAY_H_
#define ARRAY_H_

template<class T, std::size_t MAXELEMENTS>
class Array{
	typename std::aligned_storage<sizeof(T), alignof(T)>::type data[MAXELEMENTS];
	using iterator = T*;
public:
	Array()
	:
	nextPos(reinterpret_cast<T*>(data))
	{
		std::cout << "Array() MAXELEMENTS: " << MAXELEMENTS << std::endl;
		std::cout << "data: " << data << " nextPos: " << nextPos << std::endl;
		std::cout << "sizeof(T): " << sizeof(T) << std::endl;
		std::cout << "sizeof(data): " << sizeof(data) << std::endl;
	}
	template<class ...Params>
	iterator emplace(Params...params){

		if(static_cast<std::size_t>(nextPos - reinterpret_cast<T*>(data)) >= MAXELEMENTS)
			throw std::out_of_range("Array full");

		return new(nextPos++) T(std::forward<Params>(params)...);
	}
	~Array(){
		for(--nextPos; nextPos >= reinterpret_cast<T*>(data); --nextPos)
			nextPos->~T();
	}
	std::size_t size(){
		return nextPos - reinterpret_cast<T*>(data);
	}
private:
	T* nextPos;
};

#endif /* ARRAY_H_ */
