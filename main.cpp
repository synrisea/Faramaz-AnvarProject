#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

void calculateFactorials(int n, std::vector<uint1024_t>& factorials)
{
    factorials[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }
}

uint1024_t calculateCombinations(int total, int choose, const std::vector<uint1024_t>& factorials)
{
    if (total < choose)
    {
        return 1;
    }
    // +1 если учитывать ту подстроку, где нет данной буквы.

    return (factorials[total] / (factorials[choose] * factorials[total - choose])) + 1;
}

uint1024_t countGoodSubstrings(const std::string& s)
{
    std::unordered_map<char, int> charFrequency;

    int maxCount = 0;

    for (char c : s)
    {
        charFrequency[c]++;
    }

    for (const auto& entry : charFrequency)
    {
        if (entry.second > maxCount) maxCount = entry.second;
    }


    std::vector<uint1024_t> factorials(maxCount + 1);
    calculateFactorials(maxCount, factorials);

    uint1024_t finalResult = 0;

    for (int i = 1; i != maxCount + 1; i++)
    {

        uint1024_t result = 1;
        for (const auto& entry : charFrequency)
        {
            int total = entry.second;
            result *= calculateCombinations(total, i, factorials);
        }
        finalResult += result - 1;
        // Вычитаем 1 для исключения пустой подстроки
    }

    return finalResult % 1000000007;
}

int main() 
{
    std::string s1 = "aabb";
    std::cout << countGoodSubstrings(s1) << std::endl; // Ожидаемый вывод: 11

    std::string s2 = "leet";
    std::cout << countGoodSubstrings(s2) << std::endl; // Ожидаемый вывод: 12

    std::string s3 = "abcd";
    std::cout << countGoodSubstrings(s3) << std::endl; // Ожидаемый вывод: 15

    std::string s4 = "aaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s4) << std::endl; // Ожидаемый вывод: ?

    std::string s5 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s5) << std::endl; // Ожидаемый вывод: ?

    std::string s6 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::cout << countGoodSubstrings(s6) << std::endl; // Ожидаемый вывод: ?
    return 0;
}
