#include "CTAMDTelescope.h"


CTAConfig::CTAMDTelescope::CTAMDTelescope(CTAMDCoordinate* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera) {
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

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDTelescope::getPosition() {
	return this->position;
}

CTAConfig::CTAMDCamera* CTAConfig::CTAMDTelescope::getCamera() {
	return camera;
}