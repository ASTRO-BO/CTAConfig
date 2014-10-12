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
		CTAMDCoordinate3D* position;
		CTAMDTelescopeType* telescopeType;
		CTAMDCamera* camera;
		
		string name;

	public:
		
		CTAMDTelescope(int ID, string name, CTAMDCoordinate3D* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera);
		
		int getID();
		
		string getName();

		CTAMDTelescopeType* getTelescopeType();

		CTAMDCoordinate3D* getPosition();
		
		CTAMDCamera* getCamera();
	};
}
#endif