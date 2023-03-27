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

#include <gmock/gmock.h>
#include <stdio.h>

#include <float.h>

#include "gtest/gtest.h"

using namespace ::testing;

/**
 * sum Tests
 */
TEST(SumTest, IntegerInput) {
    EXPECT_NEAR(sum(1, 1), 2, 0.000000001);
}

TEST(SumTest, DoubleInput) {
    EXPECT_NEAR(sum(1.0005, 1.0005), 2.001, 0.000000001);
}

TEST(SumTest, ZeroInput) {
    EXPECT_NEAR(sum(0., 0.), 0., 0.000000001);
}

TEST(SumTest, NegativeInput) {
    EXPECT_NEAR(sum(-10., -10.), -20., 0.000000001);
}

TEST(SumTest, MaxDoubleInput) {
    EXPECT_THROW(sum(DBL_MAX, 1), std::runtime_error);
}

/**
 * sub Tests
 */
TEST(SubTest, IntegerInput) {
    EXPECT_NEAR(sub(123, 123), 0, 0.000000001);
}

TEST(SubTest, DoubleInput) {
    EXPECT_NEAR(sub(1.00010, 1.00005), 0.00005, 0.000000001);
}

TEST(SubTest, ZeroInput) {
    EXPECT_NEAR(sub(0., 0.), 0, 0.000000001);
}

TEST(SubTest, NegativeNegativeInput) {
    EXPECT_NEAR(sub(-10., -10.), 0., 0.000000001);
}

TEST(SubTest, NegativePositiveInput) {
    EXPECT_NEAR(sub(-10., 10.), -20., 0.000000001);
}

TEST(SubTest, MaxDoubleInput) {
    EXPECT_THROW(sub(DBL_MAX, -1), std::runtime_error);
}

/**
 * mul Tests
 */
TEST(MulTest, IntegerInput) {
    EXPECT_NEAR(mul(42, 69), 2898, 0.000000001);
}

TEST(MulTest, DoubleInput) {
    EXPECT_NEAR(mul(1.00005, 1.00005), 1.0001000025, 0.000000001);
}

TEST(MulTest, ZeroInput) {
    EXPECT_NEAR(mul(0., 0.), 0., 0.000000001);
}

TEST(MulTest, NegativeNegativeInput) {
    EXPECT_NEAR(mul(-10., -10.), 100., 0.000000001);
}

TEST(MulTest, NegativePositiveInput) {
    EXPECT_NEAR(mul(-10., 10.), -100., 0.000000001);
}

TEST(MulTest, MaxDoubleInput) {
    EXPECT_THROW(mul(DBL_MAX, 1.1), std::runtime_error);
}

/**
 * div Tests
 * Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, IntegerInputReturnLessThanOne) {
    EXPECT_NEAR(div(42., 69.), 0.6086956521, 0.000000001);
}

TEST(DivTest, IntegerInputReturnMoreThanOne) {
    EXPECT_NEAR(div(69., 42.), 1.6428571428, 0.000000001);
}

TEST(DivTest, DoubleInput) {
    EXPECT_NEAR(div(1.00005, 2.5), 0.40002, 0.000000001);
}

TEST(DivTest, ZeroDivisorInput) {
    EXPECT_THROW(div(10., 0.), std::runtime_error);
}

TEST(DivTest, ZeroDividendInput) {
    EXPECT_NEAR(div(0., 1.), 0., 0.000000001);
}

TEST(DivTest, NegativeNegativeInput) {
    EXPECT_NEAR(div(-10., -10.), 1., 0.000000001);
}

TEST(DivTest, NegativePositiveInput) {
    EXPECT_NEAR(div(-10., 10.), -1., 0.000000001);
}

TEST(DivTest, MaxDoubleInput) {
    EXPECT_NEAR(div(DBL_MAX, -2.), -(DBL_MAX / 2), 0.000000001);
}

/**
 * idiv Tests
 */
TEST(IDivTest, IntegerInputReturnLessThanOne) {
    EXPECT_THAT(idiv(5, 10), Pair(0, 5));
}

TEST(IDivTest, IntegerInputReturnMoreThanOne) {
    EXPECT_THAT(idiv(69, 42), Pair(1, 27));
}

TEST(IDivTest, ZeroDivisorInput) {
    EXPECT_THROW(idiv(10, 0), std::runtime_error);
}

TEST(IDivTest, ZeroDividendInput) {
    EXPECT_THAT(idiv(0, 1), Pair(0, 0));
}

TEST(IDivTest, NegativeNegativeInput) {
    EXPECT_THAT(idiv(-10, -10), Pair(1, 0));
}

TEST(IDivTest, NegativePositiveInput) {
    EXPECT_THAT(idiv(-10, 10), Pair(-1, 0));
}

TEST(IDivTest, MaxIntInput) {
    EXPECT_THAT(idiv(INT_MAX - 1, INT_MAX), Pair(0, INT_MAX - 1));
}

/**
 * fact Tests
 */
TEST(FactTest, SimpleFactorial) {
    EXPECT_EQ(fact(10), 3628800);
}

TEST(FactTest, BiggerFact) {
    EXPECT_EQ(fact(15), 1.307674368e+12);
}

TEST(FactTest, FactWithinULLRange) {
    EXPECT_LT(fact(20), ULLONG_MAX);
}

// 20 je největší faktoriál, který lze spočítat na ULL
TEST(FactTest, FactOverULLRange) {
    EXPECT_THROW(fact(21), std::runtime_error);
}

TEST(FactTest, NegativeInput) {
    EXPECT_THROW(fact(-10), std::runtime_error);
}

/**
 * power Tests
 */
TEST(PowTest, IntPow) {
    EXPECT_EQ(power(2, 2), 4);
}

TEST(PowTest, DoubleA) {
    EXPECT_NEAR(power(0.5, 2), 0.25, 0.000000001);
}

TEST(PowTest, NegativeA) {
    EXPECT_NEAR(power(-4., 2), 16., 0.000000001);
}

TEST(PowTest, MaxDouble) {
    EXPECT_THROW(power(DBL_MAX, 2), std::runtime_error);
}

/**
 * root Tests
 */
TEST(RootTest, IntSquareRoot) {
    EXPECT_EQ(root(4, 2), 2);
}

TEST(RootTest, IntRootOfZero) {
    EXPECT_EQ(root(2, 0), 0);
}

TEST(RootTest, IntZeroRoot) {
    EXPECT_THROW(root(0, 2), std::runtime_error);
}

TEST(RootTest, IntNRoot) {
    EXPECT_EQ(root(-8, 3), -2);
}

TEST(RootTest, DoubleRoot) {
    EXPECT_EQ(root(0.25, 2), 0.5);
}

TEST(RootTest, ImpossibleRoot) {
    EXPECT_THROW(root(-4, 2), std::runtime_error);
}
