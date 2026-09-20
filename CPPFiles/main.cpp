#include <iostream>

// Headers
#include "headers/Book.h"
#include "headers/Student.h"
#include "headers/Library.h"

// Function Declarations
void printTitle();

int main()
{
    std::system("clear");
    printTitle();

    Library lib{};
    bool run{ true };

    while (run)
    {
        int option{ lib.getOption() };
        run = lib.execute(option);
    }

}
