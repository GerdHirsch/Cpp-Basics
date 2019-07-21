///////////////////////////////////////////////////////////
//  Lampe.h
//  Implementation of the Class Lampe
//  Created on:      30-Sep-2008 14:54:03
///////////////////////////////////////////////////////////

#if !defined(EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_)
#define EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_


#include  <string>

class Lampe 
{

public:
	Lampe(const std::string& ipAddresse);
	void aus();
	void ein();

private:
	bool an;
	const std::string ipAddresse;

};
#endif // !defined(EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_)
