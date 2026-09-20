#include <iostream>
#include <sstream>
#include <string_view>
#include <string>

void printTitle()
{
    std::cout << "  _        __  __   _____ \n"
                  << " | |      |  \\/  | / ____|\n"
                  << " | |      | \\  / || (___  \n"
                  << " | |      | |\\/| | \\___ \\ \n"
                  << " | |____  | |  | | ____) |\n"
                  << " |______| |_|  |_||_____/ \n";
}

int validateIntInput(std::string_view repeatingMsg)
{
    std::string input{};
    int ID{};

    while (true)
    {
        std::cout << repeatingMsg;
        std::getline(std::cin >> std::ws, input);
        
        std::stringstream ss{input};

        char leftOver{};
        if (ss >> ID && !(ss >> leftOver))
        {
            break;
        }
        continue;
    }

    return ID;
}