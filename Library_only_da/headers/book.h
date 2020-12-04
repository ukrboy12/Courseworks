#pragma once
#include "date.h"
#include <iostream>

struct Book {
    Date date;
    std::string name;
    std::string author;
    std::string genre;
    int coast;
    int rating;
    int id;
    int idReader = 0;
    int idDayOfReceipt = 0;
};

Book* addBook(Book* books, Book book, int num);
Book* removeBook(Book* books, int id, int num);
Book createBook();
void printBook(Book* books, int num);
void editBook();


