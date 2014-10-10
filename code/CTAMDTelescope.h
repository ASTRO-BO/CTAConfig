#ifndef _CTAMDTelescope_H
#define _CTAMDTelescope_H
#include "CTAMDCoordinate.h"
#include "CTAMDTelescopeType.h"

/**
 * A telescope of the CTA Array
 */
class CTAMDTelescope {

private:
	/**
	 * FITS::TelID
	 */
	int ID;
	/**
	 * FITS::TelX, FITS::TelY, FITS::TelZ
	 */
	CTAMDCoordinate* coordinate;
	CTAMDTelescopeType* telescopeType;

public:
	int getTelescopeID();

	CTAMDTelescopeType* getTelescopeType();

	CTAMDCoordinate* getCoordinate();
};
#endif