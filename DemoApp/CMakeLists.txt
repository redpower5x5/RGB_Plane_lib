cmake_minimum_required(VERSION 3.8.2) # 3.8.0 is minimum version that allow Linux remote building and debugging

# Add the binary tree directory to find the version.h file
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(Demo main.cpp)



# Demo application require both libraries, so add them
target_link_libraries(Demo
    RGBPlaneLibrary
)


# Point to which directory Demo is copied during installation and packaging
install(TARGETS Demo DESTINATION demo)