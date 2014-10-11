#ifndef _CTAMDTELESCOPE_H
#define _CTAMDTELESCOPE_H
#include "CTAMDCoordinate.h"
#include "CTAMDTelescopeType.h"

namespace CTAConfig {
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
}
#endif