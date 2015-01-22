/***************************************************************************
 CTAMDArrray.cpp
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "CTAMDArray.h"
#include "ConfigLoadMCFITS.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

namespace CTAConfig {

void split(vector<string> &tokens, const string &text, char sep) {
	unsigned int start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
}



string CTAMDArray::getArrayConfigName() {
	return this->arrayConfigName;
}

void CTAMDArray::setArrayConfigName(string arrayConfigName) {
	this->arrayConfigName = arrayConfigName;
}

CTAMDTelescope* CTAMDArray::getTelescope(int telID) {
	for(unsigned int i=0; i<telescopes.size(); i++) {
		if(telescopes[i]->getID() == telID)
			return telescopes[i];
	}
	return 0;
}


void CTAMDArray::loadAdds(string filename)
{
	string s;
	ifstream infile;
	infile.open (filename.c_str());
	while(!infile.eof()) // To get you all the lines.
	{
		std::vector<std::string> tokensInput;
		getline(infile, s); // Saves the line
		//TELTYPEID TELTYPENAME CAMERATYPENAME MIRRORTYPENAME LOOKUP-TABLE-CONFIG-FILE
		if(s.size() != 0 && s.at(0) != '#')
		{
			split(tokensInput, s, ' ');
			configArray.push_back(tokensInput);
			for(unsigned int i=0; i<tokensInput.size(); i++)
			{
					cout << tokensInput[i] << " ";
			}
			cout << endl;
		}
	}
	infile.close();
}


CTAMDTelescopeType* CTAMDArray::getTelescopeType(int64_t telTypeID) {
	for(unsigned int i=0; i<telescopeTypes.size(); i++) {
		if(telescopeTypes[i]->getID() == telTypeID)
			return telescopeTypes[i];
	}
	return 0;
}


void CTAMDArray::loadConfig(string arrayName, string filenameArray, string filenameAdditionalInfos, string basedir) {
	cout << "Load config add infos" << endl;
	filenameAdditionalInfos = basedir + filenameAdditionalInfos;
	loadAdds(filenameAdditionalInfos);
	cout << "Load config" <<endl;
	filenameArray = basedir + filenameArray;
	ConfigLoadMCFITS config(filenameArray);
	this->arrayConfigName = arrayName;
	
	

	for(unsigned int i=0; i<config.telescopeTypes.size(); i++) {
		
		//get meta infos
		int64_t TelType = config.telescopeTypes[i].TelType;
		unsigned int tt;
		for(tt = 0; tt < configArray.size(); tt++) {
			int64_t teltypeid;
			stringstream(configArray[tt][0]) >> teltypeid;
			if(teltypeid == TelType)
				break;
		}
		
		
		
		//FocalLength, float FOV, int nMirrors, float MirrorArea
		
		ConfigLoadMCFITS::MirrorType *mirr = config.getMirrorType(config.telescopeTypes[i].mirrorType.mirType);
		
		CTAMDMirrorType* mirrorType = new CTAMDMirrorType(mirr->mirType, configArray[tt][3], mirr->FL, mirr->FOV, mirr->NMirrors, mirr->MirrorArea);
		
		//int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation
		ConfigLoadMCFITS::CameraType* cam = config.getCameraType(config.telescopeTypes[i].cameraType.camType);
		
		
		CTAMDCameraType* cameraType  = new CTAMDCameraType(cam->camType, configArray[tt][2], cam->CameraScaleFactor, cam->CameraCentreOffset, cam->CameraRotation);
		/*
		cout << "CAM " << cam->camType << endl;
		cout << cam->pixels.size() << endl;
		cout << cam->NPixel << endl;
		cout << "pixtype " << cam->pixelType.pixType << endl;
		*/
		ConfigLoadMCFITS::PixelType* pixtyp = config.getPixelType(cam->pixelType.pixType);
		//cout << "samp " << pixtyp->NSamples << endl;
		
		//int16_t pixTypeID, int16_t nSamples, float sampleTimeSlice, int16_t NGains, float hiLoScale, int16_t hiLoThreshold,float hiLoOffset
		CTAMDPixelType* pixelType = new CTAMDPixelType(pixtyp->pixType, pixtyp->NSamples, pixtyp->Sample_time_slice, pixtyp->NGains, pixtyp->HiLoScale, pixtyp->HiLoThreshold, pixtyp->HiLoOffset);
		
		
		
		//build the list of pixels of the camera type
		for(int pi=0; pi<cam->NPixel; pi++) {
		
			ConfigLoadMCFITS::Pixel* pix =  config.getPixel(cam->camType, pi);
			if(pix != 0) {
				CTAMDCoordinate2D* pos = new CTAMDCoordinate2D(pix->XTubeMM, pix->YTubeMM);
				CTAMDCoordinate2D* rot = new CTAMDCoordinate2D(pix->XTubeDeg, pix->YTubeDeg);
				CTAMDPixel * pixel = new CTAMDPixel(pix->PixelID, pos, pix->RTubeMM, rot, pix->RTubeDeg, pixelType);
				cameraType->addPixel(pixel);
			}
			//cout << endl;
		}
		
		//build the telescope type
		CTAMDTelescopeType* telescopeType = new CTAMDTelescopeType(config.telescopeTypes[i].TelType, configArray[tt][1], cameraType, mirrorType, i);
		string lutname = basedir + configArray[tt][4];
		telescopeType->getCameraType()->loadGeometryLUT(lutname);
		telescopeTypes.push_back(telescopeType);
	}
	
	for(unsigned int i=0; i<config.telescopes.size(); i++) {
		cout << config.telescopes[i].TelID << " " << config.telescopes[i].telescopeType.TelType << endl;
		
		CTAMDTelescopeType* telescopeType = getTelescopeType(config.telescopes[i].telescopeType.TelType);
		CTAMDCoordinate3D* pos = new CTAMDCoordinate3D(config.telescopes[i].TelX, config.telescopes[i].TelY, config.telescopes[i].TelZ);
		string camName = telescopeType->getCameraType()->getName();
		
		//TODO: formattare telName
		string telName = telescopeType->getName();
		
		//TODO formattare il nome della camera
		//camName += s;
		CTAMDCamera* camera = new CTAMDCamera(camName, telescopeType);
		//pixel status
		ConfigLoadMCFITS::CameraType* cam = config.getCameraType(telescopeType->getCameraType()->getID());
		for(int pi=0; pi<cam->NPixel; pi++) {
			ConfigLoadMCFITS::Pixel* pix = config.getPixel(cam->camType, pi);
			if(pix != 0) {
				camera->addPixelStatus(pix->PixelID, pix->TubeOFF);
			}
		}
		
		CTAMDTelescope* telescope = new CTAMDTelescope(config.telescopes[i].TelID, telName, pos, telescopeType, camera);
		telescopes.push_back(telescope);
		
	}
	
	
	
	
	cout << "End load config" <<endl;
}

string CTAMDArray::getName() {
	return this->name;
}

}
