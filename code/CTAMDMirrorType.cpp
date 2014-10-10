#include "CTAMDMirrorType.h"

float CTAMDMirrorType::getFocalLength() {
	return FocalLength;
}

float CTAMDMirrorType::getFOV() {
	return FOV;
}

int CTAMDMirrorType::getNMirrors() {
	return this->nMirrors;
}

float CTAMDMirrorType::getMirrorArea() {
	return MirrorArea;
}
