#include "Carte.h"
#include <string>

Carte::Carte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul) : titlu(titlu), autor(autor), isbn(isbn), anul(anul){};

const std::string& Carte::getTitlu(){ return titlu; }
const std::string& Carte::getAutor(){ return autor; }
const std::string& Carte::getISBN(){ return isbn; }

void Carte::setTitlu()
{
    std::cout << "Setati un nou titlu: ";
    std::cin >> titlu;
}
void Carte::setAutor()
{
    std::cout << "Setati un nou autor: ";
    std::cin >> autor;
}
void Carte::setISBN()
{
    std::cout << "Setati un nou ISBN: ";
    std::getline(std::cin >> std::ws, isbn);
}
void Carte::setId(int id)
{
    this->id = id;
}
int Carte::getId()
{
    return id;
}
