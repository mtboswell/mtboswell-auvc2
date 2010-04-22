// Config stuff

// MAGNETIC_DECLINATION = local magnetic declination.  Use this webpage to calculate:
// http://www.ngdc.noaa.gov/geomagmodels/Declination.jsp
// ' = 1/60 of a degree
// W = negative; E = positive;
// transdec zip code = 92106
// transdec mag. dec. = 12.23
#define MAGNETIC_DECLINATION -8.066

// BRAIN_STEP_TIME = 1/f for brain.  200 = 5Hz
#define BRAIN_STEP_TIME 200
// AUV_STEP_TIME = 1/f for hardware/sensor update
#define AUV_STEP_TIME 160
// DATA_LOG_STEP_TIME = time period for each log file update
#define DATA_LOG_STEP_TIME 1000

// DATA_PORT = UDP port used for data. 
// 5233 = last 3 digits of UPC of aqua's aquarium album + track number of "Barbie Girl"
#define SERVER_DATA_PORT 5233
#define CLIENT_DATA_PORT 5237

// VIDEO_PORT = UDP port used for video. 
// 5235 = last 3 digits of UPC of aqua's aquarium album + track number of "Doctor Jones"
#define VIDEO_PORT 5235
#define DASH_VIDEO_PORT 5335
// port used for second video stream:
#define SECONDARY_VIDEO_PORT 5239
#define DASH_SECONDARY_VIDEO_PORT 5339

// AUV_IP = IP address of AUV
//#define AUV_IP "127.0.0.1"
#define AUV_IP "192.168.3.5"
