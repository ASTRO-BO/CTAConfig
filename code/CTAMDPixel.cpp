#include "CTAMDPixel.h"

CTAConfig::CTAMDPixel::CTAMDPixel(int16_t pixelID, CTAMDCoordinate* tubeMM, CTAMDCoordinate* tubeDeg, int16_t tubeOFF, CTAMDPixelType* pixelType) {
	this->ID = pixelID;
	this->tubeMM = tubeMM;
	this->tubeDeg = tubeDeg;
	this->tubeOFF = tubeOFF;
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

int16_t CTAConfig::CTAMDPixel::getTubeOFF() {
	return this->tubeOFF;
}

CTAConfig::CTAMDPixelType* CTAConfig::CTAMDPixel::getPixelType() {
	return this->pixelType;
}
