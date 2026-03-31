#include "CarteTehnica.h"
#include <string>

CarteTehnica::CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& domeniu) : Carte(titlu, autor, isbn, anul), domeniu(domeniu){};

std::string CarteTehnica::afisare() const{
    return std::to_string(id) + " | Titlu: " + this->titlu + " | Autor: " + this->autor + " | Domeniu: " + this->domeniu + " | Anul publicarii: " + std::to_string(this->anul) + " | ISBN: " + this->isbn + '\n';
}

const std::string& CarteTehnica::getDomeniu(){
    return domeniu;
}
