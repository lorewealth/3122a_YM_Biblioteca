#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Stare
{
    Buna,
    Normala,
    Rea
};

enum class Tip
{
    Fictiune,
    Tehnica,
    Digitala,
    Audio,
};

class Carte{
protected:
    int anul;
    std::string titlu;
    std::string autor;
    std::string isbn;
    Tip tip;
public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const Tip& tip);
    virtual ~Carte() = default;
    virtual std::string afisare() const = 0;
    const std::string& getTitlu();
    const std::string& getAutor();
    const std::string& getISBN();
    const Tip& getTip();
    virtual std::string getTipStr() const;
    void setTitlu();
    void setAutor();
    void setISBN();
    int getAnul();
    void setAnul();
};
