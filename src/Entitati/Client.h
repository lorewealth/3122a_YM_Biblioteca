#include "Persoane.h"
#include "Carte.h"
#include <vector>

class Client : public Persoana
{
private:
public:
    Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status);
    ~Client() = default;
    std::string afisare() override;
};
