/*
 * test.cpp
 *
 * Real-Time Workshop code generation for Simulink model "test.mdl".
 *
 * Model version              : 1.36
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Fri Jun 03 07:34:21 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block signals (auto storage) */
BlockIO_test test_B;

/* Block states (auto storage) */
D_Work_test test_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_test test_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_test test_Y;

/* Real-time model */
RT_MODEL_test test_M_;
RT_MODEL_test *test_M = &test_M_;
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  uint32_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator = absNumerator % absDenominator;
      if (absNumerator > (uint32_T)0) {
        tempAbsQuotient = tempAbsQuotient + (uint32_T)1;
      }
    }

    quotient = quotientNeedsNegation ? (int32_T)(-((int32_T)tempAbsQuotient)) :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/* Model output function */
static void test_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_VariableSelector;
  real_T rtb_VariableSelector1;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  int32_T numElem;
  int32_T imgIdxLL;
  int32_T imgIdxUR;
  int32_T imgIdxLR;
  int32_T imgCol;
  int32_T imgRow;
  real_T accumOne;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  int32_T colsInMinus;
  int32_T countPeak;
  boolean_T done;
  int32_T q;
  int32_T jRowsIn;
  uint32_T rtb_FindLocalMaxima[2];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;

  /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion' incorporates:
   *  Inport: '<Root>/B_forward_in'
   *  Inport: '<Root>/G_forward_in'
   *  Inport: '<Root>/R_forward_in'
   */
  for (m = 0; m < 19200; m++) {
    test_B.ColorSpaceConversion[m] = (test_U.R_forward_in[m] * 0.299 +
      test_U.G_forward_in[m] * 0.587) + test_U.B_forward_in[m] * 0.114;
    if (test_B.ColorSpaceConversion[m] > 1.0) {
      test_B.ColorSpaceConversion[m] = 1.0;
    } else {
      if (test_B.ColorSpaceConversion[m] < 0.0) {
        test_B.ColorSpaceConversion[m] = 0.0;
      }
    }
  }

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 1; imgCol < 159; imgCol++) {
    for (imgRow = 1; imgRow < 119; imgRow++) {
      accumOne = 0.0;
      accumTwo = 0.0;
      q = imgCol * 120 + imgRow;
      for (m = 0; m < 6; m++) {
        accumOne += test_B.ColorSpaceConversion[q +
          test_DWork.EdgeDetection_VO_DW[m]] *
          test_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += test_B.ColorSpaceConversion[q +
          test_DWork.EdgeDetection_HO_DW[m]] *
          test_ConstP.EdgeDetection_HC_RTP[m];
      }

      test_DWork.EdgeDetection_GV_SQUARED_DW[q] = accumOne * accumOne;
      test_DWork.EdgeDetection_GH_SQUARED_DW[q] = accumTwo * accumTwo;
    }
  }

  for (imgCol = 1; imgCol < 159; imgCol++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    jRowsIn = imgCol * 120;
    q = imgCol * 120 + 119;
    for (m = 0; m < 6; m++) {
      accumOne += test_B.ColorSpaceConversion[jRowsIn +
        test_DWork.EdgeDetection_HOU_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += test_B.ColorSpaceConversion[q +
        test_DWork.EdgeDetection_HOD_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += test_B.ColorSpaceConversion[jRowsIn +
        test_DWork.EdgeDetection_VOU_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += test_B.ColorSpaceConversion[q +
        test_DWork.EdgeDetection_VOD_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
    }

    test_DWork.EdgeDetection_GV_SQUARED_DW[jRowsIn] = accumThree * accumThree;
    test_DWork.EdgeDetection_GH_SQUARED_DW[jRowsIn] = accumOne * accumOne;
    test_DWork.EdgeDetection_GV_SQUARED_DW[q] = accumFour * accumFour;
    test_DWork.EdgeDetection_GH_SQUARED_DW[q] = accumTwo * accumTwo;
  }

  for (imgRow = 1; imgRow < 119; imgRow++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    q = 19080 + imgRow;
    for (m = 0; m < 6; m++) {
      accumOne += test_B.ColorSpaceConversion[imgRow +
        test_DWork.EdgeDetection_VOL_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += test_B.ColorSpaceConversion[q +
        test_DWork.EdgeDetection_VOR_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += test_B.ColorSpaceConversion[imgRow +
        test_DWork.EdgeDetection_HOL_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += test_B.ColorSpaceConversion[q +
        test_DWork.EdgeDetection_HOR_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
    }

    test_DWork.EdgeDetection_GV_SQUARED_DW[imgRow] = accumOne * accumOne;
    test_DWork.EdgeDetection_GH_SQUARED_DW[imgRow] = accumThree * accumThree;
    test_DWork.EdgeDetection_GV_SQUARED_DW[q] = accumTwo * accumTwo;
    test_DWork.EdgeDetection_GH_SQUARED_DW[q] = accumFour * accumFour;
  }

  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += test_B.ColorSpaceConversion[test_DWork.EdgeDetection_VOUL_DW[m]]
      * test_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += test_B.ColorSpaceConversion[test_DWork.EdgeDetection_HOUL_DW[m]]
      * test_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += test_B.ColorSpaceConversion[119 +
      test_DWork.EdgeDetection_VOLL_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += test_B.ColorSpaceConversion[119 +
      test_DWork.EdgeDetection_HOLL_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
  }

  test_DWork.EdgeDetection_GV_SQUARED_DW[0] = accumOne * accumOne;
  test_DWork.EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  test_DWork.EdgeDetection_GV_SQUARED_DW[119] = accumThree * accumThree;
  test_DWork.EdgeDetection_GH_SQUARED_DW[119] = accumFour * accumFour;
  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += test_B.ColorSpaceConversion[19080 +
      test_DWork.EdgeDetection_VOUR_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += test_B.ColorSpaceConversion[19080 +
      test_DWork.EdgeDetection_HOUR_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += test_B.ColorSpaceConversion[19199 +
      test_DWork.EdgeDetection_VOLR_DW[m]] * test_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += test_B.ColorSpaceConversion[19199 +
      test_DWork.EdgeDetection_HOLR_DW[m]] * test_ConstP.EdgeDetection_HC_RTP[m];
  }

  test_DWork.EdgeDetection_GV_SQUARED_DW[19080] = accumOne * accumOne;
  test_DWork.EdgeDetection_GH_SQUARED_DW[19080] = accumTwo * accumTwo;
  test_DWork.EdgeDetection_GV_SQUARED_DW[19199] = accumThree * accumThree;
  test_DWork.EdgeDetection_GH_SQUARED_DW[19199] = accumFour * accumFour;
  accumTwo = 0.0;
  for (m = 0; m < 19200; m++) {
    test_DWork.EdgeDetection_GRAD_SUM_DW[m] =
      test_DWork.EdgeDetection_GV_SQUARED_DW[m];
    test_DWork.EdgeDetection_GRAD_SUM_DW[m] =
      test_DWork.EdgeDetection_GRAD_SUM_DW[m] +
      test_DWork.EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += test_DWork.EdgeDetection_GRAD_SUM_DW[m] *
      test_DWork.EdgeDetection_MEAN_FACTOR_DW;
  }

  accumOne = test_P.EdgeDetection_THRESH_TUNING_RTP * accumTwo;
  for (imgCol = 0; imgCol < 160; imgCol++) {
    for (imgRow = 0; imgRow < 120; imgRow++) {
      m = imgCol * 120 + imgRow;
      test_B.EdgeDetection[m] = ((test_DWork.EdgeDetection_GRAD_SUM_DW[m] >
        accumOne) && (((test_DWork.EdgeDetection_GV_SQUARED_DW[m] >=
                        test_DWork.EdgeDetection_GH_SQUARED_DW[m]) && (imgCol !=
        0 ? test_DWork.EdgeDetection_GRAD_SUM_DW[m - 120] <=
        test_DWork.EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgCol != 159 ?
        test_DWork.EdgeDetection_GRAD_SUM_DW[m] >
        test_DWork.EdgeDetection_GRAD_SUM_DW[m + 120] : TRUE)) ||
                      ((test_DWork.EdgeDetection_GH_SQUARED_DW[m] >=
                        test_DWork.EdgeDetection_GV_SQUARED_DW[m]) && (imgRow !=
        0 ? test_DWork.EdgeDetection_GRAD_SUM_DW[m - 1] <=
        test_DWork.EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgRow != 119 ?
        test_DWork.EdgeDetection_GRAD_SUM_DW[m] >
        test_DWork.EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* S-Function (sviphough): '<Root>/Hough Transform' */
  MWVIP_Hough_D(&test_B.EdgeDetection[0], &test_B.HoughTransform_o1[0],
                &test_ConstP.HoughTransform_SINE_[0],
                &test_ConstP.HoughTransform_FIRSTRHO_RT, 120, 160, 399, 91);

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  memcpy((void *)(&test_B.y[0]), (void *)(&test_B.HoughTransform_o1[0]), 71820U *
         sizeof(real_T));

  /* S-Function (svipfindlocalmax): '<Root>/Find Local Maxima' */
  countPeak = 0;
  done = FALSE;
  memcpy((void *)(&test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[0]), (void *)
         (&test_B.y[0]), (uint32_T)(71820 * (int32_T)MWDSP_SIZEOF_DOUBLE));
  memset((void *)&rtb_FindLocalMaxima[0], 0, (uint32_T)((int32_T)
          MWDSP_SIZEOF_INT32 << 1U));
  while (!done) {
    imgRow = 0;
    accumOne = test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (m = 0; m < 71820; m++) {
      if (test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[m] > accumOne) {
        imgRow = m;
        accumOne = test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[m];
      }
    }

    imgCol = imgRow % 399;
    q = imgRow / 399;
    if (test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[imgRow] >=
        test_P.FindLocalMaxima_THRESHOLD_RTP) {
      rtb_FindLocalMaxima[countPeak << 1U] = (uint32_T)imgCol;
      rtb_FindLocalMaxima[(countPeak << 1U) + 1] = (uint32_T)q;
      countPeak++;
      if (countPeak == 1) {
        done = TRUE;
      }

      m = imgCol - 2;
      imgIdxLR = m >= 0 ? m : 0;
      m = imgCol + 2;
      imgIdxLL = m <= 398 ? m : 398;
      imgIdxUR = q - 3;
      q += 3;
      if (!((imgIdxUR < 0) || (q > 179))) {
        while (imgIdxUR <= q) {
          jRowsIn = imgIdxUR * 399;
          for (m = imgIdxLR; m <= imgIdxLL; m++) {
            test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[m + jRowsIn] = 0.0;
          }

          imgIdxUR++;
        }
      } else {
        if (imgIdxUR < 0) {
          for (numElem = imgIdxUR; numElem <= q; numElem++) {
            if (numElem < 0) {
              imgRow = (numElem + 180) * 399;
              for (m = imgIdxLR; m <= imgIdxLL; m++) {
                test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[(398 - m) + imgRow] =
                  0.0;
              }
            } else {
              jRowsIn = numElem * 399;
              for (m = imgIdxLR; m <= imgIdxLL; m++) {
                test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[m + jRowsIn] = 0.0;
              }
            }
          }
        }

        if (q > 179) {
          for (numElem = imgIdxUR; numElem <= q; numElem++) {
            if (numElem > 179) {
              imgRow = (numElem - 180) * 399;
              for (m = imgIdxLR; m <= imgIdxLL; m++) {
                test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[(398 - m) + imgRow] =
                  0.0;
              }
            } else {
              jRowsIn = numElem * 399;
              for (m = imgIdxLR; m <= imgIdxLL; m++) {
                test_DWork.FindLocalMaxima_TEMP_IN_DWORKS[m + jRowsIn] = 0.0;
              }
            }
          }
        }
      }
    } else {
      done = TRUE;
    }
  }

  test_DWork.FindLocalMaxima_NUMPEAKS_DWORK = (uint32_T)countPeak;
  test_DWork.FindLocalMaxima_DIMS1[1] = (int32_T)
    test_DWork.FindLocalMaxima_NUMPEAKS_DWORK;

  /* Selector: '<Root>/Selector1' */
  test_B.Selector = rtb_FindLocalMaxima[(int32_T)0.0];

  /* Signal Processing Blockset Variable Selector (sdspperm2) - '<Root>/Variable Selector' */
  /* Permute columns port 0 input columns = 180, output columns = 1 */
  {
    int32_T i_idx = (int32_T)(test_B.Selector );

    /* Clip bad index */
    if (i_idx < 0) {
      i_idx = 0;
    } else if (i_idx > 179) {
      i_idx = 179;
    }

    rtb_VariableSelector = test_B.HoughTransform_o2[i_idx];
  }

  /* Selector: '<Root>/Selector' */
  test_B.Selector = rtb_FindLocalMaxima[(int32_T)0.0];

  /* Signal Processing Blockset Variable Selector (sdspperm2) - '<Root>/Variable Selector1' */
  /* Permute columns port 0 input columns = 399, output columns = 1 */
  {
    int32_T i_idx = (int32_T)(test_B.Selector );

    /* Clip bad index */
    if (i_idx < 0) {
      i_idx = 0;
    } else if (i_idx > 398) {
      i_idx = 398;
    }

    rtb_VariableSelector1 = test_B.HoughTransform_o3[i_idx];
  }

  /* S-Function (sviphoughlines): '<Root>/Hough Lines' */
  jRowsIn = 0;
  accumOne = (rtb_VariableSelector1 + 2.2204460492503131E-16) / (cos
    (rtb_VariableSelector) + 2.2204460492503131E-16);

  /* part-1: top horizontal axis */
  accumTwo = floor(accumOne + 0.5);
  if ((accumTwo >= 0.0) && (accumTwo <= 159.0)) {
    test_B.HoughLines[0] = 0;
    test_B.HoughLines[1] = (int32_T)floor((real_T)(int32_T)accumTwo + 0.5);
    jRowsIn = 1;
  }

  accumThree = (rtb_VariableSelector1 + 2.2204460492503131E-16) / (sin
    (rtb_VariableSelector) + 2.2204460492503131E-16);

  /* part-2: left vertical axis */
  accumTwo = floor(accumThree + 0.5);
  if ((accumTwo >= 0.0) && (accumTwo <= 119.0)) {
    test_B.HoughLines[(jRowsIn << 1)] = (int32_T)floor((real_T)(int32_T)accumTwo
      + 0.5);
    test_B.HoughLines[1 + (jRowsIn << 1)] = 0;
    jRowsIn++;
  }

  /* part-3: Right vertical axis */
  if (jRowsIn < 2) {
    accumTwo = floor((accumOne - 159.0) * (accumThree / accumOne) + 0.5);
    if ((accumTwo >= 0.0) && (accumTwo <= 119.0)) {
      test_B.HoughLines[(jRowsIn << 1)] = (int32_T)floor((real_T)(int32_T)
        accumTwo + 0.5);
      test_B.HoughLines[1 + (jRowsIn << 1)] = 159;
      jRowsIn++;
    }
  }

  /* part-4: bottom horizontal axis */
  if (jRowsIn < 2) {
    accumTwo = floor((accumOne - accumOne / accumThree * 119.0) + 0.5);
    if ((accumTwo >= 0.0) && (accumTwo <= 159.0)) {
      test_B.HoughLines[(jRowsIn << 1)] = 119;
      test_B.HoughLines[1 + (jRowsIn << 1)] = (int32_T)floor((real_T)(int32_T)
        accumTwo + 0.5);
      jRowsIn++;
    }
  }

  if (jRowsIn < 2) {
    test_B.HoughLines[0] = -1;
    test_B.HoughLines[1] = -1;
    test_B.HoughLines[2] = -1;
    test_B.HoughLines[3] = -1;
  }

  /* S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  /* Copy the image from input to output. */
  memcpy((void *)(&test_DWork.EdgeDetection_GV_SQUARED_DW[0]), (void *)
         (&test_B.ColorSpaceConversion[0]), 19200U * sizeof(real_T));
  colsInMinus = 0;
  for (m = 0; m < 1; m = 1) {
    imgIdxLL = test_B.HoughLines[colsInMinus];
    imgCol = test_B.HoughLines[colsInMinus + 1];
    numElem = test_B.HoughLines[colsInMinus + 2];
    imgIdxLR = test_B.HoughLines[colsInMinus + 3];
    if ((test_B.HoughLines[colsInMinus + 2] != test_B.HoughLines[colsInMinus]) ||
        (test_B.HoughLines[colsInMinus + 1] != test_B.HoughLines[colsInMinus + 3]))
    {
      isInBound = FALSE;

      /* Find the visible portion of a line. */
      visited = FALSE;
      visited_0 = FALSE;
      done = FALSE;
      imgIdxUR = test_B.HoughLines[colsInMinus];
      line_idx_1 = test_B.HoughLines[colsInMinus + 1];
      line_idx_0 = test_B.HoughLines[colsInMinus + 2];
      line_idx = test_B.HoughLines[colsInMinus + 3];
      while (!done) {
        m = 0;
        countPeak = 0;

        /* Determine viewport violations. */
        if (imgIdxUR < 0) {
          m = 4;
        } else {
          if (imgIdxUR > 119) {
            m = 8;
          }
        }

        if (line_idx_0 < 0) {
          countPeak = 4;
        } else {
          if (line_idx_0 > 119) {
            countPeak = 8;
          }
        }

        if (line_idx_1 < 0) {
          m = (int32_T)((uint32_T)m | 1U);
        } else {
          if (line_idx_1 > 159) {
            m = (int32_T)((uint32_T)m | 2U);
          }
        }

        if (line_idx < 0) {
          countPeak = (int32_T)((uint32_T)countPeak | 1U);
        } else {
          if (line_idx > 159) {
            countPeak = (int32_T)((uint32_T)countPeak | 2U);
          }
        }

        if (!((uint32_T)m | (uint32_T)countPeak)) {
          /* Line falls completely within bounds. */
          done = TRUE;
          isInBound = TRUE;
        } else if ((uint32_T)m & (uint32_T)countPeak) {
          /* Line falls completely out of bounds. */
          done = TRUE;
          isInBound = FALSE;
        } else if ((uint32_T)m != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited) {
            imgIdxUR = imgIdxLL;
            line_idx_1 = imgCol;
          }

          q = line_idx_0 - imgIdxUR;
          imgRow = line_idx - line_idx_1;
          if ((uint32_T)m & 4U) {
            /* Violated RMin. */
            jRowsIn = (0 - imgIdxUR) * imgRow;
            if (((jRowsIn >= 0) && (q >= 0)) || ((jRowsIn < 0) && (q < 0))) {
              line_idx_1 += (div_s32_floor(jRowsIn << 1U, q) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-jRowsIn) << 1U, q) + 1) >> 1);
            }

            imgIdxUR = 0;
            visited = TRUE;
          } else if ((uint32_T)m & 8U) {
            /* Violated RMax. */
            jRowsIn = (119 - imgIdxUR) * imgRow;
            if (((jRowsIn >= 0) && (q >= 0)) || ((jRowsIn < 0) && (q < 0))) {
              line_idx_1 += (div_s32_floor(jRowsIn << 1U, q) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-jRowsIn) << 1U, q) + 1) >> 1);
            }

            imgIdxUR = 119;
            visited = TRUE;
          } else if ((uint32_T)m & 1U) {
            /* Violated CMin. */
            jRowsIn = (0 - line_idx_1) * q;
            if (((jRowsIn >= 0) && (imgRow >= 0)) || ((jRowsIn < 0) && (imgRow <
                  0))) {
              imgIdxUR += (div_s32_floor(jRowsIn << 1U, imgRow) + 1) >> 1;
            } else {
              imgIdxUR += -((div_s32_floor((-jRowsIn) << 1U, imgRow) + 1) >> 1);
            }

            line_idx_1 = 0;
            visited = TRUE;
          } else {
            /* Violated CMax. */
            jRowsIn = (159 - line_idx_1) * q;
            if (((jRowsIn >= 0) && (imgRow >= 0)) || ((jRowsIn < 0) && (imgRow <
                  0))) {
              imgIdxUR += (div_s32_floor(jRowsIn << 1U, imgRow) + 1) >> 1;
            } else {
              imgIdxUR += -((div_s32_floor((-jRowsIn) << 1U, imgRow) + 1) >> 1);
            }

            line_idx_1 = 159;
            visited = TRUE;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited_0) {
            line_idx_0 = numElem;
            line_idx = imgIdxLR;
          }

          q = line_idx_0 - imgIdxUR;
          imgRow = line_idx - line_idx_1;
          if ((uint32_T)countPeak & 4U) {
            /* Violated RMin. */
            jRowsIn = (0 - line_idx_0) * imgRow;
            if (((jRowsIn >= 0) && (q >= 0)) || ((jRowsIn < 0) && (q < 0))) {
              line_idx += (div_s32_floor(jRowsIn << 1U, q) + 1) >> 1;
            } else {
              line_idx += -((div_s32_floor((-jRowsIn) << 1U, q) + 1) >> 1);
            }

            line_idx_0 = 0;
            visited_0 = TRUE;
          } else if ((uint32_T)countPeak & 8U) {
            /* Violated RMax. */
            jRowsIn = (119 - line_idx_0) * imgRow;
            if (((jRowsIn >= 0) && (q >= 0)) || ((jRowsIn < 0) && (q < 0))) {
              line_idx += (div_s32_floor(jRowsIn << 1U, q) + 1) >> 1;
            } else {
              line_idx += -((div_s32_floor((-jRowsIn) << 1U, q) + 1) >> 1);
            }

            line_idx_0 = 119;
            visited_0 = TRUE;
          } else if ((uint32_T)countPeak & 1U) {
            /* Violated CMin. */
            jRowsIn = (0 - line_idx) * q;
            if (((jRowsIn >= 0) && (imgRow >= 0)) || ((jRowsIn < 0) && (imgRow <
                  0))) {
              line_idx_0 += (div_s32_floor(jRowsIn << 1U, imgRow) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-jRowsIn) << 1U, imgRow) + 1) >> 1);
            }

            line_idx = 0;
            visited_0 = TRUE;
          } else {
            /* Violated CMax. */
            jRowsIn = (159 - line_idx) * q;
            if (((jRowsIn >= 0) && (imgRow >= 0)) || ((jRowsIn < 0) && (imgRow <
                  0))) {
              line_idx_0 += (div_s32_floor(jRowsIn << 1U, imgRow) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-jRowsIn) << 1U, imgRow) + 1) >> 1);
            }

            line_idx = 159;
            visited_0 = TRUE;
          }
        }
      }

      if (isInBound) {
        /* Draw a line using Bresenham algorithm. */
        /* Initialize the Bresenham algorithm. */
        if (line_idx_0 >= imgIdxUR) {
          q = line_idx_0 - imgIdxUR;
        } else {
          q = imgIdxUR - line_idx_0;
        }

        if (line_idx >= line_idx_1) {
          imgRow = line_idx - line_idx_1;
        } else {
          imgRow = line_idx_1 - line_idx;
        }

        if (q > imgRow) {
          jRowsIn = 1;
          imgCol = 120;
        } else {
          jRowsIn = 120;
          imgCol = 1;
          q = imgIdxUR;
          imgIdxUR = line_idx_1;
          line_idx_1 = q;
          q = line_idx_0;
          line_idx_0 = line_idx;
          line_idx = q;
        }

        if (imgIdxUR > line_idx_0) {
          q = imgIdxUR;
          imgIdxUR = line_idx_0;
          line_idx_0 = q;
          q = line_idx_1;
          line_idx_1 = line_idx;
          line_idx = q;
        }

        numElem = line_idx_0 - imgIdxUR;
        if (line_idx_1 <= line_idx) {
          imgRow = 1;
          imgIdxLL = line_idx - line_idx_1;
        } else {
          imgRow = -1;
          imgIdxLL = line_idx_1 - line_idx;
        }

        imgIdxLR = -((numElem + 1) >> 1);
        m = imgIdxUR * jRowsIn + line_idx_1 * imgCol;
        imgRow = imgRow * imgCol + jRowsIn;
        for (done = (imgIdxUR <= line_idx_0); done; done = (imgIdxUR <=
              line_idx_0)) {
          test_DWork.EdgeDetection_GV_SQUARED_DW[m] = 1.0;

          /* Compute the next location using Bresenham algorithm. */
          /* Move to the next pixel location. */
          imgIdxLR += imgIdxLL;
          if (imgIdxLR >= 0) {
            imgIdxLR -= numElem;
            m += imgRow;
          } else {
            m += jRowsIn;
          }

          imgIdxUR++;
        }
      }
    }

    colsInMinus += 2;
  }

  /* Outport: '<Root>/Out1' */
  memcpy((void *)(&test_Y.Out1[0]), (void *)
         (&test_DWork.EdgeDetection_GV_SQUARED_DW[0]), 19200U * sizeof(real_T));

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void test_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_M->Timing.clockTick0)) {
    ++test_M->Timing.clockTickH0;
  }

  test_M->Timing.t[0] = test_M->Timing.clockTick0 * test_M->Timing.stepSize0 +
    test_M->Timing.clockTickH0 * test_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void test_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test_M->Timing.sampleTimes = (&test_M->Timing.sampleTimesArray[0]);
    test_M->Timing.offsetTimes = (&test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(test_M, &test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test_M, 0.0);
  test_M->Timing.stepSize0 = 0.033333333333333333;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test_M->rtwLogInfo, (NULL));
    rtliSetLogT(test_M->rtwLogInfo, "tout");
    rtliSetLogX(test_M->rtwLogInfo, "");
    rtliSetLogXFinal(test_M->rtwLogInfo, "");
    rtliSetSigLog(test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(test_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &test_Y.Out1[0]
      };

      rtliSetLogYSignalPtrs(test_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        19200
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2
      };

      static int_T rt_LoggedOutputDimensions[] = {
        120, 160
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "test/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(test_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(test_M->rtwLogInfo, "yout");
  }

  test_M->solverInfoPtr = (&test_M->solverInfo);
  test_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&test_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test_M->ModelData.blockIO = ((void *) &test_B);
  (void) memset(((void *) &test_B), 0,
                sizeof(BlockIO_test));

  {
    test_B.HoughTransform_o2[0] = -1.5707963267948966;
    test_B.HoughTransform_o2[1] = -1.5533430342749532;
    test_B.HoughTransform_o2[2] = -1.53588974175501;
    test_B.HoughTransform_o2[3] = -1.5184364492350666;
    test_B.HoughTransform_o2[4] = -1.5009831567151235;
    test_B.HoughTransform_o2[5] = -1.4835298641951802;
    test_B.HoughTransform_o2[6] = -1.4660765716752369;
    test_B.HoughTransform_o2[7] = -1.4486232791552935;
    test_B.HoughTransform_o2[8] = -1.4311699866353502;
    test_B.HoughTransform_o2[9] = -1.4137166941154069;
    test_B.HoughTransform_o2[10] = -1.3962634015954636;
    test_B.HoughTransform_o2[11] = -1.3788101090755203;
    test_B.HoughTransform_o2[12] = -1.3613568165555769;
    test_B.HoughTransform_o2[13] = -1.3439035240356338;
    test_B.HoughTransform_o2[14] = -1.3264502315156905;
    test_B.HoughTransform_o2[15] = -1.3089969389957472;
    test_B.HoughTransform_o2[16] = -1.2915436464758039;
    test_B.HoughTransform_o2[17] = -1.2740903539558606;
    test_B.HoughTransform_o2[18] = -1.2566370614359172;
    test_B.HoughTransform_o2[19] = -1.2391837689159739;
    test_B.HoughTransform_o2[20] = -1.2217304763960306;
    test_B.HoughTransform_o2[21] = -1.2042771838760873;
    test_B.HoughTransform_o2[22] = -1.1868238913561442;
    test_B.HoughTransform_o2[23] = -1.1693705988362009;
    test_B.HoughTransform_o2[24] = -1.1519173063162575;
    test_B.HoughTransform_o2[25] = -1.1344640137963142;
    test_B.HoughTransform_o2[26] = -1.1170107212763709;
    test_B.HoughTransform_o2[27] = -1.0995574287564276;
    test_B.HoughTransform_o2[28] = -1.0821041362364843;
    test_B.HoughTransform_o2[29] = -1.064650843716541;
    test_B.HoughTransform_o2[30] = -1.0471975511965976;
    test_B.HoughTransform_o2[31] = -1.0297442586766545;
    test_B.HoughTransform_o2[32] = -1.0122909661567112;
    test_B.HoughTransform_o2[33] = -0.99483767363676789;
    test_B.HoughTransform_o2[34] = -0.97738438111682457;
    test_B.HoughTransform_o2[35] = -0.95993108859688125;
    test_B.HoughTransform_o2[36] = -0.94247779607693793;
    test_B.HoughTransform_o2[37] = -0.92502450355699462;
    test_B.HoughTransform_o2[38] = -0.90757121103705141;
    test_B.HoughTransform_o2[39] = -0.89011791851710809;
    test_B.HoughTransform_o2[40] = -0.87266462599716477;
    test_B.HoughTransform_o2[41] = -0.85521133347722145;
    test_B.HoughTransform_o2[42] = -0.83775804095727824;
    test_B.HoughTransform_o2[43] = -0.82030474843733492;
    test_B.HoughTransform_o2[44] = -0.8028514559173916;
    test_B.HoughTransform_o2[45] = -0.78539816339744828;
    test_B.HoughTransform_o2[46] = -0.767944870877505;
    test_B.HoughTransform_o2[47] = -0.75049157835756175;
    test_B.HoughTransform_o2[48] = -0.73303828583761843;
    test_B.HoughTransform_o2[49] = -0.71558499331767511;
    test_B.HoughTransform_o2[50] = -0.69813170079773179;
    test_B.HoughTransform_o2[51] = -0.68067840827778847;
    test_B.HoughTransform_o2[52] = -0.66322511575784526;
    test_B.HoughTransform_o2[53] = -0.64577182323790194;
    test_B.HoughTransform_o2[54] = -0.62831853071795862;
    test_B.HoughTransform_o2[55] = -0.6108652381980153;
    test_B.HoughTransform_o2[56] = -0.59341194567807209;
    test_B.HoughTransform_o2[57] = -0.57595865315812877;
    test_B.HoughTransform_o2[58] = -0.55850536063818546;
    test_B.HoughTransform_o2[59] = -0.54105206811824214;
    test_B.HoughTransform_o2[60] = -0.52359877559829882;
    test_B.HoughTransform_o2[61] = -0.50614548307835561;
    test_B.HoughTransform_o2[62] = -0.48869219055841229;
    test_B.HoughTransform_o2[63] = -0.47123889803846897;
    test_B.HoughTransform_o2[64] = -0.4537856055185257;
    test_B.HoughTransform_o2[65] = -0.43633231299858238;
    test_B.HoughTransform_o2[66] = -0.41887902047863912;
    test_B.HoughTransform_o2[67] = -0.4014257279586958;
    test_B.HoughTransform_o2[68] = -0.38397243543875248;
    test_B.HoughTransform_o2[69] = -0.36651914291880922;
    test_B.HoughTransform_o2[70] = -0.3490658503988659;
    test_B.HoughTransform_o2[71] = -0.33161255787892263;
    test_B.HoughTransform_o2[72] = -0.31415926535897931;
    test_B.HoughTransform_o2[73] = -0.29670597283903605;
    test_B.HoughTransform_o2[74] = -0.27925268031909273;
    test_B.HoughTransform_o2[75] = -0.26179938779914941;
    test_B.HoughTransform_o2[76] = -0.24434609527920614;
    test_B.HoughTransform_o2[77] = -0.22689280275926285;
    test_B.HoughTransform_o2[78] = -0.20943951023931956;
    test_B.HoughTransform_o2[79] = -0.19198621771937624;
    test_B.HoughTransform_o2[80] = -0.17453292519943295;
    test_B.HoughTransform_o2[81] = -0.15707963267948966;
    test_B.HoughTransform_o2[82] = -0.13962634015954636;
    test_B.HoughTransform_o2[83] = -0.12217304763960307;
    test_B.HoughTransform_o2[84] = -0.10471975511965978;
    test_B.HoughTransform_o2[85] = -0.087266462599716474;
    test_B.HoughTransform_o2[86] = -0.069813170079773182;
    test_B.HoughTransform_o2[87] = -0.05235987755982989;
    test_B.HoughTransform_o2[88] = -0.034906585039886591;
    test_B.HoughTransform_o2[89] = -0.017453292519943295;
    test_B.HoughTransform_o2[90] = 0.0;
    test_B.HoughTransform_o2[91] = 0.017453292519943295;
    test_B.HoughTransform_o2[92] = 0.034906585039886591;
    test_B.HoughTransform_o2[93] = 0.05235987755982989;
    test_B.HoughTransform_o2[94] = 0.069813170079773182;
    test_B.HoughTransform_o2[95] = 0.087266462599716474;
    test_B.HoughTransform_o2[96] = 0.10471975511965978;
    test_B.HoughTransform_o2[97] = 0.12217304763960307;
    test_B.HoughTransform_o2[98] = 0.13962634015954636;
    test_B.HoughTransform_o2[99] = 0.15707963267948966;
    test_B.HoughTransform_o2[100] = 0.17453292519943295;
    test_B.HoughTransform_o2[101] = 0.19198621771937624;
    test_B.HoughTransform_o2[102] = 0.20943951023931956;
    test_B.HoughTransform_o2[103] = 0.22689280275926285;
    test_B.HoughTransform_o2[104] = 0.24434609527920614;
    test_B.HoughTransform_o2[105] = 0.26179938779914941;
    test_B.HoughTransform_o2[106] = 0.27925268031909273;
    test_B.HoughTransform_o2[107] = 0.29670597283903605;
    test_B.HoughTransform_o2[108] = 0.31415926535897931;
    test_B.HoughTransform_o2[109] = 0.33161255787892263;
    test_B.HoughTransform_o2[110] = 0.3490658503988659;
    test_B.HoughTransform_o2[111] = 0.36651914291880922;
    test_B.HoughTransform_o2[112] = 0.38397243543875248;
    test_B.HoughTransform_o2[113] = 0.4014257279586958;
    test_B.HoughTransform_o2[114] = 0.41887902047863912;
    test_B.HoughTransform_o2[115] = 0.43633231299858238;
    test_B.HoughTransform_o2[116] = 0.4537856055185257;
    test_B.HoughTransform_o2[117] = 0.47123889803846897;
    test_B.HoughTransform_o2[118] = 0.48869219055841229;
    test_B.HoughTransform_o2[119] = 0.50614548307835561;
    test_B.HoughTransform_o2[120] = 0.52359877559829882;
    test_B.HoughTransform_o2[121] = 0.54105206811824214;
    test_B.HoughTransform_o2[122] = 0.55850536063818546;
    test_B.HoughTransform_o2[123] = 0.57595865315812877;
    test_B.HoughTransform_o2[124] = 0.59341194567807209;
    test_B.HoughTransform_o2[125] = 0.6108652381980153;
    test_B.HoughTransform_o2[126] = 0.62831853071795862;
    test_B.HoughTransform_o2[127] = 0.64577182323790194;
    test_B.HoughTransform_o2[128] = 0.66322511575784526;
    test_B.HoughTransform_o2[129] = 0.68067840827778847;
    test_B.HoughTransform_o2[130] = 0.69813170079773179;
    test_B.HoughTransform_o2[131] = 0.71558499331767511;
    test_B.HoughTransform_o2[132] = 0.73303828583761843;
    test_B.HoughTransform_o2[133] = 0.75049157835756175;
    test_B.HoughTransform_o2[134] = 0.767944870877505;
    test_B.HoughTransform_o2[135] = 0.78539816339744828;
    test_B.HoughTransform_o2[136] = 0.8028514559173916;
    test_B.HoughTransform_o2[137] = 0.82030474843733492;
    test_B.HoughTransform_o2[138] = 0.83775804095727824;
    test_B.HoughTransform_o2[139] = 0.85521133347722145;
    test_B.HoughTransform_o2[140] = 0.87266462599716477;
    test_B.HoughTransform_o2[141] = 0.89011791851710809;
    test_B.HoughTransform_o2[142] = 0.90757121103705141;
    test_B.HoughTransform_o2[143] = 0.92502450355699462;
    test_B.HoughTransform_o2[144] = 0.94247779607693793;
    test_B.HoughTransform_o2[145] = 0.95993108859688125;
    test_B.HoughTransform_o2[146] = 0.97738438111682457;
    test_B.HoughTransform_o2[147] = 0.99483767363676789;
    test_B.HoughTransform_o2[148] = 1.0122909661567112;
    test_B.HoughTransform_o2[149] = 1.0297442586766545;
    test_B.HoughTransform_o2[150] = 1.0471975511965976;
    test_B.HoughTransform_o2[151] = 1.064650843716541;
    test_B.HoughTransform_o2[152] = 1.0821041362364843;
    test_B.HoughTransform_o2[153] = 1.0995574287564276;
    test_B.HoughTransform_o2[154] = 1.1170107212763709;
    test_B.HoughTransform_o2[155] = 1.1344640137963142;
    test_B.HoughTransform_o2[156] = 1.1519173063162575;
    test_B.HoughTransform_o2[157] = 1.1693705988362009;
    test_B.HoughTransform_o2[158] = 1.1868238913561442;
    test_B.HoughTransform_o2[159] = 1.2042771838760873;
    test_B.HoughTransform_o2[160] = 1.2217304763960306;
    test_B.HoughTransform_o2[161] = 1.2391837689159739;
    test_B.HoughTransform_o2[162] = 1.2566370614359172;
    test_B.HoughTransform_o2[163] = 1.2740903539558606;
    test_B.HoughTransform_o2[164] = 1.2915436464758039;
    test_B.HoughTransform_o2[165] = 1.3089969389957472;
    test_B.HoughTransform_o2[166] = 1.3264502315156905;
    test_B.HoughTransform_o2[167] = 1.3439035240356338;
    test_B.HoughTransform_o2[168] = 1.3613568165555769;
    test_B.HoughTransform_o2[169] = 1.3788101090755203;
    test_B.HoughTransform_o2[170] = 1.3962634015954636;
    test_B.HoughTransform_o2[171] = 1.4137166941154069;
    test_B.HoughTransform_o2[172] = 1.4311699866353502;
    test_B.HoughTransform_o2[173] = 1.4486232791552935;
    test_B.HoughTransform_o2[174] = 1.4660765716752369;
    test_B.HoughTransform_o2[175] = 1.4835298641951802;
    test_B.HoughTransform_o2[176] = 1.5009831567151235;
    test_B.HoughTransform_o2[177] = 1.5184364492350666;
    test_B.HoughTransform_o2[178] = 1.53588974175501;
    test_B.HoughTransform_o2[179] = 1.5533430342749532;
    test_B.HoughTransform_o3[0] = -199.0;
    test_B.HoughTransform_o3[1] = -198.0;
    test_B.HoughTransform_o3[2] = -197.0;
    test_B.HoughTransform_o3[3] = -196.0;
    test_B.HoughTransform_o3[4] = -195.0;
    test_B.HoughTransform_o3[5] = -194.0;
    test_B.HoughTransform_o3[6] = -193.0;
    test_B.HoughTransform_o3[7] = -192.0;
    test_B.HoughTransform_o3[8] = -191.0;
    test_B.HoughTransform_o3[9] = -190.0;
    test_B.HoughTransform_o3[10] = -189.0;
    test_B.HoughTransform_o3[11] = -188.0;
    test_B.HoughTransform_o3[12] = -187.0;
    test_B.HoughTransform_o3[13] = -186.0;
    test_B.HoughTransform_o3[14] = -185.0;
    test_B.HoughTransform_o3[15] = -184.0;
    test_B.HoughTransform_o3[16] = -183.0;
    test_B.HoughTransform_o3[17] = -182.0;
    test_B.HoughTransform_o3[18] = -181.0;
    test_B.HoughTransform_o3[19] = -180.0;
    test_B.HoughTransform_o3[20] = -179.0;
    test_B.HoughTransform_o3[21] = -178.0;
    test_B.HoughTransform_o3[22] = -177.0;
    test_B.HoughTransform_o3[23] = -176.0;
    test_B.HoughTransform_o3[24] = -175.0;
    test_B.HoughTransform_o3[25] = -174.0;
    test_B.HoughTransform_o3[26] = -173.0;
    test_B.HoughTransform_o3[27] = -172.0;
    test_B.HoughTransform_o3[28] = -171.0;
    test_B.HoughTransform_o3[29] = -170.0;
    test_B.HoughTransform_o3[30] = -169.0;
    test_B.HoughTransform_o3[31] = -168.0;
    test_B.HoughTransform_o3[32] = -167.0;
    test_B.HoughTransform_o3[33] = -166.0;
    test_B.HoughTransform_o3[34] = -165.0;
    test_B.HoughTransform_o3[35] = -164.0;
    test_B.HoughTransform_o3[36] = -163.0;
    test_B.HoughTransform_o3[37] = -162.0;
    test_B.HoughTransform_o3[38] = -161.0;
    test_B.HoughTransform_o3[39] = -160.0;
    test_B.HoughTransform_o3[40] = -159.0;
    test_B.HoughTransform_o3[41] = -158.0;
    test_B.HoughTransform_o3[42] = -157.0;
    test_B.HoughTransform_o3[43] = -156.0;
    test_B.HoughTransform_o3[44] = -155.0;
    test_B.HoughTransform_o3[45] = -154.0;
    test_B.HoughTransform_o3[46] = -153.0;
    test_B.HoughTransform_o3[47] = -152.0;
    test_B.HoughTransform_o3[48] = -151.0;
    test_B.HoughTransform_o3[49] = -150.0;
    test_B.HoughTransform_o3[50] = -149.0;
    test_B.HoughTransform_o3[51] = -148.0;
    test_B.HoughTransform_o3[52] = -147.0;
    test_B.HoughTransform_o3[53] = -146.0;
    test_B.HoughTransform_o3[54] = -145.0;
    test_B.HoughTransform_o3[55] = -144.0;
    test_B.HoughTransform_o3[56] = -143.0;
    test_B.HoughTransform_o3[57] = -142.0;
    test_B.HoughTransform_o3[58] = -141.0;
    test_B.HoughTransform_o3[59] = -140.0;
    test_B.HoughTransform_o3[60] = -139.0;
    test_B.HoughTransform_o3[61] = -138.0;
    test_B.HoughTransform_o3[62] = -137.0;
    test_B.HoughTransform_o3[63] = -136.0;
    test_B.HoughTransform_o3[64] = -135.0;
    test_B.HoughTransform_o3[65] = -134.0;
    test_B.HoughTransform_o3[66] = -133.0;
    test_B.HoughTransform_o3[67] = -132.0;
    test_B.HoughTransform_o3[68] = -131.0;
    test_B.HoughTransform_o3[69] = -130.0;
    test_B.HoughTransform_o3[70] = -129.0;
    test_B.HoughTransform_o3[71] = -128.0;
    test_B.HoughTransform_o3[72] = -127.0;
    test_B.HoughTransform_o3[73] = -126.0;
    test_B.HoughTransform_o3[74] = -125.0;
    test_B.HoughTransform_o3[75] = -124.0;
    test_B.HoughTransform_o3[76] = -123.0;
    test_B.HoughTransform_o3[77] = -122.0;
    test_B.HoughTransform_o3[78] = -121.0;
    test_B.HoughTransform_o3[79] = -120.0;
    test_B.HoughTransform_o3[80] = -119.0;
    test_B.HoughTransform_o3[81] = -118.0;
    test_B.HoughTransform_o3[82] = -117.0;
    test_B.HoughTransform_o3[83] = -116.0;
    test_B.HoughTransform_o3[84] = -115.0;
    test_B.HoughTransform_o3[85] = -114.0;
    test_B.HoughTransform_o3[86] = -113.0;
    test_B.HoughTransform_o3[87] = -112.0;
    test_B.HoughTransform_o3[88] = -111.0;
    test_B.HoughTransform_o3[89] = -110.0;
    test_B.HoughTransform_o3[90] = -109.0;
    test_B.HoughTransform_o3[91] = -108.0;
    test_B.HoughTransform_o3[92] = -107.0;
    test_B.HoughTransform_o3[93] = -106.0;
    test_B.HoughTransform_o3[94] = -105.0;
    test_B.HoughTransform_o3[95] = -104.0;
    test_B.HoughTransform_o3[96] = -103.0;
    test_B.HoughTransform_o3[97] = -102.0;
    test_B.HoughTransform_o3[98] = -101.0;
    test_B.HoughTransform_o3[99] = -100.0;
    test_B.HoughTransform_o3[100] = -99.0;
    test_B.HoughTransform_o3[101] = -98.0;
    test_B.HoughTransform_o3[102] = -97.0;
    test_B.HoughTransform_o3[103] = -96.0;
    test_B.HoughTransform_o3[104] = -95.0;
    test_B.HoughTransform_o3[105] = -94.0;
    test_B.HoughTransform_o3[106] = -93.0;
    test_B.HoughTransform_o3[107] = -92.0;
    test_B.HoughTransform_o3[108] = -91.0;
    test_B.HoughTransform_o3[109] = -90.0;
    test_B.HoughTransform_o3[110] = -89.0;
    test_B.HoughTransform_o3[111] = -88.0;
    test_B.HoughTransform_o3[112] = -87.0;
    test_B.HoughTransform_o3[113] = -86.0;
    test_B.HoughTransform_o3[114] = -85.0;
    test_B.HoughTransform_o3[115] = -84.0;
    test_B.HoughTransform_o3[116] = -83.0;
    test_B.HoughTransform_o3[117] = -82.0;
    test_B.HoughTransform_o3[118] = -81.0;
    test_B.HoughTransform_o3[119] = -80.0;
    test_B.HoughTransform_o3[120] = -79.0;
    test_B.HoughTransform_o3[121] = -78.0;
    test_B.HoughTransform_o3[122] = -77.0;
    test_B.HoughTransform_o3[123] = -76.0;
    test_B.HoughTransform_o3[124] = -75.0;
    test_B.HoughTransform_o3[125] = -74.0;
    test_B.HoughTransform_o3[126] = -73.0;
    test_B.HoughTransform_o3[127] = -72.0;
    test_B.HoughTransform_o3[128] = -71.0;
    test_B.HoughTransform_o3[129] = -70.0;
    test_B.HoughTransform_o3[130] = -69.0;
    test_B.HoughTransform_o3[131] = -68.0;
    test_B.HoughTransform_o3[132] = -67.0;
    test_B.HoughTransform_o3[133] = -66.0;
    test_B.HoughTransform_o3[134] = -65.0;
    test_B.HoughTransform_o3[135] = -64.0;
    test_B.HoughTransform_o3[136] = -63.0;
    test_B.HoughTransform_o3[137] = -62.0;
    test_B.HoughTransform_o3[138] = -61.0;
    test_B.HoughTransform_o3[139] = -60.0;
    test_B.HoughTransform_o3[140] = -59.0;
    test_B.HoughTransform_o3[141] = -58.0;
    test_B.HoughTransform_o3[142] = -57.0;
    test_B.HoughTransform_o3[143] = -56.0;
    test_B.HoughTransform_o3[144] = -55.0;
    test_B.HoughTransform_o3[145] = -54.0;
    test_B.HoughTransform_o3[146] = -53.0;
    test_B.HoughTransform_o3[147] = -52.0;
    test_B.HoughTransform_o3[148] = -51.0;
    test_B.HoughTransform_o3[149] = -50.0;
    test_B.HoughTransform_o3[150] = -49.0;
    test_B.HoughTransform_o3[151] = -48.0;
    test_B.HoughTransform_o3[152] = -47.0;
    test_B.HoughTransform_o3[153] = -46.0;
    test_B.HoughTransform_o3[154] = -45.0;
    test_B.HoughTransform_o3[155] = -44.0;
    test_B.HoughTransform_o3[156] = -43.0;
    test_B.HoughTransform_o3[157] = -42.0;
    test_B.HoughTransform_o3[158] = -41.0;
    test_B.HoughTransform_o3[159] = -40.0;
    test_B.HoughTransform_o3[160] = -39.0;
    test_B.HoughTransform_o3[161] = -38.0;
    test_B.HoughTransform_o3[162] = -37.0;
    test_B.HoughTransform_o3[163] = -36.0;
    test_B.HoughTransform_o3[164] = -35.0;
    test_B.HoughTransform_o3[165] = -34.0;
    test_B.HoughTransform_o3[166] = -33.0;
    test_B.HoughTransform_o3[167] = -32.0;
    test_B.HoughTransform_o3[168] = -31.0;
    test_B.HoughTransform_o3[169] = -30.0;
    test_B.HoughTransform_o3[170] = -29.0;
    test_B.HoughTransform_o3[171] = -28.0;
    test_B.HoughTransform_o3[172] = -27.0;
    test_B.HoughTransform_o3[173] = -26.0;
    test_B.HoughTransform_o3[174] = -25.0;
    test_B.HoughTransform_o3[175] = -24.0;
    test_B.HoughTransform_o3[176] = -23.0;
    test_B.HoughTransform_o3[177] = -22.0;
    test_B.HoughTransform_o3[178] = -21.0;
    test_B.HoughTransform_o3[179] = -20.0;
    test_B.HoughTransform_o3[180] = -19.0;
    test_B.HoughTransform_o3[181] = -18.0;
    test_B.HoughTransform_o3[182] = -17.0;
    test_B.HoughTransform_o3[183] = -16.0;
    test_B.HoughTransform_o3[184] = -15.0;
    test_B.HoughTransform_o3[185] = -14.0;
    test_B.HoughTransform_o3[186] = -13.0;
    test_B.HoughTransform_o3[187] = -12.0;
    test_B.HoughTransform_o3[188] = -11.0;
    test_B.HoughTransform_o3[189] = -10.0;
    test_B.HoughTransform_o3[190] = -9.0;
    test_B.HoughTransform_o3[191] = -8.0;
    test_B.HoughTransform_o3[192] = -7.0;
    test_B.HoughTransform_o3[193] = -6.0;
    test_B.HoughTransform_o3[194] = -5.0;
    test_B.HoughTransform_o3[195] = -4.0;
    test_B.HoughTransform_o3[196] = -3.0;
    test_B.HoughTransform_o3[197] = -2.0;
    test_B.HoughTransform_o3[198] = -1.0;
    test_B.HoughTransform_o3[199] = 0.0;
    test_B.HoughTransform_o3[200] = 1.0;
    test_B.HoughTransform_o3[201] = 2.0;
    test_B.HoughTransform_o3[202] = 3.0;
    test_B.HoughTransform_o3[203] = 4.0;
    test_B.HoughTransform_o3[204] = 5.0;
    test_B.HoughTransform_o3[205] = 6.0;
    test_B.HoughTransform_o3[206] = 7.0;
    test_B.HoughTransform_o3[207] = 8.0;
    test_B.HoughTransform_o3[208] = 9.0;
    test_B.HoughTransform_o3[209] = 10.0;
    test_B.HoughTransform_o3[210] = 11.0;
    test_B.HoughTransform_o3[211] = 12.0;
    test_B.HoughTransform_o3[212] = 13.0;
    test_B.HoughTransform_o3[213] = 14.0;
    test_B.HoughTransform_o3[214] = 15.0;
    test_B.HoughTransform_o3[215] = 16.0;
    test_B.HoughTransform_o3[216] = 17.0;
    test_B.HoughTransform_o3[217] = 18.0;
    test_B.HoughTransform_o3[218] = 19.0;
    test_B.HoughTransform_o3[219] = 20.0;
    test_B.HoughTransform_o3[220] = 21.0;
    test_B.HoughTransform_o3[221] = 22.0;
    test_B.HoughTransform_o3[222] = 23.0;
    test_B.HoughTransform_o3[223] = 24.0;
    test_B.HoughTransform_o3[224] = 25.0;
    test_B.HoughTransform_o3[225] = 26.0;
    test_B.HoughTransform_o3[226] = 27.0;
    test_B.HoughTransform_o3[227] = 28.0;
    test_B.HoughTransform_o3[228] = 29.0;
    test_B.HoughTransform_o3[229] = 30.0;
    test_B.HoughTransform_o3[230] = 31.0;
    test_B.HoughTransform_o3[231] = 32.0;
    test_B.HoughTransform_o3[232] = 33.0;
    test_B.HoughTransform_o3[233] = 34.0;
    test_B.HoughTransform_o3[234] = 35.0;
    test_B.HoughTransform_o3[235] = 36.0;
    test_B.HoughTransform_o3[236] = 37.0;
    test_B.HoughTransform_o3[237] = 38.0;
    test_B.HoughTransform_o3[238] = 39.0;
    test_B.HoughTransform_o3[239] = 40.0;
    test_B.HoughTransform_o3[240] = 41.0;
    test_B.HoughTransform_o3[241] = 42.0;
    test_B.HoughTransform_o3[242] = 43.0;
    test_B.HoughTransform_o3[243] = 44.0;
    test_B.HoughTransform_o3[244] = 45.0;
    test_B.HoughTransform_o3[245] = 46.0;
    test_B.HoughTransform_o3[246] = 47.0;
    test_B.HoughTransform_o3[247] = 48.0;
    test_B.HoughTransform_o3[248] = 49.0;
    test_B.HoughTransform_o3[249] = 50.0;
    test_B.HoughTransform_o3[250] = 51.0;
    test_B.HoughTransform_o3[251] = 52.0;
    test_B.HoughTransform_o3[252] = 53.0;
    test_B.HoughTransform_o3[253] = 54.0;
    test_B.HoughTransform_o3[254] = 55.0;
    test_B.HoughTransform_o3[255] = 56.0;
    test_B.HoughTransform_o3[256] = 57.0;
    test_B.HoughTransform_o3[257] = 58.0;
    test_B.HoughTransform_o3[258] = 59.0;
    test_B.HoughTransform_o3[259] = 60.0;
    test_B.HoughTransform_o3[260] = 61.0;
    test_B.HoughTransform_o3[261] = 62.0;
    test_B.HoughTransform_o3[262] = 63.0;
    test_B.HoughTransform_o3[263] = 64.0;
    test_B.HoughTransform_o3[264] = 65.0;
    test_B.HoughTransform_o3[265] = 66.0;
    test_B.HoughTransform_o3[266] = 67.0;
    test_B.HoughTransform_o3[267] = 68.0;
    test_B.HoughTransform_o3[268] = 69.0;
    test_B.HoughTransform_o3[269] = 70.0;
    test_B.HoughTransform_o3[270] = 71.0;
    test_B.HoughTransform_o3[271] = 72.0;
    test_B.HoughTransform_o3[272] = 73.0;
    test_B.HoughTransform_o3[273] = 74.0;
    test_B.HoughTransform_o3[274] = 75.0;
    test_B.HoughTransform_o3[275] = 76.0;
    test_B.HoughTransform_o3[276] = 77.0;
    test_B.HoughTransform_o3[277] = 78.0;
    test_B.HoughTransform_o3[278] = 79.0;
    test_B.HoughTransform_o3[279] = 80.0;
    test_B.HoughTransform_o3[280] = 81.0;
    test_B.HoughTransform_o3[281] = 82.0;
    test_B.HoughTransform_o3[282] = 83.0;
    test_B.HoughTransform_o3[283] = 84.0;
    test_B.HoughTransform_o3[284] = 85.0;
    test_B.HoughTransform_o3[285] = 86.0;
    test_B.HoughTransform_o3[286] = 87.0;
    test_B.HoughTransform_o3[287] = 88.0;
    test_B.HoughTransform_o3[288] = 89.0;
    test_B.HoughTransform_o3[289] = 90.0;
    test_B.HoughTransform_o3[290] = 91.0;
    test_B.HoughTransform_o3[291] = 92.0;
    test_B.HoughTransform_o3[292] = 93.0;
    test_B.HoughTransform_o3[293] = 94.0;
    test_B.HoughTransform_o3[294] = 95.0;
    test_B.HoughTransform_o3[295] = 96.0;
    test_B.HoughTransform_o3[296] = 97.0;
    test_B.HoughTransform_o3[297] = 98.0;
    test_B.HoughTransform_o3[298] = 99.0;
    test_B.HoughTransform_o3[299] = 100.0;
    test_B.HoughTransform_o3[300] = 101.0;
    test_B.HoughTransform_o3[301] = 102.0;
    test_B.HoughTransform_o3[302] = 103.0;
    test_B.HoughTransform_o3[303] = 104.0;
    test_B.HoughTransform_o3[304] = 105.0;
    test_B.HoughTransform_o3[305] = 106.0;
    test_B.HoughTransform_o3[306] = 107.0;
    test_B.HoughTransform_o3[307] = 108.0;
    test_B.HoughTransform_o3[308] = 109.0;
    test_B.HoughTransform_o3[309] = 110.0;
    test_B.HoughTransform_o3[310] = 111.0;
    test_B.HoughTransform_o3[311] = 112.0;
    test_B.HoughTransform_o3[312] = 113.0;
    test_B.HoughTransform_o3[313] = 114.0;
    test_B.HoughTransform_o3[314] = 115.0;
    test_B.HoughTransform_o3[315] = 116.0;
    test_B.HoughTransform_o3[316] = 117.0;
    test_B.HoughTransform_o3[317] = 118.0;
    test_B.HoughTransform_o3[318] = 119.0;
    test_B.HoughTransform_o3[319] = 120.0;
    test_B.HoughTransform_o3[320] = 121.0;
    test_B.HoughTransform_o3[321] = 122.0;
    test_B.HoughTransform_o3[322] = 123.0;
    test_B.HoughTransform_o3[323] = 124.0;
    test_B.HoughTransform_o3[324] = 125.0;
    test_B.HoughTransform_o3[325] = 126.0;
    test_B.HoughTransform_o3[326] = 127.0;
    test_B.HoughTransform_o3[327] = 128.0;
    test_B.HoughTransform_o3[328] = 129.0;
    test_B.HoughTransform_o3[329] = 130.0;
    test_B.HoughTransform_o3[330] = 131.0;
    test_B.HoughTransform_o3[331] = 132.0;
    test_B.HoughTransform_o3[332] = 133.0;
    test_B.HoughTransform_o3[333] = 134.0;
    test_B.HoughTransform_o3[334] = 135.0;
    test_B.HoughTransform_o3[335] = 136.0;
    test_B.HoughTransform_o3[336] = 137.0;
    test_B.HoughTransform_o3[337] = 138.0;
    test_B.HoughTransform_o3[338] = 139.0;
    test_B.HoughTransform_o3[339] = 140.0;
    test_B.HoughTransform_o3[340] = 141.0;
    test_B.HoughTransform_o3[341] = 142.0;
    test_B.HoughTransform_o3[342] = 143.0;
    test_B.HoughTransform_o3[343] = 144.0;
    test_B.HoughTransform_o3[344] = 145.0;
    test_B.HoughTransform_o3[345] = 146.0;
    test_B.HoughTransform_o3[346] = 147.0;
    test_B.HoughTransform_o3[347] = 148.0;
    test_B.HoughTransform_o3[348] = 149.0;
    test_B.HoughTransform_o3[349] = 150.0;
    test_B.HoughTransform_o3[350] = 151.0;
    test_B.HoughTransform_o3[351] = 152.0;
    test_B.HoughTransform_o3[352] = 153.0;
    test_B.HoughTransform_o3[353] = 154.0;
    test_B.HoughTransform_o3[354] = 155.0;
    test_B.HoughTransform_o3[355] = 156.0;
    test_B.HoughTransform_o3[356] = 157.0;
    test_B.HoughTransform_o3[357] = 158.0;
    test_B.HoughTransform_o3[358] = 159.0;
    test_B.HoughTransform_o3[359] = 160.0;
    test_B.HoughTransform_o3[360] = 161.0;
    test_B.HoughTransform_o3[361] = 162.0;
    test_B.HoughTransform_o3[362] = 163.0;
    test_B.HoughTransform_o3[363] = 164.0;
    test_B.HoughTransform_o3[364] = 165.0;
    test_B.HoughTransform_o3[365] = 166.0;
    test_B.HoughTransform_o3[366] = 167.0;
    test_B.HoughTransform_o3[367] = 168.0;
    test_B.HoughTransform_o3[368] = 169.0;
    test_B.HoughTransform_o3[369] = 170.0;
    test_B.HoughTransform_o3[370] = 171.0;
    test_B.HoughTransform_o3[371] = 172.0;
    test_B.HoughTransform_o3[372] = 173.0;
    test_B.HoughTransform_o3[373] = 174.0;
    test_B.HoughTransform_o3[374] = 175.0;
    test_B.HoughTransform_o3[375] = 176.0;
    test_B.HoughTransform_o3[376] = 177.0;
    test_B.HoughTransform_o3[377] = 178.0;
    test_B.HoughTransform_o3[378] = 179.0;
    test_B.HoughTransform_o3[379] = 180.0;
    test_B.HoughTransform_o3[380] = 181.0;
    test_B.HoughTransform_o3[381] = 182.0;
    test_B.HoughTransform_o3[382] = 183.0;
    test_B.HoughTransform_o3[383] = 184.0;
    test_B.HoughTransform_o3[384] = 185.0;
    test_B.HoughTransform_o3[385] = 186.0;
    test_B.HoughTransform_o3[386] = 187.0;
    test_B.HoughTransform_o3[387] = 188.0;
    test_B.HoughTransform_o3[388] = 189.0;
    test_B.HoughTransform_o3[389] = 190.0;
    test_B.HoughTransform_o3[390] = 191.0;
    test_B.HoughTransform_o3[391] = 192.0;
    test_B.HoughTransform_o3[392] = 193.0;
    test_B.HoughTransform_o3[393] = 194.0;
    test_B.HoughTransform_o3[394] = 195.0;
    test_B.HoughTransform_o3[395] = 196.0;
    test_B.HoughTransform_o3[396] = 197.0;
    test_B.HoughTransform_o3[397] = 198.0;
    test_B.HoughTransform_o3[398] = 199.0;
  }

  /* parameters */
  test_M->ModelData.defaultParam = ((real_T *)&test_P);

  /* states (dwork) */
  test_M->Work.dwork = ((void *) &test_DWork);
  (void) memset((void *)&test_DWork, 0,
                sizeof(D_Work_test));

  /* external inputs */
  test_M->ModelData.inputs = (((void*)&test_U));
  (void) memset((void *)&test_U, 0,
                sizeof(ExternalInputs_test));

  /* external outputs */
  test_M->ModelData.outputs = (&test_Y);
  (void) memset(&test_Y.Out1[0], 0,
                19200U*sizeof(real_T));
}

/* Model terminate function */
void test_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
extern "C" void MdlOutputs(int_T tid)
{
  test_output(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  test_update(tid);
}

extern "C" void MdlInitializeSizes(void)
{
  test_M->Sizes.numContStates = (0);   /* Number of continuous states */
  test_M->Sizes.numY = (19200);        /* Number of model outputs */
  test_M->Sizes.numU = (57600);        /* Number of model inputs */
  test_M->Sizes.sysDirFeedThru = (1);  /* The model is direct feedthrough */
  test_M->Sizes.numSampTimes = (1);    /* Number of sample times */
  test_M->Sizes.numBlocks = (13);      /* Number of blocks */
  test_M->Sizes.numBlockIO = (7);      /* Number of block outputs */
  test_M->Sizes.numBlockPrms = (2);    /* Sum of parameter "widths" */
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
  {
    int32_T nonZeroIdx;

    /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
    test_DWork.EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
    for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
      test_DWork.EdgeDetection_VO_DW[nonZeroIdx] =
        test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      if (test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
        test_DWork.EdgeDetection_VOU_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOD_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      } else {
        test_DWork.EdgeDetection_VOU_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_VOD_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if (test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
        test_DWork.EdgeDetection_VOL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      } else {
        test_DWork.EdgeDetection_VOL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if ((test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        test_DWork.EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_VOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      }

      if ((test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        test_DWork.EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_VOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      }

      if ((test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        test_DWork.EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_VOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_VOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if ((test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        test_DWork.EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_VOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_VOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_VOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      test_DWork.EdgeDetection_HO_DW[nonZeroIdx] =
        test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      if (test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
        test_DWork.EdgeDetection_HOU_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOD_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      } else {
        test_DWork.EdgeDetection_HOU_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_HOD_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if (test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
        test_DWork.EdgeDetection_HOL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      } else {
        test_DWork.EdgeDetection_HOL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if ((test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        test_DWork.EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_HOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      }

      if ((test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        test_DWork.EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_HOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      }

      if ((test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        test_DWork.EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_HOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_HOLR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if ((test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        test_DWork.EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
        test_DWork.EdgeDetection_HOUL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        test_DWork.EdgeDetection_HOLL_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
        test_DWork.EdgeDetection_HOUR_DW[nonZeroIdx] =
          test_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }
    }
  }
}

extern "C" void MdlStart(void)
{
  /* Start for S-Function (svipfindlocalmax): '<Root>/Find Local Maxima' */
  test_DWork.FindLocalMaxima_DIMS1[0] = 2;
  MdlInitialize();
}

extern "C" void MdlTerminate(void)
{
  test_terminate();
}

extern "C" RT_MODEL_test *test(void)
{
  test_initialize(1);
  return test_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
