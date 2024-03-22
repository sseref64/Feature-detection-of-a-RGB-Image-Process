#include "CommonProcesses.h"

using namespace std;

/// \brief Constructor that takes a filename as a parameter.
/// \param filename The name of the file to be processed.
CommonProcesses::CommonProcesses(const string& filename) {
    //image = cv::imread(filename, cv::IMREAD_COLOR);
    this->filename = filename;
    this->image = cv::imread(filename);
    cv::Mat img_gray;
    //cvtColor(this->image, img_gray, cv::COLOR_BGR2GRAY);
}

/// \brief Constructor that takes an image matrix as a parameter.
/// \param img The image matrix.
CommonProcesses::CommonProcesses(Mat img) {
    image = img;
}

/// \brief Displays the image matrix with a specified description.
/// \param description The description to be displayed.
/// \param src The image matrix to be displayed.
void CommonProcesses::showImage(string description, cv::Mat src) {
    cv::imshow(description, src);
}

/// \brief Displays the image matrix with a default description.
/// \param src The image matrix to be displayed.
void CommonProcesses::showImage(cv::Mat src) {
    cv::imshow("Default Description", src);
}

/// \brief Writes the image matrix to the specified filename.
/// \param filename The name of the file to write the image to.
void CommonProcesses::writeTo(const string& filename) {
    //write to a file
}

/// \brief Writes the corners to the specified filename.
/// \param corners The vector of corners to be written.
/// \param filename The name of the file to write the corners to.
void CommonProcesses::writeTo(vector<cv::Point> corners, const string& filename) {
    const string filePath = filename;

    // Open the file in output mode and truncate its contents
    ofstream outputFile(filePath, ofstream::out | ofstream::trunc);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    // Write data to the file
    for (size_t i = 0; i < corners.size(); ++i) {
        // Your processing logic for the corners goes here
        // For demonstration, let's print the corner coordinates
        outputFile << "Corner Point " << i << ": "
            << corners[i].x << ", " << corners[i].y << endl;
    }

    // Close the file
    outputFile.close();

    cout << "File written successfully." << endl;
}

/// \brief Writes the lines to the specified filename.
/// \param lines The vector of lines to be written.
/// \param filename The name of the file to write the lines to.
void CommonProcesses::writeTo(vector<Vec4i> lines, const string& filename) {
    const string filePath = filename;

    // Open the file in output mode and truncate its contents
    ofstream outputFile(filePath, ofstream::out | ofstream::trunc);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    // Write data to the file
    for (size_t i = 0; i < lines.size(); ++i) {
        // Your processing logic for the lines goes here
        // For demonstration, let's print the line coordinates
        outputFile << "Line " << i << ": "
            << "Point 1 (" << lines[i][0] << ", " << lines[i][1] << "), "
            << "Point 2 (" << lines[i][2] << ", " << lines[i][3] << ")" << endl;
    }

    // Close the file
    outputFile.close();

    cout << "File written successfully." << endl;
}

/// \brief Scales the input image by the given scale factor.
/// \param src The input image matrix.
/// \param scale_factor The scale factor to be applied.
/// \return The scaled image matrix.
cv::Mat CommonProcesses::scaleImage(cv::Mat src, double scale_factor) {
    // Resize the image
    cv::Mat scaledImage;
    cv::resize(src, scaledImage, cv::Size(), scale_factor, scale_factor);

    // Display the original and scaled images
    cv::imshow("Original Image", src);
    cv::imshow("Scaled Image", scaledImage);
    return scaledImage;
}

/// \brief Getter for the image matrix.
/// \return The image matrix.
cv::Mat CommonProcesses::getImage() {
    return this->image;
}

/// \brief Reads an image from the current filename.
/// \return The image matrix.
cv::Mat CommonProcesses::readImage() {
    cv::Mat inputImage = cv::imread(this->filename);
    //exception handling
    if (inputImage.empty()) {
        cerr << "Error loading the image." << endl;
    }
    return inputImage;
}

/// \brief Reads an image from the specified filepath.
/// \param filepath The path of the image file to be read.
/// \return The image matrix.
cv::Mat CommonProcesses::readImage(const string& filepath) {
    cv::Mat inputImage = cv::imread(filepath);

    //exception handling
    if (inputImage.empty()) {
        cerr << "Error loading the image." << endl;
    }
    return inputImage;
}

/// \brief Converts the image matrix to grayscale.
/// \return The grayscale version of the image matrix.
cv::Mat CommonProcesses::convertToGrayscale() {
    //cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    cv::Mat src_gray;
    cvtColor(this->image, src_gray, cv::COLOR_BGR2GRAY);
    return src_gray;
}

/// \brief Converts the input image matrix to grayscale.
/// \param src The input image matrix.
/// \return The grayscale version of the input image matrix.
cv::Mat CommonProcesses::convertToGrayscale(cv::Mat src) {
    cv::Mat src_gray;
    cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    return src_gray;
}
