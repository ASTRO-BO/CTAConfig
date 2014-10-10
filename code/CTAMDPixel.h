#ifndef _CTAMDPixel_H
#define _CTAMDPixel_H

#include "CTAMDCoordinate.h"
#include "CTAMDPixelType.h"

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
#endif
