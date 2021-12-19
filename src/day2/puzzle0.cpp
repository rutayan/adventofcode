#include <SubmarineReadings.h>

int main()
{
    std::string file = "../data/day2/input.txt";
    SubmarineReadings puzzle0(file);

    std::cout << puzzle0.getfinalProduct() << std::endl;

    return 0;
}
