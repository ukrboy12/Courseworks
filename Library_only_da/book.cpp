#include "headers/book.h"

Book* addBook(Book* books, Book book, int num){
    Book* newBooks = new Book [num+1];
     for (int i = 0;i<num;i++){
         newBooks[i] = books[i];
     }
     newBooks[num] = book;
    delete [] books;
    return newBooks;
}

Book* removeBook(Book* books, int idBook, int num){
    Book* newBooks = new Book [num-1];
    int count = 0;
    for (int i = 0; i < num ; i++){
        if(books[i].id != idBook){
            newBooks[count] = books[i];
            count++;
        }
    }
    delete [] books;
    return newBooks;
}

Book createBook(){
    Book book;
    std::cout<<"Input day: ";
    std::cin>>book.date.day;
    std::cout<<"Input month: ";
    std::cin>>book.date.month;
    std::cout<<"Input year: ";
    std::cin>>book.date.year;
    std::cout<<"Input name: ";
    std::cin>>book.name;
    std::cout<<"Input author: ";
    std::cin>>book.author;
    std::cout<<"Input genre: ";
    std::cin>>book.genre;
    std::cout<<"Input coast: ";
    std::cin>>book.coast;
    std::cout<<"Input rating: ";
    std::cin>>book.rating;
    std::cout<<"Input id: ";
    std::cin>>book.id;
    return book;
}

void printBook(Book* books, int num){
    for(int i = 0; i<num ; i++){
        std::cout<<"Name: "<<books[i].name<<"\t";
    }
}
