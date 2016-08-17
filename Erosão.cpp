#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

int main()
{
        int erosao = 0;
        IplImage* img = cvLoadImage("C:/MyPic.jpg");
        IplImage* imgErodida = cvLoadImage("C:/MyPic.jpg");
        cvNamedWindow("Imagem");
        cvShowImage("Imagem", img);

        cvNamedWindow("Erosao");
        cvCreateTrackbar("Erosao", "Erosao", &erosao, 10, NULL);

        while(true){
            cvErode(img, imgErodida, 0, erosao);
            cvShowImage("Erosao", imgErodida);
            if(cvWaitKey(30) == 27)
                break;
        }
        cvWaitKey(0);

        cvDestroyWindow("MyWindow");
        cvDestroyWindow("Eroded");
        cvReleaseImage(&img);

        return 0;
}
