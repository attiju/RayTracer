#include <iostream>

#include "core/transform.hpp"
#include "core/ray.hpp"

int main()
{
    auto T = rotateY(45) * translate({10, 0, 0});
    auto r = Ray();

    std::cout << r << std::endl;
    std::cout << T(r) << std::endl;

    return 0;
}
