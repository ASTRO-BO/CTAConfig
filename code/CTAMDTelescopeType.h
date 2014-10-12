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