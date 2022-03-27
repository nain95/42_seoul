#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "===================================" << std::endl;
	std::cout << " display the address of the string " << std::endl;
	std::cout << "===================================" << std::endl;
    std::cout << "str 주소값 = " << &str << std::endl;
    std::cout << "stringPTR 주소값 = " << stringPTR << std::endl;
    std::cout << "stringREF 주소값 = " << &stringREF << std::endl;

    std::cout << "====================================" << std::endl;
	std::cout << "         display the string         " << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << "str = " << str << std::endl;
    std::cout << "stringPTR = " << *stringPTR << std::endl;
    std::cout << "stringREF = " << stringREF << std::endl;
}