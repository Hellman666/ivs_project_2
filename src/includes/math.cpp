/**
 * @file    math.cpp
 * @authors Radek Jestřabík <xjestr04>,
 *          Samuel Kentoš <xkento00>
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
#include <cmath>
#include <cfloat>

/**
 * @details Funkce pro scitani dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek scitani typu double
 */
double sum(double a, double b) {
    long double result = (long double) (a + b);
    
    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::runtime_error("Prilis velke cislo");

    return (double)result;
}

/**
 * @details Funkce pro odcitani dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek odcitani typu double
 */
double sub(double a, double b) {
    long double result = (long double) (a - b);
    
    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::runtime_error("Prilis velke cislo");

    return (double)result;
}

/**
 * @details Funkce pro nasobeni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek nasobeni typu double
 */
double mul(double a, double b) {
    long double result = (long double) (a * b);
    
    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::runtime_error("Prilis velke cislo");

    return (double)result;
}

/**
 * @details Funkce pro deleni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek deleni typu double
 */
double div(double a, double b) {
    if (b == 0)
        throw std::runtime_error("Deleni nulou");

    long double result = (a / b);

    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::runtime_error("Prilis velke cislo");

    return (double)result;
}

/**
 * @details Funkce pro celociselne deleni dvou hodnot
 * 
 * @param a Prvni hodnota int
 * @param b Druha hodnota int
 * @return Vysledek deleni typu pair<int, int>, kde prvni hodnota predstavuje vysledek a druha zbytek
 */
std::pair<int, int> idiv(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Deleni nulou");

    int res, rem;

    res = (int)(a / b);
    rem = (int)(a % b);

    return std::make_pair(res, rem);
}

/**
 * @details Funkce pro vypocet faktorialu
 * 
 * @param a Pocatecni hodnota faktorialu
 * @return Vysledek faktorialu typu double nebo vyvola std::runtime_error pri chybe
 */
double fact(int a) {
    if (a < 0)
        throw std::runtime_error("Neplatne cislo (mensi nez 0)");

    double result = tgamma(a+1);

    if (std::isinf(result))
        throw std::runtime_error("Prilis velke cislo");

    return result;
}

/**
 * @details Funkce pro umocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota mocniny
 * @param n Prirozeny rad mocniny 
 * @return Vysledek umocneni typu double nebo vyvola std::runtime_error pri chybe
 */
double power(double a, int n) {
    double result = std::pow(a, n);
    
    if (result > DBL_MAX)
        throw std::runtime_error("Prilis velke cislo");
    return result;
}

/**
 * @details Funkce pro odmocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota odmocniny
 * @param n Prirozeny rad odmocniny 
 * @return Vysledek odmocneni typu double nebo vyvola std::runtime_error pri chybe
 */
double root(double a, int n) {
    if ( n == 0)
        throw std::runtime_error("Nulta odmocnina neexistuje");
    if (a < 0 && n % 2 == 0)
        throw std::runtime_error("Nelze udelat sudou odmocninu ze zaporneho cisla");

    double result = std::pow(std::abs(a), 1.0/n) * (a >= 0 ? 1 : -1);

    if (std::isnan(result))
        throw std::runtime_error("Neplatna operace");

    return result;
}