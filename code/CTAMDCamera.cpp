/***************************************************************************
 CTAMDCamera.cpp
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

#include "CTAMDCamera.h"

string CTAConfig::CTAMDCamera::getName() {
	return this->name;
}

int16_t CTAConfig::CTAMDCamera::getPixelStatus(uint16_t pixelID) {
	if(linear)
		return pixelStatus[pixelID];
	
	for(uint16_t i = 0; i<this->pixelID.size(); i++) {
		if(this->pixelID[i] == pixelID)
			return pixelStatus[i];
	}
	
	return 0;
}

void CTAConfig::CTAMDCamera::addPixelStatus(uint16_t ID, int16_t status) {
	//cout << ID << " " << status << endl;
	this->pixelStatus.push_back(status);
	this->pixelID.push_back(ID);
	if(linear && (uint16_t)this->pixelID.size() != ID + 1)
		linear = false;
		
}

CTAConfig::CTAMDCamera::CTAMDCamera(string name, CTAMDTelescopeType* telescopeType) {
	this->name = name;
	this->telescopeType = telescopeType;
	linear = true;
}

CTAConfig::CTAMDCameraType* CTAConfig::CTAMDCamera::getCameraType() {
	return telescopeType->getCameraType();
}

uint16_t CTAConfig::CTAMDCamera::getNPixelsActive() {
	uint16_t nactive = 0;
	for(uint16_t i = 0; i<this->pixelStatus.size(); i++) {
		if(pixelStatus[i] == 0)
			nactive++;
	}
	return nactive;
}
