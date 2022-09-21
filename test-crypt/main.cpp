#include "ecc.h"

int main() {
    FieldElement a(2, 19);
    FieldElement b(7, 19);
    std::cout << (a / &b).getNumberFieldElement();
}
