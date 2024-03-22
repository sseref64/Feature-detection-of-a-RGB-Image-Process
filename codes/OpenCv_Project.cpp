#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include "CommonProcesses.h"
#include "CornerDetection.h"
#include "LineDetection.h"
#include "Detection.h"
using namespace cv;
using namespace std;
Mat src, src_gray;

// HATIRLATMA!!
// ---------------------
//Base classımızda yer alan 
//tum metodlar ve değişkenler türetilmiş classlarımızda da bulunmak zorundadır
//cünkü her cornerDetectionu bir detectiondur
//her lineDetection bir detectiondur
// ---------------------


int main(int argc)
{

    //CommonProcesses
    // Commonprocesses classımız openCV işlemlerinin yapıldığı yer.
    // commonprocesste yaptıgımız islemlerı main functıonumuzda da opencv nın
    // 2 tane base class oluşturdum common processes ve detection
    // 2 adet de derived class yaptım cornerDetection ve LineDetection

    //CommonProcesse fileyı okutup kaydettim
    CommonProcesses commonProcess("C:/Users/pixelpuzzle.jpg");
    cv::Mat img = commonProcess.readImage();


    //CommonProcesses dp2(img);
    //Iki farklı overloaded constructorumuz var 
    //o yuzden ıkı farklı commonprocess yaratma methodum var
    //CommonProcesses commonProcess;
    //cv::Mat img = commonProcess.readImage("C:/Users/pixelpuzzle.png");
    //buradan sonra elimide commonProcess tarafından bıze dondurulmus bır openCv matriksi var


    //Line Detection Gösterimi
    //Line detectionda overloaded farklı constructorlar mevcut
    LineDetection lineDetection("C:/Users/pixelpuzzle.jpg");
    LineDetection cp2(img);
    //50 - 400 arası dene ve 50 50 arası deneyebilirim.
    lineDetection.setLowThreshold(50);
    lineDetection.setMaxThreshold(50);
    lineDetection.detectFeatures();

    // ---------------------
   
    lineDetection.showOriginal();
    lineDetection.showEdges();
    lineDetection.showResult();
    //----------------------
    //Resım gosterme fonksiyonu olan showedges show result show orıgınıal
    // arka planda yıne de commonprocesses classının functıonlarını cagırırım 
    // cunku resımle alakalı openCv isleri oradan hallediyorum.
    // 
    // benım her linedetection ve cornerdetection clasım yaratıldıgında
    // benım detection adlı base classımında constructoru cagırılıyor (dikkat et).
    // 
    // 
    CornerDetection cornerDetection(img);
    //set thresh 150 yapabilirim.
    cornerDetection.setThresh(150);
    cornerDetection.detectFeatures();
    cornerDetection.showOriginal();
    cornerDetection.showResult();
    //lineDetection.detectFeatures(); 
    //lineDetection.printInformation();
    cornerDetection.printInformation();
    // Cıkarılan cornerlar ve lineların koordinat verisini
    // fileya kaydettim (içlerini sildirerek kaydetmeye çalış.)  
    commonProcess.writeTo(lineDetection.getLines(), "lines_extracted");
    commonProcess.writeTo(cornerDetection.getCorners(), "corners_extracted");

    commonProcess.scaleImage(lineDetection.getResult(), 0.5);

    cv::waitKey();
    return 0;
}