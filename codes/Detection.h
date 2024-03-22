#pragma once

/// \file
/// \brief Detection Class
/// \author [Seref Karakus]
/// \date [09.01.2024]

#ifndef DETECTION_H
#define DETECTION_H

#include "CommonProcesses.h"

using namespace std;
using namespace cv;

/// \brief Base class for feature detection processes.
class Detection : public CommonProcesses {
protected:
    /// \brief Original Image Matrix.
    cv::Mat original;
    /// \brief Resulting image matrix after feature detection.
    cv::Mat result;

public:
    /// \brief Constructor that takes a filename as a parameter.
    /// \param filename The name of the file to be processed.
    Detection(const string& filename);
    /// \brief Constructor with an optional parameter for the image matrix.
    /// \param img The input image matrix.
    Detection(Mat img = Mat(0, 0, CV_64F));
    /// \brief Virtual function for feature detection.
    virtual void detectFeatures() = 0;
    /// \brief Virtual function to display the original image.
    virtual void showOriginal() = 0;
    /// \brief Virtual function to display the result image after feature detection.
    virtual void showResult() = 0;
    /// \brief Virtual function to print information about the detection process.
    virtual void printInformation() = 0;

};

#endif // DETECTION_H
