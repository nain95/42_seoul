#ifndef PHONEBOOK
#define PHONEBOOK

#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#define BOOKSIZE 8

class PhoneBook {
	private:
		int index;
		bool isEmpty;
		bool isFull;
	public:
		Contact contacts[BOOKSIZE];
		PhoneBook();
		void saveInfo();
		void checkEmpty();
		void addBook();
		void searchBook();
		~PhoneBook();
};
#endif