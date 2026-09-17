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

        // Add Book
        if (option == 1)
        {
            Book book{lib.getBook()};
            lib.addBook(book);
            std::cout << "Book added...\n";
        }

        // List Books
        if (option == 2)
        {
            lib.listBooks();
        }

        // Add Student
        if (option == 3)
        {
            Student student{lib.getStudent()};
            lib.addStudent(student);
            std::cout << "Student added...\n";
        }

        // List Students
        if (option == 4)
        {
            lib.listStudents();
        }

        // Quit
        if (option == 5)
        {
            std::cout << "You quitted LMS...\n";
            break;
        }
        
    }
    
}
