#include "PhoneBook.hpp"

int main()
{
	std::string oper;
	PhoneBook pb;

	while (1)
	{
		std::cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n";
		std::cout << "press push cmd : SEARCH | ADD | EXIT" << std::endl;
		std::cin >> oper;
        std::cin.ignore();
		if (oper == "SEARCH")
			pb.searchBook();
		else if (oper == "ADD")
			pb.addBook();
		else if (oper == "EXIT")
			break;
	}
	return (0);
}