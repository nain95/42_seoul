#include "phoneBook.hpp"

phoneBook::phoneBook(){
    this->isEmpty = true;
}

void phoneBook::saveInfo(){


    std::cout << CYN << "firt_name :" << NC;
    this->first_name.clear();
    getline(std::cin, this->first_name);

	std::cout << CYN << "last_name :" << NC ;
    this->last_name.clear();
    getline(std::cin, this->last_name);

	std::cout << CYN << "nick_name :" << NC;
    this->nick_name.clear();
    getline(std::cin, this->nick_name);

	std::cout << CYN << "phone_number :" << NC;
    this->phone_number.clear();
    getline(std::cin, this->phone_number);

	std::cout << CYN << "darkest_secret :" << NC;
    this->darkest_secret.clear();
    getline(std::cin, this->darkest_secret);
    this->isEmpty = false;
    showInfo();
}

// void phoneBook::setIndex(int i){
//     this->index = i;
// }

void phoneBook::showInfo(){
	std::cout << GRN << "first name = "  << first_name << std::endl;
	std::cout << "last name = " <<  last_name << std::endl;
	std::cout << "nick name = " <<  nick_name << std::endl;
	std::cout << "phone number = " <<  phone_number << std::endl;
	std::cout << "darkest secrete = " <<  darkest_secret << NC << std::endl;
}

void phoneBook::showsubInfo(int idx)
{
	std::cout << std::setw(10) << std::right << GRN << idx << "|";
	std::cout << std::setw(10) << std::right << first_name << "|";
	std::cout << std::setw(10) << std::right << last_name << "|";
	std::cout << std::setw(10) << std::right << nick_name << "|" << NC <<std::endl;
}