#ifndef _CTAMDTelescopeType_H
#define _CTAMDTelescopeType_H

#include <string>
#include <vector>
#include "CTAMDCameraType.h"
#include "CTAMDMirrorType.h"

using namespace std;
/**
 * The telescope type
 */
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

#endif