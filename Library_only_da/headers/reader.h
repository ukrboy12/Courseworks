#pragma once
#include <iostream>
#include "date.h"

struct Reader{
    Date date;
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    std::string dateOfBirth;
    int passport;
    int id;
    int numberOfBooksRead;
};

Reader* addReader(Reader *readers, Reader reader, int num);
Reader* removeReader(Reader *readers, int idReader, int num);