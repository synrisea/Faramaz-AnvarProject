#include "combinations.h"

uint1024_t calculateCombinations(int total, int choose, const std::vector<uint1024_t>& factorials)
{
    if (total < choose)
    {
        return 1;
    }
    // +1 ���� ��������� �� ���������, ��� ��� ������ �����.

    return (factorials[total] / (factorials[choose] * factorials[total - choose])) + 1;
}