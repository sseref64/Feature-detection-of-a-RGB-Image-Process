#include "Detection.h"
using namespace std;

/// \brief Constructor that takes an image matrix as a parameter.
/// \param img The image matrix.
Detection::Detection(cv::Mat img) : CommonProcesses(img) {
    cout << "Base class constructor " << endl;
}

/// \brief Constructor that takes a filename as a parameter.
/// \param filename The name of the file to be processed.
Detection::Detection(const string& filename) : CommonProcesses(filename) {

}
