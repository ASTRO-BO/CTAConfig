#include "CTAMDTelescope.h"





int CTAConfig::CTAMDTelescope::getTelescopeID() {
	return ID;
}

CTAConfig::CTAMDTelescopeType* CTAConfig::CTAMDTelescope::getTelescopeType() {
	return telescopeType;
}

CTAConfig::CTAMDCoordinate* CTAConfig::CTAMDTelescope::getCoordinate() {
	return this->coordinate;
}

CTAConfig::CTAMDCamera* CTAConfig::CTAMDTelescope::getCamera() {
	return camera;
}