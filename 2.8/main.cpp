#include <iostream>
#include <cassert>
#include "mth/MathUtils.hpp"
using mt::math::Mat22d;
using mt::math::Vec2d;
int main() {
    std::cout << "=== Test 1 * ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        Vec2d X({ {
                          {1},
                          {1}
                  } });

        auto B = A * X;

        assert(B.get(0, 0) == 3);
        assert(B.get(1, 0) == 7);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 2 + ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {8,1}
                   } });

        Mat22d X({ {
                          {1,1},
                          {1,1}
                  } });

        auto B = A + X;
        assert(B.get(0, 0) == 2);
        assert(B.get(1, 0) == 9);
        assert(B.get(0, 1) == 3);
        assert(B.get(1, 1) == 2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 3 - ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {8,1}
                   } });

        Mat22d X({ {
                          {1,3},
                          {2,5}
                  } });

        auto B = A - X;
        assert(B.get(0, 0) == 0);
        assert(B.get(1, 0) == 6);
        assert(B.get(0, 1) == -1);
        assert(B.get(1, 1) == -4);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 4 Transposition ===" << std::endl;
    {
        Mat22d A({ {
                           {1,8},
                           {6,4}
                   } });

        auto B = A.transposition();
        assert(B.get(0, 1) == 6);
        assert(B.get(1, 0) == 8);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 5 Determinant ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        auto B = A.determinant();
        assert(B == -2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 6 Inverse ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        auto B = A.inverse();
        assert(B.get(0, 0) == -2);
        assert(B.get(0, 1) == 1);
    }
    std::cout << "Done!" << std::endl;
    return 0;
}