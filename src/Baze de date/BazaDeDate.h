#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Criptare.h"
#include "Client.h"
#include "Bibliotecar.h"
#include "Administrator.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "CarteDigitala.h"
#include "CarteAudio.h"
#include "Utilitati.h"
#include "Carte.h"

struct Imprumut {
    std::string titlu;
    std::string ISBN;
    std::string dataDeImprumut;
    std::string dataReturnare;
};

class BazaDeDate {
private:
    SQLite::Database db;
    void creeazaTabeluri();

public:
    BazaDeDate(const std::string& fisier);

    void adaugaUtilizator(const std::string& username, const std::string& parola, const std::string& nume, const std::string& prenume, const std::string& dataDeNastere, const std::string& status, double salariu);
    bool existaUtilizator(const std::string& username);
    bool verificLoginare(const std::string& username, const std::string& parola);
    Persoana* getPersoana(const std::string& username);

    int adaugaCarte(Carte* carte);
    int stergeCarte(const std::string& isbn);
    bool verificaISBN(const std::string& isbn);
    std::unordered_map<std::string, Carte*> IncarcaCartileDinBD();
    std::unordered_map<std::string, Persoana*> IncarcaUtilizatoriiDinBD();
    std::unordered_map<std::string, std::vector<Imprumut>> IncarcaImprumuturileDinBD();
    bool imprumutaCarte(const std::string& username, const std::string& isbn);
    bool esteImprumutata(const std::string& isbn);
    bool returneazaCarte(const std::string& username, const std::string& isbn);
};  
