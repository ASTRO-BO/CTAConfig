#ifndef _CTAMDCAMERA_H
#define _CTAMDCAMERA_H

#include "CTAMDTelescopeType.h"
#include <stdlib.h>
#include <string>

using namespace std;

namespace CTAConfig {
	
	class CTAMDCamera {

	private:
		string name;
		vector<int16_t> pixelStatus;
		CTAMDTelescopeType* telescopeType;

	public:
		
		CTAMDCamera(string name, CTAMDTelescopeType* telescopeType);
		
		string getName();
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(int16_t status);
		
		CTAMDCameraType* getCameraType();
	};
}

#endif

