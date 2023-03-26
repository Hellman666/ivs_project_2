/**
 * @file    math.h
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
 * Hlavickovy soubor pro matematicke funkce
 */

#include <iostream>

#ifndef MATH_H
#define MATH_H

/**
 * @details Funkce pro scitani dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek scitani typu double
 */
double sum(double, double);

/**
 * @details Funkce pro odcitani dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek odcitani typu double
 */
double sub(double, double);

/**
 * @details Funkce pro nasobeni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek nasobeni typu double
 */
double mul(double, double);

/**
 * @details Funkce pro deleni dvou hodnot
 * 
 * @param a Prvni hodnota double/int
 * @param b Druha hodnota double/int
 * @return Vysledek deleni typu double
 */
double div(double, double);

/**
 * @details Funkce pro celociselne deleni dvou hodnot
 * 
 * @param a Prvni hodnota int
 * @param b Druha hodnota int
 * @return Vysledek deleni typu pair<int, int>, kde prvni hodnota predstavuje vysledek a druha zbytek
 */
std::pair<int, int> idiv(int, int);

/**
 * @details Funkce pro vypocet faktorialu
 * 
 * @param a Pocatecni hodnota faktorialu
 * @return Vysledek faktorialu typu double nebo -1 pri chybe
 */
double fact(int);

/**
 * @details Funkce pro umocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota mocniny
 * @param n Prirozeny rad mocniny 
 * @return Vysledek umocneni typu double nebo -1 pri chybe
 */
double power(double a, int n);

/**
 * @details Funkce pro odmocneni hodnoty n-teho radu        
 * 
 * @param a Pocatecni hodnota odmocniny
 * @param n Prirozeny rad odmocniny 
 * @return Vysledek odmocneni typu double nebo -1 pri chybe
 */
double root(double a, int n);

#endif