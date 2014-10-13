/***************************************************************************
 CTAMDMirrorType.cpp
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

#include "CTAMDMirrorType.h"

CTAConfig::CTAMDMirrorType::CTAMDMirrorType(int16_t ID, string name, float FocalLength, float FOV, int nMirrors, float MirrorArea) {
	this->ID = ID;
	this->name = name;
	this->FocalLength = FocalLength;
	this->FOV = FOV;
	this->nMirrors = nMirrors;
	this->MirrorArea = MirrorArea;
}

float CTAConfig::CTAMDMirrorType::getFocalLength() {
	return FocalLength;
}

float CTAConfig::CTAMDMirrorType::getFOV() {
	return FOV;
}

int CTAConfig::CTAMDMirrorType::getNMirrors() {
	return this->nMirrors;
}

float CTAConfig::CTAMDMirrorType::getMirrorArea() {
	return MirrorArea;
}

string CTAConfig::CTAMDMirrorType::getName() {
	return this->name;
}

int16_t CTAConfig::CTAMDMirrorType::getID() {
	return this->ID;
}