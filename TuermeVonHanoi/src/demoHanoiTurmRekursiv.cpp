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
void move(Ring ring, Turm& target, Turm& source, Turm& tmp){
	print(ring, target, source, tmp);
	// Wenns der kleinste ist: verschieben
	if(ring == one){
		target.push(source.top());
		source.pop();
		print(ring, target, source, tmp);
	}else{
		// den stappel über dem untersten Ring auf tmp verschieben
		move(ring-1, tmp, source, target);
		print(ring, target, source, tmp);

		//untersten Ring von source nach target verschieben
		target.push(source.top());
		source.pop();

		// den stappel von tmp nach target verschieben
		move(ring-1, target, tmp, source);
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

