#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
using namespace cv;

int main(int argc, char** argv)
{
    UMat img, gray;
    imread("../img/image.jpg", 1).copyTo(img);

    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);

    imshow("edges", gray);
    waitKey();
    return 0;
}
