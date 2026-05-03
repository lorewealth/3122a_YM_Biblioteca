#include "Persoane.h"
#include <string>

Persoana::Persoana(const std::string& nume, const std::string& prenume,
                   const std::string&dataNasterii, const Status& status)
                   : nume(nume), prenume(prenume), dataNasterii(dataNasterii), status(status){};

std::string Persoana::afisarea()
{
    return "Nume: " + nume + " Prenume: " + prenume;
}

std::string Persoana::getStatus() const {
    switch (status) {
        case Status::Client: return "Client";
        case Status::Bibliotecar: return "Bibliotecar";
        case Status::Administrator: return "Administrator";
    }
}
