#ifndef _CTAMDMirrorType_H
#define _CTAMDMirrorType_H

/**
 * Telescope Mirror Tyoe
 */
class CTAMDMirrorType {

private:
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
	float getFocalLength();

	float getFOV();

	int getNMirrors();

	float getMirrorArea();
};

#endif