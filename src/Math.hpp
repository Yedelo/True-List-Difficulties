#pragma once

struct Statistics {
    float mean;
    float median;
    int mode;
};

Statistics getStatistics(std::vector<int> numbers);