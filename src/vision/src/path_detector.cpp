/*
 * File: path_detector.cpp
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.215
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:51:10 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:51:10 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "path_detector.h"
#include "path_detector_private.h"

/* Initial conditions for referenced model: 'path_detector' */
void mr_path_detector_Init(rtDW_mr_path_detector *localDW)
{
  int32_T nonZeroIdx;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
      path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    if (path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
      path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    if (path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }
}

/* Output and update for referenced model: 'path_detector' */
void mr_path_detector(const real_T rtu_R_in[19200], const real_T rtu_G_in[19200],
                      const real_T rtu_B_in[19200], rtB_mr_path_detector *localB,
                      rtDW_mr_path_detector *localDW)
{
  int32_T imgCol;
  int32_T imgRow;
  real_T accumOne;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  int32_T imgIdx_r;

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  for (imgIdx_r = 0; imgIdx_r < 19200; imgIdx_r++) {
    /* First get the min and max of the RGB triplet */
    if (rtu_R_in[imgIdx_r] > rtu_G_in[imgIdx_r]) {
      if (rtu_G_in[imgIdx_r] < rtu_B_in[imgIdx_r]) {
        accumOne = rtu_G_in[imgIdx_r];
      } else {
        accumOne = rtu_B_in[imgIdx_r];
      }

      if (rtu_R_in[imgIdx_r] > rtu_B_in[imgIdx_r]) {
        accumThree = rtu_R_in[imgIdx_r];
      } else {
        accumThree = rtu_B_in[imgIdx_r];
      }
    } else {
      if (rtu_R_in[imgIdx_r] < rtu_B_in[imgIdx_r]) {
        accumOne = rtu_R_in[imgIdx_r];
      } else {
        accumOne = rtu_B_in[imgIdx_r];
      }

      if (rtu_G_in[imgIdx_r] > rtu_B_in[imgIdx_r]) {
        accumThree = rtu_G_in[imgIdx_r];
      } else {
        accumThree = rtu_B_in[imgIdx_r];
      }
    }

    accumOne = accumThree - accumOne;
    if (accumThree != 0.0) {
      accumTwo = accumOne / accumThree;
    } else {
      accumTwo = 0.0;
    }

    if (accumOne != 0.0) {
      if (rtu_R_in[imgIdx_r] == accumThree) {
        accumOne = (rtu_G_in[imgIdx_r] - rtu_B_in[imgIdx_r]) / accumOne;
      } else if (rtu_G_in[imgIdx_r] == accumThree) {
        accumOne = (rtu_B_in[imgIdx_r] - rtu_R_in[imgIdx_r]) / accumOne + 2.0;
      } else {
        accumOne = (rtu_R_in[imgIdx_r] - rtu_G_in[imgIdx_r]) / accumOne + 4.0;
      }

      accumOne /= 6.0;
      if (accumOne < 0.0) {
        accumOne++;
      }
    } else {
      accumOne = 0.0;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdx_r] = accumOne;
    localB->ColorSpaceConversion1_o2[imgIdx_r] = accumTwo;
    localB->ColorSpaceConversion1_o3[imgIdx_r] = accumThree;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  for (imgIdx_r = 0; imgIdx_r < 19200; imgIdx_r++) {
    localB->EdgeDetection[imgIdx_r] = (localB->ColorSpaceConversion1_o3[imgIdx_r]
      != 0.0);
  }

  /* Embedded MATLAB: '<Root>/CheckConditions' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* Embedded MATLAB Function 'CheckConditions': '<S1>:1' */
  /*  This function checks the conditions to decide if a track is present */

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* { */
  /* Author: Yama Habib */
  /* Revision: 10/27/2010 */
  /* CentroidVertScan takes a black and white matrix (the expected output of */
  /* the blob detection algorithm) with a single (rectangular) object detected, */
  /* and returns the raw matrix coordinate of the centroid of the object. To */
  /* convert to an angular heading, use the Centroid2Heading function. */
  /*  */
  /* Should these be parameters? I think they're fine as constants. */
  /* WIDTH = size(bwMatrix, 2); */
  /* HEIGHT = size(bwMatrix, 1); */
  /*  */
  /* increase the x step to increase efficiency. The further this */
  /* number is from 1, the closer the object will have to be to be detected */
  /* NOTE: find the max distance the hedge will be from the AUV, then find the */
  /* optimal (lowest working) x step for that distance! */
  /* X_STEP = 1; */
  /* Y_STEP = 1; */
  /*  */
  /* Don't detect lines unless they are longer than HEIGHT*THRESHOLD */
  /* THRESHOLD = 0.1; */
  /*  */
  /* Allocate arrays...allocate more or less memory depending on how many lines */
  /* are found in the average case */
  /* lineLengths = zeros(WIDTH,1); */
  /* lineMidpts_y = zeros(WIDTH,1); */
  /* lineMidpts_x = zeros(WIDTH,1); */
  /*  */
  /* Find vertical lines */
  /* index = 1; */
  /* i = 1; */
  /* while(i <= WIDTH) */
  /*     j = 1; */
  /*     while(j <= HEIGHT) */
  /*         %skip whitespace */
  /*         while(bwMatrix(j,floor(i)) == 0) */
  /*         while(bwMatrix(floor(i),j) == 0) */
  /*             j = j+1; */
  /*             if(j > HEIGHT) */
  /*                 break; */
  /*             end */
  /*         end */
  /*         %count contiguous blackspace */
  /*         if(j <= HEIGHT) */
  /*             length = 0; */
  /*             midpt = j; */
  /*             while(bwMatrix(floor(i),j) ~= 0) */
  /*                 length = length+1; */
  /*                 j = j+1; */
  /*                 if(j > HEIGHT) */
  /*                     break; */
  /*                 end */
  /*             end */
  /*             midpt = midpt + length/2; */
  /*             %only register as a line if longer than HEIGHT*THRESHOLD */
  /*             if(length > HEIGHT*THRESHOLD) */
  /*                 lineLengths(index) = length; */
  /*                 lineMidpts_y(index) = midpt; */
  /*                 lineMidpts_x(index) = floor(i); */
  /*                 index = index+1; */
  /*             end */
  /*         end */
  /*         %rinse, repeat */
  /*     end */
  /*     i = i+X_STEP; */
  /* end */
  /*  */
  /* Find maximum (longest rightmost) and minimum (longest leftmost) vertical */
  /* lines */
  /* i = 1; */
  /* min = 1; */
  /* max = 1; */
  /* while(i <= index); */
  /*      */
  /*     % The following comparisons seek to minimize and maximize the metric */
  /*     %   " length*( width - x_midpt ) ". This effectively finds the largest */
  /*     %   leftmost and rightmost vertical lines. */
  /*      */
  /*     % This if statement should be "<" instead of ">" ?? */
  /*     if(lineLengths(i)*(WIDTH-lineMidpts_x(i)) > lineLengths(min)*(WIDTH-lineMidpts_x(min))) */
  /*         min = i; */
  /*     end */
  /*     % This if statement should be correct */
  /*     if(lineLengths(i)*(lineMidpts_x(i)) >= lineLengths(max)*(lineMidpts_x(max))) */
  /*         max = i; */
  /*     end */
  /*     i = i+1; */
  /* end */
  /*  */
  /* The centroid is (should be) the midpoint between the max's midpoint and */
  /* the min's midpoint */
  /*  The assumption made is that the rightmost and leftmost lines bound a */
  /*  vertically-oriented rectangular path */
  /* centroid_x = (lineMidpts_x(min) + lineMidpts_x(max))/2; */
  /* centroid_y = (lineMidpts_y(min) + lineMidpts_y(max))/2; */
  /* end */
  /*  */
  /* } */
  /* { */
  /*  */
  /*  The following is the old code: */
  /*  */
  /* function [centroid_x, centroid_y] = CentroidVertScan(bwMatrix) */
  /* Author: Yama Habib */
  /* Revision: 10/27/2010 */
  /* CentroidVertScan takes a black and white matrix (the expected output of */
  /* the blob detection algorithm) with a single (rectangular) object detected, */
  /* and returns the raw matrix coordinate of the centroid of the object. To */
  /* convert to an angular heading, use the Centroid2Heading function. */
  /*  */
  /* Should these be parameters? I think they're fine as constants. */
  /* WIDTH = size(bwMatrix, 2); */
  /* HEIGHT = size(bwMatrix, 1); */
  /* WIDTH = 160; */
  /* HEIGHT = 120; */
  /*  */
  /* increase the x step to increase efficiency. The further this */
  /* number is from 1, the closer the object will have to be to be detected */
  /* NOTE: find the max distance the hedge will be from the AUV, then find the */
  /* optimal (lowest working) x step for that distance! */
  /* X_STEP = 1; */
  /*  */
  /* Don't detect lines unless they are longer than HEIGHT*THRESHOLD */
  /* THRESHOLD = 0.1; */
  /*  */
  /* Allocate arrays...allocate more or less memory depending on how many lines */
  /* are found in the average case */
  /* lineLengths = zeros(WIDTH,1); */
  /* lineMidpts_y = zeros(WIDTH,1); */
  /* lineMidpts_x = zeros(WIDTH,1); */
  /*  */
  /* Find vertical lines */
  /* index = 1; */
  /* i = 1; */
  /* while(i <= WIDTH) */
  /*     j = 1; */
  /*     while(j <= HEIGHT) */
  /*         %skip whitespace */
  /*         while(bwMatrix(j,floor(i)) == 0) */
  /*         while(bwMatrix(floor(i),j) == 0) */
  /*             j = j+1; */
  /*             if(j > HEIGHT) */
  /*                 break; */
  /*             end */
  /*         end */
  /*         %count contiguous blackspace */
  /*         if(j <= HEIGHT) */
  /*             length = 0; */
  /*             midpt = j; */
  /*             while(bwMatrix(floor(i),j) ~= 0) */
  /*                 length = length+1; */
  /*                 j = j+1; */
  /*                 if(j > HEIGHT) */
  /*                     break; */
  /*                 end */
  /*             end */
  /*             midpt = midpt + length/2; */
  /*             %only register as a line if longer than HEIGHT*THRESHOLD */
  /*             if(length > HEIGHT*THRESHOLD) */
  /*                 lineLengths(index) = length; */
  /*                 lineMidpts_y(index) = midpt; */
  /*                 lineMidpts_x(index) = floor(i); */
  /*                 index = index+1; */
  /*             end */
  /*         end */
  /*         %rinse, repeat */
  /*     end */
  /*     i = i+X_STEP; */
  /* end */
  /*  */
  /* Find maximum (longest rightmost) and minimum (longest leftmost) vertical */
  /* lines */
  /* i = 1; */
  /* min = 1; */
  /* max = 1; */
  /* while(i <= index); */
  /*      */
  /*     % The following comparisons seek to minimize and maximize the metric */
  /*     %   " length*( width - x_midpt ) ". This effectively finds the largest */
  /*     %   leftmost and rightmost vertical lines. */
  /*      */
  /*     % This if statement should be "<" instead of ">" ?? */
  /*     if(lineLengths(i)*(WIDTH-lineMidpts_x(i)) > lineLengths(min)*(WIDTH-lineMidpts_x(min))) */
  /*         min = i; */
  /*     end */
  /*     % This if statement should be correct */
  /*     if(lineLengths(i)*(lineMidpts_x(i)) >= lineLengths(max)*(lineMidpts_x(max))) */
  /*         max = i; */
  /*     end */
  /*     i = i+1; */
  /* end */
  /*  */
  /* The centroid is (should be) the midpoint between the max's midpoint and */
  /* the min's midpoint */
  /*  The assumption made is that the rightmost and leftmost lines bound a */
  /*  vertically-oriented rectangular path */
  /* centroid_x = (lineMidpts_x(min) + lineMidpts_x(max))/2; */
  /* centroid_y = (lineMidpts_y(min) + lineMidpts_y(max))/2; */
  /* end */
  /*  */
  /* } */

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 1; imgCol < 159; imgCol++) {
    for (imgRow = 1; imgRow < 119; imgRow++) {
      accumOne = 0.0;
      accumTwo = 0.0;
      imgIdx_r = imgCol * 120 + imgRow;
      for (m = 0; m < 6; m++) {
        accumOne += localB->ColorSpaceConversion1_o3[imgIdx_r +
          localDW->EdgeDetection_VO_DW[m]] *
          path_detector_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += localB->ColorSpaceConversion1_o3[imgIdx_r +
          localDW->EdgeDetection_HO_DW[m]] *
          path_detector_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumOne * accumOne;
      localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumTwo * accumTwo;
    }
  }

  for (imgCol = 1; imgCol < 159; imgCol++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    imgIdx_r = imgCol * 120;
    imgRow = imgCol * 120 + 119;
    for (m = 0; m < 6; m++) {
      accumOne += localB->ColorSpaceConversion1_o3[imgIdx_r +
        localDW->EdgeDetection_HOU_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += localB->ColorSpaceConversion1_o3[imgRow +
        localDW->EdgeDetection_HOD_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += localB->ColorSpaceConversion1_o3[imgIdx_r +
        localDW->EdgeDetection_VOU_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += localB->ColorSpaceConversion1_o3[imgRow +
        localDW->EdgeDetection_VOD_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumThree * accumThree;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumOne * accumOne;
    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = accumTwo * accumTwo;
  }

  for (imgRow = 1; imgRow < 119; imgRow++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    imgIdx_r = 19080 + imgRow;
    for (m = 0; m < 6; m++) {
      accumOne += localB->ColorSpaceConversion1_o3[imgRow +
        localDW->EdgeDetection_VOL_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += localB->ColorSpaceConversion1_o3[imgIdx_r +
        localDW->EdgeDetection_VOR_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += localB->ColorSpaceConversion1_o3[imgRow +
        localDW->EdgeDetection_HOL_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += localB->ColorSpaceConversion1_o3[imgIdx_r +
        localDW->EdgeDetection_HOR_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = accumOne * accumOne;
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = accumThree * accumThree;
    localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumTwo * accumTwo;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumFour * accumFour;
  }

  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += localB->ColorSpaceConversion1_o3[localDW->
      EdgeDetection_VOUL_DW[m]] * path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->ColorSpaceConversion1_o3[localDW->
      EdgeDetection_HOUL_DW[m]] * path_detector_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->ColorSpaceConversion1_o3[119 +
      localDW->EdgeDetection_VOLL_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->ColorSpaceConversion1_o3[119 +
      localDW->EdgeDetection_HOLL_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[119] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[119] = accumFour * accumFour;
  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += localB->ColorSpaceConversion1_o3[19080 +
      localDW->EdgeDetection_VOUR_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->ColorSpaceConversion1_o3[19080 +
      localDW->EdgeDetection_HOUR_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->ColorSpaceConversion1_o3[19199 +
      localDW->EdgeDetection_VOLR_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->ColorSpaceConversion1_o3[19199 +
      localDW->EdgeDetection_HOLR_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[19080] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[19080] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[19199] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[19199] = accumFour * accumFour;
  accumTwo = 0.0;
  for (m = 0; m < 19200; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->EdgeDetection_GRAD_SUM_DW[m]
      + localDW->EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += localDW->EdgeDetection_GRAD_SUM_DW[m] *
      localDW->EdgeDetection_MEAN_FACTOR_DW;
  }

  accumOne = 3.0 * accumTwo;
  for (imgCol = 0; imgCol < 160; imgCol++) {
    for (imgRow = 0; imgRow < 120; imgRow++) {
      m = imgCol * 120 + imgRow;
      localB->EdgeDetection[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] >
        accumOne) && (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (imgCol != 0
        ? localDW->EdgeDetection_GRAD_SUM_DW[m - 120] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgCol != 159 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 120] : TRUE)) ||
                      ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (imgRow != 0
        ? localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgRow != 119 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function1': '<S3>:1' */
  /* Author: Yama Habib */
  /* Revision: 10/27/2010 */
  /* Centroid2Heading takes a raw matrix centroid coordinate and converts */
  /* it into a correction heading, in degrees (i.e. heading_y_deg = -30, */
  /* heading_z_deg = 45 means that in order to orient yourself so that the */
  /* object in question is centered in the video feed, you need to turn 30 */
  /* degrees to the left and 45 degrees upwards, assuming the camera is mounted */
  /* on the front) The probability that this function will return exactly 0 */
  /* degrees is laughably low, so applying a reasonable threshold to the */
  /* result is strongly recommended. */
  /* Should these be parameters? I think they're fine as constants. */
  /* '<S3>:1:18' */
  /* '<S3>:1:19' */

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function2' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function2': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function3' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function3': '<S5>:1' */
  /*  If at least one path element is found, then report that the path is being */
  /*  followed */
  /* '<S5>:1:6' */

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function4' */
  /* Embedded MATLAB Function 'Embedded MATLAB Function4': '<S6>:1' */
  /*  Editing note: */
  /*    -centroid is not a useful input. This function has yet to be written. */
  /*       -5-27-11 */
  /*  Determine whether: */
  /*    0 = No path is being followed */
  /*    1 = A single path (can be made up of n path elements along one line) */
  /*          is being followed */
  /*    2 = A Y-split is being encountered */
  /*    3 = A Y-join is being encountered */
  /* '<S6>:1:15' */

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&localB->EdgeDetection[0], &localB->HoughTransform1_o1[0],
                &path_detector_ConstP.HoughTransform1_SINE[0],
                &path_detector_ConstP.HoughTransform1_FIRSTRHO_R, 120, 160, 399,
                91);

  /* Embedded MATLAB: '<Root>/Identify Path Elements' incorporates:
   *  Constant: '<Root>/Voting Threshold'
   */
  /* Embedded MATLAB Function 'Identify Path Elements': '<S7>:1' */
  /*  This function attempts to identfiy path elements, and returns lines, */
  /*    targeting information, and a true/false path_found parameter. */
  /*  */
  /*  5-30-11 */
  /*  */
  /*  Input */
  /*  */
  /*  Output */
  /*  */
  /*  Notes: */
  /*    The hough_table is destroyed in this function (acceptable if */
  /*      hough_table is not an output) */
  /*  Initialize */
  /*  Fraction of max(rows,cols) of image within which a */
  /*                          peak is assumed to reside; this helps reduce */
  /*                          incorrect line extraction */
  /* '<S7>:1:22' */
  /*  Considers this many popular lines as candidates */
  /*  Tolerence within which two slopes are equal (radians) */
  /* rho_out = zeros(1,3); */
  /* theta_out = zeros(1,3); */
  /* '<S7>:1:31' */
  /* '<S7>:1:32' */
  /*  Apply appropriate threshold */
  /* '<S7>:1:36' */
  /*  Identify the most likely max_num_lines lines */
  /* '<S7>:1:40' */
  /* '<S7>:1:41' */
  /* '<S7>:1:43' */
  /*  debug */
  /*  Extract the three most popular lines that fit the geometric criteria for */
  /*    the goalpost */
  /* '<S7>:1:80' */
  /* '<S7>:1:81' */
  /*  debug */
  /* '<S7>:1:99' */
  /* '<S7>:1:100' */
  /* '<S7>:1:101' */
  /* '<S7>:1:102' */
  /* '<S7>:1:103' */
}

/* Model initialize function */
void mr_path_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_path_detector *const path_detector_M, rtB_mr_path_detector *localB,
  rtDW_mr_path_detector *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(path_detector_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_path_detector));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(rtDW_mr_path_detector));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
