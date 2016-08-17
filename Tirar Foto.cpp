//Câmera
#include "opencv2/highgui/highgui.hpp"
//Cout e cin
#include <iostream>
//pros vetores
#include <cstdio>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    int n;
    char nome[81], original[81], numero[2];
    cout << "Quantas fotos deseja tirar? \n";
    cin >> n;
    fflush(stdin);
    cout << "Digite o nome das fotos \n";
    gets(nome);
    //É preciso de 2 vetores pra poder nomear todas as fotos do mesmo jeito
    strcpy(original,nome);
    CvCapture* capture;
    //Abre a câmera pra vídeo
    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        cout  << "Erro: Nao foi possivel abrir a camera!" << endl;
        return -1;
    }

    capture = cvCaptureFromCAM(0);

    if (!capture)  // if not success, exit program
    {
        cout << "Erro: Nao foi tirar a foto!" << endl;
        return -1;
    }


    cout << "A primeira foto a ser tirada sera usada para calibrar a camera \n";
    cout << "Aperte qualquer tecla para continuar\n";
    cvWaitKey(0);
    IplImage* iplImg = cvQueryFrame( capture );
    //Caso o capture seja null, o programa pára.
    assert(capture != NULL);
    for(int i = 0; i < n+1; i++)
    {
        if(i > 0)
        {
            namedWindow("Video", WINDOW_AUTOSIZE);
            cout << "Aperte a tecla espaco para tirar a foto" << endl;
            while (1)
            {
                Mat frame;
                bool bSuccess = cap.read(frame); // read a new frame from video
                if (!bSuccess) //if not success, break loop
                {
                    cout << "ERROR: Nao foi possivel ler a camera!" << endl;
                    break;
                }
                imshow("Video", frame);
                if (waitKey(10) == 32) //Espera até o usuário apertar espaço
                    break;
            }
            cvDestroyWindow("Video");
        }
        //É preciso capturar duas vez a foto pra imagem mudar na tela
        iplImg = cvQueryFrame( capture );
        iplImg = cvQueryFrame( capture );
        cvNamedWindow("Foto" , CV_WINDOW_AUTOSIZE);//Criar janela da foto que vai tirar
        cvShowImage("Foto", iplImg);
        cvWaitKey(1000);
        if(i > 0)
        {
            //Pra poder colocar o número da foto no final, sendo ele a ordem em que foi tirada
            itoa(i, numero, 10);
            strcat(nome, numero);
            strcat(nome, ".jpg");
            //Salvar imagem
            cvSaveImage(nome,iplImg);
            cout << "Foto "<< i << " tirada!\n";
        }
        cout << "Aperte qualquer tecla pra continuar \n";
        cvWaitKey(0);
        cvDestroyWindow("Foto");
        strcpy(nome,original);
    }
    return 0;
}
