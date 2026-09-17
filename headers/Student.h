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
    Student() = default;

    Student(std::string_view name, int id)
    : m_name{name}, m_id{id} {}

};

#endif
