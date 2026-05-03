#include "CarteFizica.h"

#pragma once

class CarteTehnica : public CarteFizica{
private:
    std::string domeniu;
public:
    CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& ISBN, int anul, const std::string& domeniu, const Tip& tip, int nrPagini, const Stare& stare);
    std::string afisare() const override;
    const std::string& getDomeniu();
};
