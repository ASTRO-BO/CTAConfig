#ifndef _CTAMDARRAY_H
#define _CTAMDARRAY_H

#include <string>
#include "CTAMDTelescope.h"
#include <qlbase/InputFileFITS.h>

using namespace std;

namespace CTAConfig {
	/**
	 * A CTA Array Configuration
	 */
	class CTAMDArray {

	private:
		string arrayConfigName;
		string name;
		
		qlbase::InputFileFITS conf_file;

	public:
		string getArrayConfigName();

		void setArrayConfigName(string arrayConfigName);

		CTAMDTelescope* getTelescope(int telID);
		
		CTAMDTelescopeType* getTelescopeType(int64_t telTypeID);

		
		/// Load Monte Carlo CTA Array Configuration
		/// \param name the name of the array
		/// \filenameArray the name of the .fits file that contains the configuration of the array
		/// \filenameAdditionalInfos the name of the file that contains the following info: TELTYPEID TELTYPENAME CAMERATYPENAME MIRRORTYPENAME LOOKUP-TABLE-CONFIG-FILE
		void loadConfig(string arrayName, string filenameArray, string filenameAdditionalInfos);

		string getName();
		
	public:
		
		vector<CTAMDTelescope*> telescopes;
		vector<CTAMDTelescopeType*> telescopeTypes;
	};
}
#endif
