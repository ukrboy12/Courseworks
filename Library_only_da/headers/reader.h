#pragma once
#include <iostream>
#include "date.h"

struct Reader{
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    Date dateOfBirth;
    int passport;
    int id;
    //int OfBooksRead;
};

Reader* addReader(Reader *readers, Reader reader, int num);
Reader* removeReader(Reader *readers, int idReader, int num);
Reader createReader();

