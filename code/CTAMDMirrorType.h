#ifndef _CTAMDMIRRORTYPE_H
#define _CTAMDMIRRORTYPE_H

#include <stdlib.h>
#include <string>

using namespace std;

namespace CTAConfig {
	/**
	 * Telescope Mirror Tyoe
	 */
	class CTAMDMirrorType {

	private:
		
		int16_t ID;
		
		string name;
		
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
		
		CTAMDMirrorType(int16_t ID, string name, float FocalLength, float FOV, int nMirrors, float MirrorArea);
		
		float getFocalLength();

		float getFOV();

		int getNMirrors();

		float getMirrorArea();
		
		string getName();
		
		int16_t getID();
	};
}
#endif