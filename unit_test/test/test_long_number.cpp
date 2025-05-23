#include "gtest/gtest.h"
#include "long_number.hpp"

using biv::LongNumber;

TEST(LongNumber, DefaultConstructor) {
    LongNumber num;
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumber, ConstructorFromCharArray) {
    LongNumber num("123");
    ASSERT_EQ(num.get_digits_number(), 3);
    ASSERT_FALSE(num.is_negative());
    ASSERT_EQ(num.get_rank_number(1), 3);
    ASSERT_EQ(num.get_rank_number(2), 2);
    ASSERT_EQ(num.get_rank_number(3), 1);
}

TEST(LongNumber, ConstructorFromCharArrayNegative) {
    LongNumber num("-456");
    ASSERT_EQ(num.get_digits_number(), 3);
    ASSERT_TRUE(num.is_negative());
    ASSERT_EQ(num.get_rank_number(1), 6);
    ASSERT_EQ(num.get_rank_number(2), 5);
    ASSERT_EQ(num.get_rank_number(3), 4);
}

TEST(LongNumber, CopyConstructor) {
    LongNumber num1("789");
    LongNumber num2 = num1;
    ASSERT_EQ(num2.get_digits_number(), 3);
    ASSERT_FALSE(num2.is_negative());
    ASSERT_EQ(num2.get_rank_number(1), 9);
    ASSERT_EQ(num2.get_rank_number(2), 8);
    ASSERT_EQ(num2.get_rank_number(3), 7);
}

TEST(LongNumber, MoveConstructor) {
    LongNumber num1("111");
    LongNumber num2 = std::move(num1);
    ASSERT_EQ(num2.get_digits_number(), 3);
    ASSERT_FALSE(num2.is_negative());
    ASSERT_EQ(num2.get_rank_number(1), 1);
    ASSERT_EQ(num2.get_rank_number(2), 1);
    ASSERT_EQ(num2.get_rank_number(3), 1);
}

TEST(LongNumber, AssignmentOperatorCharArray) {
    LongNumber num;
    num = "234";
    ASSERT_EQ(num.get_digits_number(), 3);
    ASSERT_FALSE(num.is_negative());
    ASSERT_EQ(num.get_rank_number(1), 4);
    ASSERT_EQ(num.get_rank_number(2), 3);
    ASSERT_EQ(num.get_rank_number(3), 2);
}

TEST(LongNumber, AssignmentOperatorCopy) {
    LongNumber num1("567");
    LongNumber num2;
    num2 = num1;
    ASSERT_EQ(num2.get_digits_number(), 3);
    ASSERT_FALSE(num2.is_negative());
    ASSERT_EQ(num2.get_rank_number(1), 7);
    ASSERT_EQ(num2.get_rank_number(2), 6);
    ASSERT_EQ(num2.get_rank_number(3), 5);
}

TEST(LongNumber, AssignmentOperatorMove) {
    LongNumber num1("888");
    LongNumber num2;
    num2 = std::move(num1);
    ASSERT_EQ(num2.get_digits_number(), 3);
    ASSERT_FALSE(num2.is_negative());
    ASSERT_EQ(num2.get_rank_number(1), 8);
    ASSERT_EQ(num2.get_rank_number(2), 8);
    ASSERT_EQ(num2.get_rank_number(3), 8);
}

TEST(LongNumber, EqualityOperator) {
    LongNumber num1("123");
    LongNumber num2("123");
    ASSERT_TRUE(num1 == num2);

    LongNumber num3("456");
    ASSERT_FALSE(num1 == num3);

    LongNumber num4("-123");
    ASSERT_FALSE(num1 == num4);
}

TEST(LongNumber, InequalityOperator) {
    LongNumber num1("123");
    LongNumber num2("456");
    ASSERT_TRUE(num1 != num2);

    LongNumber num3("123");
    ASSERT_FALSE(num1 != num3);
}

TEST(LongNumber, GreaterThanOperator) {
    LongNumber num1("456");
    LongNumber num2("123");
    ASSERT_TRUE(num1 > num2);

    LongNumber num3("456");
    ASSERT_FALSE(num1 > num3);

    LongNumber num4("789");
    ASSERT_FALSE(num1 > num4);
}

