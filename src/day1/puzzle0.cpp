#include <array>
#include <fstream>
#include <iostream>
#include <string>

class Puzzle0 {
  public:
    Puzzle0(std::string inputFile)
    {
        std::ifstream file(inputFile);
        if (file.is_open()) {
            std::cout << "i ma here" << std::endl;
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl << std::flush;
            }
        }
    }
};

int main()
{
    Puzzle0 puzzle0("data/day1/puzzle0.txt");

    return 0;
}
