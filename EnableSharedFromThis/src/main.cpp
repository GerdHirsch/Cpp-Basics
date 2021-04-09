/*
 * main.cpp
 *
 *  Created on: 03.03.2016
 *      Author: Gerd
 */

#include "Widget.h"

#include<memory>
#include<iostream>
using namespace std;

void demoGood(){
	cout << "	begin demoGood" << endl;
	Widget::SharedThis pw2;

	{
		cout << "	begin Block" << endl;

		auto pW = make_shared<Widget>();
		pw2 = pW->getShared();

		cout << "	end Block" << endl;
	}
	cout << "	end demoGood" << endl;
}
void demoBad(){
	cout << "	begin demoBad" << endl;
	Widget::SharedThis pw;
	{
		cout << "	begin Block" << endl;

		Widget w;
		pw = w.getShared();
		/* begin Block
		 * Widget()
		 * terminate called after throwing an instance of 'std::bad_weak_ptr'
		 * what():  bad_weak_ptr
		 */

		cout << "	end Block" << endl;
	}
	cout << "	end demoBad" << endl;
}
void demoWorse(){
	cout << "	begin demoWorse" << endl;
	Widget::SharedThis pw;
	{
		cout << "	begin Block" << endl;

		Widget w;
		pw = w.getWorse();

		cout << "	end Block" << endl;
	}
	cout << "	end demoWorse" << endl;
	/*	end Block
	 * ~Widget()
	 * end demoWorse
	 * ~Widget()
	 * 0 [main] DemoEnableSharedFromThis 1884 cygwin_exception
	 */
}
void demoStrange(){
	cout << "	begin demoStrange" << endl;
	Widget *p = new Widget;
	std::shared_ptr<Widget> pw(p);
	std::shared_ptr<Widget> pw1 = p->getShared();
	cout << "	end demoStrange" << endl;
}

int main(){
	cout << "DemoEnableSharedFromThis" << endl;
	demoGood();
//	demoBad();
//	demoWorse();
	demoStrange();


}


