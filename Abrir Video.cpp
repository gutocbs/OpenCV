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

    cvNamedWindow(nomeVideo, CV_WINDOW_AUTOSIZE);//Criar janela do v�deo
    CvCapture* capture = cvCreateFileCapture(nomeVideo);//Usa o ponteiro pra apontar pro v�deo
    IplImage* frame;
    while(1){
    frame = cvQueryFrame(capture);//Captura o frame
    if(!frame)
        break;
    cvShowImage(nomeVideo, frame);
    char c = cvWaitKey(33);//33 � o tempo m�dio entre dois frames(33 ms)
    if(c == 27)//27 � o n�mero ASCII do ESC
        break;
    }
    cvReleaseCapture(&capture);//Fechar v�deo
    cvDestroyWindow(nomeVideo);//Fechar janela do v�deo
}
