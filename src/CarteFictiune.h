#include "Carte.h"
#include <string>
#include <vector>

class CarteFictiune : public Carte{
private:
    std::vector<std::string> genre;
public:
    CarteFictiune(const std::string& titlu, const std::string& autor, const std::string& isbn, int anul, const std::vector<std::string>& genre);
    std::string afisare() const override;
    std::vector<std::string> getGenre();
};
