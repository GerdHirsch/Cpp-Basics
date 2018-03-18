/*
Demo für const bei der Deklaration von 
Objekten, ÜbergabeParametern, Rückgabewerten
Pointern und Arrays

von rechts nach links lesen hilft bei der analyse
*/
#include <string.h>


// f ist eine funktion die einen zeiger auf einen konstanten int zurückliefert
// und einen zeiger auf einen konstanten int als parameter definiert
// die schreibweise bei der deklaration ist alternativ
struct tagPerson{
	char name[21];
};
typedef struct tagPerson* Person;
typedef struct tagPerson* PPerson;
typedef const struct tagPerson* CPPerson;

int const * f(const int* );
void fa(const int* param_apci[]);
void f(int i){
	const int ci = i;
	//constexpr int cei = ci; //error: the value of 'ci' is not usable in a constant expression
}
#define MAXANZAHL 3

int main(){
	// i ist ein int; uninitialisiert!!
	int i;
	// ai ist ein array von MAXANZAHL int; wird initialisiert mit {...}
	int ai[MAXANZAHL] = {1, 2, 3};
	// pi ist ein zeiger auf einen int; uninitialisiert!!
	int *pi;

	// apci ist ein array von zeigern auf konstante int; uninitialisiert!
	const int* apci[3];
	int* api[MAXANZAHL];

	//constexpr
	int const ceConstPointerConst[] = {1, 2, 3};
	//error: assignment of read-only location
	//ceConstPointerConst[0] = 0;
	
	// error C2734: 'ci' / cpi / cpci: Konstantes Objekt muss initialisiert werden, 
	// wenn es nicht extern ist
	//const ci;
	//int * const cpi;
	//int const * const cpci;


	// default:					int const ci = 1;
	// alternativ auch: const int ci = 1;
	// ci ist ein konstanter int
	const int ci = 1;

	constexpr int cei = ci;

	// error C2440: 'initializing' : 'const int *' kann nicht in 
	// 'int *const ' konvertiert werden
	//int * const cpi = &ci;
	// cpi ist ein konstanter zeiger auf einen int
	int * const cpi = &i;
	
	//cpci_X ist ein konstanter zeiger auf einen konstanten int
	int const * const cpci_1 = &ci; //zeigt auf einen const int
	const int * const cpci_2 = &i;  // zeigt auf einen int
	
	// zuweisung der Adressen aus ai[idx] an apci[idx]
	{
	int idx;
	for(idx=0; idx < MAXANZAHL; idx++){
		apci[idx] = &ai[idx];
		api[idx]	= &ai[idx];
	}
	}
	fa(apci);
	fa((const int**)api);

	// error C2440: '=' : 'const int *' kann nicht in 'int *' konvertiert werden
	//pi = &ci;
	// pi zeigt auf den int i
	pi = &i;

	{ // neuer Block zur Deklaration
		//pci ist ein zeiger auf einen konstanten int
		int const * pci;
		pci = pi;
		pci = &i;
		pci = &ci;
	}
	// Error C2166: L-Wert gibt ein konstantes Objekt an
	//ci = 3;
	//cpci_1 = &ci;
	//cpi = &i;
	//(*cpci_2)++;
	//*pci = 3;
	//*apci[0] = 0;

	// i wird über cpi manipuliert (i == 5) == true
	(*cpi) = 5; 


	{ // neuer Block zur Deklaration von Variablen
		struct tagPerson p;
		Person pP1 = &p;
		PPerson pP2 = &p;
		//error C2734: pP3 ist ein konstanter Zeiger auf eine Person muss initialisiert werden
		//const Person pP3; // = &p;
		const Person pP3 = &p;

		CPPerson cpP = &p;

		char buffer[] = "Helene";

		strcpy(pP1->name, buffer);
		strcpy(pP2->name, buffer);
		//strcpy(cpP->name, buffer);
		strcpy(pP3->name, buffer);
	}
}
const int* f(int const* pci){
	static int sli=0;
	//(*pci)=2; siehe oben

	//pci zeigt nicht mehr auf das übergebene objekt
	pci = &sli;

	return pci;
}
void fa(int const ** param_apci){
	//wert über den zeiger verändern
	//error C2166: L-Wert gibt ein konstantes Objekt an
	//*param_apci[0] = 0;
	
	//Inhalt des Feldes (den zeiger) verändern
	// OK
	param_apci[0] = 0;
}
