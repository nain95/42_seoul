// #include "main.hpp"
#include "phoneBook.hpp"

#define BOOKSIZE 8

class Array{
private:
    phoneBook book[8];
    int index;
    bool isEmpty;
    bool isFull;
public:
    Array();
    void searchBook();
    void addBook();
    // void setIndex(int i);
    // int getIndex();
    ~Array();
};