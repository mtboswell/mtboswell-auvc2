/**
 * @file HostLib_Multimedia.h
 * @brief Helper for Multimedia blocks
 * Copyright 2009 The MathWorks, Inc.
 * $Revision: 1.1.6.1 $ $Date: 2009/08/14 03:57:15 $
 */ 


/* Wrap everything in extern C */
#ifdef __cplusplus
extern "C" {
#endif 

#include "VideoDefs.h"
#include "AudioDefs.h"


/*******************************
 * Routines used to initialize MMAudioInfo and MMVideoInfo structures.
 *******************************/
void createAudioInfo(void *audioInfo, unsigned char isValid, double sampleRate, int numBits,
                     int numChannels, int frameSize,
                     int dataType, char* audioCompressor);

void createVideoInfo(void *videoInfo, unsigned char isValid, double frameRate, double frameRateComputed,
                     char* fourcc, int numPorts, int numBands,
                     int bandWidth, int bandHeight,
                     int dataType, int orientation,
                     char* videoCompressor);


#ifdef __cplusplus
} // extern "C"
#endif 

