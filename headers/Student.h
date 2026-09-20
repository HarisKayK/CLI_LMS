#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"

class Student
{

private:
    std::string m_name{};
    std::vector<Book> m_borrowedBooks{};
    int m_id{};

public:
    // Constructors
    Student() = default;

    Student(std::string_view name, int id)
    : m_name{name}, m_id{id} {}

    // Member functions
    void info(int counter) const
    {
        std::cout << "______________________________________\n\n";
        std::cout << "Student #" << counter << "\n\n";
        std::cout << "NAME: " << m_name << "\n";
        std::cout << "ID: " << m_id << '\n';
    }

};

#endif
