#include "includes/math.h"
#include <iostream>


/**
 * program na debugovani funkci z matematicke knihovny
 * @author Radek Jestrabik xjestr04
*/
int main()
{
    double x = 22.5;
    double y = -14.0;
    double result = sum(x, y);
    std::cout << "Vysledek scitani je " << result << std::endl;
    return 0;
}
