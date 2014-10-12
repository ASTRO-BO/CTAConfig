#include "CTAMDTelescopeType.h"


CTAConfig::CTAMDTelescopeType::CTAMDTelescopeType(int64_t ID, string name, CTAConfig::CTAMDCameraType* cameraType, CTAConfig::CTAMDMirrorType* mirrorType, uint16_t internaleCounter) {
	this->ID = ID;
	this->name = name;
	this->cameraType = cameraType;
	this->mirrorType = mirrorType;
	this->internaleCounter = internaleCounter;
}

int64_t CTAConfig::CTAMDTelescopeType::getTelescopeTypeID() {
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
