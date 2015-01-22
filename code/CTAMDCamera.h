/***************************************************************************
 CTAMDCamera.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CTAMDCAMERA_H
#define _CTAMDCAMERA_H

#include "CTAMDTelescopeType.h"
#include <stdlib.h>
#include <string>
#include <iostream>

namespace CTAConfig {
	
	class CTAMDCamera {

	private:
		std::string name;
		//0 active, 2 off
		std::vector<int16_t> pixelStatus;
		std::vector<uint16_t> pixelID;
		CTAMDTelescopeType* telescopeType;
		bool linear;

	public:
		
		CTAMDCamera(std::string name, CTAMDTelescopeType* telescopeType);
		
		std::string getName();
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(uint16_t pixelID, int16_t status);
		
		CTAMDCameraType* getCameraType();
		
		uint16_t getNPixelsActive();
	};
}

#endif

