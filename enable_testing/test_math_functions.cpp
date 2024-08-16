#include "math_functions.h"
#include <gtest/gtest.h>

TEST(MathFunctionsTest, AddPositiveNumbers) {
    EXPECT_EQ(add(3, 4), 7);
}

TEST(MathFunctionsTest, AddZero) {
    EXPECT_EQ(add(0, 0), 0);
}

TEST(MathFunctionsTest, AddNegativeAndPositive) {
    EXPECT_EQ(add(-1, 1), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}