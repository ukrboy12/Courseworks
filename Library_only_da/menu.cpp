#include "headers/menu.h"


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
        std::cout<<std::endl;
        std::cout<<"Menu: \n0. Exit\t1. Add\t2. Delete\t3. Edit\t4. Sort\n5. Print\t6. Give\t7. Return\t8. Popular\n9. BooksOnHand\t10. ActiveReaders\t11. Overdue"<<std::endl;
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
            std::cout<<"1. Book\n"<<"2. Reader"<<"\n3. All"<<std::endl;
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
        } else if (choice == "Give"){
           std::cout<<"Input id book for give"<<std::endl;
           int tempIdBook, tempIdReader, day, month, year;
           std::cin>>tempIdBook;
           std::cout<<"Input id reader"<<std::endl;
           std::cin>>tempIdReader;
           if (existIdReader(readers,tempIdReader,numberReaders) && existIdBook(books, tempIdBook, numberBooks)){
                std::cout<<"Input return Date format dd mm yyyy"<<std::endl;
                std::cin>>day>>month>>year;
                Book tempBook = findById(books,tempIdBook,numberBooks);
                tempBook.idDayOfReceipt = getDayIndex(day, month,year);
                tempBook.idReader = tempIdReader;
                findByIdReader(readers,tempIdReader,numberReaders).countOfBooksRead +=1;
           } else {
               std::cout<<"Incorrect id"<<std::cout;
           }
        }else if (choice == "Return"){
            std::cout<<"Input id book for give"<<std::endl;
            int tempIdBook, tempIdReader, day, month, year;
            std::cin>>tempIdBook;
            std::cout<<"Input id reader"<<std::endl;
            std::cin>>tempIdReader;
            if (existIdReader(readers,tempIdReader,numberReaders) && existIdBook(books, tempIdBook, numberBooks)){
                std::cout<<"Input return Date format dd mm yyyy"<<std::endl;
                std::cin>>day>>month>>year;
                Book tempBook = findById(books,tempIdBook,numberBooks);
                tempBook.idReader = 0;
                Reader tempReader = findByIdReader(readers,tempIdReader,numberReaders);
                if (tempBook.idDayOfReceipt-getDayIndex(day, month, year)<0){
                    tempReader.overdueDays = fabs(tempBook.idDayOfReceipt-getDayIndex(day, month, year));
                    tempReader.penny = tempReader.penny + tempReader.overdueDays * 3;
                    std::cout<<"Penny : "<<tempReader.penny<<std::endl;
                } else {
                    std::cout<<"No penny"<<std::endl;
                }
            } else {
                std::cout<<"Incorrect id"<<std::cout;
            }
        } else if(choice == "Popular"){
            printMostPopularBooks(books,numberBooks);
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

        } else if (choice=="Overdue"){
          printInfoOverdueDays(readers, numberReaders);
        } else if(choice=="ActiveReaders"){
          printMostActiveReader(readers, numberReaders);
        } else if (choice == "BooksOnHand"){
            booksOnHand(books, numberBooks);
        } else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
    delete [] books;
}
