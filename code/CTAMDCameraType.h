/***************************************************************************
 CTAMDCameraType.h
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

#ifndef _CTAMDCAMERATYPE_H
#define _CTAMDCAMERATYPE_H

#include <vector>
#include <string>
#include "CTAMDPixel.h"
#include <stdlib.h>

using namespace std;

namespace CTAConfig {
	class CTAMDCameraType {

	private:
		float cameraScaleFactor;
		float cameraCentreOffset;
		float cameraRotation;
		int camTypeID;
		string camTypeName;
		

	public:
		
		CTAMDCameraType(int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation);
		
		void addPixel(CTAMDPixel* pixel);
		
		int getID();
		
		string getName();
		
		float getCameraScaleFactor();

		float getCameraCentreOffset();

		float getCameraRotation();

		int16_t getNpixels();
		
		CTAMDPixel* getPixel(int16_t pixelID);
		
		uint16_t loadGeometryLUT(string filename);
		
		/// -1 the pixel is not part of the geometry
		/// -2 out of index
		int16_t getGeometryLUTValue(int16_t row, int16_t col);
		
		int16_t getGeometryLUT_Nrows();
		
		int16_t getGeometryLUT_Ncols();
		
		
	public:
		
		vector<CTAMDPixel*> pixels;
		
		int16_t* lut;
		
		int16_t lut_row;
		
		int16_t lut_col;

	};
}
#endif
