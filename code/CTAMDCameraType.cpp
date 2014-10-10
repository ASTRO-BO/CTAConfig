#include "CTAMDCameraType.h"

float CTAMDCameraType::getCameraScaleFactor() {
	return this->cameraScaleFactor;
}

float CTAMDCameraType::getCameraCentreOffset() {
	return this->cameraCentreOffset;
}

float CTAMDCameraType::getCameraRotation() {
	return this->cameraRotation;
}

int CTAMDCameraType::getNTubesOff() {
	return this->NTubesOff;
}

short CTAMDCameraType::getNpixels() {
	return this->npixels;
}

short CTAMDCameraType::getNpixels_active() {
	return this->npixels_active;
}
