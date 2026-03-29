#include "Carte.h"
#include <iostream>
#include <vector>

class Biblioteca{
private:
     std::vector<Carte*> Cartile;
public:
    Biblioteca();
    ~Biblioteca();
    void addCarte(Carte* carte);
    const std::vector<Carte*>& getCartile() const;
    int getNextId();
    void stergeCarte(int id);
};
