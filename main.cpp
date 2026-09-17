#include <iostream>

// Headers
#include "./headers/Book.h"
#include <./headers/Student.h>
#include <./headers/Library.h>

void printTitle()
{
    std::cout << "  _        __  __   _____ \n"
                  << " | |      |  \\/  | / ____|\n"
                  << " | |      | \\  / || (___  \n"
                  << " | |      | |\\/| | \\___ \\ \n"
                  << " | |____  | |  | | ____) |\n"
                  << " |______| |_|  |_||_____/ \n";
}

int main()
{
    std::system("clear");
    printTitle();

    // Library lib{
    //     std::vector<Book> {
    //         Book{"Physics", "Haris", "Science", 1001},
    //         Book{"Biology", "Irza", "Science", 1002},
    //         Book{"Maths", "Dr. Haris", "Science", 1003},
    //     }
    // };

    Library lib{};

    while (true)
    {        
        int option{ lib.options() };

        if (option == 1)
        {
            Book book{lib.getBook()};
            lib.addBook(book);
            std::cout << "Book added...\n";
        }

        if (option == 2)
        {
            lib.listBooks();
        }

        if (option == 3)
        {
            std::cout << "Book lented....";
        }

        if (option == 4)
        {
            std::cout << "Quitting...\n";
            break;
        }
        
    }
    
}
