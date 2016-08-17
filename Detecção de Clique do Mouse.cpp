#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if ( flags == (EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON) )
     {
          cout << "Clique com o botao esquerdo do mouse junto com CTRL - Posicao (" << x << ", " << y << ")" << endl;
     }
     else if ( flags == (EVENT_FLAG_RBUTTON + EVENT_FLAG_SHIFTKEY) )
     {
          cout << "Clique com o botao direito do mouse junto com Shift - Posicao (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
     {
          cout << "Mouse movido enquanto segura o botao Alt - Posicao (" << x << ", " << y << ")" << endl;
     }
}

int main(int argc, char** argv)
{
     Mat img = imread("C:/MyPic.jpg");

     if ( img.empty() )
     {
          cout << "Erro ao carregar imagem" << endl;
          return -1;
     }

     namedWindow("Janela", 1);

     setMouseCallback("Janela", CallBackFunc, NULL);

     imshow("Janela", img);

     waitKey(0);

     return 0;
}
