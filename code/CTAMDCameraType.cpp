#include "CTAMDCameraType.h"

float CTAConfig::CTAMDCameraType::getCameraScaleFactor() {
	return this->cameraScaleFactor;
}

float CTAConfig::CTAMDCameraType::getCameraCentreOffset() {
	return this->cameraCentreOffset;
}

float CTAConfig::CTAMDCameraType::getCameraRotation() {
	return this->cameraRotation;
}

int CTAConfig::CTAMDCameraType::getNTubesOff() {
	return this->NTubesOff;
}

short CTAConfig::CTAMDCameraType::getNpixels() {
	return this->npixels;
}

short CTAConfig::CTAMDCameraType::getNpixels_active() {
	return this->npixels_active;
}
