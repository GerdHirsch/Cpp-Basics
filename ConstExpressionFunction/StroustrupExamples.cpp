///*
// * ScriptExamples.cpp
// *
// *  Created on: 19.02.2016
// *      Author: Gerd
// */
//
//
//
//int global;
////constexpr int global{42};
////error: declaration of constexpr variable 'globalExtern' is not a definition
////extern constexpr int globalExtern;
//extern int nonConstGlobal;
//
////constexpr void bad1(int& a){}// error: constexpr Function cannot be void
//
////constexpr int bad1a(int& a){
////	int local = 0; 			// error: lokale Variable
////	a = local;   			// error: Seiteneffekt
////	global = a; 			// error: Seiteneffekt
////	return 0;
////}
////constexpr int bad2(int a){
////	if(a>=0) return a; 	// error: Kontrollstruktur (if, switch, for, while, do)
////	else return -a; 		// error: mehrere return Statements
////}
////constexpr int bad3(int a){
////	if(a>=0) return a; 	// error: Kontrollstruktur
////	else return -a; 		// error: mehrere return Statements
////}
////constexpr int good(int const& a){
////	return globalConst + a; // zugriff auf Referenzen und globale Objekte ohne Seiteneffekt
////}
