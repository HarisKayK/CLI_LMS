#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

#include "Book.h"
#include "Student.h"

class Library
{

private:
    std::vector<Book> m_books{};
    std::vector<Student> m_students{};
    enum AllOptions
    {
        _, // _ here so the next element starts from 1.
        
        o_addBook,          // 1
        o_addStudent,       // 2
        o_listBooks,        // 3
        o_listStudents,     // 4
        o_searchBook,       // 5
        o_quit,             // 6
    };

public:
    // Constructors
    Library() = default;

    // Member Functions

    bool execute(int option)
    {
        switch (option)
        {
            case o_quit:
            {
                std::cout << "Quitting...\n";
                return false;
            }
            
            case o_listStudents:
            {
                listStudents();
                break;
            }

            case o_listBooks:
            {
                listBooks();
                break;
            }

            case o_addBook:
            {
                Book book{getBook()};
                addBook(book);
                std::cout << "Book added...\n";
                break;
            }

            case o_addStudent:
            {
                Student student{getStudent()};
                std::cout << "Student added...\n";
                addStudent(student);
                break;
            }

            case o_searchBook:
            {
                searchBook(getID());
            }
        }

        return true;
    }

    // This functions prints the information of all available books
    void listBooks() const
    {
        if (m_books.size() == 0)
        {
            std::cout << "No Books available...\n";
        }

        int counter{};
        for (const auto& book : m_books)
        {
            book.info(++counter);
        }
    }

    void listStudents() const
    {
        if (m_students.size() == 0)
        {
            std::cout << "No Students registered...\n";
        }

        int counter{};
        for (const auto& student : m_students)
        {
            student.info(++counter);
        }
    }

    int options() const
    {
        std::vector optionTitles
        {
            "Add a Book\n",
            "Registor a Student\n",
            "List All Books\n",
            "List All Students\n",
            "Search a Book\n",
            "Quit\n",
        };

        std::cout << "\n\n";

        int counter{};
        for (const auto& optionTitle : optionTitles)
        {
            std::cout << "          " << ++counter << ". " << optionTitle;
        }
        std::cout << '\n';

        int option{};
        std::string input{};
        while (true)
        {
            std::cout << "> ";
            // std::cin >> option;
            std::getline(std::cin >> std::ws, input);
            
            std::stringstream ss{input};

            char leftOver{};
            if (ss >> option && !(ss >> leftOver))
            {
                break;
            }
            continue;
            
            // if (!std::cin)
            // {
            //     std::cin.clear();
            //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // }
            // else if (std::cin.)
            // else
            // {
            //     break;
            // }
        }

        return option;
    }

    Book getBook() const
    {
        std::cout << "Enter Title: ";
        std::string title{};
        std::getline(std::cin >> std::ws, title);

        std::cout << "Enter Author: ";
        std::string author{};
        std::getline(std::cin >> std::ws, author);

        std::cout << "Enter Genre: ";
        std::string genre{};
        std::getline(std::cin >> std::ws, genre);

        std::cout << "Enter ID: ";
        int id{};
        std::cin >> id;

        return {title, author, genre, id};

    }

    int getID() const
    {
        std::cout << "Enter the Book ID: ";
        int id{};
        std::cin >> id;
        return id;
    }

    void addBook(const Book& book)
    {
        m_books.push_back(book);
    }

    Student getStudent() const
    {
        std::cout << "Enter Name: ";
        std::string name{};
        std::getline(std::cin >> std::ws, name);

        std::cout << "Enter ID: ";
        int id{};
        std::cin >> id;

        return {name, id};
    }

    void addStudent(const Student& student)
    {
        m_students.push_back(student);
    }

    void searchBook(const int id) const
    {
        auto book{ std::find_if(std::begin(m_books), std::end(m_books), [&](const Book& b){
            return b.getID() == id;
        })};

        std::cout << "______________________________________\n\n";
        std::cout << "TITLE: " << book->getTitle() << '\n';
        std::cout << "AUTHOUR: " << book->getAuthor() << '\n';
        std::cout << "GENRE: " << book->getGenre() << '\n';
        std::cout << "ID: " << book->getID() << '\n';
        std::cout << "______________________________________\n";
    }

};

#endif
