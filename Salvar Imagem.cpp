#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     Mat img(650, 600, CV_16UC3, Scalar(50000,50000, 0)); //Cria uma imagem( 3 canais, 16 bit profundidade, 650 altura, 600 largura, (0, 50000, 50000) Azul, Verde e Vermelho)

     if (img.empty())
     {
          cout << "ERROR : Image cannot be loaded..!!" << endl;
          return -1;
     }


     ///Pra que esse código?
     vector<int> compression_params;

     compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);

     compression_params.push_back(98);

     bool bSuccess = imwrite("ImagemTeste.jpg", img, compression_params);



     if ( !bSuccess )

    {

         cout << "Falha ao salvar imagem" << endl;


    }

     namedWindow("Imagem", CV_WINDOW_AUTOSIZE);
     imshow("Imagem", img);

     waitKey(0);

     destroyWindow("MyWindow");

     return 0;
}
