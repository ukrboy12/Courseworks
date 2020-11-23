#include <iostream>
#include <vector>
#include <algorithm>

struct Book {
    std::string date;
    std::string name;
    std::string author;
    std::string genre;
    int coast;
    int rating;
    int id;

    std::string getDate() const{
        return date;
    }
    std::string getName() const {
        return name;
    }

    std::string getAuthor()  const {
        return author;
    }

    std::string getGenre()  const{
        return genre;
    }
    int getCoast()  const {
        return coast;
    }
    int getRating() const {
        return rating;
    }
    int getId() const {
        return id;
    }

    void setDate(std::string date){
        this->date = date;
    }

    void setName(std::string name){
        this->name = name;
    }

    void setAuthor(std::string author){
        this->author = author;
    }

    void setGenre(std::string genre){
        this->genre = genre;
    }

    void setCoast(int coast){
        this->coast = coast;
    }

    void setRating(int rating){
        this->rating = rating;
    }

    void setId(int id){
        this->id = id;
    }

    bool operator == (const Book & book) const {
        return (this->id == book.id);
    }
};

struct Reader{
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    std::string dateOfBirth;
    int passport;
    int id;
    int numberOfBooksRead;
    //std::vector<Book> listOfBooks;
    bool operator == (const Reader & reader) const {
        return (this->id == reader.id);
    }
};

class Library{
public:

    void addBook(const Book &book){
        books.push_back(book);
    }

    void removeBook(int id){
      books.erase(std::remove(books.begin(), books.end(),
                              findBook(id)), books.end());
    }

    void addReader(const Reader &reader){
        readers.push_back(reader);
        std::cout<<readers.size()<<std::endl;
    }

    void removeReader(int id){
        readers.erase(std::remove(readers.begin(), readers.end(),
                                  findReader( id)),readers.end());
        std::cout<<readers.size()<<std::endl;
    }


private:

    Book findBook(int id){
        for(auto i : books){
            if(i.id == id){
                return i;
            }
        }
    }


    Reader findReader(int id){
        for(auto i : readers){
            if(i.id == id){
                return i;
            }
        }
    }

    std::vector<Book> books;
    std::vector<Reader> readers;
};

int main(){
    Reader reader1 = {"L","F","A","11/12/2020",
                      1111111, 3,2};
    Reader reader2 = {"L","F","A","11/12/2020",
                      1111111, 1,2};
    Reader reader3 = {"L","F","A","11/12/2020",
                      1111111, 2,2};
    std::vector<Reader> readers = {reader1, reader2, reader3};

    Library library;
    library.addReader(reader2);
    library.addReader(reader1);
    library.addReader(reader3);
    library.removeReader(1);

    return 0;


}