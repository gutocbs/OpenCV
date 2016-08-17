#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    char nome[81], caminho[81];

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "ERRO: Nao foi possivel abrir a camera" << endl;
        return -1;
    }

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    cout << "Digite o nome do video" << endl;
    fflush(stdin);
    gets(nome);

    namedWindow(nome,CV_WINDOW_AUTOSIZE);

    strcat(caminho, "C:/Users/Augusto/Videos/Programas/Iniciação/Tarefa1/");
    strcat(caminho, nome);
    strcat(caminho, ".avi");
    cout << "O video foi salvo em: " << caminho << endl;

    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
    VideoWriter oVideoWriter(caminho, -1, 20, frameSize, true);

    if (!oVideoWriter.isOpened())
    {
        cout << "ERRO: Falha ao criar o arquivo de video" << endl;
        return -1;
    }
    cout << endl << "Para parar a gravacao, aperte ESPACO" << endl;
    while (1)
    {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (!bSuccess)
        {
            cout << "ERRO: Nao foi possivel abrir o frame do video" << endl;
            break;
        }
        oVideoWriter.write(frame);
        imshow(nome, frame);
        char c = cvWaitKey(30);
        if(waitKey(10) == 32)
            break;
    }
    return 0;
}
