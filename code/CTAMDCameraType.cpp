#include "CTAMDCameraType.h"

CTAConfig::CTAMDCameraType::CTAMDCameraType(int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation) {
	this->camTypeID = camTypeID;
	this->camTypeName = camTypeName;
	this->cameraScaleFactor = cameraScaleFactor;
	this->cameraCentreOffset = cameraCentreOffset;
	this->cameraRotation = cameraRotation;
}

void CTAConfig::CTAMDCameraType::addPixel(CTAMDPixel* pixel) {
	pixels.push_back(pixel);
}

int CTAConfig::CTAMDCameraType::getCamTypeID() {
	return this->camTypeID;
}

string CTAConfig::CTAMDCameraType::getCamTypeName() {
	return this->camTypeName;
}

float CTAConfig::CTAMDCameraType::getCameraScaleFactor() {
	return this->cameraScaleFactor;
}

float CTAConfig::CTAMDCameraType::getCameraCentreOffset() {
	return this->cameraCentreOffset;
}

float CTAConfig::CTAMDCameraType::getCameraRotation() {
	return this->cameraRotation;
}



short CTAConfig::CTAMDCameraType::getNpixels() {
	return this->pixels.size();
}

