/**
 * @file    math_test.cpp
 * @authors Ondrej Hrubos <xhrubo01>,
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
 * Testy pro matematickou knihovnu.
 */

#include "../src/includes/math.h"

#include <float.h>
#include <gmock/gmock.h>
#include <stdio.h>

#include "gtest/gtest.h"

using namespace ::testing;

/**
 * @brief sčtítání celých čísel
 */
TEST(SumTest, IntegerInput) {
    EXPECT_NEAR(sum(1, 1), 2, 0.000000001);
}

/**
 * @brief sčítání desetinných čísel
 */
TEST(SumTest, DoubleInput) {
    EXPECT_NEAR(sum(1.0005, 1.0005), 2.001, 0.000000001);
}

/**
 * @brief sčítání nul
 */
TEST(SumTest, ZeroInput) {
    EXPECT_NEAR(sum(0., 0.), 0., 0.000000001);
}

/**
 * @brief sčítání záporných čísel
 */
TEST(SumTest, NegativeInput) {
    EXPECT_NEAR(sum(-10., -10.), -20., 0.000000001);
}

/**
 * @brief odčítání stejných čísel
 */
TEST(SubTest, IntegerInput) {
    EXPECT_NEAR(sub(123, 123), 0, 0.000000001);
}

/**
 * @brief odčítání desetinných čísel
 */
TEST(SubTest, DoubleInput) {
    EXPECT_NEAR(sub(1.00010, 1.00005), 0.00005, 0.000000001);
}

/**
 * @brief odčítání nul
 */
TEST(SubTest, ZeroInput) {
    EXPECT_NEAR(sub(0., 0.), 0, 0.000000001);
}

/**
 * @brief odčítání záporných čísel
 */
TEST(SubTest, NegativeNegativeInput) {
    EXPECT_NEAR(sub(-10., -10.), 0., 0.000000001);
}

/**
 * @brief odčítání od záporného čísla
 */
TEST(SubTest, NegativePositiveInput) {
    EXPECT_NEAR(sub(-10., 10.), -20., 0.000000001);
}

/**
 * @brief násobení celých čísel
 */
TEST(MulTest, IntegerInput) {
    EXPECT_NEAR(mul(42, 69), 2898, 0.000000001);
}

/**
 * @brief násobení desetinných čísel
 */
TEST(MulTest, DoubleInput) {
    EXPECT_NEAR(mul(1.00005, 1.00005), 1.0001000025, 0.000000001);
}

/**
 * @brief násobení nul
 */
TEST(MulTest, ZeroInput) {
    EXPECT_NEAR(mul(0., 0.), 0., 0.000000001);
}

/**
 * @brief násobení dvou záporných čísel
 */
TEST(MulTest, NegativeNegativeInput) {
    EXPECT_NEAR(mul(-10., -10.), 100., 0.000000001);
}

/**
 * @brief násobení kladného a záporného čísla
 */
TEST(MulTest, NegativePositiveInput) {
    EXPECT_NEAR(mul(-10., 10.), -100., 0.000000001);
}

/**
 * @brief násobení maximální hodnoty double
 */
TEST(MulTest, MaxDoubleInput) {
    EXPECT_THROW(mul(DBL_MAX, 1.1), std::runtime_error);
}

