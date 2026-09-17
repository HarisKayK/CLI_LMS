#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "./headers/Book.h"

class Student
{

private:
    std::string m_name{};
    std::vector<Book> m_lentBooks{};
    int m_id{};

public:
    // Constructors
    Student() = default;

    Student(std::string_view name, int id)
    : m_name{name}, m_id{id} {}

    // Member functions
    void info() const
    {
        static int student_no{};
        std::cout << "______________________________________\n\n";
        std::cout << "Student #" << ++student_no << "\n\n";
        std::cout << "NAME: " << m_name << "\n";
        std::cout << "ID: " << m_id << '\n';
    }

};

#endif
