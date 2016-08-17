#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main( int argc, const char** argv )

{

    Mat img = imread("C:/MyPic.jpg", CV_LOAD_IMAGE_COLOR);


     if (img.empty())
     {
          cout << "Image cannot be loaded..!!" << endl;
          return -1;
    }

    Mat imgH;
    img.convertTo(imgH, -1, 2, 0); //Dobra o contraste

    Mat imgL;
    img.convertTo(imgL, -1, 0.5, 0); //Diminui o contraste pela metade

    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    namedWindow("High Contrast", CV_WINDOW_AUTOSIZE);
    namedWindow("Low Contrast", CV_WINDOW_AUTOSIZE);

    imshow("Original Image", img);
    imshow("High Contrast", imgH);
    imshow("Low Contrast", imgL);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
