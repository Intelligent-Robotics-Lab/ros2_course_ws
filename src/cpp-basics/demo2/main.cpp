#include <iostream>
#include "Library.h"

int main() {
    Library myLibrary;

    myLibrary.addBook("1984", "George Orwell", 1949);
    myLibrary.addBook("To Kill a Mockingbird", "Harper Lee", 1960);
    myLibrary.addBook("Brave New World", "Aldous Huxley", 1932);

    myLibrary.printInventory();

    return 0;
}
