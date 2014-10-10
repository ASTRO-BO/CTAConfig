#include "CTAMDTelescopeType.h"

long CTAMDTelescopeType::getTelescopeTypeID() {
	return ID;
}

CTAMDCameraType* CTAMDTelescopeType::getCameraType() {
	return this->cameraType;
}

CTAMDMirrorType* CTAMDTelescopeType::getMirrorType() {
	return this->mirrorType;
}

string CTAMDTelescopeType::getName() {
	return this->name;
}
