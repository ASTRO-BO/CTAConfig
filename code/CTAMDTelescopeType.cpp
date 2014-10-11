#include "CTAMDTelescopeType.h"

long CTAConfig::CTAMDTelescopeType::getTelescopeTypeID() {
	return ID;
}

CTAConfig::CTAMDCameraType* CTAConfig::CTAMDTelescopeType::getCameraType() {
	return this->cameraType;
}

CTAConfig::CTAMDMirrorType* CTAConfig::CTAMDTelescopeType::getMirrorType() {
	return this->mirrorType;
}

string CTAConfig::CTAMDTelescopeType::getName() {
	return this->name;
}
