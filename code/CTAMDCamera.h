#ifndef _CTAMDCAMERA_H
#define _CTAMDCAMERA_H

#include "CTAMDTelescopeType.h"
#include <stdlib.h>

namespace CTAConfig {
	
	class CTAMDCamera {

	private:
		string name;
		vector<int16_t> pixelStatus;
		CTAMDTelescopeType* telescopeType;

	public:
		
		CTAMDCamera(CTAMDTelescopeType* telescopeType);
		
		string getName();
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(int16_t status);
		
		CTAMDCameraType* getCameraType();
	};
}

#endif

