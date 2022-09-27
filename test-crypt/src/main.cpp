#include "../include/ecc.h"

int main() {
    auto a = FieldElement(0, 223);
    auto b = FieldElement(7, 223);

    auto x = FieldElement(143, 223);
    auto y = FieldElement(98, 223);
    auto x2 = FieldElement(76, 223);
    auto y2 = FieldElement(66, 223);

    auto p1 = Point(x, y, a, b);
    auto p2 = Point(x2, y2, a, b);
    auto c = p1 + p2;

    std::cout << (p1 + p2).getX()->getNumberFieldElement() << " " << (p1 + p2).getY()->getNumberFieldElement();
}
