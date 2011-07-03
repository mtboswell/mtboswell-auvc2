#include <QtCore>
#include <QtCore/QCoreApplication>
#include <QImage>
#include <QColor>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;


// Declare public variables
QImage im;
int h, w;  // Discovered image dimensions
const int hsub = 850;  // Dimensions of subset image (centered in input image)
const int wsub = 850;

double Rin[4000][3000] = {{0}};  // Input image matrices
double Gin[4000][3000] = {{0}};
double Bin[4000][3000] = {{0}};

double c1[wsub][hsub] = {{0}};  // Actual matrices used during analysis
double c2[wsub][hsub] = {{0}};
double c3[wsub][hsub] = {{0}};

double bw[wsub][hsub] = {{0}};  // Binary (black/white) matrix

double RGB_max = 0;  // Maximum value in R, G, or B color components


//note: to account for the maximum number of ranges, only store the previous line.
//max # of ranges  == ceil(imageWidth/2)

int num_blobs = 0;  // Variables for blob analysis
const int max_num_blobs = 1000;
int blob_bound[3][max_num_blobs];
int blob_area[max_num_blobs];
double blob_eccentricity[max_num_blobs];
double blob_centroid[2][max_num_blobs];
double bounding_box[4][max_num_blobs];
double major_axis[max_num_blobs];
double minor_axis[max_num_blobs];
double eccentricity[max_num_blobs];
int found = 0;



// Input image from file
void inputImage(char* file);

// Subset image
void subsetImage();

// Filter image
void filterImage();

// Transform
void transform(int transformType);

// Normalize image
void normalize();

// Naive blob analysis
void blobAnalysis1();

// Intelligent blob analysis
void blobAnalysis2();

// Output position field to file
void fileOutput(char* file);

// Function for determining if a pixel belongs to a blob on the previous line
int matchBlob(int r, int c, int criteria);

// Provide a standard function to merge information from two blobs
void mergeBlobs(int fromBlob, int toBlob);

// Determine if current row, column pair is outside bounding box and update
void updateBoundingBox(int blob_track, int r, int c);

// Return the min or max of two values, but ignore any value that is -1
double minIgnore(double a, double b);
double maxIgnore(double a, double b);

// Draw bounding boxes around each identified blob
void drawBoundingBox(int blob_track);

// Perform actions to extract blob information that require complete image analysis prior
void postProcess();



int main(int argc, char *argv[])
{
    // Notes
    // 1. Global variables are used when possible; this ensures access to a large set of distributed functions
    // 2. Procedural programming is employed

    // Internal initialization
    QCoreApplication a(argc, argv);

    // Input image from file
    inputImage("/home/auvt/auvc/src/vision/Modified_Files_for_Testing/temp_qtproject/temp_qtproject/IMG_3907.jpg");

    // Subset image to examine region of interest (ROI)
    subsetImage();

    // Ignore pixels with color components not expected for markers
    filterImage();

    // Form binary image
    for(int i = 0; i < wsub; i++)
    {
        for(int j = 0; j < hsub; j++)
        {

            if(c1[i][j] > 0 || c2[i][j] > 0)  // Only compare R and G components
            {
                bw[i][j] = 1;
            }
            else
            {
                bw[i][j] = 0;
            }

        }
    }

    // Output bw matrix for testing purposes
    for(int i = 0; i < wsub; i++)
    {
        for(int j = 0; j < hsub; j++)
        {
            c1[i][j] = bw[i][j]*255;  // Re-factor the 255 for 32-bit bit depth
            c2[i][j] = bw[i][j]*255;
            c3[i][j] = bw[i][j]*255;
        }
    }

    // Perform naive blob analysis
    blobAnalysis1();

    // Determine quantities that require entire image to be processed first
    postProcess();

    // Debugging output

    for(int i = 0; i < max_num_blobs; i++)
    {
//        std::cout << "Bounding box: " << bounding_box[0][i] << " " << bounding_box[1][i] << " " << bounding_box[2][i] << " " << bounding_box[3][i] << endl;
//        std::cout << "Eccentricity: " << eccentricity[i] << endl;
//        std::cout << "Major axis: " << major_axis[i] << " Minor axis: " << minor_axis[i] << endl;

        drawBoundingBox(i);

    }

    std::cout << maxIgnore(-1, -1) << " " << maxIgnore(-1, -8) << " " << maxIgnore(8, -1) << " " << maxIgnore(300, 301) << endl;

    // Save RGB arrays to an image file
    fileOutput("/home/auvt/auvc/src/vision/Modified_Files_for_Testing/temp_qtproject/temp_qtproject/outputImage.bmp");
//    fileOutput("/home/auvt/auvc/src/vision/Modified_Files_for_Testing/temp_qtproject/temp_qtproject/outputImage.jpg");

    std::cout << "Program finished." << endl;


    return a.exec();
}


