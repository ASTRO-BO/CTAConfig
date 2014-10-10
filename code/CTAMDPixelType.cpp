#include "CTAMDPixelType.h"

short CTAMDPixelType::getNSamples() {
	return this->nSamples;
}

float CTAMDPixelType::getSampleTimeSlice() {
	return this->sampleTimeSlice;
}

short CTAMDPixelType::getNgains() {
	return Ngains;
}

float CTAMDPixelType::getHiLoScale() {
	return this->hiLoScale;
}

short CTAMDPixelType::getHiLoThreshold() {
	return this->hiLoThreshold;
}

float CTAMDPixelType::getHiLoOffset() {
	return this->hiLoOffset;
}
