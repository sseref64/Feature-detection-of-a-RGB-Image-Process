#pragma once

/// \file
/// \brief LineDetection Class
/// \author [Seref Karakus]
/// \date [09.01.2024]

#ifndef LINE_DETECTION_H
#define LINE_DETECTION_H

#include "Detection.h"

using namespace std;
using namespace cv;

/// \brief Derived class for line feature detection.
class LineDetection : public Detection {
private:
    /// \brief Common processes utility for additional functionality.
    CommonProcesses commonProcesses;
    /// \brief Detected Lines
    vector<Vec4i> lines;
    /// \brief Grayscale version of the input image.
    cv::Mat img_gray;
    /// \brief Image edges obtained through edge detection.
    cv::Mat edges;
    /// \brief Image edges obtained through edge detection.
    cv::Mat result;
    /// \brief Low threshold for edge detection.
    int low_threshold;
    /// \brief Maximum threshold for edge detection.
    int max_threshold;

public:
    /// \brief Constructor that takes a filename as a parameter.
    /// \param filename The name of the file to be processed.
    LineDetection(const string& filename);
    /// \brief Constructor that takes an image matrix as a parameter.
    /// \param img The image matrix to be processed.
    LineDetection(cv::Mat img);
    /// \brief Implementation of the virtual function for line feature detection.
    void detectFeatures() override; // Hatalarý kolay bulayým diye override yaptým.
    /// \brief Function to display the edges of the image.
    void showEdges();
    /// \brief Implementation of the virtual function to display the original image.
    void showOriginal() override;
    /// \brief Implementation of the virtual function to display the result image after feature detection.
    void showResult() override;
    /// \brief Implementation of the virtual function to print information about the line detection process.
    void printInformation() override;

    /// \brief Get method for edges.
    cv::Mat getEdges();
    /// \brief Get method for result image.
    cv::Mat getResult();
    /// \brief Get method for detected lines.
    vector<Vec4i> getLines();
    /// \brief Get method for low threshold.
    int getLowThreshold();
    /// \brief Set method for low threshold.
    void setLowThreshold(int low_threshold);
    /// \brief Get method for maximum threshold.
    int getMaxThreshold();
    /// \brief Set method for maximum threshold.
    void setMaxThreshold(int max_threshold);
};

#endif // LINE_DETECTION_H
