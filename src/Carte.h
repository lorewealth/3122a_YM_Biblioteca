#include <iostream>

class Carte{
protected:
    std::string titlu;
    std::string autor;
    std::string isbn;
public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& isbn);
    virtual ~Carte() = default;
    virtual void afisare(std::ostream& c) const = 0;
    const std::string& getTitlu();
    const std::string& getAutor();
    const std::string& getISBN();
    void setTitlu();
    void setAutor();
    void setISBN();
    friend std::ostream& operator<<(std::ostream& c, const Carte& carte); 
    friend std::ostream& operator<<(std::ostream& c, const Carte* carte); 

};