#include <SubmarineReadings.h>

int main()
{
    std::string file = "../data/day1/input.txt";
    SubmarineReadings puzzle0(file);
    std::cout << puzzle0.getNumIncreased(/*windowSize=*/3) << std::endl;

    return 0;
}
