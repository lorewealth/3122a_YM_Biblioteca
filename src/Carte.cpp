#include "Carte.h"

Carte::Carte(const std::string& titlu, const std::string& autor, const std::string& isbn) : titlu(titlu), autor(autor), isbn(isbn){};

std::ostream& operator<<(std::ostream& c, const Carte& car){
    car.afisare(c);
    return c;
}
std::ostream& operator<<(std::ostream& c, const Carte* car){
    car != nullptr ? c << *car : c << "obiect nu este initializat!\n";
    return c;
}

const std::string& Carte::getTitlu(){ return titlu; }
const std::string& Carte::getAutor(){ return autor; }
const std::string& Carte::getISBN(){ return isbn; }

void Carte::setTitlu(){
    std::cout << "Setati un nou titlu: ";
    std::cin >> titlu;
}
void Carte::setAutor(){
    std::cout << "Setati un nou autor: ";
    std::cin >> autor;
}
void Carte::setISBN(){
    std::cout << "Setati un nou ISBN: ";
    std::getLine std::cin >> isbn;
}