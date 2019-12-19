#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    cv::Mat img = cv::imread( "/home/roman/Qt_gui_test/gui_test/Beginner-Class-Hierarchy.jpg");
    
    cv::cvtColor( img, img, cv::COLOR_BGR2RGB);
    
    QImage qimg = QImage( (const unsigned char*)(img.data), 
                          img.cols,
                          img.rows,
                          QImage::Format_RGB888 );
    
//    cv::imshow( "img", img );
//    cv::waitKey(30);
}
