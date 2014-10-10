#include "CTAMDArray.h"

string CTAMDArray::getArrayConfigName() {
	return this->arrayConfigName;
}

void CTAMDArray::setArrayConfigName(string arrayConfigName) {
	this->arrayConfigName = arrayConfigName;
}

CTAMDTelescope* CTAMDArray::getTelescope(int telID) {
	throw "Not yet implemented";
}

void CTAMDArray::loadConfig(string filename, string arrayName) {
	throw "Not yet implemented";
}

string CTAMDArray::getName() {
	return this->name;
}
