#include "headers/reader.h"

 Reader* addReader(Reader *&readers, Reader reader, int num){
     Reader* newReader = new Reader[num+1];
     for (int i = 0;i<num;i++){
         newReader[i] = readers[i];
     }
     delete [] readers;
     newReader[num] = reader;
     return newReader;
}

Reader* removeReader(Reader *&readers, int idReader, int num){
    Reader* newReader = new Reader[num-1];
    int count = 0;
    for (int i = 0;i<num;i++){
        if (readers->id != idReader){
        newReader[count] = readers[i];
        count++;
        }
    }
    delete [] readers;
    return newReader;
}

Reader createReader(){
    Reader reader;
    std::cout<<"Input day: ";
    std::cin>>reader.dateOfBirth.day;
    std::cout<<"Input month: ";
    std::cin>>reader.dateOfBirth.month;
    std::cout<<"Input year: ";
    std::cin>>reader.dateOfBirth.year;
    std::cout<<"Input First Name: ";
    std::cin>>reader.firstName;
    std::cout<<"Input Last Name: ";
    std::cin>>reader.lastName;
    std::cout<<"Input patronymic: ";
    std::cin>>reader.patronymic;
    std::cout<<"Input rating: ";
    std::cin>>reader.passport;
    std::cout<<"Input id: ";
    std::cin>>reader.id;
    return reader;
}

void sortById(Reader*& readers, int number){
    Reader temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].id > readers[j+1].id){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
}

void sortByCountOfBooksRead(Reader*& readers, int number){
    Reader temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].countOfBooksRead > readers[j+1].countOfBooksRead){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
}

void sortByPassport(Reader*& readers, int number){
    Reader temp;
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].passport > readers[j+1].passport){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
}

void sortByLFP(Reader*& readers, int number){
    Reader temp;
    //сортируем по фамилии
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].lastName > readers[j+1].lastName){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
    //сортируем по имени
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].firstName > readers[j+1].firstName){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
    //сортируем по отчеству
    for(int i = 0; i<number ;i++){
        for(int j = 0; j < number-1; j++){
            if(readers[j].patronymic > readers[j+1].patronymic){
                temp = readers[j];
                readers[j] = readers[j+1];
                readers[j+1] = temp;
            }
        }
    }
}

void editReader(Reader & reader){
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
            std::cin>>reader.dateOfBirth.day>>reader.dateOfBirth.month>>reader.dateOfBirth.year;
            break;
        } else if (choise == "Last Name"){
            std::cin>>data;
            reader.lastName = data;
            break;
        }  else if (choise == "First Name"){
            std::cin>>data;
            reader.firstName = data;
            break;
        } else if (choise == "Patronymic"){
            std::cin>>data;
            reader.patronymic = data;
            break;
        } else if (choise == "Passport"){
            std::cin>>numericalData;
            reader.passport = numericalData;
            break;
        } else if (choise == "ID"){
            std::cin>>numericalData;
            reader.id = numericalData;
            break;
        } else if (choise == "All"){
            std::string intermediateChoice = "";
            while (true){
                int day, month, year;
                std::cout<<"Input date in format dd mm yy"<<std::endl;
                std::cin>>reader.dateOfBirth.day>>reader.dateOfBirth.month>>reader.dateOfBirth.year;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input last name"<<std::endl;
                std::cin>>data;
                reader.lastName = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input first name"<<std::endl;
                std::cin>>data;
                reader.firstName = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input Patronymic"<<std::endl;
                std::cin>>data;
                reader.patronymic = data;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }

                std::cout<<"Input passport"<<std::endl;
                std::cin>>numericalData;
                reader.patronymic = numericalData;
                std::cout<<"You want stop?"<<'\n'
                         <<"Input yes or no"<<std::endl;
                std::cin>>intermediateChoice;
                if (intermediateChoice == "yes" or intermediateChoice == "Yes"){
                    break;
                }
                std::cout<<"Input ID"<<std::endl;
                std::cin>>numericalData;
                reader.id = numericalData;
                break;
            }
        }else if (choise == "Nothing"){
            break;
        } else {
            std::cout<<"Incorrect input"<<std::endl;
        }
    }
}

bool existIdReader(Reader *& reader, int id, int number){
    for(int i = 0; i<number; i++){
        if (reader[i].id == id){
            return true;
        }
    }
    return false;
}

Reader& findByIdReader(Reader *& reader, int id, int number){
    for(int i = 0; i<number; i++){
        if (reader[i].id == id){
            return reader[i];
        }
    }
}

void printReaders(Reader*& readers, int num){
    std::cout<<"|"<<std::setw(15)<<"Last Name"<<"|"<<std::setw(15)<< "First Name"<<"|"<<std::setw(15)<< "Patronymic"<<"|"<<std::setw(15)<<" Date Of Birth "
             <<"|"<<std::setw(10)<<" Passport"<<"|"<<std::setw(5)<<" Id"<<std::setw(5)<<"|"<<std::setw(15)<< "Count of books read"<<"|"<<std::endl;
    std::string date;
    for(int i = 0; i < num ; i++){
        date = std::to_string(readers[i].dateOfBirth.day) + "/" + std::to_string(readers[i].dateOfBirth.month) + "/" + std::to_string(readers[i].dateOfBirth.year);
        std::cout<<"|"<<std::setw(15)<<readers[i].lastName<<"|"<<std::setw(15)
        <<readers[i].firstName<<"|"<<std::setw(15)<< readers[i].patronymic<<"|"<<std::setw(15)<<date
        <<"|"<<std::setw(10)<<readers[i].passport<<"|"<<std::setw(5)<<readers[i].id
        <<std::setw(5)<<"|"<<std::setw(15) << readers[i].countOfBooksRead<<"|"<<std::endl;
    }
}