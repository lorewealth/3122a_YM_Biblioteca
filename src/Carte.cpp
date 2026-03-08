#include "Carte.h"

Carte::Carte(const std::string& titlu, const std::string& autor, const std::string& isbn){
    this->titlu = titlu;
    this->autor = autor;
    this->isbn = isbn;
}

std::ostream& operator<<(std::ostream& c, Carte carte){
    return (c << "Titlu: " << carte.titlu << " | Autor: " << carte.autor << " | ISBN: " << carte.isbn << '\n');
}