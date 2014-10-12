#include "CTAMDArray.h"
#include "ConfigLoadMCFITS.h"


string CTAConfig::CTAMDArray::getArrayConfigName() {
	return this->arrayConfigName;
}

void CTAConfig::CTAMDArray::setArrayConfigName(string arrayConfigName) {
	this->arrayConfigName = arrayConfigName;
}

CTAConfig::CTAMDTelescope* CTAConfig::CTAMDArray::getTelescope(int telID) {
	for(int i=0; i<telescopes.size(); i++) {
		if(telescopes[i]->getTelescopeID() == telID)
			return telescopes[i];
	}
	return 0;
}

CTAConfig::CTAMDTelescopeType* CTAConfig::CTAMDArray::getTelescopeType(int64_t telTypeID) {
	for(int i=0; i<telescopeTypes.size(); i++) {
		if(telescopeTypes[i]->getTelescopeTypeID() == telTypeID)
			return telescopeTypes[i];
	}
	return 0;
}


void CTAConfig::CTAMDArray::loadConfig(string arrayName, string filenameArray, string filenameAdditionalInfos) {
	cout << "Load config" <<endl;
	ConfigLoadMCFITS config(arrayFilename);
	this->arrayConfigName = arrayName;
	
	

	for(int i=0; i<config.telescopeTypes.size(); i++) {
		
		//FocalLength, float FOV, int nMirrors, float MirrorArea
		
		struct CTAConfig::ConfigLoadMCFITS::MirrorType *mirr = config.getMirrorType(config.telescopeTypes[i].mirrorType.mirType);
		
		CTAMDMirrorType* mirrorType = new CTAMDMirrorType(mirr->mirType, "NONAME", mirr->FL, mirr->FOV, mirr->NMirrors, mirr->MirrorArea);
		
		//int camTypeID, string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation
		struct CTAConfig::ConfigLoadMCFITS::CameraType* cam = config.getCameraType(config.telescopeTypes[i].cameraType.camType);
		
		
		CTAMDCameraType* cameraType  = new CTAMDCameraType(cam->camType, "NONAME", cam->CameraScaleFactor, cam->CameraCentreOffset, cam->CameraRotation);
		/*
		cout << "CAM " << cam->camType << endl;
		cout << cam->pixels.size() << endl;
		cout << cam->NPixel << endl;
		cout << "pixtype " << cam->pixelType.pixType << endl;
		*/
		struct CTAConfig::ConfigLoadMCFITS::PixelType* pixtyp = config.getPixelType(cam->pixelType.pixType);
		//cout << "samp " << pixtyp->NSamples << endl;
		
		//int16_t pixTypeID, int16_t nSamples, float sampleTimeSlice, int16_t NGains, float hiLoScale, int16_t hiLoThreshold,float hiLoOffset
		CTAMDPixelType* pixelType = new CTAMDPixelType(pixtyp->pixType, pixtyp->NSamples, pixtyp->Sample_time_slice, pixtyp->NGains, pixtyp->HiLoScale, pixtyp->HiLoThreshold, pixtyp->HiLoOffset);
		
		
		
		//build the list of pixels of the camera type
		for(int pi=0; pi<cam->NPixel; pi++) {
		
			struct CTAConfig::ConfigLoadMCFITS::Pixel* pix =  config.getPixel(cam->camType, pi);
			//cout << pix->PixelID << " ";
			if(pix != 0) {
				CTAMDCoordinate* pos = new CTAMDCoordinate(pix->XTubeMM, pix->YTubeMM);
				CTAMDCoordinate* rot = new CTAMDCoordinate(pix->XTubeDeg, pix->YTubeDeg);
				CTAMDPixel * pixel = new CTAMDPixel(pix->PixelID, pos, pix->RTubeMM, rot, pix->RTubeDeg, pixelType);
			
				cameraType->addPixel(pixel);
			}
			//cout << endl;
		}
		
		//build the telescope type
		CTAMDTelescopeType* telescopeType = new CTAMDTelescopeType(config.telescopeTypes[i].TelType, "NONAME", cameraType, mirrorType, i);
		
		telescopeTypes.push_back(telescopeType);
	}
	
	cout << "End load config" <<endl;
}

string CTAConfig::CTAMDArray::getName() {
	return this->name;
}
