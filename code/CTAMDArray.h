/***************************************************************************
 CTAMDArray.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CTAMDARRAY_H
#define _CTAMDARRAY_H

#include <string>
#include "CTAMDTelescope.h"
#include <rtautils/InputFileFITS.h>

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
		
		///Array of strings that contain the following info: TELTYPEID TELTYPENAME CAMERATYPENAME MIRRORTYPENAME LOOKUP-TABLE-CONFIG-FILE
		std::vector < std::vector<std::string> > configArray;
		
	protected:
		
		void loadAdds(string filename);

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
