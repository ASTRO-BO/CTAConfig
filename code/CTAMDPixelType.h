/***************************************************************************
 CTAMDPixelType.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CTAMDPIXELTYPE_H
#define _CTAMDPIXELTYPE_H

#include <cstdlib>

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
