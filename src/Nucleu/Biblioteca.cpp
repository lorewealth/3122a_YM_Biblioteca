#include "Biblioteca.h"

Biblioteca::Biblioteca(){};
int Biblioteca::getNextId()
{
    if(Cartile.size() == 0) return 1;
    return Cartile.size() + 1;
}
void Biblioteca::addCarte(Carte* carte)
{
    carte->setId(getNextId());
    Cartile.push_back(carte);
}
void Biblioteca::stergeCarte(int id)
{
    for(int i = 0; i < Cartile.size(); i++)
    {
        if(Cartile[i]->getId() == id)
        {
            delete Cartile[i];
            Cartile.erase(Cartile.begin() + i);
            break;
        }
    }
}

const std::vector<Carte*>& Biblioteca::getCartile() const
{
    return Cartile;
}

Biblioteca::~Biblioteca()
{
    for(auto Carte : Cartile)
    {
        delete Carte;
    }
}
