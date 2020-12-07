#include "headers/menu.h"

Book* fillArrayBook(int number){
    Book *newBooks = new Book[number];
    newBooks[0].date.day =12;
    newBooks[0].date.year =2001;
    newBooks[0].date.month =1;
    newBooks[0].name ="Pride and Prejudice";
    newBooks[0].author="Jane Austen";
    newBooks[0].coast=100;
    newBooks[0].id =0;
    newBooks[0].genre ="Novel";
    newBooks[0].rating =8;

    newBooks[1].date.day =11;
    newBooks[1].date.year =2017;
    newBooks[1].date.month =4;
    newBooks[1].name ="To Kill a Mockingbird";
    newBooks[1].author="Harper Lee";
    newBooks[1].coast=50;
    newBooks[1].id =1;
    newBooks[1].genre ="Novel";
    newBooks[1].rating =9;

    newBooks[2].date.day =9;
    newBooks[2].date.year =2011;
    newBooks[2].date.month =9;
    newBooks[2].name = "The Great Gatsby";
    newBooks[2].author = "Scott Fitzgerald";
    newBooks[2].coast = 340 ;
    newBooks[2].id = 2;
    newBooks[2].genre = "Novel";
    newBooks[2].rating = 6;

    newBooks[3].date.day = 14;
    newBooks[3].date.year =2008;
    newBooks[3].date.month =5;
    newBooks[3].name = "One Hundred Years of Solitude";
    newBooks[3].author = "Gabriel Garcia Marquez" ;
    newBooks[3].coast=150;
    newBooks[3].id = 3;
    newBooks[3].genre = "Novel";
    newBooks[3].rating = 10;

    newBooks[4].date.day = 5;
    newBooks[4].date.year = 2010;
    newBooks[4].date.month = 9;
    newBooks[4].name = "In Cold Blood";
    newBooks[4].author= "Truman Capote";
    newBooks[4].coast= 300;
    newBooks[4].id = 4;
    newBooks[4].genre = "Novel";
    newBooks[4].rating = 8 ;

    newBooks[5].date.day = 1;
    newBooks[5].date.year = 2006;
    newBooks[5].date.month = 2;
    newBooks[5].name = "Wide Sargasso Sea";
    newBooks[5].author = "Jean Rhys" ;
    newBooks[5].coast = 100;
    newBooks[5].id = 5;
    newBooks[5].genre = "Novel";
    newBooks[5].rating = 6;

    newBooks[6].date.day = 23;
    newBooks[6].date.year = 1997;
    newBooks[6].date.month = 12;
    newBooks[6].name = "The golden eagle";
    newBooks[6].author = "Ivan Franko";
    newBooks[6].coast = 200;
    newBooks[6].id = 6;
    newBooks[6].genre = "Novel";
    newBooks[6].rating = 7;
    return newBooks;
}

void menu(){
    int numberBooks = 7;
    int numberReaders = 4;
    Book* books = fillArrayBook(numberBooks);
    Reader* readers = new Reader[numberReaders];
    std::string choice = "";

    while (true){
        std::cout<<std::endl;
        std::cout<<"Menu: \n0. Exit\t1. Add\t2. Delete\t3. Edit\t4. Sort\n5. Print\t6. Give\t7. Return\t8. Popular\n9. BooksOnHand\t10. ActiveReaders\t11. Overdue\t12. Find"<<std::endl;
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
                std::cout<<"Incorrect id"<<std::endl;
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

        } else if (choice == "Find"){
            std::cout<<"1. Book"<<std::endl;
            while (true){
                std::cout<<"Input choice : ";
                std::cin>>choice;
                if (choice == "Book"){
                    while (true) {
                        std::cout << "1. Author\n" << "2. Name\n" <<"3. Genre"<< std::endl;
                        std::cout << "Input find : ";
                        std::cin >> choice;
                        if(choice == "Author"){
                            findByAuthor(books, numberBooks);
                            break;
                        } else if(choice == "Genre"){
                            findByGenre(books, numberBooks);
                            break;
                        } else if(choice == "Name") {
                            findByName(books, numberBooks);
                            break;
                        } else {
                            std::cout<<"Incorrect input"<<std::endl;
                        }
                    }
                    break;
                }
                else{
                    std::cout<<"Incorrect input"<<std::endl;
                }
            }
        } else if (choice=="Overdue"){
          printInfoOverdueDays(readers, numberReaders);
        } else if (choice=="ActiveReaders"){
          printMostActiveReader(readers, numberReaders);
        } else if (choice == "BooksOnHand"){
            booksOnHand(books, numberBooks);
        } else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
    delete [] books;
}
