cmake_minimum_required(VERSION 3.17)
project(Library_only_da)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_only_da main.cpp headers/book.h book.cpp headers/reader.h headers/menu.h menu.cpp reader.cpp headers/date.h date.cpp)