#include "CarteFictiune.h"
#include <string>

CarteFictiune::CarteFictiune(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::vector<std::string>& genre) : Carte(titlu, autor, isbn, anul), genre(genre){};

std::vector<std::string> CarteFictiune::getGenre()
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
    return std::to_string(id) + " | Titlu: " + this->titlu + " | Autor: " + this->autor + " | Anul publicarii: " + std::to_string(this->anul) + " | ISBN: " + this->isbn + " | Genre: " + genreStr + '\n';
}
