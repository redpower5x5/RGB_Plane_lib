#pragma once

#ifndef PLANE_FITTING_H
#define PLANE_FITTING_H

#include "RGBPlaneLibrary_export.h"
#include <vector>
#include <string>
#include <Eigen/Core>

/// @brief структура, описывающая плоскость
DLIB_EXPORT struct Plane {
    double a, b, c;
    std::string solution;
    Eigen::VectorXd errors;
    double residual;
};

/// @brief создание плоскости по массивам координат точек
/// @param xs 
/// @param ys 
/// @param zs 
/// @return структура Plane
DLIB_EXPORT Plane plane_from_arrays(std::vector<double> xs, std::vector<double> ys, std::vector<double> zs);

/// @brief cоздание плоскости по изображению
/// @param path путь к изображению
/// @return структура Plane
DLIB_EXPORT Plane plane_from_image(std::string path);

#endif