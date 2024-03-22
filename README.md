# Feature Detection of an RGB Image

## CommonProcesses Class
The `CommonProcesses` class serves as a foundation for common image processing tasks. These tasks encompass functions such as image reading, resizing, grayscale conversion, and various other operations. Class members include the image matrix and file name, with functions facilitating image reading from a file, scaling, file writing, grayscale conversion, and image display. This class also supports the implementation of line definition tables as per Doxygen documentation standards.

## Detection Class
The `Detection` class, an abstract class, forms the basis for basic feature detection processes. It inherits from the `CommonProcesses` class, providing a framework for image processing. Key members of this class comprise original and result matrices. Additionally, it features an abstract function `detectFeatures()` for the generation of feature detection processes. Similar to the `CommonProcesses` class, this class supports the implementation of line definition tables as per Doxygen documentation standards.

## LineDetection Class
The `LineDetection` class specializes in detecting line features within images. Derived from the `Detection` class, it encompasses a range of feature matrices, a grayscale-converted image matrix, and an edges matrix. This class offers support for implementing line definition tables in accordance with Doxygen documentation standards.

## Corner Detection Class
The `CornerDetection` class focuses on identifying corner features within images. Like the `LineDetection` class, it derives from the `Detection` class and includes feature matrices, a grayscale-converted image matrix, and a result matrix. This class is equipped to implement vertices definitions according to Doxygen documentation standards.

The outputs of the code are illustrated in figures 1 through 5, showcasing various stages of the feature detection process:
<p align="center">
        <img src="https://github.com/sseref64/Feature-detection-of-a-RGB-Image-Process/blob/main/img/Figure%201.png" width="600" height="400">
        <br>
        <em>Figure 1: Original Image as Gray Scale</em>
    </p>
! [](img/Figure 1.png)

<p align="center">
        <img src="[https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig4.jpg](https://github.com/sseref64/Feature-detection-of-a-RGB-Image-Process/blob/main/img/Figure%202.png)" width="600" height="400">
        <br>
        <em>Figure 2: Canny Map Image</em>
    </p>
- **Figure 2**: Canny Map Image
- **Figure 3**: Line Detection Detected
- **Figure 4**: Scaled Image
- **Figure 5**: Corner Detection Detected Image

This project encompasses a hierarchical structure, as depicted in figures 6 and 7, ranging from general image processing to feature detection:

- **Figure 6**: Class Hierarchy and Inheritance
- **Figure 7**: Main Hierarchy

These descriptions encapsulate the primary functionalities of each file and class. For more detailed explanations of individual functions within each file and class, refer to the code documentation. Additionally, an UML diagram, depicted in figure 7, provides a visual representation of the project's structure and relationships.
