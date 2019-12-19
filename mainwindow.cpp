#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
///////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    int deviceID = 2;                   //  camera 1
    int apiID = cv::CAP_ANY;            //  0 = autodetect default API
    camera0.open(deviceID + apiID);     //  Open camera
    
    if( !camera0.isOpened() )
    {
        ui->textEdit->append("error: Camera not accessed successfully");
        return;
    }
    else ui->textEdit->append("Camera opened successfully");
    
    tmrTimer = new QTimer(this);
    connect( tmrTimer, SIGNAL(timeout()), this, SLOT(getFrameAndUpdateGUI()) );
    tmrTimer->start(20);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::getFrameAndUpdateGUI()
{
    camera0.read( frame );
    if( frame.empty() ) return;
    
    cv::cvtColor( frame, frame, cv::COLOR_BGR2RGB);
    cv::resize( frame, frame, cv::Size(640, 480), 0, 0, cv::INTER_LINEAR );
    
    QImage q_frame( frame.data, 
                    frame.cols, 
                    frame.rows, 
                    int(frame.step),
                    QImage::Format_RGB888 );
    
    ui->camera->setPixmap( QPixmap::fromImage(q_frame));
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_clicked()
{
    //cv::Mat img = cv::imread( "../gui_test/Beginner-Class-Hierarchy.jpg" );
    //cv::cvtColor( img, img, cv::COLOR_BGR2RGB);
    
//    cv::Mat temp;
//    camera0.read( temp );
//    if( temp.empty() ) return;
    
    //cv::cvtColor( frame, frame, cv::COLOR_BGR2RGB );
    
//    QImage qimg = QImage( (const unsigned char*)(img.data), 
//                          img.cols,
//                          img.rows,
//                          QImage::Format_RGB888 );
    
    
    
//    cv::imshow( "frame", temp );
//    cv::waitKey(20);
}
