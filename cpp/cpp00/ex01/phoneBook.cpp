#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->index = 0;
    this->isEmpty = true;
    this->isFull = false;
}

void PhoneBook::saveInfo()
{
    std::string input_data;

    std::cout << "firt_name :";

    getline(std::cin, input_data);
    this->contacts[index].setFirstName(input_data);

	std::cout << "last_name :" ;
    getline(std::cin, input_data);
    this->contacts[index].setLastName(input_data);

	std::cout << "nick_name :";
    getline(std::cin, input_data);
    this->contacts[index].setNickname(input_data);

	std::cout << "phone_number :";
    getline(std::cin, input_data);
    this->contacts[index].setPhoneNumber(input_data);

	std::cout << "darkest_secret :";
    getline(std::cin, input_data);
    this->contacts[index].setDarkestSecrete(input_data);
    this->isEmpty = false;
    contacts[index].showInfo();
}

void PhoneBook::addBook()
{
    saveInfo();
    this->isEmpty = false;
    if (this->index == BOOKSIZE - 1)
        this->isFull = true;
    this->index++;
    this->index %= 8; 
}

void PhoneBook::searchBook()
{
    if (this->isEmpty == true)
    {
        std::cout << "NO SEARCH DATA" << std:: endl;
        return ;
    }
    int start;
    int idx = 0;
    if (this->isFull)
        start = (this->index % 8);
    else
        start = 0;
    while (1){
        contacts[start].showsubInfo(idx++);
        start++;
        start %= 8;
        if (start == this->index)
            break;
    }
    while (1){
        int num;
        std::cin >> num;
        if (this->isFull && 0 <= num && num < BOOKSIZE){
            contacts[(this->index + num) % 8].showInfo();
            break;
        } 
        else if (!this->isFull && 0 <= num && num < this->index){
            contacts[num].showInfo();
            break;
        }
        else
            std::cout << "NOT FOUND INDEX" << std:: endl;
    }
}

PhoneBook::~PhoneBook(){}