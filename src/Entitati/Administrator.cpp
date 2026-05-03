#include "Administrator.h"

Administrator::Administrator(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status, double salariu)
    : Persoana(nume, prenume, dataNasterii, username, status), salariu(salariu) {}

std::string Administrator::afisare() {
    return "Administrator: " + nume + " " + prenume + " (Salariu: " + std::to_string(salariu) + ")";
}

double Administrator::getSalariu() {
    return salariu;
}