void inputImage(char* file)
{
    // Input QImage from file
    im = QImage(file, "JPG");

    // Determine image dimensions
    h = im.size().height();
    w = im.size().width();

    // Fill three 2D arrays with double-precision values, representing the color components of the image (for practice with the QImage class)
    QRgb pixelValue;
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            pixelValue = im.pixel(i,j);
            Rin[i][j] = qRed(pixelValue);
            Gin[i][j] = qGreen(pixelValue);
            Bin[i][j] = qBlue(pixelValue);
        }
    }

    return;
}


void subsetImage()
{
    // Extract ROI
    int ii, jj;
    ii = 0;
    for(int i = w/2 - wsub/2; i < w/2 + wsub/2; i++)
    {
        jj = 0;
        for(int j = h/2 - hsub/2; j < h/2 + hsub/2; j++)
        {
            c1[ii][jj] = Rin[i][j]/255;  // Normalize values for 32-bit image
            c2[ii][jj] = Gin[i][j]/255;
            c3[ii][jj] = Bin[i][j]/255;
            jj++;
        }
        ii++;
    }

    return;
}


void filterImage()
{
    // The following are experimentally-determined RGB ranges to extract dot information
    // R: [0.070588235294118, 0.129411764705882]
    // G: [0.184313725490196, 0.203921568627451]
    // B: Do not limit

    // Allow only pixels whose component values lie in the expected range (consider each color component separately)
    double R_lower = 0.070588235294118;
    double R_upper = 0.129411764705882;
    double G_lower =  0.184313725490196;
    double G_upper = 0.203921568627451;
    double B_lower = 0;
    double B_upper = 1;

    for(int i = 0; i < wsub; i++)
    {
        for(int j = 0; j < hsub; j++)
        {
            if( c1[i][j] < R_lower || c1[i][j] > R_upper )
            {
                c1[i][j] = -1;
            }

            if( c2[i][j] < G_lower || c2[i][j] > G_upper )
            {
                c2[i][j] = -1;
            }

            if( c3[i][j] < B_lower || c3[i][j] > B_upper )
            {
                c3[i][j] = -1;
            }
        }
    }

    return;
}


void fileOutput(char* file)
{
    // Store RGB arrays in a QImage
    QImage imOut = QImage(wsub, hsub, QImage::Format_RGB32);
    QColor value;
    for(int i = 0; i < wsub; i++)
    {
        for(int j = 0; j < hsub; j++)
        {
            value = QColor(c1[i][j], c2[i][j], c3[i][j]);
            imOut.setPixel(i, j, value.rgb());
        }
    }

    // Write output image file
    bool success = imOut.save(file, "BMP", 100);
//    bool success = imOut.save(file, "JPG", 100);

    return;
}


void transform(int transformType)
{
    // transformType selects which conversion to perform
    if(transformType == 0)
    {

        // Change each pixel color
        QColor value;
        for(int i = 0; i < wsub; i++)
        {
            for(int j = 0; j < hsub; j++)
            {
                value = QColor(c1[i][j], c2[i][j], c3[i][j]);
                c1[i][j] = value.hue();
                c2[i][j] = value.saturation();
                c1[i][j] = value.value();
            }
        }

    }

    return;
}


