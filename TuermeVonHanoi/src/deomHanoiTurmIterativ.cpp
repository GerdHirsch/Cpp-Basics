/*
 * deomHanoiTurmIterativ.cpp
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 *  Iterative Variante ist sehr aufwändig
 *  und noch nicht fertig!
 */



#include "../include/HanoiTurm.h"
#include "../include/Ring.h"
#include "../include/Common.h"

#include <stack>
#include <iostream>
using namespace std;

namespace{

using Turm = HanoiTurm<Ring>;

Ring biggest { 4 };
Turm a(biggest, "a"), b("b"), c("c");

template<class Ring, class Turm>
void move(Ring ring_, Turm& target_, Turm& source_, Turm& ht){

	std::stack<Turm*> targetTurm;
	std::stack<Turm*> sourceTurm;
	std::stack<Turm*> tempTurm;
	std::stack<Ring> ringStack;

	ringStack.push(ring_);
	targetTurm.push(&target_);
	sourceTurm.push(&source_);
	tempTurm.push(&ht);
	Ring one(1);

//	Ring ring = ringStack.top();
	Turm *target = targetTurm.top();
	Turm *source = sourceTurm.top();
//	Turm *turm = tempTurm.top();

	// outer loop with end criterion
	while(target_.size() != ring_.getValue()){

		cout << "while(target_.size() != ring.getValue()" << endl;
		print(ringStack.top(), *targetTurm.top(), *sourceTurm.top(), *tempTurm.top());
//		print(ring, *target, *source, *turm);

		//stack aufbauen
		while(!(ringStack.top() == one) ){
			ringStack.push(ringStack.top() - 1);
			Turm* pTarget = targetTurm.top();

			targetTurm.push(tempTurm.top());
			sourceTurm.push(sourceTurm.top());
			tempTurm.push(pTarget);
			cout << "1 while(!(ringStack.top() == one)" << endl;
			print(ringStack.top(), *targetTurm.top(), *sourceTurm.top(), *tempTurm.top());
		}
		// ringStack.top() == one
		target = targetTurm.top();
		source = sourceTurm.top();

		target->push(source->top());
		source->pop();

		//stack abbauen
//		cout << "ringStack.top() == one" << endl;
//		print(ringStack.top(), *targetTurm.top(), *sourceTurm.top(), *tempTurm.top());
		ringStack.pop();
		targetTurm.pop();
		sourceTurm.pop();
		tempTurm.pop();

		cout << "nach stack abbauen" << endl;
		print(ringStack.top(), *targetTurm.top(), *sourceTurm.top(), *tempTurm.top());

		// letzten Ring von source_ nach target_ verschieben
		Ring num = sourceTurm.top()->top();
		sourceTurm.top()->pop();
		targetTurm.top()->push(num);

		//stack aufbauen
		while(!(ringStack.top() == one)){
			ringStack.push(ringStack.top() - 1);
			Turm* pSource = sourceTurm.top();

			targetTurm.push(targetTurm.top());
			sourceTurm.push(tempTurm.top());
			tempTurm.push(pSource);
			cout << "2 while(!(ringStack.top() == one)" << endl;
			print(ringStack.top(), *targetTurm.top(), *sourceTurm.top(), *tempTurm.top());
		}
	}
}


} // end namespace
void demoHanoiTurmIterativ(){
	cout << "demoHanoiTurmIterativ" << endl;

	cout << "source stack: ";
	a.print(cout);
	cout << "target stack: ";
	c.print(cout);
	cout << endl;

	move(biggest, c, a, b);

	cout << "source stack: ";
	a.print(cout);
	cout << "target stack: ";
	c.print(cout);
}
