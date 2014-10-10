#ifndef _CTAMDCameraType_H
#define _CTAMDCameraType_H

#include <vector>
#include "CTAMDPixel.h"

using namespace std;

class CTAMDCameraType {

private:
	float cameraScaleFactor;
	float cameraCentreOffset;
	float cameraRotation;
	int NTubesOff;
	short npixels;
	short npixels_active;
	vector<CTAMDPixel> pixels;

public:
	float getCameraScaleFactor();

	float getCameraCentreOffset();

	float getCameraRotation();

	int getNTubesOff();

	short getNpixels();

	short getNpixels_active();
};

#endif
