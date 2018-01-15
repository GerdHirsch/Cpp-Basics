/*
* Demo all Callable Entities of C++ in preparation for template meta programming
* Examples like/from Modern C++, Generic Programming and Design Patterns Applied
* Andrei Alexandrescu
*/
#include "Parrot.h"
#include <iostream>

using namespace std;

class MyFunctor
{
public:  
    void operator()(int i, int j)
    {
        cout << "MyFunctor.operator()(" << i <<", " << j <<") called" << endl;
    }
};

void foo(int i, int j) { cout << "foo(" << i <<", " << j <<") called" << endl;}
void bar(int i, int j) { cout << "bar(" << i <<", " << j <<") called" << endl;}
void unaryFunction(int i);

// A Function with a Functionpointer Parameter
void callerF(void(int,int));

// A FunctionTemplate expecting some Parameter
template<class Function>
void callerT(Function function);

// seit C++11
auto callerL = [](auto & function){
    cout << "void callerL(auto & function)"<<endl;
	function(42,43);
};

int main()
{
    //Function Pointer variable pF
    void (*pF)(int, int) = bar;
    //Function Reference variable rF
    void (&rF)(int, int) = foo;

    //Define a Type of Pointer to Function named TpF
    typedef void (*TpF)(int, int);
    //use the FunctionPointer Type
    TpF pF2 = foo;
    
    //call by name
    foo(1, 2);
    //call by reference
    rF(3, 4);

    //error: assignment of read-only reference 'rF'
    //rF = bar;

    //call by pointer
    pF(5, 6);
    (*pF)(7, 8);
    //change pointer
    pF = foo;
    // call it
    pF(9, 10);

    //function as an Argument
    callerF(foo);
    // error: invalid conversion from 'void (*)(int)' to 'void (*)(int, int)'
    // callerF(unaryFunction);

    callerT(bar);

    // error: too many arguments to function
    // callerT(unaryFunction);


    callerL(bar);

    cout << endl;
    //Create an Functor
    MyFunctor myFunctor;
    
    // Call Operator()
    myFunctor(42, 666); // the beast ...
    myFunctor.operator()(42, 667); //and it's neighbour
    
    cout << endl;
    // Variable pMemFunc of type Pointer to Member Function of Parrot
    void (Parrot::*pMemFunc)();

    //Define a Pointer to Member Function Type named TpMemFunc
    typedef void (Parrot::*TpMemFunc)();
    //use it
    TpMemFunc pMemFunc2 = &Parrot::speak;
    
    // Reference to Member Function does not exist
    //void (Parrot::&rMemFunc)() = Parrot::speak;

    // Assign a Member Function
    pMemFunc = &Parrot::eat;

    //Create an Objekt 
    Parrot geronimo;
    // and a Pointer to it
    Parrot *pGeronimo = &geronimo;

    // send em a message via Object
    geronimo.eat();
    // send em a message via Pointer
    pGeronimo->speak();

    //Call Member Function via Object
    (geronimo.*pMemFunc)();

    //Call Member Function via Pointer
    (pGeronimo->*pMemFunc)();

    //change Pointer
    pMemFunc = &Parrot::speak;

    //Call it
    (pGeronimo->*pMemFunc)();
}

template<class Function>
void callerT(Function function){
    cout << "void callerT(Function function)"<<endl;
	function(42, 664); // the neighbour of the neighbour
}
void callerF(void pf(int, int)){
    cout << "void caller(void pf(int, int))"<<endl;
    pf(42,665); // the other neighbour
}

