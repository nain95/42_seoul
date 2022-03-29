#ifndef PHONEBOOK
#define PHONEBOOK

#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#define BOOKSIZE 8

class PhoneBook {
	private:
		Contact contacts[BOOKSIZE];
		int index;
		bool isEmpty;
		bool isFull;
	public:
		PhoneBook();
		void saveInfo();
		void checkEmpty();
		void addBook();
		void searchBook();
		~PhoneBook();
};
#endif