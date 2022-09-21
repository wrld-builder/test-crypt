#include "ecc.h"
#include <bitset>

int main() {
    std::cout << sizeof(0) << std::endl;
    std::cout << sizeof(NULL) << std::endl;
    std::cout << sizeof(nullptr) << std::endl;
    std::cout << sizeof(std::bitset<0>) << std::endl;
    //std::cout << sizeof(std::optional) << std::endl;
}
