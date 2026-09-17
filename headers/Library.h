#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "Book.h"
#include "Student.h"

class Library
{

private:
    std::vector<Book> m_books{};
    std::vector<Student> m_students{};

public:
    // Constructors
    Library() = default;

    // Member Functions

    // This functions prints the information of all available books
    void listBooks() const
    {
        if (m_books.size() == 0)
        {
            std::cout << "No Books available...\n";
        }

        for (const auto& book : m_books)
        {
            book.info();
        }
    }

    void listStudents() const
    {
        if (m_students.size() == 0)
        {
            std::cout << "No Students registered...\n";
        }

        for (const auto& student : m_students)
        {
            student.info();
        }
    }

    int options() const
    {
        std::vector optionTitles
        {
            "Add a Book\n",
            "List All Books\n",
            "Add a Student\n",
            "List All Students\n",
            "Quit\n",
        };

        std::cout << "\n\n";

        int counter{};
        for (const auto& optionTitle : optionTitles)
        {
            std::cout << "          " << ++counter << ". " << optionTitle;
        }
        std::cout << '\n';

        std::cout << "> ";
        int option{};
        std::cin >> option;
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

};

#endif
