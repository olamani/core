#include <iostream>
#include "DSL.hpp"

int main() {
    std::cout << Olamani::DSL::getIntParameter("value", "(value 10)") << std::endl;
    return 0;
}
