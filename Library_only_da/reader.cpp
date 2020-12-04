#include "headers/reader.h"

 Reader* addReader(Reader *readers, Reader reader, int num){
     Reader* newReader = new Reader[num+1];
     for (int i = 0;i<num;i++){
         newReader[i] = readers[i];
     }
     delete [] readers;
     newReader[num] = reader;
     return newReader;
}

Reader* removeReader(Reader *readers, int idReader, int num){
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
