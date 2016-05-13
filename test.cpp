#include <iostream>
#include "DSL.hpp"

int main() {
    std::cout << Olamani::DSL::getIntParameter("(value 10)", "value", 0) << std::endl;
    std::cout << Olamani::DSL::getDoubleParameter("(value 9.9)", "value", 0.0) << std::endl;
    std::cout << Olamani::DSL::getStringParamenter("(value hello)", "value", "not found") << std::endl;
    return 0;
}
