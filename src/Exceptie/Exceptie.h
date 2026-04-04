#include <iostream>

class Exceptie{
private:
    std::string locul;
    std::string error;
public:
    Exceptie(const std::string& locul, const std::string& error);
    ~Exceptie() = default;
    const std::string afisare() const;
};
