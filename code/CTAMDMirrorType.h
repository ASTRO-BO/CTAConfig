/***************************************************************************
 CTAMDMirrorType.h
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

#ifndef _CTAMDMIRRORTYPE_H
#define _CTAMDMIRRORTYPE_H

#include <string>

namespace CTAConfig {
	/**
	 * Telescope Mirror Tyoe
	 */
	class CTAMDMirrorType {

	private:
		
		int16_t ID;
		
		std::string name;
		
		/**
		 * FITS::FL
		 */
		float FocalLength;
		/**
		 * FITS::FOV
		 */
		float FOV;
		/**
		 * FITS::NMirrors
		 */
		int nMirrors;
		/**
		 * FITS::MirrorArea
		 */
		float MirrorArea;

	public:
		
		CTAMDMirrorType(int16_t ID, std::string name, float FocalLength, float FOV, int nMirrors, float MirrorArea);
		
		float getFocalLength();

		float getFOV();

		int getNMirrors();

		float getMirrorArea();
		
		std::string getName();
		
		int16_t getID();
	};
}
#endif
