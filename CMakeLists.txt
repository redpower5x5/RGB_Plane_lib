cmake_minimum_required(VERSION 3.8.2)
project( RGBPLaneDetection )
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(RGBPLaneLib)
add_subdirectory(DemoApp)

# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

