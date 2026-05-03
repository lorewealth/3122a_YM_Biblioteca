#include "Carte.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include "Persoane.h"
#include "BazaDeDate.h"

class Biblioteca{
private:
     std::unordered_map<std::string, std::unique_ptr<Carte>> Cartile;
     std::unordered_map<std::string, std::unique_ptr<Persoana>> Utilizatorii;
     BazaDeDate *db;
public:
    Biblioteca(BazaDeDate *db);
    ~Biblioteca();
    void addCarte(std::unique_ptr<Carte> carte);
    const std::unordered_map<std::string, std::unique_ptr<Carte>>& getCartile() const;
    void stergeCarte(const std::string& isbn);
    void editeazaCarte(const std::string& isbn);
};
