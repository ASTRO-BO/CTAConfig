#include "CTAMDTelescope.h"


CTAConfig::CTAMDTelescope::CTAMDTelescope(int ID, CTAMDCoordinate3D* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera) {
	this->ID = ID;
	this->position = position;
	this->telescopeType = telescopeType;
	this->camera = camera;
}



int CTAConfig::CTAMDTelescope::getTelescopeID() {
	return ID;
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