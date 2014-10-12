#ifndef _CTAMDPIXEL_H
#define _CTAMDPIXEL_H

#include "CTAMDCoordinate.h"
#include "CTAMDPixelType.h"
#include <stdlib.h>

namespace CTAConfig {
	
	class CTAMDPixel {

	private:
		int16_t ID;
		CTAMDCoordinate2D* tubeMM;
		float RTubeMM;
		CTAMDCoordinate2D* tubeDeg;
		float RTubeDeg;
		CTAMDPixelType* pixelType;

	public:
		
		CTAMDPixel(int16_t pixelID, CTAMDCoordinate2D* tubeMM, float RTubeMM, CTAMDCoordinate2D* tubeDeg, float RTubeDeg, CTAMDPixelType* pixelType);
		
		int16_t getID();

		CTAMDCoordinate2D* getTubeMM();

		CTAMDCoordinate2D* getTubeDeg();

		CTAMDPixelType* getPixelType();
	};
}
#endif
