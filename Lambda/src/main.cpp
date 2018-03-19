/*
 * main.cpp
 *
 *  Created on: 24.10.2013
 *      Author: Gerd
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void demoAccumLambda();
void demoLambdaMemorize();

int main(){
	cout << "Lambda" << endl;
//	demoAccumLambda();
	demoLambdaMemorize();
}

template<class T>
struct LambdaType{
	using type = T;
	type myLambda;
	LambdaType(T t):myLambda(t){}
};

void demoLambdaMemorize(){
	vector<int> intVec{1, 2, 3, 4};

	string separator = "-";
	auto sepHyphen = [separator](int i)
		{cout << i << separator;};


	separator = ", ";
	auto sepComma = [separator](int i)
		{cout << i << separator;};

	for_each(intVec.begin(), intVec.end(),sepHyphen);
	cout << endl;
	for_each(intVec.begin(), intVec.end(),sepComma);
	cout << endl;
}

void demoAccumLambda(){
	class AccumTemp{
		int & sum;
		int inc;
	public:
		AccumTemp(int& sum, int inc):sum(sum), inc(inc){}

		int operator()(int v) const {
			return sum += v + inc;
		}
	};

	vector<int> intVec{1, 2, 3, 4};
	int sum = 0;
	int inc = 2;

	for_each(
			intVec.begin(), intVec.end(),
			[&sum, inc](int v){
				return sum += v +inc;}
	);
	cout << "sum: " << sum << endl;

	sum = 0;
	for_each(
			intVec.begin(), intVec.end(),
			AccumTemp(sum, inc)
	);
	cout << "sum: " << sum << endl;
}
