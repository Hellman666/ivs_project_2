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
#include <string.h>
#include <stack>

#include "includes/math.h"

/**
 * @details Hlavni telo programu       
 * 
 * @return 0 pri ukonceni programu, jinak hodnota chyby
 */
int main() {

    /*
     * - Pouziti idiv funkce
     *
     * std::pair<int, int> Result = idiv(2, 1);
     * std::cout<<Result.first<<' '<<Result.second<<'\n';
     */
    
    /*
     * - Pouziti zasobniku
     *
     * std::stack<std::string> Stack;       Inicializace
     * 
     * Stack.push("6\0");
     * Stack.push("*\0");
     * Stack.push("2\0");
     * 
     * double b = std::stod(Stack.top());   Ulozeni dvojky
     * Stack.pop();                         Uvolneni dvojky
     * 
     * Stack.pop();                         Uvolneni hviezdicky
     * 
     * double a = std::stod(Stack.top());   Ulozeni sestky
     * Stack.pop();                         Uvolneni sestky
     * 
     * double c = div(a, b);                Vypocet
     * Stack.push(std::to_string(c));       Pushnuti vysledku
     * std::cout<<Stack.top()<<'\n';        Vypis vysledku
     */

	return 0;
}