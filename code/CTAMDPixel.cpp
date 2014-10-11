#include "CTAMDPixel.h"

CTAConfig::CTAMDPixel::CTAMDPixel(int16_t pixelID, CTAMDCoordinate* tubeMM, CTAMDCoordinate* tubeDeg, CTAMDPixelType* pixelType) {
	this->ID = pixelID;
	this->tubeMM = tubeMM;
	this->tubeDeg = tubeDeg;
	this->pixelType = pixelType;
}

int16_t CTAConfig::CTAMDPixel::getID() {
	return ID;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDPixel::getTubeMM() {
	return this->tubeMM;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDPixel::getTubeDeg() {
	return this->tubeDeg;
}


CTAConfig::CTAMDPixelType* CTAConfig::CTAMDPixel::getPixelType() {
	return this->pixelType;
}
