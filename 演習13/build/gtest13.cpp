#include <gtest/gtest.h>
#include "header13.h"

TEST(header13Test, AddPointers) {
    int num1 = 3, num2 = 5, num3 = 7;
    EXPECT_EQ(add(&num1, &num2, &num3), 15);

    int x = -5, y = 10, z = 0;
    EXPECT_EQ(add(&x, &y, &z), 5);
}