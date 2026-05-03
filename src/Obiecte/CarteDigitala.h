#pragma once
#include "Carte.h"

#pragma once

class CarteDigitala : public Carte {
private:
    std::string format;
    double marime;
public:
    CarteDigitala(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& format, const Tip& tip, double marime);
    std::string afisare() const override;
    const std::string& getFormat() const;
    double getMarime() const;
};
