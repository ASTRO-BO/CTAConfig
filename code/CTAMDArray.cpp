#include "CTAMDArray.h"
#include "ConfigLoadMCFITS.h"

#define CONF_L0HEADER 1
#define CONF_L1HEADER 2

string CTAConfig::CTAMDArray::getArrayConfigName() {
	return this->arrayConfigName;
}

void CTAConfig::CTAMDArray::setArrayConfigName(string arrayConfigName) {
	this->arrayConfigName = arrayConfigName;
}

CTAConfig::CTAMDTelescope* CTAConfig::CTAMDArray::getTelescope(int telID) {
	for(int i=0; i<telescopes.size(); i++) {
		if(telescopes[i]->getTelescopeID() == telID)
			return telescopes[i];
	}
	return 0;
}

void CTAConfig::CTAMDArray::loadConfig(string filename, string arrayName) {
	ConfigLoadMCFITS config(filename);
}

string CTAConfig::CTAMDArray::getName() {
	return this->name;
}
