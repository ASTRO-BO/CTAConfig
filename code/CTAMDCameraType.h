#ifndef _CTAMDCAMERATYPE_H
#define _CTAMDCAMERATYPE_H

#include <vector>
#include <string>
#include "CTAMDPixel.h"

using namespace std;

namespace CTAConfig {
	class CTAMDCameraType {

	private:
		float cameraScaleFactor;
		float cameraCentreOffset;
		float cameraRotation;
		
		vector<CTAMDPixel*> pixels;
		int camTypeID;
		string camTypeName;
		

	public:
		
		CTAMDCameraType(int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation);
		
		void addPixel(CTAMDPixel* pixel);
		
		int getCamTypeID();
		
		string getCamTypeName();
		
		float getCameraScaleFactor();

		float getCameraCentreOffset();

		float getCameraRotation();

		int16_t getNpixels();

	};
}
#endif
