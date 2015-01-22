/***************************************************************************
 CTAMDCameraType.cpp
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "CTAMDCameraType.h"
#include <ctautils/InputFileFITS.h>
#include <iostream>

using namespace std;

namespace CTAConfig {

#define L0HEADER 1

CTAMDCameraType::CTAMDCameraType(int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation) {
	this->camTypeID = camTypeID;
	this->camTypeName = camTypeName;
	this->cameraScaleFactor = cameraScaleFactor;
	this->cameraCentreOffset = cameraCentreOffset;
	this->cameraRotation = cameraRotation;
}

void CTAMDCameraType::addPixel(CTAMDPixel* pixel) {
	pixels.push_back(pixel);
}

int CTAMDCameraType::getID() {
	return this->camTypeID;
}

string CTAMDCameraType::getName() {
	return this->camTypeName;
}

float CTAMDCameraType::getCameraScaleFactor() {
	return this->cameraScaleFactor;
}

float CTAMDCameraType::getCameraCentreOffset() {
	return this->cameraCentreOffset;
}

float CTAMDCameraType::getCameraRotation() {
	return this->cameraRotation;
}



short CTAMDCameraType::getNpixels() {
	return this->pixels.size();
}


CTAMDPixel* CTAMDCameraType::getPixel(int16_t pixelID) {
	for(unsigned int i=0; i<pixels.size(); i++) {
		if(pixels[i]->getID() == pixelID)
			return pixels[i];
	}
	return 0;
}

CTAHexagonalPointyTopOddRowGridMap* CTAMDCameraType::getMap() {
	return map;
}

uint16_t CTAMDCameraType::loadGeometryLUT(string fn) {
	CTAUtils::InputFileFITS conf_file;
	
	string filename = fn;
	
	try {
		
		if (filename != "") {
			/// open FITS file
			conf_file.open(filename);
			//conf_Nheader = conf_file.getHeadersNum();
			//cout << "Number of headers: " << conf_Nheader << endl;
			
			/// Moving to the Telescope level Header L0
			conf_file.moveToHeader(L0HEADER);
			
			/// Loading the number of rows
			int conf_Nrows_L0 = conf_file.getNRows();
			
			/// Loading the data
			int row_colnum = conf_file.getColNum("ROW");
			int col_colnum = conf_file.getColNum("COLUMN");
			int pix_colnum = conf_file.getColNum("PixelID");
			
			row = conf_file.read16u(row_colnum, 0, conf_Nrows_L0-1);
			col = conf_file.read16u(col_colnum, 0, conf_Nrows_L0-1);
			pix = conf_file.read16i(pix_colnum, 0, conf_Nrows_L0-1);
			
			conf_file.close();
		}
		//cout << row.size() << " " << col.size() << " " << pix.size() << endl;
		
		//build the lut
		//get row max
		int16_t maxrow=0;
		for(unsigned int i=0; i<row.size(); i++) {
			if(row[i] > maxrow)
				maxrow = row[i];
		}
		//cout << maxrow << endl;
		lutOffset_row = maxrow + 1;
		//get row max
		int16_t maxcol=0;
		for(unsigned int i=0; i<col.size(); i++) {
			if(col[i] > maxcol)
				maxcol = col[i];
		}
		//cout << maxcol << endl;
		lutOffset_col = maxcol + 1;
		lutOffset = (int16_t*) new int16_t[lutOffset_row * lutOffset_col];
		for(unsigned int ir=0; ir < row.size(); ir++) {
			int16_t rowindex = row[ir];
			int16_t colindex = col[ir];
			//cout << rowindex << " " << colindex << endl;
			lutOffset[rowindex * lutOffset_col + colindex] = pix[ir];
			//cout << rowindex << " " << colindex << " " << lutOffset[rowindex * lutOffset_col + colindex] << endl;
		}
		
		
	}
	catch (CTAUtils::IOException& e) {
		cout << "ERROR: File "<< filename <<" does not exist. Error code: " << e.getErrorCode() << endl;
	}
	
	//load Grid Map
	map = new CTAHexagonalPointyTopOddRowGridMap(row.size(), &row[0], &col[0], &pix[0], 1);
	map->fillLUT();
	
	return 0;
}

int16_t CTAMDCameraType::getGeometryLUTOffsetValue(int16_t row, int16_t col) {
	if(row > lutOffset_row)
		return -2;
	if(col > lutOffset_col)
		return -2;
	return lutOffset[row * lutOffset_col + col];
}

uint16_t CTAMDCameraType::getGeometryLUTOffset_Nrows() {
	return lutOffset_row;
}

uint16_t CTAMDCameraType::getGeometryLUTOffset_Ncols() {
	return lutOffset_col;
}

}