void blobAnalysis1()
{

    // Initialize all arrays
    for(int b = 0; b < max_num_blobs; b++)
    {
        blob_bound[0][b] = 0;  // Left bound
        blob_bound[1][b] = 0;  // Right bound
        blob_bound[2][b] = 0;  // Row on which these bounds were identified
        blob_area[b] = 0;
        blob_eccentricity[b] = 0;
        blob_centroid[0][b] = 0;
        blob_centroid[1][b] = 0;
        bounding_box[0][b] = -1;
        bounding_box[1][b] = -1;
        bounding_box[2][b] = -1;
        bounding_box[3][b] = -1;
        major_axis[b] = 0;
        minor_axis[b] = 0;
        eccentricity[b] = 0;
    }

    // Loop through bw image line-by-line
    int blob_track = -1;
    for(int r = 0; r < hsub; r++)  // Iterate over rows
    {
        for(int c = 0; c < wsub; c++)  // Iterate over columns
        {

            if(bw[c][r] == 1)  // Handle "true" pixel
            {

                if(blob_track == -1)  // Case "not previously tracking"
                {

                    // Determine which blob from the previous line the current pixel belongs to
                    blob_track = matchBlob(r, c, 0);

                    if(blob_track == -1)  // No matching blob is identified
                    {

                        // Find first zero value in blob_area
                        for(int b = 0; b < max_num_blobs; b++)
                        {
                            if(blob_area[b] == 0)
                            {
                                blob_track = b;
                                break;
                            }
                        }
                        if(blob_track == -1)
                        {
                            blob_track = max_num_blobs;
                        }

                        // A new blob is being tracked
                        num_blobs++;

                        blob_bound[0][blob_track] = c;
                        blob_bound[1][blob_track] = c;
                        blob_bound[2][blob_track] = r;

                        blob_area[blob_track] = 1;

                        blob_eccentricity[blob_track] = 0;

                        blob_centroid[0][blob_track] = r;
                        blob_centroid[1][blob_track] = c;

                        bounding_box[0][blob_track] = r;
                        bounding_box[1][blob_track] = r;
                        bounding_box[2][blob_track] = c;
                        bounding_box[3][blob_track] = c;

                    }
                    else  // Matching blob is identified
                    {

                        // An old blob is being tracked
                        blob_bound[1][blob_track] = c;
                        blob_bound[2][blob_track] = r;

                        blob_eccentricity[blob_track] = 0;

                        blob_centroid[0][blob_track] = (  ( ( (double)blob_area[blob_track]/((double)blob_area[blob_track] + 1) )*(double)blob_centroid[0][blob_track] ) + ( (double)r/((double)blob_area[blob_track] + 1) )  );
                        blob_centroid[1][blob_track] = (  ( ( (double)blob_area[blob_track]/((double)blob_area[blob_track] + 1) )*(double)blob_centroid[1][blob_track] ) + ( (double)c/((double)blob_area[blob_track] + 1) )  );

                        blob_area[blob_track]++;

                        updateBoundingBox(blob_track, r, c);

                    }


                }
                else  // Case "previously tracking"
                {

                    // Tally area, centroid, etc.
                    blob_bound[1][blob_track] = c;
                    blob_bound[2][blob_track] = r;

                    blob_eccentricity[blob_track] = 0;

                    blob_centroid[0][blob_track] = (  ( ( (double)blob_area[blob_track]/((double)blob_area[blob_track] + 1) )*(double)blob_centroid[0][blob_track] ) + ( (double)r/((double)blob_area[blob_track] + 1) )  );
                    blob_centroid[1][blob_track] = (  ( ( (double)blob_area[blob_track]/((double)blob_area[blob_track] + 1) )*(double)blob_centroid[1][blob_track] ) + ( (double)c/((double)blob_area[blob_track] + 1) )  );

                    blob_area[blob_track]++;

                    updateBoundingBox(blob_track, r, c);

                    // If bounds of an existing blob are encountered, then merge the two blobs
                    found = matchBlob(r, c, 0);
                    if(found != -1)
                    {
//                        c1[c][r] = 255;
    //                    c2[c][r] = 0;
  //                      c3[c][r] = 0;
                        mergeBlobs(blob_track, found);
                        blob_track = found;
                    }

                    // Possibly other logic

                }



                //debug
                if(bw[c][r] == 1)
                {
                    //debug
                    c1[c][r] = 0;
                    c2[c][r] = 0;
                    c3[c][r] = 128;

                    //c1[ (int)blob_centroid[1][blob_track] ][ (int)blob_centroid[0][blob_track] ] = 128;
                    //c2[ (int)blob_centroid[1][blob_track] ][ (int)blob_centroid[0][blob_track] ] = 128;
                    //c3[ (int)blob_centroid[1][blob_track] ][ (int)blob_centroid[0][blob_track] ] = 128;
                }



            }
            else  // Handle "false" pixel
            {
                blob_track = -1;
            }

        }
    }

    int area_threshold = 50;
    for(int b = 0; b < max_num_blobs; b++)
    {
        if(blob_area[b] > area_threshold)
        {
            c1[ (int)blob_centroid[1][b] ][ (int)blob_centroid[0][b] ] = 255;
            c2[ (int)blob_centroid[1][b] ][ (int)blob_centroid[0][b] ] = 255;
            c3[ (int)blob_centroid[1][b] ][ (int)blob_centroid[0][b] ] = 255;
        }
    }


    return;
}


