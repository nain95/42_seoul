#include "Harl.hpp"

int main()
{
    Harl ex = Harl();

    ex.complain("DEBUG");
    ex.complain("info");
    ex.complain("INFO");
    ex.complain("debug");
    ex.complain("warning");
    ex.complain("WARNING");
    ex.complain("error");
    ex.complain("ERROR");

}