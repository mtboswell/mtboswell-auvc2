/*
*  vipdrawtext_rt.h
*
*  Copyright 1995-2005 The MathWorks, Inc.
*  $Revision.3 $ $Date: 2009/11/16 22:38:39 $
*/

#ifndef vipdrawtext_rt_h
#define vipdrawtext_rt_h

#include "dsp_rt.h"

#ifdef VIPDRAWTEXT_EXPORTS
#define VIPDRAWTEXT_EXPORT EXPORT_FCN
#else
#define VIPDRAWTEXT_EXPORT MWSP_IDECL
#endif

#define MWVIP_DrawText_upscaleFactor            128
#define MWVIP_DrawText_upscaleFactorBits        7

#define MWVIP_DrawText_aaScaleFactor            256
#define MWVIP_DrawText_aaScaleFactorBits        8

/* 
* MWVIP = MathWorks VIP Blockset 
* _RGB_ = Red, Green, Blue
* _I_   = intensity only
* _AA   = anti-alias
*/
#ifdef __cplusplus
extern "C" {
#endif

	typedef void (*DRAW_TEXT_FUNC_I)(const uint8_T*,int32_T,int32_T,int32_T,int32_T,uint16_T,uint16_T,uint32_T,uint32_T,void*,const void*,const void*,boolean_T);
	typedef void (*DRAW_TEXT_FUNC_RGB)(const uint8_T*,int32_T,int32_T,int32_T,int32_T,uint16_T,uint16_T,uint32_T,uint32_T,void*,void*,void*,const void*,const void*,boolean_T);
	typedef void (*DTYPE_CONVERT_FCN)(int32_T,uint32_T,const void*,void*,int32_T);
	typedef void (*SATURATE_FLT_CLR_FCN)(int32_T,const void*,void*,int_T);

	VIPDRAWTEXT_EXPORT DRAW_TEXT_FUNC_RGB MWVIP_GetDrawTextFcn_RGB(int_T dataTypeID, boolean_T isAntiAliased);

	VIPDRAWTEXT_EXPORT DRAW_TEXT_FUNC_I MWVIP_GetDrawTextFcn_I(int_T dataTypeID, boolean_T isAntiAliased);

	VIPDRAWTEXT_EXPORT void MWVIP_snprintf(char_T* outbuf, char_T* formatString,
		void* items, int_T numItems,
		int_T itemDataType, boolean_T isString, int_T size);

    VIPDRAWTEXT_EXPORT void MWVIP_snprintf_wrapper(void* outbuf, void* formatString,
		void* items, int_T numItems,
		int_T itemDataType, boolean_T isString, int_T size);

	/* double */
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_RGB_double_AA(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		void* outputImageG,
		void* outputImageB,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_RGB_double(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		void* outputImageG,
		void* outputImageB,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_I_double_AA(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_I_double(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);


	/* single */
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_RGB_single_AA(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		void* outputImageG,
		void* outputImageB,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_RGB_single(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		void* outputImageG,
		void* outputImageB,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_I_single_AA(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_I_single(const uint8_T* fontBitmap,
		int32_T pen_x,
		int32_T pen_y,
		int32_T left_bearing,
		int32_T top_bearing,
		uint16_T bitmapWidth,
		uint16_T bitmapHeight,
		uint32_T imageWidth,
		uint32_T imageHeight,
		void* outputImageR,
		const void* colorVector,
		const void* opacityPtr,
        boolean_T isImageTransposed);


	/* stuff for converting amongst data types... */
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_copyDT1ToUint32(int32_T dataType1, uint32_T numElements, const void* input, void* uint32Output, int32_T dummy);
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_copyDT1ToInt32(int32_T dataType1, uint32_T numElements, const void* input, void* int32Output, int32_T indx);
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_noCopyNeeded(int32_T dataType1, uint32_T numElements, const void* input, void* output, int32_T indx);

	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_SatFltptRGBVals(int32_T dType, const void* input, void* output, int_T nPlanes);
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_SatFltptIntensityVals(int32_T dType, const void* input, void* output, int_T nPlanes);
	VIPDRAWTEXT_EXPORT void MWVIP_DrawText_noFltSaturationNeeded(int32_T dType, const void* input, void* output, int_T nPlanes);
	VIPDRAWTEXT_EXPORT int32_T MWVIP_strlen(const void * str);


#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* vipdrawtext_rt_h */

/* [EOF] vipdrawtext_rt.h */
