#include "Persoane.h"

class Administrator : public Persoana {
private:
    double salariu;
public:
    Administrator(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const Status& status, double salariu);
    ~Administrator() = default;
    std::string afisarea() override;
    double getSalariu();
};
