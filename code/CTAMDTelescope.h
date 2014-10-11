#ifndef _CTAMDTELESCOPE_H
#define _CTAMDTELESCOPE_H
#include "CTAMDCoordinate.h"
#include "CTAMDTelescopeType.h"
#include <stdlib.h>

namespace CTAConfig {
	
	/**
	 * The status of a telescope of the CTA Array
	 */
	class CTAMDTelescopeStatus {
	
	private:
		///Pixel status: 0 off, 1 on
		/// FITS: tubeOFF
		vector<int16_t> pixelStatus;
		
	public:
		
		int16_t getPixelStatus(uint16_t pixelID);
		
		void addPixelStatus(int16_t status);
	};
	
	
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
		CTAMDTelescopeStatus* telescopeStatus;

	public:
		int getTelescopeID();

		CTAMDTelescopeType* getTelescopeType();

		CTAMDCoordinate* getCoordinate();
		
		CTAMDTelescopeStatus* getTelescopeStatus();
	};
}
#endif