#include "Library.h"
#include <iostream>

void Library::addBook(const std::string& title, const std::string& author, int year) {
    Book newBook(title, author, year);
    books.push_back(newBook);
}

void Library::printInventory() const {
    std::cout << "Library Inventory:\n";
    std::cout << "-----------------------------\n";
    for (const Book& book : books) {
        book.printInfo();
    }
    // for (i = 0; i < books.size(); ++i) {
    //     books[i].printInfo();
    // }
}
