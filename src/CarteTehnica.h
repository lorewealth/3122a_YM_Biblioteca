#include "Carte.h"

class CarteTehnica : public Carte{
private:
    std::string domeniu;
public:
    CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& ISBN, const std::string& domeniu);
    void afisare(std::ostream& c) const override;
    const std::string& getDomeniu();
};