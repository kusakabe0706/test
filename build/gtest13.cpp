#include <gtest/gtest.h>
#include "header13.h"

TEST(header13Test, AddPointers) {
    int a = 3, b = 5, c = 7;
    EXPECT_EQ(add(&a, &b, &c), 15);

    int x = -5, y = 10, z = 0;
    EXPECT_EQ(add(&x, &y, &z), 5);
}