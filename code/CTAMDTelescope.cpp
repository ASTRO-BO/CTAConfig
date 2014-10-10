#include "CTAMDTelescope.h"

int CTAMDTelescope::getTelescopeID() {
	return ID;
}

CTAMDTelescopeType* CTAMDTelescope::getTelescopeType() {
	return telescopeType;
}

CTAMDCoordinate* CTAMDTelescope::getCoordinate() {
	return this->coordinate;
}
