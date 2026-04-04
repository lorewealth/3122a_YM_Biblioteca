#include "Persoane.h"
#include <string>

Persoana::Persoana(const std::string& nume, const std::string& prenume,
                   const std::string&dataNasterii, const std::string& dataDecis)
                   : nume(nume), prenume(prenume), dataNasterii(dataNasterii), dataDecis(dataDecis){};

std::string Persoana::afisarea()
{
    return "Nume: " + nume + " Prenume: " + prenume;
}
