#include "header.h"

Test::Test(int units, const std::string& name){
    this->units = units;
    this->name = name;
}
Test::~Test() = default;
const std::string& Test::getName(){
    return name;
}
int Test::getUnits(){
    return units;
}