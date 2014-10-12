#ifndef _CTAMDCOORDINATE_H
#define _CTAMDCOORDINATE_H

namespace CTAConfig {
	
	class CTAMDCoordinate2D {

	public:
		float x;
		float y;
		
		CTAMDCoordinate2D(float x, float y) {
			this->x = x;
			this->y = y;
		}
		
	};
	
	class CTAMDCoordinate3D {
		
	public:
		float x;
		float y;
		float z;
		
		CTAMDCoordinate3D(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		
	};


}
#endif