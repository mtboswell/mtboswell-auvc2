/*
 * File: brain_capi.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.364
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu May 27 18:36:36 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu May 27 18:36:36 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives:
 *    1. Debugging
 *    2. Safety precaution
 *    3. Traceability
 *    4. Execution efficiency
 *    5. ROM efficiency
 *    6. RAM efficiency
 * Validation result: Not run
 */

#include "brain.h"
#include "rtw_capi.h"
#include "brain_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 27, "brain/StateFlow Functions",
    "Left", 0, 0, 0, 0, 0 },

  { 1, 27, "brain/StateFlow Functions",
    "Right", 1, 0, 0, 0, 0 },

  { 2, 27, "brain/StateFlow Functions",
    "Strafe", 2, 0, 0, 0, 0 },

  { 3, 27, "brain/StateFlow Functions",
    "Vertical", 3, 0, 0, 0, 0 },

  { 4, 27, "brain/StateFlow Functions",
    "DesiredDepth", 4, 1, 0, 0, 0 },

  { 5, 27, "brain/StateFlow Functions",
    "DesiredHeading", 5, 1, 0, 0, 0 },

  { 6, 27, "brain/StateFlow Functions",
    "CameraPosition", 6, 0, 0, 0, 0 },

  { 7, 27, "brain/StateFlow Functions",
    "BuoyCentroidX", 7, 1, 0, 0, 0 },

  { 8, 27, "brain/StateFlow Functions",
    "BuoyCentroidY", 8, 1, 0, 0, 0 },

  { 9, 27, "brain/StateFlow Functions",
    "State", 9, 0, 0, 0, 0 },

  { 10, 27, "brain/StateFlow Functions",
    "BWout", 10, 1, 1, 0, 0 },

  { 11, 0, "brain/GetVideo1/Chroma Resampling",
    "", 0, 2, 2, 0, 0 },

  { 12, 0, "brain/GetVideo1/Chroma Resampling",
    "", 1, 2, 2, 0, 0 },

  { 13, 0, "brain/GetVideo1/Resize",
    "", 0, 3, 1, 0, 0 },

  { 14, 0, "brain/GetVideo1/Resize1",
    "", 0, 3, 1, 0, 0 },

  { 15, 0, "brain/GetVideo1/Resize2",
    "", 0, 3, 1, 0, 0 },

  { 16, 0, "brain/GetVideo1/Y-Cb-Cr to RGB Color Space  Conversion",
    "RGBVid_R", 0, 2, 2, 0, 0 },

  { 17, 0, "brain/GetVideo1/Y-Cb-Cr to RGB Color Space  Conversion",
    "RGBVid_G", 1, 2, 2, 0, 0 },

  { 18, 0, "brain/GetVideo1/Y-Cb-Cr to RGB Color Space  Conversion",
    "RGBVid_B", 2, 2, 2, 0, 0 },

  { 19, 2, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "BlobArea", 0, 1, 0, 0, 1 },

  { 20, 4, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "", 1, 1, 0, 0, 1 },

  { 21, 4, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "", 2, 1, 0, 0, 1 },

  { 22, 4, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "", 3, 0, 0, 0, 1 },

  { 23, 2, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "BlobCentroidY", 4, 1, 0, 0, 1 },

  { 24, 2, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "BlobCentroidX", 5, 1, 0, 0, 1 },

  { 25, 4, "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy",
    "", 6, 4, 1, 0, 1 },

  { 26, 5,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy",
    "Image", 0, 1, 0, 0, 1 },

  { 27, 6,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy",
    "BW", 1, 4, 1, 0, 1 },

  { 28, 7,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.GetBuoyForwardVelocity",
    "", 0, 1, 0, 0, 1 },

  { 29, 8,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage",
    "HSVImage1", 0, 1, 3, 0, 1 },

  { 30, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver",
    "", 0, 0, 0, 0, 1 },

  { 31, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver",
    "", 1, 0, 0, 0, 1 },

  { 32, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver",
    "", 2, 1, 0, 0, 1 },

  { 33, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver",
    "", 3, 1, 0, 0, 1 },

  { 34, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver",
    "BW", 4, 4, 1, 0, 1 },

  { 35, 14,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit",
    "BWleft", 0, 4, 4, 0, 1 },

  { 36, 14,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit",
    "BWright", 1, 4, 4, 0, 1 },

  { 37, 15,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings",
    "ToPathHeading", 0, 1, 5, 0, 1 },

  { 38, 15,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings",
    "AlongPathHeading", 1, 1, 5, 0, 1 },

  { 39, 19, "brain/StateFlow Functions/StateFlowFunctions.GetDesiredDepth",
    "", 0, 1, 0, 0, 1 },

  { 40, 20, "brain/StateFlow Functions/StateFlowFunctions.MaintainDepth",
    "", 0, 0, 0, 0, 1 },

  { 41, 23, "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading",
    "", 0, 0, 0, 0, 1 },

  { 42, 23, "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading",
    "", 1, 0, 0, 0, 1 },

  { 43, 24,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity",
    "", 0, 1, 0, 0, 1 },

  { 44, 25,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack",
    "Image", 0, 1, 0, 0, 1 },

  { 45, 26,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack",
    "BW", 1, 4, 1, 0, 1 },

  { 46, 2,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function",
    "BlobArea", 0, 1, 0, 0, 1 },

  { 47, 2,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function",
    "BlobCentroidX", 1, 1, 0, 0, 1 },

  { 48, 2,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function",
    "BlobCentroidY", 2, 1, 0, 0, 1 },

  { 49, 3,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1",
    "XCenter", 0, 1, 0, 0, 1 },

  { 50, 3,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1",
    "YCenter", 1, 1, 0, 0, 1 },

  { 51, 4,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Dilation",
    "", 0, 4, 1, 0, 1 },

  { 52, 4,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Erosion",
    "", 0, 4, 1, 0, 1 },

  { 53, 7,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.GetBuoyForwardVelocity/Constant",
    "", 0, 1, 0, 0, 1 },

  { 54, 8,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether",
    "HSVImage1", 0, 1, 3, 0, 1 },

  { 55, 11,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function1",
    "XCenter", 0, 1, 0, 0, 1 },

  { 56, 11,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function1",
    "YCenter", 1, 1, 0, 0, 1 },

  { 57, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Logical Operator1",
    "BW", 0, 4, 1, 0, 1 },

  { 58, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Subtract",
    "", 0, 1, 0, 0, 1 },

  { 59, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Subtract1",
    "", 0, 1, 0, 0, 1 },

  { 60, 15,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath",
    "ToPathHeading", 0, 1, 5, 0, 1 },

  { 61, 15,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath",
    "AlongPathHeading", 1, 1, 5, 0, 1 },

  { 62, 19,
    "brain/StateFlow Functions/StateFlowFunctions.GetDesiredDepth/Constant",
    "", 0, 1, 0, 0, 1 },

  { 63, 20,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/Double To Int8",
    "", 0, 0, 0, 0, 1 },

  { 64, 21,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1",
    "", 0, 1, 0, 0, 1 },

  { 65, 21,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1",
    "", 1, 1, 0, 0, 1 },

  { 66, 22,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2",
    "", 0, 1, 0, 0, 1 },

  { 67, 22,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2",
    "", 1, 1, 0, 0, 1 },

  { 68, 23,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/DoubleToint1",
    "", 0, 0, 0, 0, 1 },

  { 69, 23,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/DoubleToint8",
    "", 0, 0, 0, 0, 1 },

  { 70, 24,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity/Heading Forward Velocity",
    "", 0, 1, 0, 0, 1 },

  { 71, 4,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/Add",
    "", 0, 1, 0, 0, 1 },

  { 72, 4,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/Add1",
    "", 0, 1, 0, 0, 1 },

  { 73, 4,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl/Data Type Conversion",
    "", 0, 0, 0, 0, 1 },

  { 74, 5,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions",
    "Image", 0, 1, 0, 0, 1 },

  { 75, 6,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Logical Operator1",
    "BW", 0, 4, 1, 0, 1 },

  { 76, 6,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Dilation",
    "", 0, 4, 1, 0, 1 },

  { 77, 6,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Erosion",
    "", 0, 4, 1, 0, 1 },

  { 78, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/Data Type Conversion",
    "", 0, 0, 0, 0, 1 },

  { 79, 12,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/Data Type Conversion",
    "", 0, 0, 0, 0, 1 },

  { 80, 13,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row",
    "BWleft", 0, 1, 4, 0, 1 },

  { 81, 13,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row",
    "BWright", 1, 1, 4, 0, 1 },

  { 82, 14,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Data Type Conversion",
    "BWleft", 0, 4, 4, 0, 1 },

  { 83, 14,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Data Type Conversion1",
    "BWright", 0, 4, 4, 0, 1 },

  { 84, 16,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent",
    "Theta", 0, 1, 5, 0, 1 },

  { 85, 16,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent",
    "Rho", 1, 1, 5, 0, 1 },

  { 86, 16,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent",
    "maxVotes", 2, 1, 5, 0, 1 },

  { 87, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/Hough Transform",
    "", 0, 1, 6, 0, 1 },

  { 88, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/Hough Transform",
    "", 1, 1, 7, 0, 2 },

  { 89, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/Hough Transform",
    "", 2, 1, 8, 0, 2 },

  { 90, 17,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent",
    "Theta", 0, 1, 5, 0, 1 },

  { 91, 17,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent",
    "Rho", 1, 1, 5, 0, 1 },

  { 92, 17,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent",
    "maxVotes", 2, 1, 5, 0, 1 },

  { 93, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/Hough Transform",
    "", 0, 1, 6, 0, 1 },

  { 94, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/Hough Transform",
    "", 1, 1, 7, 0, 2 },

  { 95, 18,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/Hough Transform",
    "", 2, 1, 8, 0, 2 },

  { 96, 21,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1/Constant1",
    "", 0, 1, 0, 0, 1 },

  { 97, 21,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1/Add",
    "", 0, 1, 0, 0, 1 },

  { 98, 22,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2/Constant1",
    "", 0, 1, 0, 0, 1 },

  { 99, 22,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2/Add",
    "", 0, 1, 0, 0, 1 },

  { 100, 25,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions",
    "Image", 0, 1, 0, 0, 1 },

  { 101, 26,
    "brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Logical Operator1",
    "BW", 0, 4, 1, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Individual block tuning is not valid when inline parameters is *
 * selected. An empty map is produced to provide a consistent     *
 * interface independent  of inlining parameters.                 *
 */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static const rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous
   */
  { 102, -1,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller\nDepth S3/Depth\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 103, -1,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller\nHeading S4/Heading\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 104, -1,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller\nX Position/X-Buoy\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 105, -1,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller\nY Position/Y-Buoy\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 106, -1,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller\nX Position/X-Buoy\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 107, -1,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller\nY Axis/Y-Buoy\nDiscrete-Time\nIntegrator",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 108, -1,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller\nDepth S3/Depth\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 109, -1,
    "brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller\nHeading S4/Heading\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 110, -1,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller\nX Position/X-Buoy\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 111, -1,
    "brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller\nY Position/Y-Buoy\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 112, -1,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller\nX Position/X-Buoy\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  { 113, -1,
    "brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller\nY Axis/Y-Buoy\nDiscrete Derivative/UD",
    "", "", 0, 1, 0, 0, 0, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 114, "Buoy_HueHigher", 1, 0, 0 },

  { 115, "Buoy_HueLower", 1, 0, 0 },

  { 116, "Buoy_Max_Eccentricity", 1, 0, 0 },

  { 117, "Buoy_Max_Extent", 1, 0, 0 },

  { 118, "Buoy_Min_Eccentricity", 1, 0, 0 },

  { 119, "Buoy_Min_Extent", 1, 0, 0 },

  { 120, "Buoy_Saturation", 1, 0, 0 },

  { 121, "Cam_Down_XPos_Kd", 1, 0, 0 },

  { 122, "Cam_Down_XPos_Ki", 1, 0, 0 },

  { 123, "Cam_Down_XPos_Kp", 1, 0, 0 },

  { 124, "Cam_Down_YPos_Kd", 1, 0, 0 },

  { 125, "Cam_Down_YPos_Ki", 1, 0, 0 },

  { 126, "Cam_Down_YPos_Kp", 1, 0, 0 },

  { 127, "Cam_Forward_XPosition_Kd", 1, 0, 0 },

  { 128, "Cam_Forward_XPosition_Ki", 1, 0, 0 },

  { 129, "Cam_Forward_XPosition_Kp", 1, 0, 0 },

  { 130, "Cam_Forward_YPosition_Kd", 1, 0, 0 },

  { 131, "Cam_Forward_YPosition_Ki", 1, 0, 0 },

  { 132, "Cam_Forward_YPosition_Kp", 1, 0, 0 },

  { 133, "Depth_Kd", 1, 0, 0 },

  { 134, "Depth_Ki", 1, 0, 0 },

  { 135, "Depth_Kp", 1, 0, 0 },

  { 136, "Heading_Forward_Velocity", 1, 0, 0 },

  { 137, "Heading_Kd", 1, 0, 0 },

  { 138, "Heading_Ki", 1, 0, 0 },

  { 139, "Heading_Kp", 1, 0, 0 },

  { 140, "Track_Desired_Depth", 1, 0, 0 },

  { 141, "Track_HueHigher", 1, 0, 0 },

  { 142, "Track_HueLower", 1, 0, 0 },

  { 143, "Track_Min_Eccentricity", 1, 0, 0 },

  { 144, "Track_Saturation", 1, 0, 0 },

  { 145, "Vision_Forward_Velocity", 1, 0, 0 },

  { 146, "Max_Blob_Size", 5, 0, 0 },

  { 147, "Min_Blob_Size", 5, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &brain_B.Left,                       /* 0: Signal */
  &brain_B.Right,                      /* 1: Signal */
  &brain_B.Strafe,                     /* 2: Signal */
  &brain_B.Vertical,                   /* 3: Signal */
  &brain_B.DesiredDepth,               /* 4: Signal */
  &brain_B.DesiredHeading,             /* 5: Signal */
  &brain_B.CameraPosition,             /* 6: Signal */
  &brain_B.BuoyCentroidX,              /* 7: Signal */
  &brain_B.BuoyCentroidY,              /* 8: Signal */
  &brain_B.State,                      /* 9: Signal */
  &brain_B.BWout[0],                   /* 10: Signal */
  &brain_B.ChromaResampling_o1[0],     /* 11: Signal */
  &brain_B.ChromaResampling_o2[0],     /* 12: Signal */
  &brain_B.Resize[0],                  /* 13: Signal */
  &brain_B.Resize1[0],                 /* 14: Signal */
  &brain_B.Resize2[0],                 /* 15: Signal */
  &brain_B.RGBVid_R[0],                /* 16: Signal */
  &brain_B.RGBVid_G[0],                /* 17: Signal */
  &brain_B.RGBVid_B[0],                /* 18: Signal */
  &brain_B.BlobArea,                   /* 19: Signal */
  &brain_B.Add_h,                      /* 20: Signal */
  &brain_B.Add1,                       /* 21: Signal */
  &brain_B.DataTypeConversion_e,       /* 22: Signal */
  &brain_B.BlobCentroidY,              /* 23: Signal */
  &brain_B.BlobCentroidX,              /* 24: Signal */
  &brain_B.Erosion[0],                 /* 25: Signal */
  &brain_B.Image,                      /* 26: Signal */
  &brain_B.BW_g[0],                    /* 27: Signal */
  &brain_B.Constant_i,                 /* 28: Signal */
  &brain_B.StateFlowFunctionsFollowOnePa_g.HSVImage1[0],/* 29: Signal */
  &brain_B.DataTypeConversion,         /* 30: Signal */
  &brain_B.DataTypeConversion_h,       /* 31: Signal */
  &brain_B.Subtract1,                  /* 32: Signal */
  &brain_B.Subtract,                   /* 33: Signal */
  &brain_B.BW[0],                      /* 34: Signal */
  &brain_B.BWleft_k[0],                /* 35: Signal */
  &brain_B.BWright_e[0],               /* 36: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.ToPathHeading[0],/* 37: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.AlongPathHeading[0],/* 38: Signal */
  &brain_B.Constant,                   /* 39: Signal */
  &brain_B.DoubleToInt8,               /* 40: Signal */
  &brain_B.DoubleToint8,               /* 41: Signal */
  &brain_B.DoubleToint1,               /* 42: Signal */
  &brain_B.HeadingForwardVelocity,     /* 43: Signal */
  &brain_B.StateFlowFunctionsValidationG_a.Image,/* 44: Signal */
  &brain_B.StateFlowFunctionsValidationG_a.BW[0],/* 45: Signal */
  &brain_B.BlobArea,                   /* 46: Signal */
  &brain_B.BlobCentroidX,              /* 47: Signal */
  &brain_B.BlobCentroidY,              /* 48: Signal */
  &brain_B.sf_EmbeddedMATLABFunction1.XCenter,/* 49: Signal */
  &brain_B.sf_EmbeddedMATLABFunction1.YCenter,/* 50: Signal */
  &brain_B.Dilation_e[0],              /* 51: Signal */
  &brain_B.Erosion[0],                 /* 52: Signal */
  &brain_B.Constant_i,                 /* 53: Signal */
  &brain_B.StateFlowFunctionsFollowOnePa_g.HSVImage1[0],/* 54: Signal */
  &brain_B.sf_EmbeddedMATLABFunction1_d.XCenter,/* 55: Signal */
  &brain_B.sf_EmbeddedMATLABFunction1_d.YCenter,/* 56: Signal */
  &brain_B.BW[0],                      /* 57: Signal */
  &brain_B.Subtract,                   /* 58: Signal */
  &brain_B.Subtract1,                  /* 59: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.ToPathHeading[0],/* 60: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.AlongPathHeading[0],/* 61: Signal */
  &brain_B.Constant,                   /* 62: Signal */
  &brain_B.DoubleToInt8,               /* 63: Signal */
  &brain_B.Add_o,                      /* 64: Signal */
  &brain_B.Constant1_e,                /* 65: Signal */
  &brain_B.Add,                        /* 66: Signal */
  &brain_B.Constant1,                  /* 67: Signal */
  &brain_B.DoubleToint1,               /* 68: Signal */
  &brain_B.DoubleToint8,               /* 69: Signal */
  &brain_B.HeadingForwardVelocity,     /* 70: Signal */
  &brain_B.Add_h,                      /* 71: Signal */
  &brain_B.Add1,                       /* 72: Signal */
  &brain_B.DataTypeConversion_e,       /* 73: Signal */
  &brain_B.Image,                      /* 74: Signal */
  &brain_B.BW_g[0],                    /* 75: Signal */
  &brain_B.Dilation[0],                /* 76: Signal */
  &brain_B.Erosion_l[0],               /* 77: Signal */
  &brain_B.DataTypeConversion,         /* 78: Signal */
  &brain_B.DataTypeConversion_h,       /* 79: Signal */
  &brain_B.BWleft[0],                  /* 80: Signal */
  &brain_B.BWright[0],                 /* 81: Signal */
  &brain_B.BWleft_k[0],                /* 82: Signal */
  &brain_B.BWright_e[0],               /* 83: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent.Theta[0],/* 84: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent.Rho[0],/* 85: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent.maxVotes[0],/* 86: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o1[0],/* 87: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[0],/* 88: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[0],/* 89: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent_m.Theta[0],/* 90: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent_m.Rho[0],/* 91: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.sf_IsLinePresent_m.maxVotes[0],/* 92: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o1_p[0],/* 93: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[0],/* 94: Signal */
  &brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[0],/* 95: Signal */
  &brain_B.Constant1_e,                /* 96: Signal */
  &brain_B.Add_o,                      /* 97: Signal */
  &brain_B.Constant1,                  /* 98: Signal */
  &brain_B.Add,                        /* 99: Signal */
  &brain_B.StateFlowFunctionsValidationG_a.Image,/* 100: Signal */
  &brain_B.StateFlowFunctionsValidationG_a.BW[0],/* 101: Signal */
  &brain_DWork.DepthDiscreteTimeIntegrator_DST,/* 102: Discrete State */
  &brain_DWork.HeadingDiscreteTimeIntegrator_D,/* 103: Discrete State */
  &brain_DWork.XBuoyDiscreteTimeIntegrator_D_k,/* 104: Discrete State */
  &brain_DWork.YBuoyDiscreteTimeIntegrator_D_a,/* 105: Discrete State */
  &brain_DWork.XBuoyDiscreteTimeIntegrator_DST,/* 106: Discrete State */
  &brain_DWork.YBuoyDiscreteTimeIntegrator_DST,/* 107: Discrete State */
  &brain_DWork.UD_DSTATE,              /* 108: Discrete State */
  &brain_DWork.UD_DSTATE_p,            /* 109: Discrete State */
  &brain_DWork.UD_DSTATE_f,            /* 110: Discrete State */
  &brain_DWork.UD_DSTATE_m,            /* 111: Discrete State */
  &brain_DWork.UD_DSTATE_k,            /* 112: Discrete State */
  &brain_DWork.UD_DSTATE_ko,           /* 113: Discrete State */
  &brain_P.Buoy_HueHigher,             /* 114: Model Parameter */
  &brain_P.Buoy_HueLower,              /* 115: Model Parameter */
  &brain_P.Buoy_Max_Eccentricity,      /* 116: Model Parameter */
  &brain_P.Buoy_Max_Extent,            /* 117: Model Parameter */
  &brain_P.Buoy_Min_Eccentricity,      /* 118: Model Parameter */
  &brain_P.Buoy_Min_Extent,            /* 119: Model Parameter */
  &brain_P.Buoy_Saturation,            /* 120: Model Parameter */
  &brain_P.Cam_Down_XPos_Kd,           /* 121: Model Parameter */
  &brain_P.Cam_Down_XPos_Ki,           /* 122: Model Parameter */
  &brain_P.Cam_Down_XPos_Kp,           /* 123: Model Parameter */
  &brain_P.Cam_Down_YPos_Kd,           /* 124: Model Parameter */
  &brain_P.Cam_Down_YPos_Ki,           /* 125: Model Parameter */
  &brain_P.Cam_Down_YPos_Kp,           /* 126: Model Parameter */
  &brain_P.Cam_Forward_XPosition_Kd,   /* 127: Model Parameter */
  &brain_P.Cam_Forward_XPosition_Ki,   /* 128: Model Parameter */
  &brain_P.Cam_Forward_XPosition_Kp,   /* 129: Model Parameter */
  &brain_P.Cam_Forward_YPosition_Kd,   /* 130: Model Parameter */
  &brain_P.Cam_Forward_YPosition_Ki,   /* 131: Model Parameter */
  &brain_P.Cam_Forward_YPosition_Kp,   /* 132: Model Parameter */
  &brain_P.Depth_Kd,                   /* 133: Model Parameter */
  &brain_P.Depth_Ki,                   /* 134: Model Parameter */
  &brain_P.Depth_Kp,                   /* 135: Model Parameter */
  &brain_P.Heading_Forward_Velocity,   /* 136: Model Parameter */
  &brain_P.Heading_Kd,                 /* 137: Model Parameter */
  &brain_P.Heading_Ki,                 /* 138: Model Parameter */
  &brain_P.Heading_Kp,                 /* 139: Model Parameter */
  &brain_P.Track_Desired_Depth,        /* 140: Model Parameter */
  &brain_P.Track_HueHigher,            /* 141: Model Parameter */
  &brain_P.Track_HueLower,             /* 142: Model Parameter */
  &brain_P.Track_Min_Eccentricity,     /* 143: Model Parameter */
  &brain_P.Track_Saturation,           /* 144: Model Parameter */
  &brain_P.Vision_Forward_Velocity,    /* 145: Model Parameter */
  &brain_P.Max_Blob_Size,              /* 146: Model Parameter */
  &brain_P.Min_Blob_Size,              /* 147: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR_ND, 6, 3, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 9, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 11, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 13, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 15, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 17, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  120,                                 /* 2 */
  160,                                 /* 3 */
  480,                                 /* 4 */
  640,                                 /* 5 */
  120,                                 /* 6 */
  160,                                 /* 7 */
  3,                                   /* 8 */
  120,                                 /* 9 */
  80,                                  /* 10 */
  1,                                   /* 11 */
  2,                                   /* 12 */
  287,                                 /* 13 */
  180,                                 /* 14 */
  1,                                   /* 15 */
  180,                                 /* 16 */
  1,                                   /* 17 */
  287                                  /* 18 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.2, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (NULL), (NULL), -1, 0 },

  { (NULL), (NULL), -2, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 102 },

  { rtBlockParameters, 0,
    rtModelParameters, 34 },

  { rtBlockStates, 12 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", (NULL)
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void brain_InitializeDataMapInfo(RT_MODEL_brain *brain_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(brain_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(brain_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(brain_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(brain_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(brain_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(brain_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(brain_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(brain_M->DataMapInfo.mmi, 0);
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
