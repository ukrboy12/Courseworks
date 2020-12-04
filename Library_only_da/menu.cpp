#include "headers/menu.h"
#include <iostream>
#include "headers/book.h"
#include "headers/reader.h"

//books[0] = {"1","1","1",1,1,1, 0, 0};
//books[1] = {"2","2","2",2,2,2, 0, 0};
//books[2] = {"3","3","3",3,3,3, 0, 0};

void menu(){
    int numberBooks = 0;
    int numberReaders = 0;
    Book* books = new Book[numberBooks];
    Reader* readers = new Reader[numberReaders];
    std::string choice = "";
    while (true){
        std::cout<<"Menu: \n"<<"0. Exit\t1. Add\t"<<"2. Delete\t"<<std::endl;
        std::cout<<"Input choice : ";
        std::cin>>choice;

        if (choice == "Add"){
            std::cout<<"1. Book\n"<<"2. Reader"<<std::endl;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice =="Book"){
                    books = addBook(books, createBook(),numberBooks);
                    numberBooks++;
                    break;
                } else if (choice == "Reader"){
                    readers = addReader(readers,createReader(),numberReaders);
                    numberReaders++;
                    break;
                } else {
                    std::cout<<"Incorrect input"<<std::endl;
                }

            }

        } else if (choice == "Delete"){
            std::cout<<"1. Book\n"<<"2. Reader"<<std::endl;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice =="Book"){
                    int id;
                    std::cout<<"Input id : ";
                    std::cin>>id;
                    books = removeBook(books, id,numberBooks);
                    numberBooks--;
                    break;
                } else if (choice == "Reader"){
                    int id;
                    std::cout<<"Input id : ";
                    std::cin>>id;
                    readers = removeReader(readers, id, numberReaders);
                    numberReaders++;
                    break;
                } else{
                    std::cout<<"Incorrect input"<<std::endl;
                }
            }
        } else if (choice == "Print"){
            printBook(books, numberBooks);
        } else if (choice == "Exit"){
            break;
        }else if (choice == "Sort"){

        } else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
    delete [] books;
}
