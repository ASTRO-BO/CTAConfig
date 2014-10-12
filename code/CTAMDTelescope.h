#ifndef _CTAMDTELESCOPE_H
#define _CTAMDTELESCOPE_H
#include "CTAMDCoordinate.h"
#include "CTAMDTelescopeType.h"
#include "CTAMDCamera.h"
#include <stdlib.h>

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
		CTAMDCoordinate* position;
		CTAMDTelescopeType* telescopeType;
		CTAMDCamera* camera;

	public:
		
		CTAMDTelescope(CTAMDCoordinate* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera);
		
		int getTelescopeID();

		CTAMDTelescopeType* getTelescopeType();

		CTAMDCoordinate* getPosition();
		
		CTAMDCamera* getCamera();
	};
}
#endif