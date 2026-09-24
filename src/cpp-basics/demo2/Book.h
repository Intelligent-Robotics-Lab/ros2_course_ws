#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(std::string t, std::string a, int y);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;

    void printInfo() const;
};

#endif
