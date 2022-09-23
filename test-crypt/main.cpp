#include "ecc.h"

int main() {
    auto a  = Point(std::make_pair(true, 2), std::make_pair(true, 5), 5, 7);
    auto b = Point(std::make_pair(true, -1), std::make_pair(true, -1), 5 ,7);
    auto c = a + &b;
    std::cout << c.getXCoordinate() << " " << c.getYCoordinate() << std::endl;
    std::cout << c.getACoefficient() << " " << c.getBCoefficient() << std::endl;
}
