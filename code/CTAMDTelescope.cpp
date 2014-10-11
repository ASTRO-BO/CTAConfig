#include "CTAMDTelescope.h"


int16_t CTAConfig::CTAMDTelescopeStatus::getPixelStatus(uint16_t pixelID) {
	return pixelStatus[pixelID];
}

void CTAConfig::CTAMDTelescopeStatus::addPixelStatus(int16_t status) {
	pixelStatus.push_back(status);
}


int CTAConfig::CTAMDTelescope::getTelescopeID() {
	return ID;
}

CTAConfig::CTAMDTelescopeType* CTAConfig::CTAMDTelescope::getTelescopeType() {
	return telescopeType;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDTelescope::getCoordinate() {
	return this->coordinate;
}

CTAConfig::CTAMDTelescopeStatus* CTAConfig::CTAMDTelescope::getTelescopeStatus() {
	return telescopeStatus;
}