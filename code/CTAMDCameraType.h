#ifndef _CTAMDCAMERATYPE_H
#define _CTAMDCAMERATYPE_H

#include <vector>
#include <string>
#include "CTAMDPixel.h"
#include <stdlib.h>

using namespace std;

namespace CTAConfig {
	class CTAMDCameraType {

	private:
		float cameraScaleFactor;
		float cameraCentreOffset;
		float cameraRotation;
		int camTypeID;
		string camTypeName;
		

	public:
		
		CTAMDCameraType(int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation);
		
		void addPixel(CTAMDPixel* pixel);
		
		int getID();
		
		string getName();
		
		float getCameraScaleFactor();

		float getCameraCentreOffset();

		float getCameraRotation();

		int16_t getNpixels();
		
		CTAMDPixel* getPixel(int16_t pixelID);
		
		
	public:
		
		vector<CTAMDPixel*> pixels;

	};
}
#endif
