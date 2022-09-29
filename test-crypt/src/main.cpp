#include "../include/ecc.h"

int main() {
    auto a = FieldElement(0, 223);
    auto b = FieldElement(7, 223);

    auto x = FieldElement(15, 223);
    auto y = FieldElement(86, 223);
    auto y1 = FieldElement(23, 223);

    auto p = Point(&x, &y, a, b);
    auto inf = Point(nullptr, nullptr, a, b);
    auto product = p;

    int count = 1;
    while(product != inf) {
        product = product + p;
        count++;
    }
    std::cout << count << std::endl;
}
