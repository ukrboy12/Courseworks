#pragma once
#include <iostream>
#include "date.h"
#include <iomanip>
struct Reader{
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    Date dateOfBirth;
    int passport;
    int id;
    int countOfBooksRead = 0;
};

Reader* addReader(Reader *&readers, Reader reader, int num);
Reader* removeReader(Reader *&readers, int idReader, int num);
Reader createReader();
void sortById(Reader*& readers, int number);
void sortByCountOfBooksRead(Reader*& readers, int number);
void sortByPassport(Reader*& readers, int number);
void sortByLFP(Reader*& readers, int number);
void editReader(Reader& reader);
Reader & findByIdReader(Reader *&books,int id, int number);
void printReaders(Reader*& readers, int num);