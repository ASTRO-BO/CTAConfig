/***************************************************************************
 CTAMDPixel.cpp
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "CTAMDPixel.h"

CTAConfig::CTAMDPixel::CTAMDPixel(int16_t pixelID, CTAMDCoordinate2D* tubeMM, float RTubeMM, CTAMDCoordinate2D* tubeDeg, float RTubeDeg, CTAMDPixelType* pixelType) {
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

CTAConfig::CTAMDCoordinate2D* CTAConfig::CTAMDPixel::getTubeMM() {
	return this->tubeMM;
}

CTAConfig::CTAMDCoordinate2D* CTAConfig::CTAMDPixel::getTubeDeg() {
	return this->tubeDeg;
}


CTAConfig::CTAMDPixelType* CTAConfig::CTAMDPixel::getPixelType() {
	return this->pixelType;
}
