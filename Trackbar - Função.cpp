#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

void MyCallbackForBrightness(int iValueForBrightness, void *userData)
{
    Mat dst;
    int iValueForContrast = *( static_cast<int*>(userData) );

    int iBrightness = iValueForBrightness - 50;
    double dContrast = iValueForContrast / 50.0;

    cout << "Contraste =" << dContrast << ", Brilho =" << iBrightness << endl;

    //Pra poder usar valores negativos
    src.convertTo(dst, -1, dContrast, iBrightness);

    imshow("Imagem", dst);
}

void MyCallbackForContrast(int iValueForContrast, void *userData)
{
    Mat dst;
    int iValueForBrightness = *( static_cast<int*>(userData) );

    int iBrightness = iValueForBrightness - 50;
    double dContrast = iValueForContrast / 50.0;

    cout << "Contraste =" << dContrast << ", Brilho =" << iBrightness << endl;

    src.convertTo(dst, -1, dContrast, iBrightness);

    imshow("Imagem", dst);
}



int main(int argc, char** argv)
{
    src = imread("C:/MyPic.JPG", CV_LOAD_IMAGE_UNCHANGED);

    if (src.data == false)
    {
        cout << "Nao foi possivel abrir a imagem" << endl;
        return -1;
    }

    namedWindow("Imagem", 1);

    int iValueForBrightness = 50;
    int iValueForContrast = 50;

    createTrackbar("Brilho", "Imagem", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);

    createTrackbar("Contraste", "Imagem", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);

    imshow("Imagem", src);

    waitKey(0);


    return 0;
}
