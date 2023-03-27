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

#include <limits>

#include "gtest/gtest.h"

using namespace ::testing;

/**
 * sum Tests
 */
TEST(SumTest, IntegerInput) {
    EXPECT_FLOAT_EQ(sum(1, 1), 2);
}

TEST(SumTest, FloatInput) {
    EXPECT_FLOAT_EQ(sum(1.0005f, 1.0005f), 2.001f);
}

TEST(SumTest, ZeroInput) {
    EXPECT_FLOAT_EQ(sum(0.f, 0.f), 0.f);
}

TEST(SumTest, NegativeInput) {
    EXPECT_FLOAT_EQ(sum(-10.f, -10.f), -20.f);
}

TEST(SumTest, MaxFloatInput) {
    EXPECT_THROW(sum(FLT_MAX, 1), std::runtime_error);
}

/**
 * sub Tests
 */
TEST(SubTest, IntegerInput) {
    EXPECT_FLOAT_EQ(sub(123, 123), 0);
}

TEST(SubTest, FloatInput) {
    EXPECT_NEAR(sub(1.00010f, 1.00005f), 0.00005f, 0.001);
}

TEST(SubTest, ZeroInput) {
    EXPECT_FLOAT_EQ(sub(0.f, 0.f), 0);
}

TEST(SubTest, NegativeNegativeInput) {
    EXPECT_FLOAT_EQ(sub(-10.f, -10.f), 0.f);
}

TEST(SubTest, NegativePositiveInput) {
    EXPECT_FLOAT_EQ(sub(-10.f, 10.f), -20.f);
}

TEST(SubTest, MaxFloatInput) {
    EXPECT_THROW(sub(FLT_MAX, -1), std::runtime_error);
}

/**
 * mul Tests
 */
TEST(MulTest, IntegerInput) {
    EXPECT_FLOAT_EQ(mul(42, 69), 2898);
}

TEST(MulTest, FloatInput) {
    EXPECT_FLOAT_EQ(mul(1.00005f, 1.00005f), 1.0001000025f);
}

TEST(MulTest, ZeroInput) {
    EXPECT_FLOAT_EQ(mul(0.f, 0.f), 0.f);
}

TEST(MulTest, NegativeNegativeInput) {
    EXPECT_FLOAT_EQ(mul(-10.f, -10.f), 100.f);
}

TEST(MulTest, NegativePositiveInput) {
    EXPECT_FLOAT_EQ(mul(-10.f, 10.f), -100.f);
}

TEST(MulTest, MaxFloatInput) {
    EXPECT_THROW(mul(FLT_MAX, 1.1f), std::runtime_error);
}

/**
 * div Tests
 * Zaokrouhlování na 15 desetinných míst
 */
TEST(DivTest, IntegerInputReturnLessThanOne) {
    EXPECT_FLOAT_EQ(div(42.f, 69.f), 0.608695652174f);
}

TEST(DivTest, IntegerInputReturnMoreThanOne) {
    EXPECT_FLOAT_EQ(div(69.f, 42.f), 1.64285714286f);
}

TEST(DivTest, FloatInput) {
    EXPECT_FLOAT_EQ(div(1.00005f, 2.5f), 0.40002f);
}

TEST(DivTest, ZeroDivisorInput) {
    EXPECT_THROW(div(10.f, 0.f), std::runtime_error);
}

TEST(DivTest, ZeroDividendInput) {
    EXPECT_FLOAT_EQ(div(0.f, 1.f), 0.f);
}

TEST(DivTest, NegativeNegativeInput) {
    EXPECT_FLOAT_EQ(div(-10.f, -10.f), 1.f);
}

TEST(DivTest, NegativePositiveInput) {
    EXPECT_FLOAT_EQ(div(-10.f, 10.f), -1.f);
}

TEST(DivTest, MaxFloatInput) {
    EXPECT_FLOAT_EQ(div(FLT_MAX, -2.f), -(FLT_MAX / 2));
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

TEST(PowTest, FloatA) {
    EXPECT_FLOAT_EQ(power(0.5f, 2), 0.25f);
}

TEST(PowTest, NegativeA) {
    EXPECT_FLOAT_EQ(power(-4.f, 2), 16.f);
}

TEST(PowTest, MaxFloat) {
    EXPECT_THROW(power(FLT_MAX, 2), std::runtime_error);
}

/**
 * root Tests
 */
TEST(RootTest, IntSquareRoot) {
    EXPECT_EQ(root(4, 2), 2);
}

TEST(RootTest, IntNRoot) {
    EXPECT_EQ(root(-8, 3), -2);
}

TEST(RootTest, FloatRoot) {
    EXPECT_EQ(root(0.25f, 2), 0.5);
}

TEST(RootTest, ImpossibleRoot) {
    EXPECT_THROW(root(-4, 2), std::runtime_error);
}
