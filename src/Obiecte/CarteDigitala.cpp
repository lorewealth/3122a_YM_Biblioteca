#include "CarteDigitala.h"

CarteDigitala::CarteDigitala(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& format, const Tip& tip, double marime)
    : Carte(titlu, autor, isbn, anul, tip), format(format), marime(marime) {}

std::string CarteDigitala::afisare() const {
    return "\nTitlu: " + titlu + "\nTip: " + getTipStr() + "\nAutor: " + autor + "\nFormat: " + format + "\nMarime: " + std::to_string(marime) + "MB\nAnul: " + std::to_string(anul) + "\nISBN: " + isbn;
}

const std::string& CarteDigitala::getFormat() const {
    return format;
}

double CarteDigitala::getMarime() const {
    return marime;
}
