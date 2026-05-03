#include "Carte.h"
#include <string>

Carte::Carte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const Tip& tip) : anul(anul), titlu(titlu), autor(autor), isbn(isbn), tip(tip){};

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
const Tip& Carte::getTip()
{
     return tip;
}

std::string Carte::getTipStr() const {
    switch (tip)
    {
    case Tip::Fictiune:
        return "Fictiune";
    case Tip::Tehnica:
        return "Tehnica";
    case Tip::Digitala:
        return "Digitala";
    case Tip::Audio:
        return "Audio";
    }
}

int Carte::getAnul() { return anul; }

void Carte::setAnul() {
    std::cout << "Setati noul an: ";
    std::cin >> anul;
}
