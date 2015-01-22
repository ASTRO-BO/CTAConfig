/***************************************************************************
 ConfigLoadMCFITS.cpp  -  description
 -------------------
 copyright            : (C) 2014 Valentina Fioretti
 email                : fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include <algorithm>

#include "ConfigLoadMCFITS.h"

#define CONF_L0HEADER 1
#define CONF_L1HEADER 2

using namespace std;

namespace CTAConfig {

ConfigLoadMCFITS::ConfigLoadMCFITS(const string& confInputFileName) {
	/// structure declaration
	PixelType temp_pixtype;
	Pixel temp_pixel;
	CameraType temp_camtype;
	MirrorType temp_mirtype;
	TelescopeType temp_teltype;
	Telescope temp_tel;
	
	/// FITS structure parameters definition
	//int conf_Nheader;
	int conf_Nrows_L0;
	int conf_Nrows_L1;
	
	/// Column number
	int L0ID_colnum;
	int TelID_colnum;
	int TelType_colnum;
	int TelX_colnum;
	int TelY_colnum;
	int TelZ_colnum;
	int FL_colnum;
	int FOV_colnum;
	int CameraScaleFactor_colnum;
	int CameraCentreOffset_colnum;
	int CameraRotation_colnum;
	int NPixel_colnum;
	int NPixel_active_colnum;
	int NSamples_colnum;
	int Sample_time_slice_colnum;
	int NGains_colnum;
	int HiLoScale_colnum;
	int HiLoThreshold_colnum;
	int HiLoOffset_colnum;
	int NTubesOFF_colnum;
	int NMirrors_colnum;
	int MirrorArea_colnum;
	
	int L1ID_colnum;
	int L0ID_L1_colnum;
	int PixelID_colnum;
	int XTubeMM_colnum;
	int YTubeMM_colnum;
	int RTubeMM_colnum;
	int XTubeDeg_colnum;
	int YTubeDeg_colnum;
	int RTubeDeg_colnum;
	int TubeOFF_colnum;
	
	/// Vector declaration
	vector<int64_t> vecL0ID;
	vector<int16_t> vecTelID;
	vector<int64_t> vecTelType;
	vector<float> vecTelX;
	vector<float> vecTelY;
	vector<float> vecTelZ;
	vector<float> vecFL;
	vector<float> vecFOV;
	vector<float> vecCameraScaleFactor;
	vector<float> vecCameraCentreOffset;
	vector<float> vecCameraRotation;
	vector<int16_t> vecNPixel;
	vector<int16_t> vecNPixel_active;
	vector<int16_t> vecNSamples;
	vector<float> vecSample_time_slice;
	vector<int16_t> vecNGains;
	vector<float> vecHiLoScale;
	vector<int16_t> vecHiLoThreshold;
	vector<float> vecHiLoOffset;
	vector<int16_t> vecNTubesOFF;
	vector<int16_t> vecNMirrors;
	vector<float> vecMirrorArea;
	
	vector<int64_t> vecL1ID;
	vector<int64_t> vecL0ID_L1;
	vector<int16_t> vecPixelID;
	vector<float> vecXTubeMM;
	vector<float> vecYTubeMM;
	vector<float> vecRTubeMM;
	vector<float> vecXTubeDeg;
	vector<float> vecYTubeDeg;
	vector<float> vecRTubeDeg;
	vector<int16_t> vecTubeOFF;
	
	/// Vectors for the identification of the telescope type metadata
	vector<int64_t> vecUniqueTelType;
	vector<float> vecUniqueMirrorArea;
	vector<float> vecUniqueFL;
	vector<float> vecUniqueFOV;
	vector<float> vecUniqueCameraScaleFactor;
	vector<float> vecUniqueCameraCentreOffset;
	vector<float> vecUniqueCameraRotation;
	vector<int16_t> vecUniqueNTubesOFF;
	vector<int16_t> vecUniqueNMirrors;
	vector<int16_t> vecUniqueNPixel;
	vector<int16_t> vecUniqueNPixel_active;
	vector<int16_t> vecUniqueNSamples;
	vector<float> vecUniqueSample_time_slice;
	vector<int16_t> vecUniqueNGains;
	vector<float> vecUniqueHiLoScale;
	vector<int16_t> vecUniqueHiLoThreshold;
	vector<float> vecUniqueHiLoOffset;
	vector<int16_t> vecUniquePixelID;
	vector<float> vecUniqueXTubeMM;
	vector<float> vecUniqueYTubeMM;
	vector<float> vecUniqueRTubeMM;
	vector<float> vecUniqueXTubeDeg;
	vector<float> vecUniqueYTubeDeg;
	vector<float> vecUniqueRTubeDeg;
	vector<int16_t> vecUniqueTubeOFF;

	try {
		
		
		if (confInputFileName != "") {
			/// open FITS file
			conf_file.open(confInputFileName);
			//conf_Nheader = conf_file.getHeadersNum();
            //cout << "Number of headers: " << conf_Nheader << endl;
			
			
            /// Moving to the Telescope level Header L0
            conf_file.moveToHeader(CONF_L0HEADER);
			
            /// Loading the number of rows
            conf_Nrows_L0 = conf_file.getNRows();
			
            /// Loading the data
            L0ID_colnum = conf_file.getColNum("L0ID");
            TelID_colnum = conf_file.getColNum("TelID");
            TelType_colnum = conf_file.getColNum("TelType");
            TelX_colnum = conf_file.getColNum("TelX");
            TelY_colnum = conf_file.getColNum("TelY");
            TelZ_colnum = conf_file.getColNum("TelZ");
            FL_colnum = conf_file.getColNum("FL");
            FOV_colnum = conf_file.getColNum("FOV");
            CameraScaleFactor_colnum = conf_file.getColNum("CameraScaleFactor");
            CameraCentreOffset_colnum = conf_file.getColNum("CameraCentreOffset");
            CameraRotation_colnum = conf_file.getColNum("CameraRotation");
            NPixel_colnum = conf_file.getColNum("NPixel");
            NPixel_active_colnum = conf_file.getColNum("NPixel_active");
            NSamples_colnum = conf_file.getColNum("NSamples");
            Sample_time_slice_colnum = conf_file.getColNum("Sample_time_slice");
            NGains_colnum = conf_file.getColNum("NGains");
            HiLoScale_colnum = conf_file.getColNum("HiLoScale");
            HiLoThreshold_colnum = conf_file.getColNum("HiLoThreshold");
            HiLoOffset_colnum = conf_file.getColNum("HiLoOffset");
            NTubesOFF_colnum = conf_file.getColNum("NTubesOFF");
            NMirrors_colnum = conf_file.getColNum("NMirrors");
            MirrorArea_colnum = conf_file.getColNum("MirrorArea");
            
			vecL0ID = conf_file.read64i(L0ID_colnum, 0, conf_Nrows_L0-1);
			vecTelID = conf_file.read16i(TelID_colnum, 0, conf_Nrows_L0-1);
			vecTelType = conf_file.read64i(TelType_colnum, 0, conf_Nrows_L0-1);
			vecTelX = conf_file.read32f(TelX_colnum, 0, conf_Nrows_L0-1);
			vecTelY = conf_file.read32f(TelY_colnum, 0, conf_Nrows_L0-1);
			vecTelZ = conf_file.read32f(TelZ_colnum, 0, conf_Nrows_L0-1);
			vecFL = conf_file.read32f(FL_colnum, 0, conf_Nrows_L0-1);
			vecFOV = conf_file.read32f(FOV_colnum, 0, conf_Nrows_L0-1);
			vecCameraScaleFactor = conf_file.read32f(CameraScaleFactor_colnum, 0, conf_Nrows_L0-1);
			vecCameraCentreOffset = conf_file.read32f(CameraCentreOffset_colnum, 0, conf_Nrows_L0-1);
			vecCameraRotation = conf_file.read32f(CameraRotation_colnum, 0, conf_Nrows_L0-1);
			vecNPixel = conf_file.read16i(NPixel_colnum, 0, conf_Nrows_L0-1);
			vecNPixel_active = conf_file.read16i(NPixel_active_colnum, 0, conf_Nrows_L0-1);
			vecNSamples = conf_file.read16i(NSamples_colnum, 0, conf_Nrows_L0-1);
			vecSample_time_slice = conf_file.read32f(Sample_time_slice_colnum, 0, conf_Nrows_L0-1);
			vecNGains = conf_file.read16i(NGains_colnum, 0, conf_Nrows_L0-1);
			vecHiLoScale = conf_file.read32f(HiLoScale_colnum, 0, conf_Nrows_L0-1);
			vecHiLoThreshold = conf_file.read16i(HiLoThreshold_colnum, 0, conf_Nrows_L0-1);
			vecHiLoOffset = conf_file.read32f(HiLoOffset_colnum, 0, conf_Nrows_L0-1);
			vecNTubesOFF = conf_file.read16i(NTubesOFF_colnum, 0, conf_Nrows_L0-1);
			vecNMirrors = conf_file.read16i(NMirrors_colnum, 0, conf_Nrows_L0-1);
			vecMirrorArea = conf_file.read32f(MirrorArea_colnum, 0, conf_Nrows_L0-1);
			
			/// Moving to the Pixel level Header L1
			conf_file.moveToHeader(CONF_L1HEADER);
            
			/// Loading the number of rows
			conf_Nrows_L1 = conf_file.getNRows();
            
			/// Loading the data
			L1ID_colnum = conf_file.getColNum("L1ID");
			L0ID_L1_colnum = conf_file.getColNum("L0ID");
			PixelID_colnum = conf_file.getColNum("PixelID");
			XTubeMM_colnum = conf_file.getColNum("XTubeMM");
			YTubeMM_colnum = conf_file.getColNum("YTubeMM");
			RTubeMM_colnum = conf_file.getColNum("RTubeMM");
			XTubeDeg_colnum = conf_file.getColNum("XTubeDeg");
			YTubeDeg_colnum = conf_file.getColNum("YTubeDeg");
			RTubeDeg_colnum = conf_file.getColNum("RTubeDeg");
			TubeOFF_colnum = conf_file.getColNum("TubeOFF");
            
			vecL1ID = conf_file.read64i(L1ID_colnum, 0, conf_Nrows_L1-1);
			vecL0ID_L1 = conf_file.read64i(L0ID_L1_colnum, 0, conf_Nrows_L1-1);
			vecPixelID = conf_file.read16i(PixelID_colnum, 0, conf_Nrows_L1-1);
			vecXTubeMM = conf_file.read32f(XTubeMM_colnum, 0, conf_Nrows_L1-1);
			vecYTubeMM = conf_file.read32f(YTubeMM_colnum, 0, conf_Nrows_L1-1);
			vecRTubeMM = conf_file.read32f(RTubeMM_colnum, 0, conf_Nrows_L1-1);
			vecXTubeDeg = conf_file.read32f(XTubeDeg_colnum, 0, conf_Nrows_L1-1);
			vecYTubeDeg = conf_file.read32f(YTubeDeg_colnum, 0, conf_Nrows_L1-1);
			vecRTubeDeg = conf_file.read32f(RTubeDeg_colnum, 0, conf_Nrows_L1-1);
			vecTubeOFF = conf_file.read16i(TubeOFF_colnum, 0, conf_Nrows_L1-1);
            
			
			/// Setting the dummy array
			array.ArrayID = 1;
			array.NTel = conf_Nrows_L0;
			array.vecTelID = vecTelID;

			/// Setting the Telescope structure objects
			for(int i=0; i<array.NTel; i++) {
				temp_tel.TelID = vecTelID[i];
				temp_tel.telescopeType.TelType = vecTelType[i];
				temp_tel.TelX = vecTelX[i];
				temp_tel.TelY = vecTelY[i];
				temp_tel.TelZ = vecTelZ[i];
				telescopes.push_back(temp_tel);
			}
			
			/// Setting the TelescopeType structure
			
			vecUniqueMirrorArea = vecMirrorArea;
			sort( vecUniqueMirrorArea.begin(), vecUniqueMirrorArea.end() );
			vecUniqueMirrorArea.erase( unique( vecUniqueMirrorArea.begin(), vecUniqueMirrorArea.end() ), vecUniqueMirrorArea.end() );
			
			NTelType = vecUniqueMirrorArea.size();
			int pos;
			for(int i=0; i<NTelType; i++) {
				pos = -1;
				while (pos < 0){
					pos = find(vecMirrorArea.begin(), vecMirrorArea.end(), vecUniqueMirrorArea[i]) - vecMirrorArea.begin();
				}
				
				vecUniqueTelType.push_back(vecTelType[pos]);
			    vecUniqueFL.push_back(vecFL[pos]);
			    vecUniqueFOV.push_back(vecFOV[pos]);
			    vecUniqueCameraScaleFactor.push_back(vecCameraScaleFactor[pos]);
			    vecUniqueCameraCentreOffset.push_back(vecCameraCentreOffset[pos]);
			    vecUniqueCameraRotation.push_back(vecCameraRotation[pos]);
			    vecUniqueNTubesOFF.push_back(vecNTubesOFF[pos]);
			    vecUniqueNMirrors.push_back(vecNMirrors[pos]);
			    vecUniqueMirrorArea.push_back(vecMirrorArea[pos]);
			    vecUniqueNPixel.push_back(vecNPixel[pos]);
			    vecUniqueNPixel_active.push_back(vecNPixel_active[pos]);
			    vecUniqueNSamples.push_back(vecNSamples[pos]);
			    vecUniqueSample_time_slice.push_back(vecSample_time_slice[pos]);
			    vecUniqueNGains.push_back(vecNGains[pos]);
			    vecUniqueHiLoScale.push_back(vecHiLoScale[pos]);
			    vecUniqueHiLoThreshold.push_back(vecHiLoThreshold[pos]);
			    vecUniqueHiLoOffset.push_back(vecHiLoOffset[pos]);
			}

            int where_L0ID;
            int i = 0;
            int count_tel = 0;
		    while (count_tel < NTelType){
			    where_L0ID = find(vecTelType.begin(), vecTelType.end(), vecUniqueTelType[count_tel]) - vecTelType.begin();
			    int temp_L0ID = vecL0ID[where_L0ID];
                for(unsigned int iL0=0; iL0<vecL0ID_L1.size(); iL0++) {
                    if (vecL0ID_L1[iL0] == temp_L0ID){
                        i = iL0;
                        break;
                    }
                }

			    int temp_Npixel = vecNPixel[where_L0ID];
			    
			    for(int j=i; j<(i+temp_Npixel); j++) {
			    	vecUniquePixelID.push_back(vecPixelID[j]);
			    	vecUniqueXTubeMM.push_back(vecXTubeMM[j]);
			    	vecUniqueYTubeMM.push_back(vecYTubeMM[j]);
			    	vecUniqueRTubeMM.push_back(vecRTubeMM[j]);
			    	vecUniqueXTubeDeg.push_back(vecXTubeDeg[j]);
			    	vecUniqueYTubeDeg.push_back(vecYTubeDeg[j]);
			    	vecUniqueRTubeDeg.push_back(vecRTubeDeg[j]);
			    	vecUniqueTubeOFF.push_back(vecTubeOFF[j]); 
			    }
			    count_tel++;
			}

			
			/// The telescopes size increases as the index in the vector increases
			
			//cout << "Small telescope: " << vecUniqueTelType[0] << endl;
			//cout << "Medium telescope: " << vecUniqueTelType[1] << endl;
			//cout << "Large telescope: " << vecUniqueTelType[2] << endl;
			
			for(int i=0; i<NTelType; i++) {
				temp_teltype.TelType = vecUniqueTelType[i];
				temp_teltype.mirrorType.mirType = i+1;
				temp_teltype.cameraType.camType = i+1;
				telescopeTypes.push_back(temp_teltype);
			}
            
			/// Setting the MirrorType structure
			for(int i=0; i<NTelType; i++) {
				temp_mirtype.mirType = i+1;
				temp_mirtype.FL =  vecUniqueFL[i];
				temp_mirtype.FOV =  vecUniqueFOV[i];
				temp_mirtype.NTubesOFF =  vecUniqueNTubesOFF[i];
				temp_mirtype.NMirrors =  vecUniqueNMirrors[i];
				temp_mirtype.MirrorArea =  vecUniqueMirrorArea[i];
				mirrorTypes.push_back(temp_mirtype);
			}
			
			/// Setting the CameraType structure
			int prevNPixel = 0;
            pixels.resize(NTelType);
			for(int i=0; i<NTelType; i++) {
				temp_camtype.camType = i+1;
				temp_camtype.CameraScaleFactor = vecUniqueCameraScaleFactor[i];
				temp_camtype.CameraCentreOffset = vecUniqueCameraCentreOffset[i];
				temp_camtype.CameraRotation = vecUniqueCameraRotation[i];
				temp_camtype.NPixel = vecUniqueNPixel[i];
				temp_camtype.NPixel_active = vecUniqueNPixel_active[i];
				temp_camtype.pixelType.pixType = i+1;
                
                pixels[i].resize(vecUniqueNPixel[i]);					
				for(int j=0; j<vecUniqueNPixel[i]; j++) {
					temp_pixel.PixelID = vecUniquePixelID[prevNPixel + j];
					temp_pixel.XTubeMM = vecUniqueXTubeMM[prevNPixel + j];
					temp_pixel.YTubeMM = vecUniqueYTubeMM[prevNPixel + j];
					temp_pixel.RTubeMM = vecUniqueRTubeMM[prevNPixel + j];
					temp_pixel.XTubeDeg = vecUniqueXTubeDeg[prevNPixel + j];
					temp_pixel.YTubeDeg = vecUniqueYTubeDeg[prevNPixel + j];
					temp_pixel.RTubeDeg = vecUniqueRTubeDeg[prevNPixel + j];
					temp_pixel.TubeOFF = vecUniqueTubeOFF[prevNPixel + j];
					temp_camtype.pixels.push_back(temp_pixel);
					pixels[i][j] = temp_pixel;
					}
    			prevNPixel = prevNPixel + vecUniqueNPixel[i];
            
				cameraTypes.push_back(temp_camtype);
				
			}
			
			/// Setting the PixelType structure
			for(int i=0; i<NTelType; i++) {
				temp_pixtype.pixType = i+1;
				temp_pixtype.NSamples =  vecUniqueNSamples[i];
				temp_pixtype.Sample_time_slice =  vecUniqueSample_time_slice[i];
				temp_pixtype.NGains =  vecUniqueNGains[i];
				temp_pixtype.HiLoScale =  vecUniqueHiLoScale[i];
				temp_pixtype.HiLoThreshold =  vecUniqueHiLoThreshold[i];
				temp_pixtype.HiLoOffset =  vecUniqueHiLoOffset[i];
				pixelTypes.push_back(temp_pixtype);
			}
			
            
		}
		
		
	}
	catch (qlbase::IOException& e) {
		cout << "ERROR: File "<< confInputFileName <<" does not exist. Error code: " << e.getErrorCode() << endl;
	}
}

ConfigLoadMCFITS::Array *ConfigLoadMCFITS::getArray() {
	return &array;
}

ConfigLoadMCFITS::Telescope *ConfigLoadMCFITS::getTelescope(int TelID) {
	for (int i=0; i<array.NTel; i++) {
    	if (telescopes[i].TelID == TelID){
    		return &telescopes[i];
    	} 
    }
	return 0;
}

ConfigLoadMCFITS::TelescopeType *ConfigLoadMCFITS::getTelescopeType(int TelType) {
	for (int i=0; i<NTelType; i++) {
    	if (telescopeTypes[i].TelType == TelType){
    		return &telescopeTypes[i];
    	}
    }
    return 0;
}

ConfigLoadMCFITS::MirrorType *ConfigLoadMCFITS::getMirrorType(int mirType) {
	for (int i=0; i<NTelType; i++) {
    	if (mirrorTypes[i].mirType == mirType){
    		return &mirrorTypes[i];
    	}
    }
    return 0;
}

ConfigLoadMCFITS::CameraType *ConfigLoadMCFITS::getCameraType(int camType) {
	for (int i=0; i<NTelType; i++) {
    	if (cameraTypes[i].camType == camType){
    		return &cameraTypes[i];
    	}
    }
    return 0;
}

ConfigLoadMCFITS::PixelType *ConfigLoadMCFITS::getPixelType(int pixType) {
	for (int i=0; i<NTelType; i++) {
    	if (pixelTypes[i].pixType == pixType){
    		return &pixelTypes[i];
    	}
    }
    return 0;
}

ConfigLoadMCFITS::Pixel *ConfigLoadMCFITS::getPixel(int camType, int pixelID) {
	//vector<Pixel> *selPixel;
	for (int i=0; i<NTelType; i++) {
    	if (cameraTypes[i].camType == camType){
    	    return &pixels[i][pixelID];
    	}
    }
    return 0;
}

ConfigLoadMCFITS::~ConfigLoadMCFITS() {
	conf_file.close();
    
}

}