int matchBlob(int r, int c, int criteria)
{

    // The first row can only contain new blobs
    if(r == 0)
    {
        return -1;
    }

    // Return -1 if no match is found; else, return the index of the match
    int returnInt = -1;

    if(criteria == 0)  // Matching algorithm 0
    {
        for(int b = 0; b < max_num_blobs; b++)
        {
            // Allow only pixels that touch or are diagonal
            if( c+1 >= blob_bound[0][b] && c-1 <= blob_bound[1][b] && r == blob_bound[2][b] + 1)
//                if( c-1 >= blob_bound[0][b] && c+1 <= blob_bound[1][b] )
            {
                returnInt = b;
                break;
            }
        }
    }

    // Return value
    return returnInt;

}


void mergeBlobs(int fromBlob, int toBlob)
{

    // Update information for the toBlob
    num_blobs--;

    blob_bound[0][toBlob] = blob_bound[0][fromBlob];
    blob_bound[1][toBlob] = blob_bound[1][fromBlob];
    blob_bound[2][toBlob] = blob_bound[2][fromBlob];

    blob_eccentricity[toBlob] += blob_eccentricity[fromBlob];

    blob_centroid[0][toBlob] = ( (double)blob_centroid[0][fromBlob] * (double)blob_area[fromBlob] + (double)blob_centroid[0][toBlob] * (double)blob_area[toBlob] ) / ( (double)blob_area[fromBlob] + (double)blob_area[toBlob] );
    blob_centroid[1][toBlob] = ( (double)blob_centroid[1][fromBlob] * (double)blob_area[fromBlob] + (double)blob_centroid[1][toBlob] * (double)blob_area[toBlob] ) / ( (double)blob_area[fromBlob] + (double)blob_area[toBlob] );

    blob_area[toBlob] += blob_area[fromBlob];

    bounding_box[0][toBlob] = minIgnore( bounding_box[0][fromBlob], bounding_box[0][toBlob] );
    bounding_box[1][toBlob] = maxIgnore( bounding_box[1][fromBlob], bounding_box[1][toBlob] );
    bounding_box[2][toBlob] = minIgnore( bounding_box[2][fromBlob], bounding_box[2][toBlob] );
    bounding_box[3][toBlob] = maxIgnore( bounding_box[3][fromBlob], bounding_box[3][toBlob] );

    // Set information for fromBlob to zero
    blob_bound[0][fromBlob] = 0;
    blob_bound[1][fromBlob] = 0;
    blob_bound[2][fromBlob] = 0;
    blob_area[fromBlob] = 0;
    blob_eccentricity[fromBlob] = 0;
    blob_centroid[0][fromBlob] = 0;
    blob_centroid[1][fromBlob] = 0;
    bounding_box[0][fromBlob] = 0;
    bounding_box[0][fromBlob] = 0;

    return;
}


