#include "Carte.h"

class CarteTehnica : public Carte{
private:
    std::string domeniu;
public:
    CarteTehnica(const std::string& titlu, const std::string& autor, const std::string& ISBN, int anul, const std::string& domeniu);
    std::string afisare() const override;
    const std::string& getDomeniu();
};
