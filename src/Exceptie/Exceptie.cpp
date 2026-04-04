#include "Exceptie.h"

Exceptie::Exceptie(const std::string& locul, const std::string& error) : locul(locul), error(error){};
const std::string Exceptie::afisare() const
{
    return "|ERROR| Unde: [" + locul + "]" + " - Cauza: " + error + '\n';
}
