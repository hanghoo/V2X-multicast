#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
//#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){
    Mat img = imread (argv[1]);

    SimpleBlobDetector::Params params;
    //阈值控制
    params.thresholdStep = 10;
    params.minThreshold = 50;
    params.maxThreshold = 250;
    params.minRepeatability = 2;
    params.minDistBetweenBlobs = 10;
    //像素面积大小控制
    params.filterByArea = true;
    params.minArea = 25;
    params.maxArea = 5000000;
    //形状（凸）
    params.filterByCircularity = true;
    params.minCircularity = 0.1;
    // //形状（凹）
    // params.filterByConvexity = true;
    // params.minConvexity = 0.8;
    //形状（园）
    params.filterByInertia = true;
    params.minInertiaRatio = 0.5;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    vector<KeyPoint> keypoints;

    detector->detect(img,keypoints);
    printf("Total blob points %ld\n", keypoints.size());      
    
    Mat img_with_keypoints;
    drawKeypoints(img,keypoints,img_with_keypoints,Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS); //
    
    for(int i=0; i<keypoints.size(); i++){
        printf("Coordinate (%f, %f)\n",keypoints[i].pt.x, keypoints[i].pt.y);
        //circle(img_with_keypoints, Point((keypoints[i].pt.x, keypoints[i].pt.y)), 5, (0,0,255), 2);
        circle(img_with_keypoints, keypoints[i].pt, 2, Scalar(255, 255, 255),1);
    }

    imshow("keypoints",img_with_keypoints);
    waitKey(0);
    return 0;
}
