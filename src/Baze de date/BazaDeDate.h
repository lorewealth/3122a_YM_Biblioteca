#pragma once
#include <string>
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Criptare.h"
#include "Persoane.h"

// struct InfoCarte {
//     int id;
//     std::string titlu;
//     std::string autor;
//     std::string isbn;
//     int anul;
// };

class BazaDeDate {
private:
    static SQLite::Database db;
    void creeazaTabeluri();

public:
    BazaDeDate(const std::string& fisier);

    // Utilizatori
    void adaugaUtilizator(const std::string& username, const std::string& parola, const std::string& nume, const std::string& prenume, const std::string& rol, double salariu);
    bool existaUtilizator(const std::string& username);
    std::string verificLoginare(const std::string& username, const std::string& parola);
    Persoana* getPersoana(const std::string& username);

    // Carti
    void adaugaCarte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul);
    bool stergeCarte(int id);
};
