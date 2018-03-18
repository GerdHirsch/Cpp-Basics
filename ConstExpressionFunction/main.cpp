/*
 * main.cpp
 *
 *  Created on: 07.12.2013
 *      Author: Gerd
 */


#include <iostream>
using namespace std;


constexpr int global{42};
//error: declaration of constexpr variable 'globalExtern' is not a definition
//extern constexpr int globalExtern;
extern int nonConstGlobal;

//warning: inline function 'constexpr int f()' used but never defined
constexpr int f();

// constexpr Funktionsdefinition
constexpr int square(int x){ return x*x; }

constexpr int globalAccess(int const& i){
	return global + i;
}
void f(int n){
	int nonConstlocal{1};
	constexpr int constLocal{1};
	//error: uninitialized const 'i1'
	//constexpr int i1;
	// error: 'n' is not a constant expression
	//constexpr int i1 = n;

	int square5 = square(5); // wird möglicherweise zur compile time ausgewertet
	constexpr int square2 = square(2); // wird sicher zur compile time ausgewertet
	int squareN = square(n); // wird zur runtime ausgewertet, n ist eine Variable
	float fa[square(9)]; // fa mit 81 Elementen

	constexpr int i2 = globalAccess(constLocal);

	// error: the value of 'nonConstlocal' is not usable in a constant expression
	//constexpr int i3 = globalAccess(nonConstlocal);

	// OK: runtime evaluation
	cout << globalAccess(nonConstlocal) << endl;

	// error: 'constexpr int f()' used before its definition
	//constexpr int i4 = f();

	// error: the value of 'nonConstGlobal' is not usable in a constant expression
	//constexpr int i5 = globalAccess(nonConstGlobal);

	// OK: runtime evaluation
	cout << globalAccess(nonConstGlobal) << endl;
}
int main(){
	cout << "ConstExpressionFunction" << endl;
	f(5);
}
