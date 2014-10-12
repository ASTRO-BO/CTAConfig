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
