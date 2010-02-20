/*
 * File: rtGetNaN.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.222
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Sat Feb 20 17:49:48 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Sat Feb 20 17:49:49 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finite, NaN
 */
#include "rtGetNaN.h"
#define NumBitsPerChar                 8

extern "C" {
  /* Function: rtGetNaN ==================================================
   * Abstract:
   *	Initialize rtNaN needed by the generated code.
   *	NaN is initialized as non-signaling. Assumes IEEE.
   */
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32) {
      nan = rtGetNaNF();
    } else {
      uint16_T one = 1;
      enum {
        LittleEndian,
        BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1) ? LittleEndian : BigEndian;
      switch (machByteOrder) {
       case LittleEndian:
        {
          typedef struct {
            struct {
              uint32_T wordL;
              uint32_T wordH;
            } words;
          } LittleEndianIEEEDouble;

          union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0xFFF80000;
          tmpVal.bitVal.words.wordL = 0x00000000;
          nan = tmpVal.fltVal;
          break;
        }

       case BigEndian:
        {
          typedef struct {
            struct {
              uint32_T wordH;
              uint32_T wordL;
            } words;
          } BigEndianIEEEDouble;

          union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0x7FFFFFFF;
          tmpVal.bitVal.words.wordL = 0xFFFFFFFF;
          nan = tmpVal.fltVal;
          break;
        }
      }
    }

    return nan;
  }

  /* Function: rtGetNaNF ==================================================
   * Abstract:
   *	Initialize rtNaNF needed by the generated code.
   *	NaN is initialized as non-signaling. Assumes IEEE.
   */
  real32_T rtGetNaNF(void)
  {
    typedef struct {
      union {
        real32_T wordLreal;
        uint32_T wordLuint;
      } wordL;
    } IEEESingle;

    IEEESingle nanF;
    uint16_T one = 1;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        nanF.wordL.wordLuint = 0xFFC00000;
        break;
      }

     case BigEndian:
      {
        nanF.wordL.wordLuint = 0x7FFFFFFF;
        break;
      }
    }

    return nanF.wordL.wordLreal;
  }
}
#undef NumBitsPerChar

/* end rt_getNaN.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
