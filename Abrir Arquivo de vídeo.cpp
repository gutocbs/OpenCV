#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("C:/Users/Augusto/Videos/Filmes/Laputa.Castle.In.The.Sky.1986.1080p.BluRay.x264.anoXmous/Laputa.Castle.In.The.Sky.1986.1080p.BluRay.x264.anoXmous_.mp4");

    if ( !cap.isOpened() )
    {
         cout << "Impossivel abrir o arquivo de video \n" << endl;
         return -1;
    }


    double fps = cap.get(CV_CAP_PROP_FPS);

     cout << "Frame per seconds : " << fps << endl;

    namedWindow("Video",CV_WINDOW_AUTOSIZE);

    while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame);

         if (!bSuccess)
        {
                        cout << "Nao e possivel ler o arquivo de video" << endl;
                       break;
        }

        imshow("Video", frame);

        if(waitKey(30) == 27)
       {
                cout << "Voce apertou ESC \n" << endl;
                break;
       }
    }

    return 0;

}
