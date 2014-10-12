#ifndef _CTAMDPIXELTYPE_H
#define _CTAMDPIXELTYPE_H

#include <stdlib.h>

namespace CTAConfig {
	
	class CTAMDPixelType {

	private:
		int16_t pixTypeID;
		int16_t nSamples;
		float sampleTimeSlice;
		int16_t NGains;
		float hiLoScale;
		int16_t hiLoThreshold;
		float hiLoOffset;


	public:
		
		CTAMDPixelType(int16_t pixTypeID, int16_t nSamples, float sampleTimeSlice, int16_t NGains, float hiLoScale, int16_t hiLoThreshold,float hiLoOffset);
		
		int16_t getID();
		
		int16_t getNSamples();

		float getSampleTimeSlice();

		int16_t getNGains();

		float getHiLoScale();

		int16_t getHiLoThreshold();

		float getHiLoOffset();
	};

}
#endif
