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

void editBook(Book& book){
    std::string choise = "";
    std::string data = " ";
    int numericalData = 0;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout<<"Input name cell"<<std::endl;
    std::cout<<"1. Date"<<'\n'<<"2. Name"<<'\n'<<"3.Author"<<'\n'
             <<"4. Genre"<<'\n'<<"5. Coast"<<'\n'<<"6. Rating"<<'\n'<<"7. ID"<<'\n'
             <<"8. All"<<'\n'<<"9. Nothing"<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    while( true ){
        std::cin>>choise;
        if (choise == "Date"){
            int day, month, year;
            std::cout<<"Input date in format dd mm yy"<<std::endl;
            std::cin>>book.date.day>>book.date.month>>book.date.year;
            break;
        } else if (choise == "Name"){
            std::cin>>data;
            book.name = data;
            break;
        } else if (choise == "Author"){
            std::cin>>data;
            book.author = data;
            break;
        } else if (choise == "Genre"){
            std::cin>>data;
            book.genre = data;
            break;
        } else if (choise == "Coast"){
            std::cin>>numericalData;
            book.coast = numericalData;
            break;
        } else if (choise == "Rating"){
            std::cin>>numericalData;
            book.rating = numericalData;
            break;
        } else if (choise == "ID"){
            std::cin>>numericalData;
            book.id = numericalData;
            break;
        } else if (choise == "All"){
            std::string intermediateChoice = "";
            while (true){
                int day, month, year;
                std::cout<<"Input date in format dd mm yy"<<std::endl;
                std::cin>>book.date.day>>book.date.month>>book.date.year;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input name"<<std::endl;
                std::cin>>data;
                book.name = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input Author"<<std::endl;
                std::cin>>data;
                book.author = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input Genre"<<std::endl;
                std::cin>>data;
                book.genre = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input coast"<<std::endl;
                std::cin>>numericalData;
                book.coast = numericalData;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input rating"<<std::endl;
                std::cin>>numericalData;
                book.rating = numericalData;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input ID"<<std::endl;
                std::cin>>numericalData;
                book.id = numericalData;
                break;
            }
        }else if (choise == "Nothing"){
            break;
        } else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
}

