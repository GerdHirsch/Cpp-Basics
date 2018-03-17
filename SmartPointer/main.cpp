#include <iostream> // cout, endl
#include <utility> //move


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
// Demo für bad_alloc_exception in Memberinitialisierung
void demoSharedPointerBadAlloc();
void demoUniquePointer();
void demoSharedConvertierungAB();
void demoSharedToConst();
void demoMakeUnique();
void demoMakeShared();

int main(){
	cout << "=== Hello SmartPointer" << endl;
//	demoSharedToConst();
//	demoSharedConvertierungAB();
//	demoSharedPointer();
//	demoUniquePointer();
	demoMakeUnique();
//	demoMakeShared();
//	demoSharedPointerBadAlloc();

}
void demoMakeUnique(){
	cout << "=== demoMakeUnique" << endl;
	cout << "=== p1(makeUnique<A>() );" << endl;
	auto p1(makeUnique<A>() );
	cout << "=== p2 = makeUnique<A>(43);" << endl;
	auto p2 = makeUnique<A>(43);

	cout << "=== p3 = makeUnique<A>(*p1);" << endl;
	auto p3 = makeUnique<A>(*p1);
	cout << "=== p4 = makeUnique<A>(A(44));" << endl;
	auto p4 = makeUnique<A>(A(44));

	cout << "=== p1->operation();" << endl;
	p1->operation();
	cout << "=== p2->operation();" << endl;
	p2->operation();
	cout << "=== p4->operation();" << endl;
	p4->operation();
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
		cout << endl << "=== begin block" << endl;

//		cout << "=== SharedPointer<A> pA1(new A);" << endl;
//		SharedPointer<A> pA1(new A); //RAII
		cout << "=== SharedPointer<A> pA1(makeShared<A>());" << endl;
		SharedPointer<A> pA1(makeShared<A>()); //RAII

//		cout << "=== SharedPointer<A> pA2();" << endl;
//		SharedPointer<A> pA2; //RAII
//		cout << "=== pA2->operation();" << endl;
//		pA2->operation();

		cout << "=== SharedPointer<B> pB1(pA1);" << endl;
		SharedPointer<B> pB1(pA1);

		cout << "=== pB1->operation();" << endl;
		pB1->operation();

		cout << "=== SharedPointer<C> pC1(pA1);" << endl;
		SharedPointer<C> pC1(pA1);

		cout << "=== pC1->operation();" << endl;
		pC1->operation();

		cout << "=== pB1 = pA1;" << endl;
		pB1 = pA1;

		cout << "=== pB1 = std::move(pA1);" << endl;
		pB1 = std::move(pA1);

		cout << "=== end block" << endl;
		cout << endl;
	}

		cout << endl << "=== bevor block Move ctor" << endl;
	{
		cout << endl << "=== begin block Move ctor" << endl;

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
	SharedPointer<A> pA1(makeShared<A>(42, "Demo")); //RAII

	//delete pA1.operator->();

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
	try{
		SharedPointer<A> pA1(new A);
	}catch(std::bad_alloc& e){
		cout << "catch std::bad_alloc: " << e.what() << endl;
	}

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
//	UniquePointer<B> pB2((pA3)); error: lvalue to rvalue
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


