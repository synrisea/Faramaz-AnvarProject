#include "factorials.h"

void calculateFactorials(int n, std::vector<uint1024_t>& factorials)
{
    factorials[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }
}