/**
 * @file    math.cpp
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
 * Implementace knihovny matematickych funkci
 */

#include <iostream>

/**
 * @details Funkce pro scitani dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek scitani typu float
 */
float sum(float a, float b) {
    return (float)(a + b);
}

/**
 * @details Funkce pro odcitani dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek odcitani typu float
 */
float sub(float a, float b) {
    return (float)(a - b);
}

/**
 * @details Funkce pro nasobeni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek nasobeni typu float
 */
float mul(float a, float b) {
    return (float)(a * b);
}

/**
 * @details Funkce pro deleni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek deleni typu float
 */
float div(float a, float b) {
    return (float)(a / b);
}

/**
 * @details Funkce pro celociselni deleni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek deleni typu float
 */
std::pair<int, int> idiv(int a, int b) {
    int res = 0, rem = 0;
    return std::make_pair(res, rem);
}

/**
 * @details Funkce pro vypocet faktorialu
 * 
 * @param a Pocatecni hodnota faktorialu
 * @return Vysledek faktorialu typu float nebo -1 pri chybe
 */
float fact(int a) {
    return -1;
}

/**
 * @details Funkce pro umocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota mocniny
 * @param n Prirozeny rad mocniny 
 * @return Vysledek umocneni typu float nebo -1 pri chybe
 */
float power(float a, int n) {
    return -1;
}

/**
 * @details Funkce pro odmocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota odmocniny
 * @param n Prirozeny rad odmocniny 
 * @return Vysledek odmocneni typu float nebo -1 pri chybe
 */
float root(float a, int n) {
    return -1;
}