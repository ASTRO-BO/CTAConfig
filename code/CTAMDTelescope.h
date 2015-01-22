/***************************************************************************
 CTAMDTelescope.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CTAMDTELESCOPE_H
#define _CTAMDTELESCOPE_H
#include "CTAMDCoordinate.h"
#include "CTAMDTelescopeType.h"
#include "CTAMDCamera.h"
#include <string>

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
		
		std::string name;

	public:
		
		CTAMDTelescope(int ID, std::string name, CTAMDCoordinate3D* position, CTAMDTelescopeType* telescopeType, CTAMDCamera* camera);
		
		int getID();
		
		std::string getName();

		CTAMDTelescopeType* getTelescopeType();

		CTAMDCoordinate3D* getPosition();
		
		CTAMDCamera* getCamera();
	};
}
#endif
