#include "Criptare.h"

std::string Criptare::criptare(const std::string& text) {
    std::string criptat = text;
    for(char& c : criptat){
        c += 3;
    }
    return criptat;
}

std::string Criptare::decriptare(const std::string& text) {
    std::string decriptat = text;
    for(char& c : decriptat)
    {
        c -= 3;
    }

    return decriptat;
}
