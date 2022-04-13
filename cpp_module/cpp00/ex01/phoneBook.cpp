#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->index = 0;
    this->isEmpty = true;
    this->isFull = false;
}

void PhoneBook::saveInfo()
{
    std::string input_data;

    while (input_data.empty())
    {
        std::cout << "\nfirt_name :";
        getline(std::cin, input_data);
    }
    this->contacts[index].setFirstName(input_data);

    input_data.clear();
    while (input_data.empty())
	{
        std::cout << "last_name :" ;
        getline(std::cin, input_data);
    }
    this->contacts[index].setLastName(input_data);

    input_data.clear();
    while (input_data.empty())
	{
        std::cout << "nick_name :";
        getline(std::cin, input_data);
    }
    this->contacts[index].setNickname(input_data);

    input_data.clear();
    while (input_data.empty())
	{
        std::cout << "phone_number :";
        getline(std::cin, input_data);
    }
    this->contacts[index].setPhoneNumber(input_data);

    input_data.clear();
    while (input_data.empty())
    {
        std::cout << "darkest_secret :";
        getline(std::cin, input_data);
    }
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
    int end;
    if (this->isFull)
        end = 8;
    else
        end = this->index;
    for (int i = 0; i < end; i ++)
        contacts[i].showsubInfo(i);
    std::cout << "Select the index to search" << std::endl;
    int num;
    while (1){
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cout << "INDEX ERROR" << std::endl;
            std::cin.clear();
			std::cin.ignore(100, '\n');
        }
        else if (num == -1)
            break;
        else if (this->isFull && 0 <= num && num < BOOKSIZE){
            contacts[num].showInfo();
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