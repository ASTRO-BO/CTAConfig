#ifndef _CTAMDPIXEL_H
#define _CTAMDPIXEL_H

#include "CTAMDCoordinate.h"
#include "CTAMDPixelType.h"

namespace CTAConfig {
	
	class CTAMDPixel {

	private:
		short ID;
		CTAMDCoordinate* tubeMM;
		CTAMDCoordinate* tubeDeg;
		short tubeOFF;
		CTAMDPixelType* pixelType;

	public:
		short getID();

		CTAMDCoordinate* getTubeMM();

		CTAMDCoordinate* getTubeDeg();

		short getTubeOFF();

		CTAMDPixelType* getPixelType();
	};
}
#endif
