#ifndef _CTAMDCOORDINATE_H
#define _CTAMDCOORDINATE_H

namespace CTAConfig {
	
	class CTAMDCoordinate {

	public:
		float x;
		float y;
		
		CTAMDCoordinate(float x, float y) {
			this->x = x;
			this->y = y;
		}
		
	};

}
#endif