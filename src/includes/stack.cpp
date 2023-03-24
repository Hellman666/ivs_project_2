/**
 * @file    stack.cpp
 * @authors Jmeno Prijmneni <xlogin00>,
 *          Jmeno Prijmneni <xkento00>
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
 * Implementace zasobnikovych funkci
 */

#include <iostream>

#define _STACK_ struct Stack

/**
 * @details Funkce pro inicializaci zasobniku
 * 
 * @param Stack Ukazatel na strukturu zasobniku
 */
void Stack_Init(_STACK_ *Stack) {
}

/**
 * @details Funkce pro vytvoreni ukazatele na strukturu zasobniku
 * 
 * @return Ukazatel na strukturu zasobniku
 */
_STACK_ *Stack_Create() {
    Stack *Stack_New = nullptr;
    return Stack_New;
}

/**
 * @details Funkce pro pridani nove hodnoty na zasobnik
 * 
 * @param Stack Ukazatel na strukturu zasobniku
 * @param Token Hodnota na vlozeni na zasobnik
 * @return Kod chyby inak 0
 */
int Stack_Push (_STACK_ *Stack, char Token) {
    return 0;
}

/**
 * @details Funkce pro odebrani hodnoty ze zasobniku
 * 
 * @param Stack Ukazatel na strukturu zasobniku
 * @return Ukazatel na strukturu zasobniku
 */
_STACK_ *Stack_Pop(_STACK_ *Stack) {
    return Stack;
}