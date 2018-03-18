/*
 * demoHanoiTurm.cpp
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 */

#include "../include/HanoiTurm.h"
#include "../include/Ring.h"
#include "../include/Common.h"

#include <iostream>
using namespace std;

namespace{

using Turm = HanoiTurm<Ring>;

Ring biggest { 4 };
Turm a(biggest, "a"), b("b"), c("c");
Ring one(1);

template<class Ring, class Turm>
void move(Ring ring, Turm& target, Turm& source, Turm& ht){
	print(ring, target, source, ht);

	if(ring == one){
		target.push(source.top());
		source.pop();
	}else{
		move(ring-1, ht, source, target);

		//letzten Ring von n nach target verschieben
		target.push(source.top());
		source.pop();

		move(ring-1, target, ht, source);
	}
}

}// end namespace

void demoHanoiTurmRekursiv(){
	cout << "demoHanoiTurmRekursiv" << endl;

	cout << "source stack: ";
	a.print(cout);
	cout << "target stack: ";
	c.print(cout);
	cout << endl;

	move(a.size(), c, a, b);

	cout << "source stack: ";
	a.print(cout);
	cout << "target stack: ";
	c.print(cout);
}

