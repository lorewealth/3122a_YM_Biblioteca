#include "CarteFictiune.h"
#include <string>

CarteFictiune::CarteFictiune(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::vector<std::string>& genre, const Tip& tip, int nrPagini, const Stare& stare) : CarteFizica(titlu, autor, isbn, anul, genre, tip, nrPagini, stare){};

const std::vector<std::string>& CarteFictiune::getGenre()
{
    return genre;
}

std::string CarteFictiune::afisare() const
{
    std::string genreStr = "[";
    for(int i = 0; i < genre.size(); i++)
    {
        if(i+1 != genre.size()) genreStr.append(genre[i] + ", ");
        else genreStr.append(genre[i]);
    }
    genreStr += "]";
    return "\nTitlu: " + titlu + "\nTip: " + getTipStr() + "\nAutor: " + autor + "\nAnul publicarii: " + std::to_string(anul) + "\nISBN: " + isbn + "\nStare: " + getStareStr() + "\nGenre: " + genreStr;
}
