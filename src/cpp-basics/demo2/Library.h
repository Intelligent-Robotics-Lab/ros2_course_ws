#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, int year);
    void printInventory() const;
};

#endif
