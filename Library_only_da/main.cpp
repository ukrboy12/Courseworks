#include <iostream>
#include "headers/menu.h"
int main() {
    int *arr = new int [100000000];
    arr[0]=7;
    int *arr1 = arr;
    std::cout<<arr1[0]<<std::endl;
    menu();
    std::system("Pause");
    return 0;
}
