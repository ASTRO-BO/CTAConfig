#ifndef _CTAMDPIXEL_H
#define _CTAMDPIXEL_H

#include "CTAMDCoordinate.h"
#include "CTAMDPixelType.h"
#include <stdlib.h>

namespace CTAConfig {
	
	class CTAMDPixel {

	private:
		int16_t ID;
		CTAMDCoordinate* tubeMM;
		float RTubeMM;
		CTAMDCoordinate* tubeDeg;
		float RTubeDeg;
		CTAMDPixelType* pixelType;

	public:
		
		CTAMDPixel(int16_t pixelID, CTAMDCoordinate* tubeMM, float RTubeMM, CTAMDCoordinate* tubeDeg, float RTubeDeg, CTAMDPixelType* pixelType);
		
		int16_t getID();

		CTAMDCoordinate* getTubeMM();

		CTAMDCoordinate* getTubeDeg();

		CTAMDPixelType* getPixelType();
	};
}
#endif
