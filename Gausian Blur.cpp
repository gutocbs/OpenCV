#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{
    namedWindow( "Imagem Original" , CV_WINDOW_AUTOSIZE );
    namedWindow( "Imagem suavizada" , CV_WINDOW_AUTOSIZE );

    Mat src = imread("C:/MyPic.jpg", CV_LOAD_IMAGE_COLOR);

    imshow( "Imagem Original", src );

    Mat dst;
    char zBuffer[35];

    for ( int i = 1; i  <  31; i = i + 2 )
    {
        snprintf(zBuffer, 35,"Kernel Size : %d x %d", i, i);

        GaussianBlur( src, dst, Size( i, i ), 0, 0 );

        putText( dst, zBuffer, Point( src.cols/4, src.rows/8), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 2 );

        imshow( "Imagem suavizada", dst );

        int c = waitKey(2000);

        if (c == 27)
        {
            return 0;
        }
    }

    dst = Mat::zeros( src.size(), src.type() );

    snprintf(zBuffer, 35,"Aperte qualquer tecla para parar");

    putText( dst, zBuffer, Point( src.cols/4,  src.rows / 2), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

    imshow( "Imagem Suavizada", dst );

    waitKey(0);

    return 0;
}
