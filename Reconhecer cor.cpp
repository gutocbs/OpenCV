#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    int iLowH = 0;
    int iHighH = 255;

    int iLowS = 0;
    int iHighS = 255;

    int iLowV = 0;
    int iHighV = 255;

    //int contador = 0;

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "ERRO: Nao foi possivel abrir a camera" << endl;
        return -1;
    }

    namedWindow("Camera",CV_WINDOW_AUTOSIZE);
    namedWindow("Controle",CV_WINDOW_AUTOSIZE);

    cvCreateTrackbar("Matriz Menor", "Controle", &iLowH, 180, NULL);
    cvCreateTrackbar("Matriz Maior", "Controle", &iHighH, 180, NULL);

    cvCreateTrackbar("Saturacao menor", "Controle", &iLowS, 256, NULL);
    cvCreateTrackbar("Saturacao maior", "Controle", &iHighS, 256, NULL);

    cvCreateTrackbar("Luminosidade menor", "Controle", &iLowV, 256, NULL);
    cvCreateTrackbar("Luminosidade maior", "Controle", &iHighV, 256, NULL);

    cout << endl << "Para parar, aperte ESC" << endl;

    Mat frame;
    //int i = 1;

    while (1)
    {

        bool bSuccess = cap.read(frame);
        if (!bSuccess)
        {
            cout << "ERRO: Nao foi possivel abrir o frame do video" << endl;
            break;
        }
        Mat imagemRiscada;
        //if(i == 1){
            imagemRiscada = ((frame.size()), 8, 3);
            resize(frame, imagemRiscada, Size(), 1, 1, INTER_LINEAR);

            //imagemRiscada = Scalar(255,255,255,0);
            //i++;
        //}

        //IplImage* threshold(IplImage*);

        CvCapture* captura = cvCaptureFromCAM(0);
        Mat frameAtual = cvQueryFrame(captura);

        //imagemRiscada = Scalar(255,255,255,0);

        Mat frameDestino;
        frameDestino = ((frameAtual), 8, 3);

        blur(frameAtual, frameAtual, Size(3,3));
        cvtColor(frameAtual, frameDestino, CV_BGR2HSV);
        ///HUE, SATURATION, VALUE
        blur(frameDestino, frameDestino, Size(3,3));

        Mat imagemThresh;
        imagemThresh = ((frameAtual), 8, 1);
        //resize(imagemThresh, imagemThresh, Size(), 0.5, 0.5, INTER_LINEAR);
        inRange(frameDestino, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),imagemThresh);

        ///Scalar(10, 190, 80) -> valores inferiores da faixa
        ///HUE / SATURAÇÃO / BRILHO
        ///Scalar(90, 255, 255) -> valores superiores da faixa

        Moments momentos;
        momentos = moments(imagemThresh, true);
        double primeira_ordem_x = momentos.m10;
        double primeira_ordem_y = momentos.m01;
        double segunda_ordem = momentos.m00;

        static int pos_x = 0;
        static int pos_y = 0;
        int ultimo_x = pos_x;
        int ultimo_y = pos_y;
        pos_x = primeira_ordem_x / segunda_ordem;
        pos_y = primeira_ordem_y / segunda_ordem;

        //Mat nova_imagem;
        //nova_imagem = ((frameAtual), 8, 3);
        int largura_linha = 5;
        if(ultimo_x > 0 && ultimo_y > 0 && pos_x > 0 && pos_y > 0)
            line(imagemRiscada, Point(pos_x, pos_y),Point(ultimo_x, ultimo_y), Scalar(0, 179, 179), largura_linha);

        //add(imagemRiscada, imagemRiscada, frameAtual);
        add(frameAtual, imagemRiscada, frameAtual);
        //add(frameAtual, imagemRiscada, nova_imagem);
       // if(contador % 14 == 0 ) {
            imshow("Camera", frameAtual);
            //imshow("Camera", frameAtual);
            //imagemRiscada = ((frame.size()), 8, 3);
            //largura_linha = 5;
        //} else
          //  imshow("Camera", frameAtual);

        //imshow("Camera", frameDestino );
        imshow("Controle", imagemThresh);
        //largura_linha += (largura_linha % 24) == 0 ? 0 : 1;
        char c = cvWaitKey(30);
        if(waitKey(30) == 27)
            break;
        //scontador++;
    }
    destroyWindow("Camera");
    destroyWindow("Controle");
    return 0;
}
