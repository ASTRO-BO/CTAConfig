#include "CTAMDPixel.h"

short CTAMDPixel::getID() {
	return ID;
}

CTAMDCoordinate* CTAMDPixel::getTubeMM() {
	return this->tubeMM;
}

CTAMDCoordinate* CTAMDPixel::getTubeDeg() {
	return this->tubeDeg;
}

short CTAMDPixel::getTubeOFF() {
	return this->tubeOFF;
}

CTAMDPixelType* CTAMDPixel::getPixelType() {
	return this->pixelType;
}
