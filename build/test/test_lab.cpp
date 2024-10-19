#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"

TEST(TriangleTest, Constructor) {
    Triangle t(0, 0, 1, 0, 0.5, 1);
    EXPECT_DOUBLE_EQ(t.area(), 0.5);
}

TEST(TriangleTest, Center) {
    Triangle t(0, 0, 1, 0, 0.5, 1);
    auto center = t.center();
    EXPECT_DOUBLE_EQ(center.first, 0.5);
    EXPECT_DOUBLE_EQ(center.second, 0.3333333333333333);
}

TEST(TriangleTest, Equality) {
    Triangle t1(0, 0, 1, 0, 0.5, 1);
    Triangle t2(0, 0, 1, 0, 0.5, 1);
    Triangle t3(1, 1, 2, 1, 1.5, 2);
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(SquareTest, Constructor) {
    Square s(0, 0, 2);
    EXPECT_DOUBLE_EQ(s.area(), 4);
}

TEST(SquareTest, Center) {
    Square s(0, 0, 2);
    auto center = s.center();
    EXPECT_DOUBLE_EQ(center.first, 1);
    EXPECT_DOUBLE_EQ(center.second, 1);
}

TEST(SquareTest, Equality) {
    Square s1(0, 0, 2);
    Square s2(0, 0, 2);
    Square s3(1, 1, 3);
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(RectangleTest, Constructor) {
    Rectangle r(0, 0, 2, 3);
    EXPECT_DOUBLE_EQ(r.area(), 6);
}

TEST(RectangleTest, Center) {
    Rectangle r(0, 0, 2, 3);
    auto center = r.center();
    EXPECT_DOUBLE_EQ(center.first, 1);
    EXPECT_DOUBLE_EQ(center.second, 1.5);
}

TEST(RectangleTest, Equality) {
    Rectangle r1(0, 0, 2, 3);
    Rectangle r2(0, 0, 2, 3);
    Rectangle r3(1, 1, 3, 4);
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}