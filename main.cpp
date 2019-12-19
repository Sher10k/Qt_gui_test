#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>

#include <iostream>

// Opencv 4.1.0
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

// ZCM
//#include "ZcmCameraBaslerJpegFrame.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    
    
    
    w.show();
    return a.exec();
}
