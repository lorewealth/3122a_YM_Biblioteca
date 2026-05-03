#include "Carte.h"
#include <iostream>
#include <unordered_map>
#include "Persoane.h"
#include "BazaDeDate.h"
#include <random>
#include <string>

#pragma once


class Biblioteca{
private:
     std::unordered_map<std::string, Carte*> Cartile;
     std::unordered_map<std::string, Persoana*> Utilizatorii;
     std::unordered_map<std::string, std::vector<Imprumut>> Imprumuturi;
     BazaDeDate *db;
     Persoana *utilizator;
public:
    Biblioteca(BazaDeDate *db);
    ~Biblioteca();
    bool adaugaUtilizator(const std::string& username, const std::string& parola, const std::string& nume, const std::string& prenume, const std::string& dataDeNastere, const std::string& status, double salariu);
    bool existaUtilizator(const std::string& username);
    bool verificLoginare(const std::string& username, const std::string& parola);
    Persoana* getPersoana(const std::string& username);
    
    bool adaugaCarte(Carte* carte);
    std::string creazaISBN();
    std::unordered_map<std::string, Carte*>& getCartile();
    std::vector<Imprumut>& getImprumuturi(const std::string& username);
    bool stergeCarte(const std::string& isbn);
    void afisareaCartilor();
    void afisareaUtilizatorilor();
    void afisareaImprumuturilor(const std::string& username);
    void afisareaImprumuturilor();
    void incarcaCartileDinBD();
    void incarcaUtilizatoriiDinBD();
    void reseteazaCartileMemorie();
    void incarcaImprumuturileDinBD();
    bool imprumutaCarte(const std::string& username, const std::string& isbn);
    bool esteImprumutata(const std::string& isbn);
    bool returneazaCarte(const std::string& username, const std::string& isbn);
};
