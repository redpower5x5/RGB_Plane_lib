#include <iostream>
#include "RGBPlaneLibrary.h"

void test_target_slope(int N_POINTS = 10000, double TARGET_X_SLOPE = 2, double TARGET_Y_SLOPE = 3, double TARGET_OFFSET = 5, double EXTENTS = 255, double NOISE = 30) {

    std::vector<double> xs(N_POINTS), ys(N_POINTS), zs(N_POINTS);
    for (int i = 0; i < N_POINTS; i++) {
        xs[i] = rand() / double(RAND_MAX) * 2 * EXTENTS - EXTENTS;
        ys[i] = rand() / double(RAND_MAX) * 2 * EXTENTS - EXTENTS;
        zs[i] = xs[i] * TARGET_X_SLOPE + ys[i] * TARGET_Y_SLOPE + TARGET_OFFSET + rand() / double(RAND_MAX) * 2 * NOISE - NOISE;
    }
    Plane results = plane_from_arrays(xs, ys, zs);
    std::cout << results.solution << std::endl;
    std::cout << results.residual << std::endl;
}

int main(int argc, char** argv) {
    test_target_slope();
    return 0;
}