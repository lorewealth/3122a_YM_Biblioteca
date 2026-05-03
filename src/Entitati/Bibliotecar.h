#include "Persoane.h"

class Bibliotecar : public Persoana {
private:
    double salariu;
public:
    Bibliotecar(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status, double salariu);
    ~Bibliotecar() = default;
    std::string afisare() override;
    double getSalariu();
};