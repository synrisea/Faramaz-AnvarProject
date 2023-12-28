#include <iostream>
#include <fstream>
#include "countGoodStrings.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

std::vector<std::string>strings;


void readFromFile(std::vector<std::string>& strings) 
{
    std::ifstream file("test.txt");


    if (file.is_open())
    {
        std::string tempStr;

        while (getline(file, tempStr))
        {
            strings.push_back(tempStr);
        }
    }

    file.close();
}

void writeResultsToFile(std::vector<std::string>& strings)
{
    std::ofstream out;

    out.open("results.txt");
    if (out.is_open())
    {
        for (int i = 0; i != strings.size(); i++)
        {
            out << countGoodSubstrings(strings[i]) << "\n";
        }
    }
    out.close();
}

TEST(GoodStringTest, Test1)
{
    ASSERT_EQ(0, countGoodSubstrings(strings[0]));
}


TEST(GoodStringTest, Test2)
{
    ASSERT_EQ(1, countGoodSubstrings(strings[1]));
}


TEST(GoodStringTest, Test3)
{
    ASSERT_EQ(3, countGoodSubstrings(strings[2]));
}


TEST(GoodStringTest, Test4)
{
    ASSERT_EQ(11, countGoodSubstrings(strings[3]));
}


TEST(GoodStringTest, Test5)
{
    ASSERT_EQ(12, countGoodSubstrings(strings[4]));
}


TEST(GoodStringTest, Test6)
{
    ASSERT_EQ(15, countGoodSubstrings(strings[5]));
}



int main(int argc, char** argv)
{
    readFromFile(strings);
    writeResultsToFile(strings);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}