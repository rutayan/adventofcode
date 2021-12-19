#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class SubmarineReadings {
  private:
    using Action = std::pair<std::string, unsigned>;
    std::vector<Action> actions;
    int horizontal{0};
    int depth{0};

  public:
    SubmarineReadings(std::string inputFile)
    {
        std::ifstream file(inputFile);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                actions.push_back(parse(line));
            }
        }

        std::cout << actions.size() << std::endl;
    }

    Action parse(std::string spaceSeparatedLine)
    {
        char inputSring[spaceSeparatedLine.length() + 1];
        strcpy(inputSring, spaceSeparatedLine.c_str());
        char* pch;
        pch = strtok(inputSring, " ");

        // Get the action string forward/backward/up/down
        std::string action = pch;
        pch = strtok(NULL, " ");

        // Get the units of action to execute
        unsigned units = std::stoul(std::string{pch});

        return {action, units};
    }

    void executeAction(std::string action, unsigned units)
    {
        if (action == "forward") {
            forward(units);
        }
        // else if (action == "backward") {
        //     backward(units);
        // }
        else if (action == "up") {
            up(units);
        }
        else if (action == "down") {
            down(units);
        }
        else {
        }
    }

    void performActions()
    {
        for (auto action : actions) {
            executeAction(action.first, action.second);
        }
    }

    int getfinalProduct()
    {
        performActions();
        return horizontal * depth;
    }

    void forward(unsigned units) { horizontal += units; }
    void backward(unsigned units) { horizontal -= units; }
    void up(unsigned units) { depth -= units; }
    void down(unsigned units) { depth += units; }
};

class SubmarineReadingsWithAim {
  private:
    using Action = std::pair<std::string, unsigned>;
    std::vector<Action> actions;
    int horizontal{0};
    int depth{0};
    int aim{0};

  public:
    SubmarineReadingsWithAim(std::string inputFile)
    {
        std::ifstream file(inputFile);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                actions.push_back(parse(line));
            }
        }

        std::cout << actions.size() << std::endl;
    }

    Action parse(std::string spaceSeparatedLine)
    {
        char inputSring[spaceSeparatedLine.length() + 1];
        strcpy(inputSring, spaceSeparatedLine.c_str());
        char* pch;
        pch = strtok(inputSring, " ");

        // Get the action string forward/backward/up/down
        std::string action = pch;
        pch = strtok(NULL, " ");

        // Get the units of action to execute
        unsigned units = std::stoul(std::string{pch});

        return {action, units};
    }

    void executeAction(std::string action, unsigned units)
    {
        if (action == "forward") {
            forward(units);
        }
        // else if (action == "backward") {
        //     backward(units);
        // }
        else if (action == "up") {
            up(units);
        }
        else if (action == "down") {
            down(units);
        }
        else {
        }
    }

    void performActions()
    {
        for (auto action : actions) {
            executeAction(action.first, action.second);
        }
    }

    int getfinalProduct()
    {
        performActions();
        return horizontal * depth;
    }

    void forward(unsigned units)
    {
        horizontal += units;
        depth += aim * units;
    }
    void up(unsigned units) { aim -= units; }
    void down(unsigned units) { aim += units; }
};