TEST(LongNumber, LessThanOperator) {
    LongNumber num1("123");
    LongNumber num2("456");
    ASSERT_TRUE(num1 < num2);

    LongNumber num3("123");
    ASSERT_FALSE(num1 < num3);

    LongNumber num4("78");
    ASSERT_FALSE(num1 < num4);
}

TEST(LongNumber, AdditionOperatorPositive) {
    LongNumber num1("123");
    LongNumber num2("456");
    LongNumber sum = num1 + num2;
    ASSERT_EQ(sum.get_digits_number(), 3);
    ASSERT_FALSE(sum.is_negative());
    ASSERT_EQ(sum.get_rank_number(1), 9);
    ASSERT_EQ(sum.get_rank_number(2), 7);
    ASSERT_EQ(sum.get_rank_number(3), 5);
}

TEST(LongNumber, AdditionOperatorNegative) {
    LongNumber num1("-123");
    LongNumber num2("-456");
    LongNumber sum = num1 + num2;
    ASSERT_EQ(sum.get_digits_number(), 3);
    ASSERT_TRUE(sum.is_negative());
    ASSERT_EQ(sum.get_rank_number(1), 9);
    ASSERT_EQ(sum.get_rank_number(2), 7);
    ASSERT_EQ(sum.get_rank_number(3), 5);
}

TEST(LongNumber, SubtractionOperatorPositive) {
    LongNumber num1("456");
    LongNumber num2("123");
    LongNumber diff = num1 - num2;
    ASSERT_EQ(diff.get_digits_number(), 3);
    ASSERT_FALSE(diff.is_negative());
    ASSERT_EQ(diff.get_rank_number(1), 3);
    ASSERT_EQ(diff.get_rank_number(2), 3);
    ASSERT_EQ(diff.get_rank_number(3), 3);
}

TEST(LongNumber, SubtractionOperatorNegative) {
    LongNumber num1("123");
    LongNumber num2("456");
    LongNumber diff = num1 - num2;
    ASSERT_EQ(diff.get_digits_number(), 3);
    ASSERT_TRUE(diff.is_negative());
    ASSERT_EQ(diff.get_rank_number(1), 3);
    ASSERT_EQ(diff.get_rank_number(2), 3);
    ASSERT_EQ(diff.get_rank_number(3), 3);
}

TEST(LongNumber, MultiplicationOperator) {
    LongNumber num1("12");
    LongNumber num2("10");
    LongNumber product = num1 * num2;
    ASSERT_EQ(product.get_digits_number(), 3);
    ASSERT_FALSE(product.is_negative());
    ASSERT_EQ(product.get_rank_number(1), 0);
    ASSERT_EQ(product.get_rank_number(2), 2);
    ASSERT_EQ(product.get_rank_number(3), 1);
}

TEST(LongNumber, DivisionOperator) {
    LongNumber num1("144");
    LongNumber num2("12");
    LongNumber quotient = num1 / num2;
    ASSERT_EQ(quotient.get_digits_number(), 2);
    ASSERT_FALSE(quotient.is_negative());
    ASSERT_EQ(quotient.get_rank_number(1), 2);
    ASSERT_EQ(quotient.get_rank_number(2), 1);
}

TEST(LongNumber, ModuloOperator) {
    LongNumber num1("145");
    LongNumber num2("12");
    LongNumber remainder = num1 % num2;
    ASSERT_EQ(remainder.get_digits_number(), 1);
    ASSERT_FALSE(remainder.is_negative());
    ASSERT_EQ(remainder.get_rank_number(1), 1);
}

TEST(LongNumber, GetDigitsNumber) {
    LongNumber num("12345");
    ASSERT_EQ(num.get_digits_number(), 5);
}

TEST(LongNumber, GetRankNumber) {
    LongNumber num("54321");
    ASSERT_EQ(num.get_rank_number(1), 1);
    ASSERT_EQ(num.get_rank_number(3), 3);
    ASSERT_EQ(num.get_rank_number(5), 5);
}

TEST(LongNumber, IsNegative) {
    LongNumber num1("123");
    ASSERT_FALSE(num1.is_negative());

    LongNumber num2("-456");
    ASSERT_TRUE(num2.is_negative());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}