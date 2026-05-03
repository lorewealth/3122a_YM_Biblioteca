#include "CarteFizica.h"
#include <string>
#include <vector>

#pragma once

class CarteFictiune : public CarteFizica
{
public:
    CarteFictiune(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::vector<std::string>& genre, const Tip& tip, int nrPagini, const Stare& stare);
    std::string afisare() const override;
    const std::vector<std::string>& getGenre() override;
};
