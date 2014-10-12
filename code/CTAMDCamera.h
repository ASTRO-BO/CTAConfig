#ifndef _CTAMDCAMERA_H
#define _CTAMDCAMERA_H

#include "CTAMDTelescopeType.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

namespace CTAConfig {
	
	class CTAMDCamera {

	private:
		string name;
		//0 active, 2 off
		vector<int16_t> pixelStatus;
		vector<uint16_t> pixelID;
		CTAMDTelescopeType* telescopeType;
		bool linear;

	public:
		
		CTAMDCamera(string name, CTAMDTelescopeType* telescopeType);
		
		string getName();
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(uint16_t pixelID, int16_t status);
		
		CTAMDCameraType* getCameraType();
		
		uint16_t getNPixelsActive();
	};
}

#endif

