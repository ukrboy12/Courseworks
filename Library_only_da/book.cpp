#include "headers/book.h"

Book* addBook(Book*& books, Book book, int num){
    Book* newBooks = new Book [num+1];
     for (int i = 0;i<num;i++){
         newBooks[i] = books[i];
     }
     newBooks[num] = book;
    delete [] books;
    return newBooks;
}

Book* removeBook(Book*& books, int idBook, int num){
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
    std::cin.ignore();
    std::getline(std::cin, book.name);
    std::cout<<"Input author: ";
    std::getline(std::cin, book.author);
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
    std::cout<<"|"<<std::setw(15)<<"Name"<<"|"<<std::setw(15)<< "Author"<<"|"<<std::setw(15)<< "Genre"<<"|"<<std::setw(15)<<"Date"
             <<"|"<<std::setw(10)<<"Coast"<<"|"<<std::setw(5)<<" Id"<<std::setw(5)<<"|"<<std::setw(15)<< "Rating"<<"|"<<std::endl;
    std::string date;

    for(int i = 0; i < num ; i++){
        date = std::to_string(books[i].date.day) + "/" + std::to_string(books[i].date.month) + "/" + std::to_string(books[i].date.year);
        std::cout<<"|"<<std::setw(15)<<books[i].name<<"|"<<std::setw(15)
                 <<books[i].author<<"|"<<std::setw(15)<< books[i].genre<<"|"<<std::setw(15)<<date
                 <<"|"<<std::setw(10)<<books[i].coast<<"|"<<std::setw(5)<<books[i].id
                 <<std::setw(5)<<"|"<<std::setw(15) << books[i].rating<<"|"<<std::endl;
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
            std::cin.ignore();
            std::getline(std::cin, book.name);
            break;
        } else if (choise == "Author"){
            std::cin.ignore();
            std::getline(std::cin, data);
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
                std::cin.ignore();
                book.name = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input Author"<<std::endl;
                std::cin.ignore('\n');
                std::getline(std::cin, data);
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

void sortByAuthor(Book*& books, int number){
    Book temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(books[j].author > books[j+1].author){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void sortByRating(Book*& books, int number){
    Book temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(books[j].rating > books[j+1].rating){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void sortByName(Book*& books, int number){
    Book temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(books[j].name > books[j+1].name){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}
void sortByGenre(Book*& books, int number){
    Book temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(books[j].genre > books[j+1].genre){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

bool existIdBook(Book *&books,int id, int number){
    for(int i = 0; i<number; i++){
        if (books[i].id == id){
            return true;
        }
    }
    return false;
}

Book& findById(Book *&books,int id, int number){
    for(int i = 0; i<number; i++){
        if (books[i].id == id){
            return books[i];
        }
    }
}

void printMostPopularBooks(Book *&books, int number){
    sortByGenre(books, number);
    std::string genre = books[0].genre;
    std::string date = "";
    Book temp = books[0];
    std::cout<<"|"<<std::setw(15)<<"Name"<<"|"<<std::setw(15)<< "Author"<<"|"<<std::setw(15)<< "Genre"<<"|"<<std::setw(15)<<"Date"
             <<"|"<<std::setw(10)<<"Coast"<<"|"<<std::setw(5)<<" Id"<<std::setw(5)<<"|"<<std::setw(15)<< "Rating"<<"|"<<std::endl;
    for(int i = 0; i<number; i++){

        if (books[i].genre == temp.genre and books[i].rating>temp.rating){
            temp = books[i];
        }
        if (books[i].genre != temp.genre || number - 1 == i){
            date = std::to_string(temp.date.day) + "/" + std::to_string(temp.date.month) + "/" + std::to_string(temp.date.year);
            std::cout<<"|"<<std::setw(15)<<temp.name<<"|"<<std::setw(15)
                     <<temp.author<<"|"<<std::setw(15)<< temp.genre<<"|"<<std::setw(15)<<date
                     <<"|"<<std::setw(10)<<temp.coast<<"|"<<std::setw(5)<<temp.id
                     <<std::setw(5)<<"|"<<std::setw(15) << temp.rating<<"|"<<std::endl;
        }
    }
}
