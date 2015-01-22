/***************************************************************************
 CTAMDTelescopeType.cpp
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "CTAMDTelescopeType.h"

using namespace std;

namespace CTAConfig {

CTAMDTelescopeType::CTAMDTelescopeType(int64_t ID, string name, CTAMDCameraType* cameraType, CTAMDMirrorType* mirrorType, uint16_t internaleCounter) {
	this->ID = ID;
	this->name = name;
	this->cameraType = cameraType;
	this->mirrorType = mirrorType;
	this->internaleCounter = internaleCounter;
}

int64_t CTAMDTelescopeType::getID() {
	return ID;
}

CTAMDCameraType* CTAMDTelescopeType::getCameraType() {
	return this->cameraType;
}

CTAMDMirrorType* CTAMDTelescopeType::getMirrorType() {
	return this->mirrorType;
}

string CTAMDTelescopeType::getName() {
	return this->name;
}

}
