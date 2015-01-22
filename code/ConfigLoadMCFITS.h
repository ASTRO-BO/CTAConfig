/***************************************************************************
 ConfigLoadMCFITS.h  -  description
 -------------------
 copyright            : (C) 2014 Valentina Fioretti
 email                : fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CONFIGLOADMCFITS_H
#define _CONFIGLOADMCFITS_H

#include <ctautils/InputFileFITS.h>
#include <iostream>
#include <stdlib.h>

namespace CTAConfig {
    
    /// Uploading the CTA configuration parameters and converting
    /// them to metadata
    /// \brief CTA Configuration data conversion into metadata from MC data
    class ConfigLoadMCFITS {
        
    private:
        CTAUtils::InputFileFITS conf_file;
        
        
    public:
        /// It takes the CTA configuration file in FITS format
        /// \param confInputFileName The input file name of the CTA configuration
        ConfigLoadMCFITS(const std::string& confInputFileName);
        
        ~ConfigLoadMCFITS();
		
        /// Number of telescope types
        int NTelType;
        
        /// Struct constructor
        
        struct PixelType {
            int pixType;
            int16_t NSamples;
            float Sample_time_slice;
            int16_t NGains;
            float HiLoScale;
            int16_t HiLoThreshold;
            float HiLoOffset;
        };
        
        struct Pixel {
            int16_t PixelID;
            float XTubeMM;
            float YTubeMM;
            float RTubeMM;
            float XTubeDeg;
            float YTubeDeg;
            float RTubeDeg;
            int16_t TubeOFF;
        };
        
        
        struct CameraType {
            int camType;
            float CameraScaleFactor;
            float CameraCentreOffset;
            float CameraRotation;
            int16_t NPixel;
            int16_t NPixel_active;
            PixelType pixelType;
            std::vector<Pixel> pixels;
        };
        
        struct MirrorType {
            int mirType;
            float FL;
            float FOV;
            int16_t NTubesOFF;
            int16_t NMirrors;
            float MirrorArea;
        };
        
        struct TelescopeType {
            int64_t TelType;
            MirrorType mirrorType;
            CameraType cameraType;
        };
        
        struct Telescope {
            int16_t TelID;
            TelescopeType telescopeType;
            float TelX;
            float TelY;
            float TelZ;
        };
        
        struct Array {
            int16_t ArrayID;
            int16_t NTel;
            std::vector<int16_t> vecTelID;
        };
		
        std::vector<PixelType> pixelTypes;
        std::vector< std::vector<Pixel> > pixels;
        std::vector<CameraType> cameraTypes;
        std::vector<MirrorType> mirrorTypes;
        std::vector<TelescopeType> telescopeTypes;
        std::vector<Telescope> telescopes;
        struct Array array;
        
        /// It gets the array structure
        ConfigLoadMCFITS::Array *getArray();
        
        /// It gets the telescope structure from the identification number
        ConfigLoadMCFITS::Telescope *getTelescope(int TelID);
        
        /// It gets the telescope type structure from the type identification number
        ConfigLoadMCFITS::TelescopeType *getTelescopeType(int TelType);
        
        /// It gets the mirror structure from the mirror type identification number
        ConfigLoadMCFITS::MirrorType *getMirrorType(int mirType);
        
        /// It gets the camera structure from the camera type identification number
        ConfigLoadMCFITS::CameraType *getCameraType(int camType);
        
        /// It gets the pixel structure from the pixel type identification number
        ConfigLoadMCFITS::PixelType *getPixelType(int pixType);

        /// It gets the pixel structure from the pixel type identification number
        ConfigLoadMCFITS::Pixel *getPixel(int camType, int pixelID);
        
    };
}

#endif
