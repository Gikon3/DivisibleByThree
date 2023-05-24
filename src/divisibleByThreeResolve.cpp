#include <algorithm>
#include "divisibleByThreeResolve.h"

long divisibleByThreeResolve(const std::vector<int>& m)
{
    long count[3] = { 0, 0, 0 };
    for (const auto& val : m)
        ++count[val % 3];

    const long max = std::min(count[1], count[2]);
    count[1] -= max;
    count[2] -= max;

    return count[0] + max + count[1] / 3 + count[2] / 3;
}