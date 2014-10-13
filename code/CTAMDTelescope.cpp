/***************************************************************************
 CTAMDTelescope.cpp
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

#include "CTAMDTelescope.h"


CTAConfig::CTAMDTelescope::CTAMDTelescope(int ID, string name, CTAMDCoordinate3D* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera) {
	this->ID = ID;
	this->position = position;
	this->telescopeType = telescopeType;
	this->camera = camera;
	this->name = name;
}



int CTAConfig::CTAMDTelescope::getID() {
	return ID;
}

string CTAConfig::CTAMDTelescope::getName() {
	return name;
}

CTAConfig::CTAMDTelescopeType* CTAConfig::CTAMDTelescope::getTelescopeType() {
	return telescopeType;
}

CTAConfig::CTAMDCoordinate3D* CTAConfig::CTAMDTelescope::getPosition() {
	return this->position;
}

CTAConfig::CTAMDCamera* CTAConfig::CTAMDTelescope::getCamera() {
	return camera;
}