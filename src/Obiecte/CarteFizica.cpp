#include "CarteFizica.h"

CarteFizica::CarteFizica(const std::string& titlu, const std::string& autor, const std::string& isbn,
                        int anul, const std::vector<std::string>& genre, const Tip& tip, int nrPagini, Stare stare)
                        : Carte(titlu, autor, isbn, anul, tip), genre(genre), nrPagini(nrPagini), stare(stare){};

std::string CarteFizica::afisare() const {
    std::string res = "Titlu: " + titlu + " | Autor: " + autor + " | ISBN: " + isbn + " | Anul: " + std::to_string(anul) + " | Pagini: " + std::to_string(nrPagini) + " | Genuri: ";
    for (const auto& g : genre) res += g + " ";
    return res;
}

const Stare& CarteFizica::getStare() {
    return stare;
}

const std::vector<std::string>& CarteFizica::getGenre() {
    return genre;
}

int CarteFizica::getNrPagini() const {
    return nrPagini;
}

std::string CarteFizica::getStareStr() const
{
    switch (stare)
    {
    case Stare::Buna:
        return "Buna";
    case Stare::Normala:
        return "Normala";
    case Stare::Rea:
        return "Rea";
    default:
        return "Inca necunoscut";
    }
}