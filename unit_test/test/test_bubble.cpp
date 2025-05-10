#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bubble_sort.hpp"

TEST(BubbleSortTest, SortsCorrectly) {
    std::vector<int> actual = {1, 8, 2, 5, 3, 11};
    std::vector<int> expected = {1, 2, 3, 5, 8, 11};
    bubbleSort(actual);

    ASSERT_EQ(expected.size(), actual.size()) 
        << "Разные размеры ожидаемого и отсортированного массивов";

    for (int i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]) 
            << "Массив ожидаемый и отсортированный отличаются в элементе с индексом " << i;
    }
}

TEST(BubbleSortTest, EmptyArray) {
    std::vector<int> actual = {};
    std::vector<int> expected = {};
    bubbleSort(actual);

    ASSERT_EQ(expected.size(), actual.size()) 
        << "Разные размеры ожидаемого и отсортированного массивов";
}

TEST(BubbleSortTest, AlreadySorted) {
    std::vector<int> actual = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    bubbleSort(actual);

    ASSERT_EQ(expected.size(), actual.size()) 
        << "Разные размеры ожидаемого и отсортированного массивов";

    for (int i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]) 
            << "Массив ожидаемый и отсортированный отличаются в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}