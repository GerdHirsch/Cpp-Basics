/*
 * main.cpp
 *
 *  Created on: 24.03.2021
 *      Author: Gerd
 */

#include <iostream>
#include <type_traits>
#include <type_traits>
using namespace std;

template
<
	class Enum,
	class = typename std::enable_if< std::is_enum<Enum>::value >::type
>
std::ostream& operator<<(std::ostream& out, Enum value){
	using EnumType = typename std::underlying_type<Enum>::type;
	out << static_cast<EnumType>(value);
	return out;
}

int main(){
	cout << "StreamOperatorScopedEnums" << endl;

	enum class Enums { Init, NextState };

	cout << "Init: " << Enums::Init << endl;
}


