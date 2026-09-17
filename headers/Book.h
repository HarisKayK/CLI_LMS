#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{

private:
    std::string m_title{};
    std::string m_author{};
    std::string m_genre{};
    int m_id{};

public:
    Book(std::string_view title, std::string_view author, std::string_view genre, int id)
    : m_title{title}, m_author{author}, m_genre{genre}, m_id{id} {}

    void info() const
    {
        static int book_no{};
        std::cout << "______________________________________\n\n";
        std::cout << "Book #" << ++book_no << "\n\n";
        std::cout << "TITLE: " << m_title << '\n';
        std::cout << "AUTHOR: " << m_author << '\n';
        std::cout << "GENRE: " << m_genre << '\n';
        std::cout << "ID: " << m_id << '\n';
    }

};

#endif