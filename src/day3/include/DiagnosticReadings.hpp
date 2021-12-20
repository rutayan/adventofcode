#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FrequencyCounter {
  private:
    std::vector<unsigned> counters{};

  public:
    void updateNumCounters(unsigned num) { counters.resize(num); }

    void incrementCounter(unsigned counterId) { counters.at(counterId)++; }

    void resetCounter(unsigned counterId) { counters.at(counterId) = 0; }

    std::vector<unsigned> getCounters() const { return counters; }

    unsigned getCount(unsigned counterId) const { return counters.at(counterId); }

    unsigned getNumCounters() const { return counters.size(); }
};

class Diagnostics {
  private:
    std::vector<std::string> readings{};
    FrequencyCounter frequencyOfOne;
    unsigned gamma{};
    unsigned epsilon{};

    void parseString(std::string str)
    {
        for (unsigned index = 0; index < str.length(); index++) {
            if (str[index] == '1') {
                frequencyOfOne.incrementCounter(index);
            }
        }
    }

    void parseReadings()
    {
        for (auto reading : readings) {
            parseString(reading);
        }

        updateGammaAndEpsilon();
    }

    void updateGammaAndEpsilon()
    {
        std::string gammaStr(readings.at(0).length(), '0');
        std::string epsilonStr(readings.at(0).length(), '1');
        for (unsigned counterId = 0; counterId < frequencyOfOne.getNumCounters(); counterId++) {
            unsigned frequencyOfZero = readings.size() - frequencyOfOne.getCount(counterId);
            if (frequencyOfOne.getCount(counterId) > frequencyOfZero) {
                unsigned charPos = counterId;
                gammaStr.at(charPos) = '1';
                epsilonStr.at(charPos) = '0';
            }
        }

        std::cout << gammaStr << std::endl;
        gamma = stoi(gammaStr, nullptr, /*base=*/2);
        epsilon = stoi(epsilonStr, nullptr, /*base=*/2);
        std::cout << gamma << std::endl;
        std::cout << epsilon << std::endl;
    }

  public:
    Diagnostics(std::string inputFile) : frequencyOfOne()
    {
        std::ifstream file(inputFile);

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                readings.push_back(line);  // Save all the lines
            }
        }

        std::cout << "Number of readings: " << readings.size() << std::endl;
        frequencyOfOne.updateNumCounters(readings.at(0).length());
    }

    unsigned getGamma() { return gamma; }
    unsigned getEpsilon() { return epsilon; }

    unsigned getPowerConsumption()
    {
        parseReadings();
        return gamma * epsilon;
    }
};
