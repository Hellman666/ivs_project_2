/**
 * @file    math.h
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
 * Hlavickovy soubor pro matematicke funkce
 */

#include <iostream>

#ifndef MATH_H
#define MATH_H

/**
 * @details Funkce pro scitani dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek scitani typu float
 */
float sum(float, float);

/**
 * @details Funkce pro odcitani dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek odcitani typu float
 */
float sub(float, float);

/**
 * @details Funkce pro nasobeni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek nasobeni typu float
 */
float mul(float, float);

/**
 * @details Funkce pro deleni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek deleni typu float
 */
float div(float, float);

/**
 * @details Funkce pro celociselni deleni dvou hodnot
 * 
 * @param a Prvni hodnota float/int
 * @param b Druha hodnota float/int
 * @return Vysledek deleni typu float
 */
std::pair<int, int> idiv(int, int);

/**
 * @details Funkce pro vypocet faktorialu
 * 
 * @param a Pocatecni hodnota faktorialu
 * @return Vysledek faktorialu typu float nebo -1 pri chybe
 */
float fact(int);

/**
 * @details Funkce pro umocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota mocniny
 * @param n Prirozeny rad mocniny 
 * @return Vysledek umocneni typu float nebo -1 pri chybe
 */
float power();

/**
 * @details Funkce pro odmocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota odmocniny
 * @param n Prirozeny rad odmocniny 
 * @return Vysledek odmocneni typu float nebo -1 pri chybe
 */
float root();

#endif