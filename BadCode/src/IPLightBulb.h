///////////////////////////////////////////////////////////
//  IPLightBulb.h
//  Implementation of the Class IPLightBulb
//  Created on:      30-Sep-2008 14:54:03
///////////////////////////////////////////////////////////

#if !defined(EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_)
#define EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_

#include  <string>
#include "LightBulb.h"

class IPLightBulb : public LightBulb
{

public:
	IPLightBulb(const std::string& ipAddress);
	void off();
	void on();

private:
	bool an;
	const std::string ipAddress;

};
#endif // !defined(EA_ECD4E76C_FB2A_46d3_BEA3_92A784F6B442__INCLUDED_)
