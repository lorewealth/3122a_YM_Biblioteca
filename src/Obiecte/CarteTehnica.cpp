#include "CarteTehnica.h"
#include <string>

CarteTehnica::CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& domeniu, const Tip& tip, int nrPagini, const Stare& stare) : CarteFizica(titlu, autor, isbn, anul, {}, tip, nrPagini, stare), domeniu(domeniu){};

std::string CarteTehnica::afisare() const{
    return "\nTitlu: " + titlu + "\nTip: " + getTipStr() + "\nAutor: " + autor + "\nDomeniu: " + domeniu + "\nAnul publicarii: " + std::to_string(anul) + "\nISBN: " + isbn + "\nStare: " + getStareStr(); 
}

const std::string& CarteTehnica::getDomeniu(){
    return domeniu;
}