#include <iostream>
#include <cstdio>
#include <cstring>
#include "highgui.hpp"

using namespace std;

int main() {
    char nomeVideo[100];

    cout << "Digite o nome do video que deseja abrir: \n";
    fflush(stdin);
    gets(nomeVideo);
    strcat(nomeVideo, ".avi");

    cvNamedWindow(nomeVideo, CV_WINDOW_AUTOSIZE);//Criar janela do vídeo
    CvCapture* capture = cvCreateFileCapture(nomeVideo);//Usa o ponteiro pra apontar pro vídeo
    IplImage* frame;
    while(1){
    frame = cvQueryFrame(capture);//Captura o frame
    if(!frame)
        break;
    cvShowImage(nomeVideo, frame);
    char c = cvWaitKey(33);//33 é o tempo médio entre dois frames(33 ms)
    if(c == 27)//27 é o número ASCII do ESC
        break;
    }
    cvReleaseCapture(&capture);//Fechar vídeo
    cvDestroyWindow(nomeVideo);//Fechar janela do vídeo
}
