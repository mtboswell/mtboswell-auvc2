/*
 * File: rtGetInf.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.243
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Mar  2 17:24:21 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Mar  2 17:24:21 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finite, Inf
 */
#include "rtGetInf.h"
#define NumBitsPerChar                 8

extern "C" {
  /* Function: rtGetInf ==================================================
   * Abstract:
   *	Initialize rtInf needed by the generated code.
   *	Inf is initialized as non-signaling. Assumes IEEE.
   */
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32) {
      inf = rtGetInfF();
    } else {
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

      tmpVal.bitVal.words.wordH = 0x7FF00000;
      tmpVal.bitVal.words.wordL = 0x00000000;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  /* Function: rtGetInfF ==================================================
   * Abstract:
   *	Initialize rtInfF needed by the generated code.
   *	Inf is initialized as non-signaling. Assumes IEEE.
   */
  real32_T rtGetInfF(void)
  {
    typedef struct {
      union {
        real32_T wordLreal;
        uint32_T wordLuint;
      } wordL;
    } IEEESingle;

    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000;
    return infF.wordL.wordLreal;
  }

  /* Function: rtGetMinusInf ==================================================
   * Abstract:
   *	Initialize rtMinusInf needed by the generated code.
   *	Inf is initialized as non-signaling. Assumes IEEE.
   */
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32) {
      minf = rtGetMinusInfF();
    } else {
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

      tmpVal.bitVal.words.wordH = 0xFFF00000;
      tmpVal.bitVal.words.wordL = 0x00000000;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  /* Function: rtGetMinusInfF ==================================================
   * Abstract:
   *	Initialize rtMinusInfF needed by the generated code.
   *	Inf is initialized as non-signaling. Assumes IEEE.
   */
  real32_T rtGetMinusInfF(void)
  {
    typedef struct {
      union {
        real32_T wordLreal;
        uint32_T wordLuint;
      } wordL;
    } IEEESingle;

    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000;
    return minfF.wordL.wordLreal;
  }
}
#undef NumBitsPerChar

/* end rtGetInf.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
