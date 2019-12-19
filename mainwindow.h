#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>

// Opencv 4.1.0
//#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

///////////////////////////////////////////////////////////////////////////////////////////////////
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
public slots:
    void getFrameAndUpdateGUI();
    
private slots:
    void on_pushButton_clicked();
    
private:
    Ui::MainWindow *ui;
    
    cv::VideoCapture camera0;
    cv::Mat frame;
    cv::Mat img_out;
    
    QImage q_frame;
    QImage q_img_out;
    
    QTimer *tmrTimer;

};



#endif // MAINWINDOW_H
