#include "array.hpp"

Array::Array(){
    this->index = 0;
    this->isEmpty = true;
    this->isFull = false;
}

void Array::addBook(){
    book[this->index].saveInfo();
    // book[this->index].setIndex(this->index);
    this->isEmpty = false;
    if (this->index == BOOKSIZE - 1)
        this->isFull = true;
    this->index++;
    this->index %= 8; 
}

void Array::searchBook(){
    if (this->isEmpty == true)
    {
        std::cout << RED << "NO SEARCH INDEX" << NC << std:: endl;
        return ;
    }
    int start;
    int idx = 0;
    if (this->isFull)
        start = (this->index % 8);
    else
        start = 0;
    while (1){
        book[start].showsubInfo(idx++);
        start++;
        start %= 8;
        if (start == this->index)
            break;
    }
    while (1){
        int num;
        std::cin >> num;
        if (this->isFull && 0 <= num && num < BOOKSIZE){
            book[(this->index + num) % 8].showInfo();
            break;
        } 
        else if (!this->isFull && 0 <= num && num < this->index){
            book[num].showInfo();
            break;
        }
    }
}

Array::~Array(){}