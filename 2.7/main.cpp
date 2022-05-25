#include "mth/MathUtils.hpp"

int main() {
    Matrix A(3, 3);
    std::cin >> A;

    Matrix B(3, 3);
    std::cin >> B;

    Matrix C(3, 3);

    C = A * B;
    std::cout << C << std::endl;

    C = A - B;
    std::cout << C << std::endl;

    std::cout << A.determinant() << std::endl;
    std::cout << A.inverse() << std::endl;
    std::cout << A.transposition() << std::endl;
    return 0;
}