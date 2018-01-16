#include <iostream> // cout, endl
#include <utility> //move

// Demo für bad_alloc_exception in Memberinitialisierung

//#include "A2.h"
#include "A4BaseBC.h"
#include "B.h"
#include "UniquePointer.h"
#include "SharedPointer.h"

//template<class T>
//using SmartPointer = SharedPointer<T>;
//using SmartPointer = UniquePointer<T>;

using namespace std;

void demoSharedPointer();
void demoSharedPointerBadAlloc();
void demoUniquePointer();
void demoSharedConvertierungAB();
void demoSharedToConst();
void demoMakeUnique();
void demoMakeShared();

int main(){
	cout << "=== Hello SmartPointer" << endl;
	demoSharedToConst();
//	demoSharedConvertierungAB();
//	demoSharedPointer();
	demoUniquePointer();
//	demoMakeUnique();
//	demoMakeShared();
//	demoSharedPointerBadAlloc();

}
void demoMakeUnique(){
	cout << "=== demoMakeUnique" << endl;
	auto p1(makeUnique<A>() );
	auto p2 = makeUnique<A>(43);

	p1->operation();
	p2->operation();
}
void demoMakeShared(){
	cout << "=== demoMakeShared" << endl;
	auto p1(makeShared<A>() );
	auto p2 = makeShared<const A>(43);

	p1->operation();
	p2->opConst();
}

void demoSharedToConst(){
	cout << "=== demoSharedToConst" << endl;
		{
			cout << "=== begin block" << endl;

//			cout << "=== SharedPointer<const A> pA1(new A);" << endl;
//			SharedPointer<const A> pA1(new A); //RAII

			cout << "=== SharedPointer<A> pA(new A);" << endl;
			SharedPointer<A> pA(new A); //RAII

			cout << "=== SharedPointer<const A> pAConst(pA);" << endl;
			SharedPointer<const A> pAConst(pA);
			cout << "=== SharedPointer<const B> pBConst(pA);" << endl;
			SharedPointer<const B> pBConst(pA);


			pAConst->opConst();
			pBConst->opConst();

			// error: passing 'const A' as 'this' argument discards qualifiers
//			pAConst->operation();

			cout << "=== end block" << endl;
		}
}

void demoSharedConvertierungAB(){
	cout << "=== demoSharedConvertierungAB" << endl;
	{
		cout << "=== begin block" << endl;

		cout << "=== SharedPointer<A> pA1(new A);" << endl;
		SharedPointer<A> pA1(new A); //RAII

		cout << "=== SharedPointer<B> pB1(pA1);" << endl;
		SharedPointer<B> pB1(pA1);

		cout << "=== pB1->operation();" << endl;
		pB1->operation();

		cout << "=== pB1 = pA1;" << endl;
		pB1 = pA1;

		cout << "=== pB1 = std::move(pA1);" << endl;
		pB1 = std::move(pA1);

		cout << "=== end block" << endl;
	}

	{
		cout << "=== begin block Move ctor" << endl;

		cout << "=== SharedPointer<A> pA2(new A);" << endl;
		SharedPointer<A> pA2(new A); //RAII

		cout << "=== SharedPointer<B> pB2(std::move(pA2));" << endl;
		SharedPointer<B> pB2(std::move(pA2));

		cout << "=== pB2->operation();" << endl;
		pB2->operation();
		cout << "=== end block" << endl;
	}
}
void demoSharedPointer(){
	cout << "=== demoSharedPointer" << endl;

	cout << "=== SharedPointer<A> pA1(new A);" << endl;
	SharedPointer<A> pA1(new A); //RAII

	cout << "=== SharedPointer<B> pB1(new A);" << endl;
	SharedPointer<B> pB1(new A); //RAII

	cout << "=== SharedPointer<A> pA2(pA1);" << endl;
	SharedPointer<A> pA2(pA1);

	cout << "=== SharedPointer<A> pA3(new A);" << endl;
	SharedPointer<A> pA3(new A); //RAII

	cout << "=== SharedPointer<B> pB2(std::move(pA3));" << endl;
	SharedPointer<A> pA4(std::move(pA3));

	cout << "=== pA2 = std::move(pA1);" << endl;
	pA2 = std::move(pA1);

//	cout << "=== pA2 = std::move(pA1);" << endl;
//	pB1 = std::move(pA1);

	if(pA2) pA2->operation();

	if(pB1) pB1->operation();

//	if(pB2) pB2->operation();

	cout << "=== pA2 = std::move(pA2); // self assignment!" << endl;
	pA2 = std::move(pA2); // self assignment!
	if(pA2) pA2->operation();
}
void demoSharedPointerBadAlloc(){
	Counter::throwBadAlloc() = true;
	SharedPointer<A> pA1(new A);

}
void demoUniquePointer(){
	cout << "=== demoUniquePointer" << endl;

	cout << "=== UniquePointer<A> pA1(new A);" << endl;
	UniquePointer<A> pA1(new A); //RAII

	cout << "=== UniquePointer<B> pB1(new A);" << endl;
	UniquePointer<B> pB1(new A); //RAII

	cout << "=== UniquePointer<A> pA2(new A);" << endl;
	UniquePointer<A> pA2(new A); //RAII
	UniquePointer<A> pA2a(std::move(pA2));


	cout << "=== UniquePointer<A> pA3(new A);" << endl;
	UniquePointer<A> pA3(new A); //RAII

	cout << "=== UniquePointer<B> pB2(std::move(pA3));" << endl;
//	UniquePointer<B> pB2((pA3)); //RAII
	UniquePointer<B> pB2(std::move(pA3)); //RAII

	cout << "=== pA2 = std::move(pA1);" << endl;
	pA2 = std::move(pA1);

	cout << "=== pA2 = std::move(pA1);" << endl;
	pB1 = std::move(pA1);

	if(pA2) pA2->operation();

	if(pB1) pB1->operation();

	if(pB2) pB2->operation();

	cout << "=== pA2 = std::move(pA2); // self assignment!" << endl;
	pA2 = std::move(pA2); // self assignment!
	if(pA2) pA2->operation();
}

//	SmartPointer<A1> pA3(new A1); //RAII

// explicit eliminates the Problem
//	if(pA3.bool() == pA2.bool())
//		cout << "pA3 == pA2" << endl;
//	else
//		cout << "pA3 != pA2" << endl;