/**
 * @brief dělení celých čísel (a<b)
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, IntegerInputReturnLessThanOne) {
    EXPECT_NEAR(div(42., 69.), 0.6086956521, 0.000000001);
}

/**
 * @brief dělení celých čísel (a>b)
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, IntegerInputReturnMoreThanOne) {
    EXPECT_NEAR(div(69., 42.), 1.6428571428, 0.000000001);
}

/**
 * @brief dělení desetinných čísel
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, DoubleInput) {
    EXPECT_NEAR(div(1.00005, 2.5), 0.40002, 0.000000001);
}

/**
 * @brief dělení nulou
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, ZeroDivisorInput) {
    EXPECT_THROW(div(10., 0.), std::runtime_error);
}

/**
 * @brief dělení nuly
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, ZeroDividendInput) {
    EXPECT_NEAR(div(0., 1.), 0., 0.000000001);
}

/**
 * @brief dělení záporných čísel
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, NegativeNegativeInput) {
    EXPECT_NEAR(div(-10., -10.), 1., 0.000000001);
}

/**
 * @brief dělení záporného čísla kladným
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, NegativePositiveInput) {
    EXPECT_NEAR(div(-10., 10.), -1., 0.000000001);
}

/**
 * @brief dělení maximální hodnoty double
 * @note Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, MaxDoubleInput) {
    EXPECT_NEAR(div(DBL_MAX, -2.), -(DBL_MAX / 2), 0.000000001);
}

/**
 * @brief celočíselné dělení (a<b)
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, IntegerInputReturnLessThanOne) {
    EXPECT_THAT(idiv(5, 10), Pair(0, 5));
}

/**
 * @brief celočíselné dělení (a>b)
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, IntegerInputReturnMoreThanOne) {
    EXPECT_THAT(idiv(69, 42), Pair(1, 27));
}

/**
 * @brief dělení nulou (celočíselné dělení)
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, ZeroDivisorInput) {
    EXPECT_THROW(idiv(10, 0), std::runtime_error);
}

/**
 * @brief celočíselné dělení nuly
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, ZeroDividendInput) {
    EXPECT_THAT(idiv(0, 1), Pair(0, 0));
}

/**
 * @brief celočíselné dělení záporných čísel
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, NegativeNegativeInput) {
    EXPECT_THAT(idiv(-10, -10), Pair(1, 0));
}

/**
 * @brief celočíselné dělení záporného čísla
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, NegativePositiveInput) {
    EXPECT_THAT(idiv(-10, 10), Pair(-1, 0));
}

/**
 * @brief celočíselné dělení maximální hodnoty int
 * @note Očekává jako výstup dvojici (výsledek, zbytek)
 */
TEST(IDivTest, MaxIntInput) {
    EXPECT_THAT(idiv(INT_MAX - 1, INT_MAX), Pair(0, INT_MAX - 1));
}

/**
 * @brief jednoduchý faktoriál
 */
TEST(FactTest, SimpleFactorial) {
    EXPECT_EQ(fact(10), 3628800);
}

/**
 * @brief faktoriál 15
 */
TEST(FactTest, BiggerFact) {
    EXPECT_EQ(fact(15), 1.307674368e+12);
}

/**
 * @brief maximální faktoriál
 */
TEST(FactTest, FactWithinULLRange) {
    EXPECT_LT(fact(20), ULLONG_MAX);
}

/**
 * @brief přetečení výsledku faktoriálu
 * @note 170 je největší faktoriál, který lze spočítat na double
 */
TEST(FactTest, FactOverULLRange) {
    EXPECT_THROW(fact(171), std::runtime_error);
}

/**
 * @brief faktoriál negativního čísla
 */
TEST(FactTest, NegativeInput) {
    EXPECT_THROW(fact(-10), std::runtime_error);
}

/**
 * @brief mocnina celého čísla
 */
TEST(PowTest, IntPow) {
    EXPECT_EQ(power(2, 2), 4);
}

/**
 * @brief mocnina desetinného čísla
 */
TEST(PowTest, DoubleA) {
    EXPECT_NEAR(power(0.5, 2), 0.25, 0.000000001);
}

/**
 * @brief mocnina negativního čísla
 */
TEST(PowTest, NegativeA) {
    EXPECT_NEAR(power(-4., 2), 16., 0.000000001);
}

/**
 * @brief mocnina maximální hodnoty double
 */
TEST(PowTest, MaxDouble) {
    EXPECT_THROW(power(DBL_MAX, 2), std::runtime_error);
}

/**
 * @brief odmocnina celého čísla
 */
TEST(RootTest, IntSquareRoot) {
    EXPECT_EQ(root(4, 2), 2);
}

/**
 * @brief odmocnina nuly
 */
TEST(RootTest, IntRootOfZero) {
    EXPECT_EQ(root(0, 2), 0);
}

/**
 * @brief odmocnění nulou
 */
TEST(RootTest, IntZeroRoot) {
    EXPECT_THROW(root(2, 0), std::runtime_error);
}

/**
 * @brief odmocnění celým číslem > 2
 */
TEST(RootTest, IntNRoot) {
    EXPECT_EQ(root(-8, 3), -2);
}

/**
 * @brief odmocnění desetinným číslem
 */
TEST(RootTest, DoubleRoot) {
    EXPECT_EQ(root(0.25, 2), 0.5);
}

/**
 * @brief neexistující odmocnina
 */
TEST(RootTest, ImpossibleRoot) {
    EXPECT_THROW(root(-4, 2), std::runtime_error);
}
