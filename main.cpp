#include <iostream>
#include "countGoodStrings.h"

int main() 
{
    std::string s1 = "aabb";
    std::cout << countGoodSubstrings(s1) << std::endl; // ��������� �����: 11

    std::string s2 = "leet";
    std::cout << countGoodSubstrings(s2) << std::endl; // ��������� �����: 12

    std::string s3 = "abcd";
    std::cout << countGoodSubstrings(s3) << std::endl; // ��������� �����: 15

    std::string s4 = "aaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s4) << std::endl; // ��������� �����: ?

    std::string s5 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s5) << std::endl; // ��������� �����: ?

    std::string s6 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s6) << std::endl; // ��������� �����: ?
    return 0;
}
