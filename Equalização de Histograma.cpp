#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
    Mat img = imread("C:/MyPic.jpg", CV_LOAD_IMAGE_COLOR); //open and read the image

    if (img.empty())
    {
        cout << "A imagem nao pode ser carregada" << endl;
        return -1;
    }

    cvtColor(img, img, CV_BGR2GRAY);

    Mat img_hist_equalized;
    equalizeHist(img, img_hist_equalized);

    namedWindow("Imagem Original", CV_WINDOW_AUTOSIZE);
    namedWindow("Histograma Equalizado", CV_WINDOW_AUTOSIZE);

    imshow("Imagem Original", img);
    imshow("Histograma Equalizado", img_hist_equalized);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
