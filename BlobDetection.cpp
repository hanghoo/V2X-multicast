#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img = imread("lena.png",IMREAD_GRAYSCALE);

    /*
    SimpleBlobDetector::Params params;
    //阈值控制
    params.minThreshold = 10;
    params.maxThreshold = 200;
    //像素面积大小控制
    params.filterByArea = true;
    params.minArea = 1000;
    //形状（凸）
    params.filterByCircularity = false;
    params.minCircularity = 0.7;
    //形状（凹）
    params.filterByConvexity = true;
    params.minConvexity = 0.9;
    //形状（园）
    params.filterByInertia = false;
    params.minInertiaRatio = 0.5;
    */

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();
    vector<KeyPoint> keypoints;
    detector->detect(img,keypoints);
    Mat img_with_keypoints;
    drawKeypoints(img,keypoints,img_with_keypoints,Scalar(0,0,255),DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    imshow("keypoints",img_with_keypoints);
    waitKey(0);
    return 0;
}