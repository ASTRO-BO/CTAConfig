#include "CTAMDPixelType.h"

short CTAConfig::CTAMDPixelType::getNSamples() {
	return this->nSamples;
}

float CTAConfig::CTAMDPixelType::getSampleTimeSlice() {
	return this->sampleTimeSlice;
}

short CTAConfig::CTAMDPixelType::getNgains() {
	return Ngains;
}

float CTAConfig::CTAMDPixelType::getHiLoScale() {
	return this->hiLoScale;
}

short CTAConfig::CTAMDPixelType::getHiLoThreshold() {
	return this->hiLoThreshold;
}

float CTAConfig::CTAMDPixelType::getHiLoOffset() {
	return this->hiLoOffset;
}
