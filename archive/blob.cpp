#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;
 
int main( int, char** argv )  
{  
    Mat image = imread( argv[1] );  
    vector<KeyPoint> keypoints;  
    SimpleBlobDetector::Params params;  
    params.filterByArea = true;
    params.minArea = 10;
    params.maxArea = 10000;  
 
    SimpleBlobDetector blobDetector( params );  
    blobDetector.create("SimpleBlob");  
    blobDetector.detect( image, keypoints ); 
    drawKeypoints(image, keypoints, image, Scalar(255,0,0)); 
    
    namedWindow("result", 1); 
    imshow("result", image);
    waitKey();
    return 0;  
}