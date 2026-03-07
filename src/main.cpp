#include "header.h"

int main(){

    std::cout << "Hello, World!\n";
    Test t1(30, "He");
    std::cout << t1.getName() << ' ' << t1.getUnits() << '\n';

    return 0;
}