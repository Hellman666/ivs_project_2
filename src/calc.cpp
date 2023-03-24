/**
 * @file    calc.cpp
 * @authors Jmeno Prijmneni <xlogin00>,
 *          Jmeno Prijmneni <xlogin00>
 * @version 1.0
 *
 * @section LICENCE
 *
 * Tento program je poskytovan pod licenci GNU. Pro vice informaci se podivejte
 * na Readme.md sekce LICENCE nebo na General Public License GNU na adrese
 * https://www.gnu.org/copyleft/gpl.html.
 *
 * @section POPIS
 *
 * Implementace backend pro kalkulacku
 */

#include <iostream>
#include "includes/math.h"

/**
 * @details Hlavni telo programu       
 * 
 * @return 0 pri ukonceni programu, jinak hodnota chyby
 */
int main() {
    std::pair<int, int> Result = idiv(2, 1);
    std::cout<<Result.first<<' '<<Result.second;
    
	return 0;
}