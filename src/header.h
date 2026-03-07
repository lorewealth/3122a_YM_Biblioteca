#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

class Test{
private:
    int units = 0;
    std::string name;
public:
    Test(int units, const std::string& name);
    ~Test();
    const std::string& getName();
    int getUnits();

};

#endif // HEADER_H_INCLUDED