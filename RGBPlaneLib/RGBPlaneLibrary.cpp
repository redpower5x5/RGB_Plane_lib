#include "RGBPlaneLibrary.h"
#include <opencv2/opencv.hpp>
#include <map>
#include <Eigen/Core>
#include <Eigen/Dense>


Plane plane_from_arrays(std::vector<double> xs, std::vector<double> ys, std::vector<double> zs) {
    int n = xs.size();
    Eigen::MatrixXd A(n, 3);
    Eigen::VectorXd b(n);
    for (int i = 0; i < n; i++) {
        A(i, 0) = xs[i];
        A(i, 1) = ys[i];
        A(i, 2) = 1;
        b(i) = zs[i];
    }
    Eigen::VectorXd fit = (A.transpose() * A).inverse() * A.transpose() * b;
    Eigen::VectorXd errors = b - A * fit;
    double residual = errors.norm();
    std::string solution = "solution: " + std::to_string(fit[0]) + " x + " + std::to_string(fit[1]) + " y + " + std::to_string(fit[2]) + " = z";
    return {fit[0], fit[1], fit[2], solution, errors, residual};
}

Plane plane_from_image(std::string path) {
    cv::Mat img = cv::imread(path);
    //convert from BGR to RGB
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    //get rgb values from image to 1D array
    std::vector<cv::Mat> channels;
    cv::split(img, channels);
    std::vector<double> xs, ys, zs;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            xs.push_back(channels[0].at<uchar>(i, j));
            ys.push_back(channels[1].at<uchar>(i, j));
            zs.push_back(channels[2].at<uchar>(i, j));
        }
    }

    return plane_from_arrays(xs, ys, zs);
}