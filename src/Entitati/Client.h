#include "Persoane.h"
#include "Carte.h"
#include <vector>

class Client : public Persoana
{
private:
    std::vector<Carte*> listaDeCartiImprumutate;
public:
    Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const Status& status);
    ~Client() = default;
    std::string afisarea() override;
};
