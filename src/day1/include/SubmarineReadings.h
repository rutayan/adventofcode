#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class SubmarineReadings {
  private:
    std::vector<unsigned> depths;

  public:
    SubmarineReadings(std::string inputFile)
    {
        std::ifstream file(inputFile);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                depths.push_back(std::stoul(line));
            }
        }
    }

    unsigned getNumIncreased(unsigned windowSize = 1)
    {
        unsigned numIncreased = 0;
        unsigned previous = UINT_MAX;

        for (auto i = 0; i < depths.size() - windowSize + 1; i++) {
            unsigned sum = 0;
            for (auto j = i; j < i + windowSize; j++) {
                sum += depths[j];
            }
            if (sum > previous) {
                numIncreased++;
            }
            previous = sum;
        }

        return numIncreased;
    }
};
