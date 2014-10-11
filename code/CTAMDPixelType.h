#ifndef _CTAMDPIXELTYPE_H
#define _CTAMDPIXELTYPE_H

namespace CTAConfig {
	
	class CTAMDPixelType {

	private:
		short nSamples;
		float sampleTimeSlice;
		short Ngains;
		float hiLoScale;
		short hiLoThreshold;
		float hiLoOffset;

	public:
		short getNSamples();

		float getSampleTimeSlice();

		short getNgains();

		float getHiLoScale();

		short getHiLoThreshold();

		float getHiLoOffset();
	};

}
#endif
