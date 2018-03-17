// Operationen die der Compiler zur Verfügung stellt //

//#include "A1Empty.h"
//#include "A2.h"
//#include "A3MemberBC.h"
#include "A4BaseBC.h"
//#include "A5MemberbBaseC.h"

#include <iostream>
#include <utility>
using namespace std;

// comment in for experience propose
A f(){ return A(); }
//void f(A&& a){ cout << "void f(A&& a)" << endl; }
//void f(A& a){ cout << "void f(A& a)" << endl; }
void f(A a){ cout << "void f(A a)" << endl; }
//void f(A const& a){ cout << "void f(A const& a)" << endl; }

void lebenszyklus()
{
	cout << "=== begin Lebenszyklus()" << endl;
	{
		cout << "=== begin Block \n{" << endl;

		cout << "=== A a1;" << endl;
		A a1;
		cout << "a1.i: " << a1.i << endl;

		cout << "=== A a2 = a1;" << endl;
		A a2 = a1;
		cout << "a2.i: " << a2.i << endl;

		cout << "=== A a3(a1);" << endl;
		A a3(a2);
		cout << "a3.i: " << a3.i << endl;

		a1.i = 43;
		cout << "=== a1.i = 43: " << a1.i << endl;

		cout << "=== a2 = a1" << endl;
		a2 = a1;
		cout << "a2.i: " << a2.i << endl;

		cout << "=== A a4(move(a1));" << endl;
		A a4(move(a1));
		cout << "a1.i: " << a1.i << endl;
		cout << "a4.i: " << a4.i << endl;

		cout << "a4 = move(a3);" << endl;
		a4 = move(a3);
		cout << "a3.i: " << a3.i << endl;
		cout << "a4.i: " << a4.i << endl;

		cout << "=== A a5 = f();" << endl;
		A a5 = f();
		cout << "a5.i: " << a5.i << endl;

		cout << "=== f(A());" << endl;
		f(A());

		cout << "=== f(a4);" << endl;
		f(a4);

		cout << "=== end Block \n}" << endl;
	}
	cout << "=== end Lebenszyklus()" << endl;
}
// Welche Ausgabe erzeugt dieses Programm ?
/*

*/
