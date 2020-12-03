#include "headers/book.h"
#include "headers/date.h"


Book* addBook(Book* books, Book book, int num){
    Book* newBooks = new Book [num+1];
     for (int i = 0;i<num;i++){
         newBooks[i] = books[i];
     }
     newBooks[num] = book;
    return newBooks;
}

Book* removeBook(Book* books, int idBook, int num){
    Book* newBooks = new Book [num-1];
    for (int i = 0; i < num ; i++){
        if(books[i].id != idBook){
            newBooks[i] = books[i];
        }
    }
    return newBooks;
}

