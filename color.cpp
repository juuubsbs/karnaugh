#include <iostream>

int main() {

    std::cout << "\e[0;32mmisses beautiful cyan.\e[0m" << std::endl;

    std::cout << "\e[44mThis text is blue.\e[0m" << std::endl;

    system("pause");

    return 0;
}