#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char** argv)
{
    Mat img, gray;
    img = imread("../img/image.jpg", 1);

    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);

    imshow("edges", gray);
    waitKey();
    return 0;
}
