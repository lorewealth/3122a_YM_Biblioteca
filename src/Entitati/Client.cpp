#include "Client.h"

Client::Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const Status& status) 
    : Persoana(nume, prenume, dataNasterii, status){};

std::string Client::afisarea() {
    return "Client: " + nume + " " + prenume;
}