#include "Persoane.h"
#include <string>

Persoana::Persoana(const std::string& nume, const std::string& prenume,
                   const std::string&dataNasterii,const std::string&username, const Status& status)
                   : nume(nume), prenume(prenume), dataNasterii(dataNasterii),username(username), status(status){};

std::string Persoana::afisare()
{
    return "Nume: " + nume + " Prenume: " + prenume;
}

std::string Persoana::getUsername() const { 
    return username;
}

std::string Persoana::getStatus() const {
    switch (status) {
        case Status::Client: return "Client";
        case Status::Bibliotecar: return "Bibliotecar";
        case Status::Administrator: return "Administrator";
    }
}
