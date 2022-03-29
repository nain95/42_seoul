#include <iostream>
#include <string>
#include <fstream>



void replace_str(std::string *str, int first, int length, std::string s2)
{
    int index;
    index = first;
    str->erase(index, length);
    str->insert(index, s2);
}

int main(int ac, char **av)
{
    std::ifstream ifs;
    std::ofstream ofs;
    std::string s1;
    std::string s2;
    std::string newFile;
    std::string temp;

    if (ac == 4)
    {
        ifs.open(av[1]);
        if (!ifs.good())   
        {       
            std::cout << "File Open Error" << std::endl;
            return 0;
        }
        s1 = av[2];
        s2 = av[3];
        newFile =  av[1];
        newFile += ".replace";
        ofs.open(newFile);
        if (!ofs.good())
        {       
            std::cout << "Write File Open Error" << std::endl;
            return 0;
        }
        while (std::getline(ifs,temp))
        {
            size_t check = temp.find(s1);
            if (check != std::string::npos)
            {
                replace_str(&temp, temp.find(s1), s1.length(), s2);
            }
            temp += '\n';
            if (ofs.good())
                ofs << temp;
        }
        ifs.close();
        ofs.close();
    }
    else
        std::cout << "Invalid input please try again" << std::endl;
}