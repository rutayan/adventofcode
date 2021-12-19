#include <SubmarineReadings.h>

int main()
{
    std::string file = "../data/day2/input.txt";
    SubmarineReadingsWithAim puzzle1(file);

    std::cout << puzzle1.getfinalProduct() << std::endl;

    return 0;
}
