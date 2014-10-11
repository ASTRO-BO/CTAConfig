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
		vector<CTAMDTelescope*> telescopes;
		qlbase::InputFileFITS conf_file;

	public:
		string getArrayConfigName();

		void setArrayConfigName(string arrayConfigName);

		CTAMDTelescope* getTelescope(int telID);

		/**
		 * Load Monte Carlo CTA Array Configuration
		 */
		void loadConfig(string filename, string arrayName);

		string getName();
	};
}
#endif
