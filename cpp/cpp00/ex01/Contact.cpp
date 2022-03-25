#include "PhoneBook.hpp"

std::string Contact::getFirstName(void) const {
  return this->firstName;
}

std::string Contact::getLastName(void) const {
  return this->lastName;
}

std::string Contact::getNickname(void) const {
  return this->nickname;
}

std::string Contact::getPhoneNumber(void) const {
  return this->phoneNumber;
}

std::string Contact::getDarkestSecrete(void) const {
  return this->darkestSecret;
}

void Contact::setFirstName(std::string& firstName) {
	this->firstName.clear();
	this->firstName = firstName;
}

void Contact::setLastName(std::string& lastName) {
	this->lastName.clear();
	this->lastName = lastName;
}

void Contact::setNickname(std::string& nickname) {
	this->nickname.clear();
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string& phoneNumber) {
	this->phoneNumber.clear();
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecrete(std::string& darkestSecret) {
	this->darkestSecret.clear();
	this->darkestSecret = darkestSecret;
}

void Contact::showInfo() const
{
	std::cout << "first name = "  << firstName << std::endl;
	std::cout << "last name = " <<  lastName << std::endl;
	std::cout << "nick name = " <<  nickname << std::endl;
	std::cout << "phone number = " <<  phoneNumber << std::endl;
	std::cout << "darkest secrete = " <<  darkestSecret << std::endl;
}

void Contact::showsubInfo(int idx) const
{
    size_t print_len = 10;

	std::cout << std::setw(print_len) << std::right << idx << "|";
    if (firstName.length() > print_len)
	    std::cout << std::setw(print_len) << std::right << firstName.substr(0, print_len - 1) + "." << "|";
    else
	    std::cout << std::setw(print_len) << std::right << firstName << "|";
    if (lastName.length() > print_len)
	    std::cout << std::setw(print_len) << std::right << lastName.substr(0, print_len - 1) + "." << "|";
    else
	    std::cout << std::setw(print_len) << std::right << lastName << "|";
    if (nickname.length() > print_len)
	    std::cout << std::setw(print_len) << std::right << nickname.substr(0, print_len - 1) + "." << "|";
    else
	    std::cout << std::setw(print_len) << std::right << nickname << "|";
	std::cout << std::endl;
}