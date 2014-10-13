/***************************************************************************
 CTAMDCoordinate.h
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

#ifndef _CTAMDCOORDINATE_H
#define _CTAMDCOORDINATE_H

namespace CTAConfig {
	
	class CTAMDCoordinate2D {

	public:
		float x;
		float y;
		
		CTAMDCoordinate2D(float x, float y) {
			this->x = x;
			this->y = y;
		}
		
	};
	
	class CTAMDCoordinate3D {
		
	public:
		float x;
		float y;
		float z;
		
		CTAMDCoordinate3D(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		
	};


}
#endif