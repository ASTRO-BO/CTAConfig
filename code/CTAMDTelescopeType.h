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
		long ID;
		string name;
		CTAMDCameraType* cameraType;
		CTAMDMirrorType* mirrorType;

	public:
		long getTelescopeTypeID();

		CTAMDCameraType* getCameraType();

		CTAMDMirrorType* getMirrorType();

		string getName();
	};

}
#endif