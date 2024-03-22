#include "LineDetection.h";

using namespace std;



LineDetection::LineDetection(const string& filename) : Detection(filename) {
    //default
    //this->img = NULL;
    this->img_gray = NULL;
    this->low_threshold = 50;
    this->max_threshold = 150;
    this->edges = NULL;
    this->result = NULL;
    cout << "Could not open or find the image for line detection!\n" << endl;
}

LineDetection::LineDetection(cv::Mat img) :Detection(img) {
    this->edges = NULL;
    this->result = NULL;

    if (img.empty()) {
        cout << "Could not open or find the image for line detection!\n" << endl;
    }
    this->img_gray = img;
    //this->img_gray = commonProcesses.convertToGrayscale(this->img);
    this->low_threshold = 50;
    this->max_threshold = 150;

}


void LineDetection::showEdges() {
    commonProcesses.showImage("Line Detection Canny Edge Detection", this->edges);
}

void LineDetection::showOriginal() {
    commonProcesses.showImage("Line Detection Original Image", this->img_gray);
}

void LineDetection::showResult() {
    commonProcesses.showImage("Line Detection Detected Lines", this->result);
}


void LineDetection::detectFeatures() {

    img_gray = convertToGrayscale();
  
    if (img_gray.empty()) {
        cout << "Image is empty cannot proceed further!" << endl;
        return;
    }
    // Apply Canny edge detection
    cv::Mat edges;
    cv::Canny(img_gray, edges, this->low_threshold, this->max_threshold);

    // Perform Hough Line Transform to detect lines
    vector<cv::Vec4i> lines;  // Vector to store lines

    // HoughLinesP is used instead of HoughLines to get line segments
    cv::HoughLinesP(edges, lines, 1, CV_PI / 180, 100, 50, 10);

    this->lines = lines;
    // Append the extracted edges to the vector of lines
    // Display the original image, Canny edges, and detected lines
    cv::Mat resultImage = getImage().clone();
    //cv::cvtColor(resultImage, resultImage, cv::COLOR_GRAY2BGR);

    for (size_t i = 0; i < lines.size(); ++i) {
        cv::line(resultImage, cv::Point(lines[i][0], lines[i][1]),
            cv::Point(lines[i][2], lines[i][3]), cv::Scalar(255, 0, 0), 2, cv::LINE_AA);
    }
    /*commonProcesses.showImage("Original Gray Image", img_gray);
    commonProcesses.showImage("Canny Edges", edges);*/
    this->edges = edges;
    //commonProcesses.showImage("Detected Lines", resultImage);
    this->result = resultImage;
}



void LineDetection::printInformation() {
    cout << "Line Detection Class is Called" << endl;
    cout << "Low threshold" << this->low_threshold << endl;
    cout << "Max threshold" << this->max_threshold << endl;
    cout << endl;
}

cv::Mat LineDetection::getEdges() {
    if (this->edges.empty()) {
        cerr << "Error opening the file for writing." << endl;
    }
    return this->edges;
}

cv::Mat LineDetection::getResult() {
    return this->result;
}

int LineDetection::getMaxThreshold() {
    return this->max_threshold;
}

int LineDetection::getLowThreshold() {
    return this->low_threshold;
}

vector<Vec4i> LineDetection::getLines() {
    return this->lines;
}

void LineDetection::setLowThreshold(int low_threshold) {
    this->low_threshold = low_threshold;
}

void LineDetection::setMaxThreshold(int max_threshold) {
    this->max_threshold = max_threshold;
}