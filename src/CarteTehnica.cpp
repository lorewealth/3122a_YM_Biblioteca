#include "CarteTehnica.h"

CarteTehnica::CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& isbn, const std::string& domeniu) : Carte(titlu, autor, isbn), domeniu(domeniu){};

void CarteTehnica::afisare(std::ostream& c) const{
    c << "Titlu: " << this->titlu << " | Autor: " + this->autor + " | Domeniu: " + this->domeniu << " | ISBN: " << this->isbn << '\n';
}

const std::string& CarteTehnica::getDomeniu(){
    return domeniu;
}