/**
 * @file HostLib_Audio.h
 * @brief Helper for the AudioDevices.
 * Copyright 2007-2008 The MathWorks, Inc.
 * $Revision: 1.1.6.4.2.1 $ $Date: 2009/12/17 13:55:07 $
 */ 


/* Wrap everything in extern C */
#ifdef __cplusplus
extern "C" {
#endif 

extern const char *libName_Audio;
  
/*******************************
 * Routines which are defined in the library in question
 *******************************/
typedef void (*pFnLibCreate_Audio)(char *err, char *warn, const char *deviceName, int apiID, int inOut, void **m_device,
                             int numChannels, double sampleRate, int deviceDatatype, int bufferSize, double queueDuration,
                             int frameSize, int signalDatatype);
typedef void (*pFnLibUpdate_Audio)(void *device, char *err, const void *src, int signalDatatype, int samplesPerFrame, int *nDroppedSamples);
typedef void (*pFnLibOutputs_Audio)(void *device, char *err, void *src, int signalDatatype, int samplesPerFrame, int *nDroppedSamples);

/*******************************
 * Routines which we define to call the functions in the library 
 *******************************/
void LibCreate_Audio(void *hostLib, char *warn, const char *deviceName, int apiID, int inOut,
                     int numChannels, double sampleRate, int deviceDatatype, int bufferSize, double queueDuration,
                     int frameSize, int signalDatatype);
void LibUpdate_Audio(void *hostLib, const void *src, int signalDatatype, int samplesPerFrame, int *nDroppedSamples);
void LibOutputs_Audio(void *hostLib, void *src, int signalDatatype, int samplesPerFrame, int *nDroppedSamples);

/* Include HostLib for declarations of LibStart, LibTerminate, CreateHostLibrary, and DestroyHostLibrary. */
#include "HostLib_rtw.h"

#ifdef __cplusplus
} // extern "C"
#endif 
