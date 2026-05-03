#pragma once
#include "Carte.h"

class CarteAudio : public Carte {
private:
    std::string format;
    double durata;
public:
    CarteAudio(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& format, const Tip& tip, double durata);
    std::string afisare() const override;
    const std::string& getFormat() const;
    double getDurata() const;
};
