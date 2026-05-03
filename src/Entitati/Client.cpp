#include "Client.h"

Client::Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status) 
    : Persoana(nume, prenume, dataNasterii, username, status){};

std::string Client::afisare() {
    return "Client: " + nume + " " + prenume;
}