/***************************************************************************
 CTAMDPixelType.cpp
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

#include "CTAMDPixelType.h"

namespace CTAConfig {

CTAMDPixelType::CTAMDPixelType(int16_t pixTypeID, int16_t nSamples, float sampleTimeSlice, int16_t NGains, float hiLoScale, int16_t hiLoThreshold,float hiLoOffset) {
	this->pixTypeID = pixTypeID;
	this->nSamples = nSamples;
	this->sampleTimeSlice = sampleTimeSlice;
	this->NGains = NGains;
	this->hiLoScale = hiLoScale;
	this->hiLoThreshold = hiLoThreshold;
	this->hiLoOffset = hiLoOffset;
}

int16_t CTAMDPixelType::getID() {
	return this->pixTypeID;
}

int16_t CTAMDPixelType::getNSamples() {
	return this->nSamples;
}

float CTAMDPixelType::getSampleTimeSlice() {
	return this->sampleTimeSlice;
}

int16_t CTAMDPixelType::getNGains() {
	return NGains;
}

float CTAMDPixelType::getHiLoScale() {
	return this->hiLoScale;
}

int16_t CTAMDPixelType::getHiLoThreshold() {
	return this->hiLoThreshold;
}

float CTAMDPixelType::getHiLoOffset() {
	return this->hiLoOffset;
}

}
