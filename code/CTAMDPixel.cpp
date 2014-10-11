#include "CTAMDPixel.h"

short CTAConfig::CTAMDPixel::getID() {
	return ID;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDPixel::getTubeMM() {
	return this->tubeMM;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDPixel::getTubeDeg() {
	return this->tubeDeg;
}

short CTAConfig::CTAMDPixel::getTubeOFF() {
	return this->tubeOFF;
}

CTAConfig::CTAMDPixelType* CTAConfig::CTAMDPixel::getPixelType() {
	return this->pixelType;
}
