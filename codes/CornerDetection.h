#pragma once

/// \file
/// \brief Corner Detection Class
/// \author [Seref Karakus]
/// \date [09.01.2024]

#ifndef CORNER_DETECTION_H
#define CORNER_DETECTION_H

#include "Detection.h"

using namespace std;

/// \brief Derived class for corner feature detection.
class CornerDetection : public Detection {
private:
    /// \brief Window name for displaying detected corners.
    const char* corners_window = "Corners detected";
    /// \brief Input image matrix.
    cv::Mat mat;
    /// \brief Grayscale version of the input image.
    cv::Mat mat_gray;
    /// \brief Resulting image matrix after corner detection.
    cv::Mat result;
    /// \brief Detected corners.
    vector<cv::Point> corners;
    /// \brief Common processes utility for additional functionality.
    CommonProcesses commonProcesses;

    /// \brief Harris Corner Detection Parameters
    /// \brief Threshold for corner detection.
    int thresh;
    /// \brief Maximum threshold for corner detection.
    int max_thresh;
    /// \brief Block size for corner detection.
    int block_size;
    /// \brief Aperture size for corner detection. (Köþe tespiti için)
    int aperture_size;
    /// \brief k parameter for Harris corner detection.
    double k;

public:
    // Overloading Constructors
    /// \brief Default constructor.
    CornerDetection();
    /// \brief Constructor that takes both image and grayscale image as parameters.
    /// \param img The input image matrix.
    /// \param img_gray The grayscale version of the input image.
    CornerDetection(cv::Mat img, cv::Mat img_gray);
    /// \brief Constructor that takes only the input image matrix as a parameter.
    /// \param img The input image matrix.
    CornerDetection(cv::Mat img);

    // Overridden functions from Detection Class
    /// \brief Implementation of the virtual function for corner feature detection.
    void detectFeatures() override;
    /// \brief Implementation of the virtual function to display the original image.
    void showOriginal() override;
    /// \brief Implementation of the virtual function to display the result image after feature detection.
    void showResult() override;
    /// \brief Implementation of the virtual function to print information about the corner detection process.
    void printInformation() override;

    // Get and set methods for corners and parameters...

    // Getters
    /// \brief Get method for resulting image matrix.
    cv::Mat getResult();
    /// \brief Get method for block size parameter.
    int getBlockSize();
    /// \brief Get method for aperture size parameter.
    int getApertureSize();
    /// \brief Get method for k parameter.
    int getK();
    /// \brief Get method for threshold parameter.
    int getThresh();
    /// \brief Get method for maximum threshold parameter.
    int getMaxThresh();
    /// \brief Get method for detected corners.
    vector<cv::Point> getCorners();

    // Setters
    /// \brief Set method for detected corners.
    void setCorners(vector<cv::Point> corners);
    /// \brief Set method for block size parameter.
    void setBlockSize(int block_size);
    /// \brief Set method for aperture size parameter.
    void setApertureSize(int aperture_size);
    /// \brief Set method for k parameter.
    void setK(int k);
    /// \brief Set method for threshold parameter.
    void setThresh(int thresh);
    /// \brief Set method for maximum threshold parameter.
    void setMaxThresh(int max_thresh);
};

#endif // CORNER_DETECTION_H
