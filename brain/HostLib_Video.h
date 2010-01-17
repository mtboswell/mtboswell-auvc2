/**
 * @file HostLib_Video.h
 * @brief Helper for the ToVideoDevice block
 * Copyright 2007-2008 The MathWorks, Inc.
 * $Revision: 1.1.6.1 $ $Date: 2008/09/15 21:12:03 $
 */ 

#include "VideoDefs.h"

/* Wrap everything in extern C */
#ifdef __cplusplus
extern "C" {
#endif 

extern const char *libName_Video;

/*******************************
 * Routines which are defined in the library in question
 *******************************/
typedef void* (*pFnLibCreate_Video)(char *err, char *warning, const char *id, const char *windowCaption,
                              int outputWidth, int outputHeight, unsigned char bFullscreen, int rendererType,
                              double fps, int rowOrColumn, int dType, unsigned char openAtMdlStart,
                              int x, int y, unsigned char setSize, int windowWidth, int windowHeight);
typedef void (*pFnLibUpdate_Video)(void *obj, char *err, const void *R, const void *G, const void *B);
typedef void (*pFnLibOutputs_Video)(void);

/*******************************
 * Routines which we define to call the functions in the library 
 *******************************/
void LibCreate_Video(void *hostLib, char *warning, const char *id, const char *windowCaption,
                     int outputWidth, int outputHeight, unsigned char bFullscreen, int rendererType,
                     double fps, int rowOrColumn, int dType, unsigned char openAtMdlStart,
                     int x, int y, unsigned char setSize, int windowWidth, int windowHeight);
void LibUpdate_Video(void *hostLib, const void *R, const void *G, const void *B);

/* Include HostLib for declarations of LibStart, LibTerminate, CreateHostLibrary, and DestroyHostLibrary. */
#include "HostLib_rtw.h"

#ifdef __cplusplus
} // extern "C"
#endif 

