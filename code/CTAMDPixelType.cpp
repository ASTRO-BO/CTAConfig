#include "CTAMDPixelType.h"

CTAConfig::CTAMDPixelType::CTAMDPixelType(int16_t pixTypeID, int16_t nSamples, float sampleTimeSlice, int16_t NGains, float hiLoScale, int16_t hiLoThreshold,float hiLoOffset) {
	this->pixTypeID = pixTypeID;
	this->nSamples = nSamples;
	this->sampleTimeSlice = sampleTimeSlice;
	this->NGains = NGains;
	this->hiLoScale = hiLoScale;
	this->hiLoThreshold = hiLoThreshold;
	this->hiLoOffset = hiLoOffset;
}

int16_t CTAConfig::CTAMDPixelType::getID() {
	return this->pixTypeID;
}

int16_t CTAConfig::CTAMDPixelType::getNSamples() {
	return this->nSamples;
}

float CTAConfig::CTAMDPixelType::getSampleTimeSlice() {
	return this->sampleTimeSlice;
}

int16_t CTAConfig::CTAMDPixelType::getNGains() {
	return NGains;
}

float CTAConfig::CTAMDPixelType::getHiLoScale() {
	return this->hiLoScale;
}

int16_t CTAConfig::CTAMDPixelType::getHiLoThreshold() {
	return this->hiLoThreshold;
}

float CTAConfig::CTAMDPixelType::getHiLoOffset() {
	return this->hiLoOffset;
}
