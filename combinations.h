#pragma once
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using namespace boost::multiprecision;

uint1024_t calculateCombinations(int total, int choose, const std::vector<uint1024_t>& factorials);
