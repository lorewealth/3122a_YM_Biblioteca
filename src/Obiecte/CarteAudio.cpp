#include "CarteAudio.h"

CarteAudio::CarteAudio(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::string& format, const Tip& tip, double durata)
    : Carte(titlu, autor, isbn, anul, tip), format(format), durata(durata) {}

std::string CarteAudio::afisare() const {
    return "\nTitlu: " + titlu + "\nTip: Audio\nAutor: " + autor + "\nFormat: " + format + "\nDurata: " + std::to_string(durata) + " min\nAnul: " + std::to_string(anul) + "\nISBN: " + isbn;
}

const std::string& CarteAudio::getFormat() const {
    return format;
}

double CarteAudio::getDurata() const {
    return durata;
}
