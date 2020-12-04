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
        std::cout<<"Menu: \n"<<"0. Exit\t1. Add\t"<<"2. Delete 3. Edit\t4. Sort"<<std::endl;
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
            std::cout<<"1. Book\n"<<"2. Reader"<<"3. All"<<std::endl;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice == "Book"){
                    printBook(books, numberBooks);
                    break;
                } else if (choice == "Reader"){
                    printReaders(readers, numberReaders);
                    break;
                } else if (choice == "All"){
                    printBook(books, numberBooks);
                    printReaders(readers, numberReaders);
                }
            }

        } else if (choice == "Exit"){
            break;
        } else if (choice == "Sort"){
            std::cout << "1. Book\n" << "2. Reader" << std::endl;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice == "Book"){
                    std::cout<<"1. Author\t2. Name\t3. Genre\t4. Rating"<<std::endl;
                    while (true){
                        std::cout<<"Input choice : ";
                        std::cin>>choice;
                        if (choice == "Author"){
                            sortByAuthor(books, numberBooks);
                            break;
                        } else if (choice == "Name"){
                            sortByName(books, numberBooks);
                            break;
                        } else if (choice == "Genre") {
                            sortByGenre(books, numberBooks);
                            break;
                        } else if (choice == "Rating"){
                            sortByRating(books, numberBooks);
                            break;
                        } else {
                            std::cout<<"Incorrect input"<<std::endl;
                        }
                    }
                    break;
                } else if (choice == "Reader"){
                    std::cout<<"1. ID\t2. Passport\t3. LFP\t4. CountOfBooksRead"<<std::endl;
                    while (true){
                        std::cout<<"Input choice : ";
                        std::cin>>choice;
                        if (choice =="Id"){
                            sortById(readers, numberReaders);
                            break;
                        } else if (choice == "Passport"){
                            sortByPassport(readers, numberReaders);
                            break;
                        } else if (choice == "CountOfBooksRead"){
                            sortByCountOfBooksRead(readers, numberReaders);
                            break;
                        } else if (choice == "LFP"){
                            sortByLFP(readers, numberReaders);
                            break;
                        } else {
                            std::cout<<"Incorrect input"<<std::endl;
                        }
                    }
                }
            }
        } else if (choice == "Edit"){
            std::cout<<"1. Book\n"<<"2. Reader"<<std::endl;
            int tempId;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice == "Book"){
                    std::cout<<"Input id book for edit"<<std::endl;
                    std::cin>>tempId;
                    editBook(findById(books, tempId, numberBooks));
                    break;
                }
                else if (choice == "Reader"){
                    std::cout<<"Input id reader for edit"<<std::endl;
                    std::cin>>tempId;
                    editReader(findByIdReader(readers, tempId, numberReaders));
                    break;
                }
                else{
                    std::cout<<"Incorrect input"<<std::endl;
                }
            }

        }else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
    delete [] books;
}
