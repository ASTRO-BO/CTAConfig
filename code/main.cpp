/***************************************************************************
 main.cpp  -  description
 -------------------
 copyright            : (C) 2013 Andrea Bulgarelli
 2013 Andrea Zoli
 2014 Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it
 zoli@iasfbo.inaf.it
 fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#define PRINTALG 1

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

#include "ConfigLoadMCFITS.h"
#include "CTAMDArray.h"

using namespace std;
using namespace CTAConfig;

int main(int argc, char *argv[])
{
	ConfigLoadMCFITS config("./conf/PROD2_telconfig.fits.gz");
	cout << config.array.NTel << endl;
	cout << config.telescopes.size() << endl;
	cout << config.telescopeTypes.size() << endl;
	cout << config.cameraTypes.size() << endl;
	cout << config.pixelTypes.size() << endl;
	cout << config.pixels[0].size() << endl;
	
	CTAMDArray array;
	
	array.loadConfig("AARPROD2", "./conf/PROD2_telconfig.fits.gz", "");
	
	for(int i=0; i<array.telescopeTypes.size(); i++) {
		cout << array.telescopeTypes[i]->getTelescopeTypeID() << endl;
		cout << array.telescopeTypes[i]->getCameraType()->getNpixels() << endl;
		cout << array.telescopeTypes[i]->getMirrorType()->getMirrorArea() << endl;
		cout << array.telescopeTypes[i]->getCameraType()->pixels[0]->getPixelType()->getNSamples() << endl;
	}
}