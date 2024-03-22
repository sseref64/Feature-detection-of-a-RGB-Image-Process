#include "CornerDetection.h"

using namespace std;

CornerDetection::CornerDetection(cv::Mat img) : Detection(img) {
    this->mat = img;
    //this->mat_gray = img;
    this->mat_gray = this->commonProcesses.convertToGrayscale(img);
    this->block_size = 2;
    this->aperture_size = 3;
    this->k = 0.04;
    this->thresh = 200;
    this->max_thresh = 255;
}

CornerDetection::CornerDetection(cv::Mat img, cv::Mat img_gray) :Detection(img) {
    this->mat = img;
    this->mat_gray = img_gray;
    this->block_size = 2;
    this->aperture_size = 3;
    this->k = 0.04;
    this->thresh = 200;
    this->max_thresh = 255;
}

CornerDetection::CornerDetection() : Detection() {
    this->mat = cv::Mat::zeros(500, 500, CV_32FC1);

}


void CornerDetection::showOriginal() {
    commonProcesses.showImage("Corner Detection Original Image", this->mat_gray);
}


void CornerDetection::showResult() {
    commonProcesses.showImage("Corner Detection Harris Corners", this->result);
}


void CornerDetection::printInformation() {
    cout << "Corner Detection Class" << endl;
    this->block_size = 2;
    this->aperture_size = 3;
    this->k = 0.04;
    this->thresh = 200;
    this->max_thresh = 255;
    cout << "Block Size: " << this->block_size << "\n"
        << "Aperture Size: " << this->aperture_size << "\n"
        << "K Value: " << this->k << "\n"
        << "Low Threshold: " << this->thresh << "\n"
        << "Max Threshold: " << this->max_thresh << endl;

    cout << endl;
}

void CornerDetection::detectFeatures() {
    Mat dst = Mat::zeros(this->mat.size(), CV_32FC1);
    cornerHarris(mat_gray, dst, this->block_size, this->aperture_size, this->k);
    Mat dst_norm, dst_norm_scaled;
    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    for (int i = 0; i < dst_norm.rows; i++)
    {
        for (int j = 0; j < dst_norm.cols; j++)
        {
            if ((int)dst_norm.at<float>(i, j) > this->thresh)
            {
                corners.push_back(Point(j, i));
                circle(dst_norm_scaled, Point(j, i), 5, Scalar(0), 2, 8, 0);
            }
        }
    }
    //namedWindow(this->corners_window);
    //imshow(this->corners_window, dst_norm_scaled);
    this->result = dst_norm_scaled;
    //for (int i = 0; i < corners.size(); ++i) {
    //    std::cout << corners[i] << " ";
    //}
    //cout << "" << endl;
}



//setters and getters for parameters of corner detection

cv::Mat CornerDetection::getResult() {
    return this->result;
}

void CornerDetection::setApertureSize(int aperture_size) {
    this->aperture_size = aperture_size;
}

void CornerDetection::setBlockSize(int block_size) {
    this->block_size = block_size;
}

void CornerDetection::setK(int k) {
    this->k = k;
}

void CornerDetection::setMaxThresh(int max_thresh) {
    this->max_thresh = max_thresh;
}

void CornerDetection::setThresh(int thresh) {
    this->thresh = thresh;
}

void CornerDetection::setCorners(std::vector<cv::Point> corners) {
    this->corners = corners;
}

std::vector<cv::Point> CornerDetection::getCorners() {
    return this->corners;
}

int CornerDetection::getApertureSize() {
    return this->aperture_size;
}

int CornerDetection::getBlockSize() {
    return this->block_size;
}

int CornerDetection::getK() {
    return this->k;
}

int CornerDetection::getThresh() {
    return this->thresh;
}

int CornerDetection::getMaxThresh() {
    return this->max_thresh;
}