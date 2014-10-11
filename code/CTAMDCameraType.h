#ifndef _CTAMDCAMERATYPE_H
#define _CTAMDCAMERATYPE_H

#include <vector>
#include "CTAMDPixel.h"

using namespace std;

namespace CTAConfig {
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
}
#endif
