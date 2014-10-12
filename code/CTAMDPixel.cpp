#include "CTAMDPixel.h"

CTAConfig::CTAMDPixel::CTAMDPixel(int16_t pixelID, CTAMDCoordinate* tubeMM, float RTubeMM, CTAMDCoordinate* tubeDeg, float RTubeDeg, CTAMDPixelType* pixelType) {
	this->ID = pixelID;
	this->tubeMM = tubeMM;
	this->RTubeMM = RTubeMM;
	this->tubeDeg = tubeDeg;
	this->RTubeDeg = RTubeDeg;
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
