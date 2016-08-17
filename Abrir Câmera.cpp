#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        cout << "Video nao pode ser aberto" << endl;
        return -1;
    }

    namedWindow("Video",CV_WINDOW_AUTOSIZE);

    while (1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame);

         if (!bSuccess)
        {
             cout << "Nao foi possivel abrir o video" << endl;
             break;
        }

        imshow("Video", frame);

        if (waitKey(30) == 27)
       {
            cout << "Apertou ESC" << endl;
            break;
       }
    }
    return 0;

}
