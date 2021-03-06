#include <iostream>
#include <iterator>
#include <numeric>

#include <array>
#include <vector>
#include <list>
#include <map>

#include "stdrv/transform.h"

int main()
{
    const auto int2int = [](const int e) { return e * 2; };
    const auto int2intxint = [](const int e) { return std::make_pair(e, e * 2); };
    {
        const std::array<int, 6> x{ 1, 9, 8, 6, 7, 22 };
        const auto vector
            = stdrv::transform<std::vector>(x, int2int);
        const auto list
            = stdrv::transform<std::list>(x, int2int);
        const auto map
            = stdrv::transform<std::map>(x, int2intxint);
    }

    {
        const std::vector<int> x{ 1, 9, 8, 6, 12, 14 };
        const auto vector
            = stdrv::transform<std::vector>(x, int2int);
        const auto list
            = stdrv::transform<std::list>(x, int2int);
        const auto map
            = stdrv::transform<std::map>(x, int2intxint);
    }

    const auto intxint2int = [](const int e0, const int e1) { return e0 + e1; };
    const auto intxint2intxint = [](const int e0, const int e1) { return std::make_pair(e0, e1); };
    {
        const std::vector<int> x{ 2, 0, 1, 3, 6, 1 };
        const std::vector<int> y{ 2, 0, 1, 8, 7, 5 };
        const auto vector
            = stdrv::transform<std::vector>(x, y, intxint2int);
        const auto list
            = stdrv::transform<std::list>(x, y, intxint2int);
        const auto map
            = stdrv::transform<std::map>(x, y, intxint2intxint);
    }

    return 0;
}
