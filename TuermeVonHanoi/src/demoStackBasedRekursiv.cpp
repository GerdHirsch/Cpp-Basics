/*
 * main.cpp
 *
 *  Created on: 16.03.2018
 *      Author: Gerd
 */


#include <stack>
#include <iostream>
using namespace std;

namespace{
using MyTurm = std::stack<int>;

MyTurm a, b, c;

void initSource(int);
void print(MyTurm turm);


//void move(int number, MyTurm target, MyTurm source, MyTurm ht){
void print(int number){
	cout << "move( number: "
		<< number << ") " << endl;

	if (!a.empty())
		cout << "a.top: " << a.top();
	if (!b.empty())
		cout << " b.top: " << b.top();
	if(!c.empty())
		cout << " c.top: " << c.top();

	cout << endl;
}
void move(int number, MyTurm& target, MyTurm& source, MyTurm& ht){
	print(number);
	if(number == 1){
		target.push(1);
		source.pop();
	}else{
		move(number-1, ht, source, target);
		int num = source.top();
		source.pop();
		target.push(num);
		move(number-1, target, ht, source);
	}
}
void print(MyTurm turm){
	while(!turm.empty()){
		cout << turm.top() << " ";
		turm.pop();
	}
	cout << endl;
}
void initSource(int numElements){
	for(int i = numElements; i>0; --i)
		a.push(i);
	cout << "Source: " << a.size() << endl;
}

} // end namespace
void demoStackbasedRekursiv(){
	cout << "demoStackbased" << endl;
	int numElements = 5;
	initSource(numElements);
	move(numElements, c, a, b);
	cout << "source stack: ";
	print(a);
	cout << "target stack: ";
	print(c);

}
