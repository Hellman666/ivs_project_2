/**
 * @file    math.cpp
 * @authors Radek Jestrabik <xjestr04>,
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
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek scitani typu double
 */
double sum(double a, double b) {
    return (double)(a + b);
}

/**
 * @details Funkce pro odcitani dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek odcitani typu double
 */
double sub(double a, double b) {
    return (double)(a - b);
}

/**
 * @details Funkce pro nasobeni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek nasobeni typu double
 */
double mul(double a, double b) {
    return (double)(a * b);
}

/**
 * @details Funkce pro deleni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek deleni typu double
 */
double div(double a, double b) {
    return (double)(a / b);
}

/**
 * @details Funkce pro celociselne deleni dvou hodnot
 * 
 * @param a Prvni hodnota int
 * @param b Druha hodnota int
 * @return Vysledek deleni typu pair<int, int>, kde prvni hodnota predstavuje vysledek a druha zbytek
 */
std::pair<int, int> idiv(int a, int b) {
    int res = 0, rem = 0;
    return std::make_pair(res, rem);
}

/**
 * @details Funkce pro vypocet faktorialu
 * 
 * @param a Pocatecni hodnota faktorialu
 * @return Vysledek faktorialu typu double nebo -1 pri chybe
 */
double fact(int a) {
    return -1;
}

/**
 * @details Funkce pro umocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota mocniny
 * @param n Prirozeny rad mocniny 
 * @return Vysledek umocneni typu double nebo -1 pri chybe
 */
double power(double a, int n) {
    return -1;
}

/**
 * @details Funkce pro odmocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota odmocniny
 * @param n Prirozeny rad odmocniny 
 * @return Vysledek odmocneni typu double nebo -1 pri chybe
 */
double root(double a, int n) {
    return -1;
}