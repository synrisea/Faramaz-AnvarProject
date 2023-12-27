#include "countGoodStrings.h"
#include <unordered_map>
#include "factorials.h"
#include "combinations.h"

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