#include <iostream>
#include "countGoodStrings.h"
#include <gtest/gtest.h>

TEST(GoodStringTest, Test1)
{
	ASSERT_EQ(0, countGoodSubstrings(""));
}


TEST(GoodStringTest, Test2)
{
	ASSERT_EQ(1, countGoodSubstrings("a"));
}


TEST(GoodStringTest, Test3)
{
	ASSERT_EQ(3, countGoodSubstrings("aa"));
}


TEST(GoodStringTest, Test4)
{
	ASSERT_EQ(11, countGoodSubstrings("aabb"));
}


TEST(GoodStringTest, Test5)
{
	ASSERT_EQ(12, countGoodSubstrings("leet"));
}


TEST(GoodStringTest, Test6)
{
	ASSERT_EQ(15, countGoodSubstrings("abcd"));
}


int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}