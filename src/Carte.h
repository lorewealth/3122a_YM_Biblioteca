#include <iostream>

class Carte{
private:
    std::string titlu;
    std::string autor;
    std::string isbn;
public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& isbn);
    virtual ~Carte() = default;
    const std::string& getTitlu() = 0; 
    const std::string& getAutor() = 0; 
    const std::string& getISBN() = 0; 
    friend std::ostream& operator<<(std::ostream& c, Carte carte); 

};