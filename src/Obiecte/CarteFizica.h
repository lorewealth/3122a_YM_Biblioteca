#include "Carte.h"
#include <string>
#include <vector>

#pragma once

class CarteFizica : public Carte
{
protected:
    std::vector<std::string> genre = {};
    int nrPagini;
    Stare stare;
public:
    CarteFizica(const std::string& titlu, const std::string& autor, const std::string& isbn,
                int anul, const std::vector<std::string>& genre, const Tip& tip, int nrPagini, Stare stare);
    std::string afisare() const override;
    virtual const Stare& getStare();
    virtual std::string getStareStr() const;
    virtual const std::vector<std::string>& getGenre();
    int getNrPagini() const;
};
