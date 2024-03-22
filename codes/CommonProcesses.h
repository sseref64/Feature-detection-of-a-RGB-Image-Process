/// \file
/// \brief Common Processes Class (Resim okuma, büyütme, gri scale yapma vb iþleri burada yapýlmaktadýr.)
/// \author [Seref Karakus]
/// \date [09.01.2024]

#ifndef COMMON_PROCESSES_H
#define COMMON_PROCESSES_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

/// \brief Class providing common image processing operations.
class CommonProcesses {
protected:
    /// \brief Image matrix for processing.
    cv::Mat image;
    /// \brief Filename associated with the image.
    string filename;

public:
    /// \brief Constructor that takes an image matrix (default is an empty matrix of double type).
    /// \param img The image matrix.
    CommonProcesses(Mat img = Mat(0, 0, CV_64F)); // Fonksiyon parametresine varsayýlan deðer atamak için.
    /// \brief Constructor that takes a filename as a parameter.
    /// \param filename The name of the file to be processed.
    CommonProcesses(const string& filename);

    /// \brief Reads an image from the current filename.
    cv::Mat readImage();
    /// \brief Reads an image from the specified filepath.
    /// \param filepath The path of the image file to be read.
    cv::Mat readImage(const string& filepath);
    /// \brief Scales the input image by the given scale factor.
    /// \param src The input image matrix.
    /// \param scale_factor The scale factor to be applied.
    cv::Mat scaleImage(cv::Mat src, double scale_factor);
    /// \brief Writes the image matrix to the specified filename.
    /// \param filename The name of the file to write the image to.
    void writeTo(const string& filename);
    /// \brief Writes the corners to the specified filename.
    /// \param corners The vector of corners to be written.
    /// \param filename The name of the file to write the corners to.
    void writeTo(std::vector<cv::Point> corners, const string& filename);
    /// \brief Writes the lines to the specified filename.
    /// \param lines The vector of lines to be written.
    /// \param filename The name of the file to write the lines to.
    void writeTo(vector<Vec4i> lines, const string& filename);
    /// \brief Displays the image matrix with a description.
    /// \param description The description to be displayed.
    /// \param src The image matrix to be displayed.
    void showImage(string description, cv::Mat src);
    /// \brief Displays the image matrix.
    /// \param src The image matrix to be displayed.
    void showImage(cv::Mat src);
    /// \brief Converts the image matrix to grayscale.
    /// \return The grayscale version of the image matrix.
    cv::Mat convertToGrayscale();
    /// \brief Converts the input image matrix to grayscale.
    /// \param src The input image matrix.
    /// \return The grayscale version of the input image matrix.
    cv::Mat convertToGrayscale(cv::Mat src);
    /// \brief Getter for the image matrix.
    /// \return The image matrix.
    cv::Mat getImage();

};

#endif // COMMON_PROCESSES_H
