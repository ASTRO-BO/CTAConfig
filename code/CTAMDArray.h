#ifndef _CTAMDArray_H
#define _CTAMDArray_H

#include <string>
#include "CTAMDTelescope.h"

using namespace std;
/**
 * A CTA Array Configuration
 */
class CTAMDArray {

private:
	string arrayConfigName;
	string name;
	vector<CTAMDTelescope> telescopes;

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

#endif
