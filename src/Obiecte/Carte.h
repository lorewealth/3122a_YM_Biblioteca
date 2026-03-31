#pragma once
#include <iostream>
#include <string>

class Carte{
protected:
    int id;
    int anul;
    std::string titlu;
    std::string autor;
    std::string isbn;
public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul);
    virtual ~Carte() = default;
    virtual std::string afisare() const = 0;
    int getId();
    const std::string& getTitlu();
    const std::string& getAutor();
    const std::string& getISBN();
    void setTitlu();
    void setAutor();
    void setISBN();
    void setId(int id);
    int getAnul();
    void setAnul();
};
