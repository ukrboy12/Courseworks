#include "headers/reader.h"

 Reader* addReader(Reader *readers, Reader reader, int num){
     Reader* newReader = new Reader[num+1];
     for (int i = 0;i<num;i++){
         newReader[i] = readers[i];
     }
     newReader[num] = reader;
     return newReader;
}

Reader* removeReader(Reader *readers, int idReader, int num){
    Reader* newReader = new Reader[num-1];
    for (int i = 0;i<num;i++){
        if (readers->id!=idReader){
        newReader[i] = readers[i];
        }
    }
    return newReader;
}
