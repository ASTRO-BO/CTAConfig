/***************************************************************************
 CTAMDTelescopeType.h
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

#ifndef _CTAMDTELESCOPETYPE_H
#define _CTAMDTELESCOPETYPE_H

#include <string>
#include <vector>
#include "CTAMDCameraType.h"
#include "CTAMDMirrorType.h"

using namespace std;
/**
 * The telescope type
 */

namespace CTAConfig {

	class CTAMDTelescopeType {

	private:
		/**
		 * FITS::TelType
		 */
		int64_t ID;
		int16_t internaleCounter;
		string name;
		CTAMDCameraType* cameraType;
		CTAMDMirrorType* mirrorType;

	public:
		
		CTAMDTelescopeType(int64_t ID, string name, CTAMDCameraType* cameraType, CTAMDMirrorType* mirrorType, uint16_t internaleCounter);
		
		int64_t getID();

		CTAMDCameraType* getCameraType();

		CTAMDMirrorType* getMirrorType();

		string getName();
	};

}
#endif