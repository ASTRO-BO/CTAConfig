#ifndef _CTAMDCAMERA_H
#define _CTAMDCAMERA_H

#include "CTAMDCameraType.h"
#include <stdlib.h>

namespace CTAConfig {
	
	class CTAMDCamera {

	private:
		string name;
		vector<int16_t> pixelStatus;

	public:
		string getName();
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(int16_t status);
	};
}

#endif

