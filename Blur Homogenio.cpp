#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{

    namedWindow( "Imagem Original" , CV_WINDOW_AUTOSIZE );
    namedWindow( "Imagem Suavizada" , CV_WINDOW_AUTOSIZE );

    Mat src = imread("C:/MyPic.jpg", CV_LOAD_IMAGE_COLOR);

    imshow( "Imagem Original", src );

    Mat dst;
    char zBuffer[35];

    for ( int i = 1; i < 31; i = i + 2 )
    {
        snprintf(zBuffer, 35,"Testando",s i, i);
        blur( src, dst, Size( i, i ) );

        //Coloca o texto do  zBuffer na imagem dst
        putText( dst, zBuffer, Point( src.cols/4, src.rows/8), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

        imshow( "Imagem Suavizada", dst );

        int c = waitKey(2000);

        if (c == 27)
        {
            return 0;
        }
    }

    //make the "dst" image, black
    dst = Mat::zeros( src.size(), src.type() );

    //copy the text to the "zBuffer"
    snprintf(zBuffer, 35,"Press Any Key to Exit");

    //put the text in the "zBuffer" to the "dst" image
    putText( dst, zBuffer, Point( src.cols/4,  src.rows / 2), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

    //show the black image with the text
    imshow( "Smoothed Image", dst );

//wait for a key press infinitely
    waitKey(0);

    return 0;

}
