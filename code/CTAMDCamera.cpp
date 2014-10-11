#include "CTAMDCamera.h"

string CTAConfig::CTAMDCamera::getName() {
	return this->name;
}

int16_t CTAConfig::CTAMDCamera::getPixelStatus(uint16_t pixelID) {
	return pixelStatus[pixelID];
}

void CTAConfig::CTAMDCamera::addPixelStatus(int16_t status) {
	pixelStatus.push_back(status);
}

CTAConfig::CTAMDCamera::CTAMDCamera(CTAMDTelescopeType* telescopeType) {
	this->telescopeType = telescopeType;
}

CTAConfig::CTAMDCameraType* CTAConfig::CTAMDCamera::getCameraType() {
	return telescopeType->getCameraType();
}