#include "Biblioteca.h"

Biblioteca::Biblioteca(BazaDeDate *db):db(db){};

void Biblioteca::addCarte(std::unique_ptr<Carte> carte) {}

const std::unordered_map<std::string, std::unique_ptr<Carte>>& Biblioteca::getCartile() const {
    return Cartile;
}

void Biblioteca::stergeCarte(const std::string& isbn) {}

void Biblioteca::editeazaCarte(const std::string& isbn) {}

Biblioteca::~Biblioteca() {}

