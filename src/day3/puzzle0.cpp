#include <DiagnosticReadings.hpp>

int main()
{
    std::string file = "../data/day3/input.txt";
    Diagnostics puzzle0(file);
    std::cout << puzzle0.getPowerConsumption() << std::endl;

    return 0;
}
