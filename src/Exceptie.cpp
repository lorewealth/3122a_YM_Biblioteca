#include "Exceptie.h"

Exceptie::Exceptie(const std::string& locul, const std::string& error) : locul(locul), error(error){};
std::string Exceptie::afisare()
{
    return "|ERROR| Unde: [" + locul + "]" + " - Cauza: " + error + '\n';
}
