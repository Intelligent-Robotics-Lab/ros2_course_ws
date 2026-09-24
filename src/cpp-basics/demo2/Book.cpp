#include "Book.h"
#include <iostream>

Book::Book(std::string t, std::string a, int y)
    : title(t), author(a), year(y) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

void Book::printInfo() const {
    std::cout << "Title : " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Year  : " << year << "\n";
    std::cout << "-----------------------------\n";
}