void updateBoundingBox(int blob_track, int r, int c)
{
    /*
    // Handle uninitialized bounding_box array (uninitialized contains -1)
    if(bounding_box[0][blob_track] == -1)
{
        bounding_box[0][blob_track] = (double)r;
    }
    else
    {
        bounding_box[0][blob_track] = min( (double)r, bounding_box[0][blob_track] );
    }

    if(blob_box[2][blob_track] == -1)
    {
        bounding_box[2][blob_track] = (double)c;
    }
    else
    {
        bounding_box[2][blob_track] = min( (double)c, bounding_box[2][blob_track] );
    }
*/

    bounding_box[0][blob_track] = minIgnore( (double)r, bounding_box[0][blob_track] );
    bounding_box[1][blob_track] = maxIgnore( (double)r, bounding_box[1][blob_track] );
    bounding_box[2][blob_track] = minIgnore( (double)c, bounding_box[2][blob_track] );
    bounding_box[3][blob_track] = maxIgnore( (double)c, bounding_box[3][blob_track] );

/*


    if(r < bounding_box[0][blob_track])
    {
        bounding_box[0][blob_track] = r;
    }
    if(r > bounding_box[1][blob_track])
    {
        bounding_box[1][blob_track] = r;
    }
    if(c < bounding_box[2][blob_track])
    {
        bounding_box[2][blob_track] = c;
    }
    if(c > bounding_box[3][blob_track])
    {
        bounding_box[3][blob_track] = c;
    }
*/
    return;
}


double minIgnore(double a, double b)
{
    if(b != -1 && a == -1)
    {
        // If one number is == -1, then return the other number
        return b;
    }
    else if(a != -1 && b == -1)
    {
        return a;
    }
    else if(a == -1 && b == -1)
    {
        // If both numbers are == -1, then return 0
        return 0;
    }

    // If neither number is == -1, then return the minimum
    return min(a, b);
}


double maxIgnore(double a, double b)
{
    if(b != -1 && a == -1)
    {
        // If one number is == -1, then return the other number
        return b;
    }
    if(a != -1 && b == -1)
    {
        return a;
    }
    if(a == -1 && b == -1)
    {
        // If both numbers are == -1, then return 0
        return 0;
    }

    // If neither number is == -1, then return the minimum
    return max(a, b);
}


void drawBoundingBox(int blob_track)
{
    double rdisplay = 255;
    double gdisplay = 0;
    double bdisplay = 0;

    for(int r = bounding_box[0][blob_track]; r < bounding_box[1][blob_track]; r++)
    {
        c1[ (int)bounding_box[2][blob_track] ][r] = rdisplay;
        c2[ (int)bounding_box[2][blob_track] ][r] = gdisplay;
        c3[ (int)bounding_box[2][blob_track] ][r] = bdisplay;

        c1[ (int)bounding_box[3][blob_track] ][r] = rdisplay;
        c2[ (int)bounding_box[3][blob_track] ][r] = gdisplay;
        c3[ (int)bounding_box[3][blob_track] ][r] = bdisplay;
    }

    for(int c = bounding_box[2][blob_track]; c < bounding_box[3][blob_track]; c++)
    {
        c1[c][ (int)bounding_box[0][blob_track] ] = rdisplay;
        c2[c][ (int)bounding_box[0][blob_track] ] = gdisplay;
        c3[c][ (int)bounding_box[0][blob_track] ] = bdisplay;

        c1[c][ (int)bounding_box[1][blob_track] ] = rdisplay;
        c2[c][ (int)bounding_box[1][blob_track] ] = gdisplay;
        c3[c][ (int)bounding_box[1][blob_track] ] = bdisplay;
    }

    return;
}


void postProcess()
{
    for(int b = 0; b < num_blobs; b++)
    {
        // Store major and minor axes for each blob
        major_axis[b] = maxIgnore( bounding_box[1][b] - bounding_box[0][b], bounding_box[3][b] - bounding_box[2][b] );
        minor_axis[b] = minIgnore( bounding_box[1][b] - bounding_box[0][b], bounding_box[3][b] - bounding_box[2][b] );

        std::cout << bounding_box[1][b] - bounding_box[0][b] << " " << bounding_box[3][b] - bounding_box[2][b] << endl;
        std::cout << bounding_box[1][b] - bounding_box[0][b] << " " << bounding_box[3][b] - bounding_box[2][b] << endl;

        // Determine eccentricity for each blob
        if(major_axis[b] == 0)
        {
            eccentricity[b] = 1;
        }
        eccentricity[b] = (double)sqrt(  (double)1 - ( pow(.5*minor_axis[b], 2)/pow(.5*major_axis[b], 2) )  );
    }

    return;
}
