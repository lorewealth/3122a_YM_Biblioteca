#include "Bibliotecar.h"

Bibliotecar::Bibliotecar(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status, double salariu)
    : Persoana(nume, prenume, dataNasterii, username, status), salariu(salariu) {}

std::string Bibliotecar::afisare() {
    return "Bibliotecar: " + nume + " " + prenume + " (Salariu: " + std::to_string(salariu) + ")";
}

double Bibliotecar::getSalariu() {
    return salariu;
}
