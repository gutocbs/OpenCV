#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

///Sério, o que isso faz?

using namespace cv;

int main( int argc, char** argv )
{
 namedWindow( "Imagem Original" , CV_WINDOW_AUTOSIZE );
 namedWindow( "Imagem Suavizada" , CV_WINDOW_AUTOSIZE );

 Mat src = imread( "C:/MyPic.JPG", CV_LOAD_IMAGE_UNCHANGED);

 imshow( "Imagem Original", src );

 Mat dst;
 char zBuffer[35];

 //for ( int i = 1; i  <  31; i = i + 2 )
 int i = 0;
 while(true)
 {
  snprintf(zBuffer, 35,"Tamanho do kernel : %d x %d", i, i);

  bilateralFilter( src, dst, i, i*2, i/2);

  putText( dst, zBuffer, Point( src.cols/4, src.rows/8), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 2 );

  imshow( "Imagem Suavizada", dst );

  int c = waitKey(2000);

  if (c == 27)
  {
    return 0;
  }
  i+=10;
 }

 dst = Mat::zeros( src.size(), src.type() );

 //snprintf(zBuffer, 35,"Aperte qualquer tecla pra sair");

 putText( dst, zBuffer, Point( src.cols/4,  src.rows / 2), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

 imshow( "Imagem suavizada", dst );

 waitKey(0);

 return 0;
}
