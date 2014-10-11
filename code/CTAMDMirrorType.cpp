#include "CTAMDMirrorType.h"

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
