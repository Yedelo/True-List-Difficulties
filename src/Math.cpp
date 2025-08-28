#include "Math.hpp"

Statistics getStatistics(std::vector<int> numbers) {
    float mean = 0;
    float median = 0;
    int mode = 0;

    return Statistics {
        .mean = mean,
        .median = median,
        .mode = mode
    };
}