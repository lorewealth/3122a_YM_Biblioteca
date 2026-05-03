#pragma once
#include <string>
#include <vector>
#include <memory>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Criptare.h"
#include "Client.h"
#include "Bibliotecar.h"
#include "Administrator.h"


class BazaDeDate {
private:
    SQLite::Database db;
    void creeazaTabeluri();

public:
    BazaDeDate(const std::string& fisier);

    // Utilizatori
    void adaugaUtilizator(const std::string& username, const std::string& parola, const std::string& nume, const std::string& prenume, const std::string& dataDeNastere, const std::string& status, double salariu);
    bool existaUtilizator(const std::string& username);
    bool verificLoginare(const std::string& username, const std::string& parola);
    std::unique_ptr<Persoana> getPersoana(const std::string& username);

    // Carti
    void adaugaCarte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul);
    bool stergeCarte(int id);
};
