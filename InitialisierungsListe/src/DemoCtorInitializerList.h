/*
 * DemoCtorInitializerList.h
 *
 *  Created on: 16.02.2016
 *      Author: Gerd
 */

#ifndef DEMOCTORINITIALIZERLIST_H_
#define DEMOCTORINITIALIZERLIST_H_
#include <iostream>
#include <vector>

class DemoCtor{
public:
	virtual ~DemoCtor()
	{
		std::cout << "~DemoCtor()" << std::endl;
	}

	DemoCtor(int i1=0, int i2=0, int i3=0)
	: values{i1, i2, i3}
	{
		std::cout << "DemoCtor(int i1: " << values[0] <<", int i2: "<< values[1] <<", int i3: " << values[2] << ")" << std::endl;
	}
	DemoCtor(std::initializer_list<int> list)
	: values{list}
	{
		std::cout << "DemoCtor(std::initializer_list<int> list)" << std::endl;
	}


	friend std::ostream& operator<<(std::ostream& out, DemoCtor const& o){
		for(auto const& i: o.values)
			out << i << " ";

		return out;
	}

private:
	std::vector<int> values;
};


#endif /* DEMOCTORINITIALIZERLIST_H_ */
