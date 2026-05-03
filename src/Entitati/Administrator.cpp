#include "Administrator.h"

Administrator::Administrator(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const Status& status, double salariu)
    : Persoana(nume, prenume, dataNasterii, status), salariu(salariu) {}

std::string Administrator::afisarea() {
    return "Administrator: " + nume + " " + prenume + " (Salariu: " + std::to_string(salariu) + ")";
}

double Administrator::getSalariu() {
    return salariu;
}
