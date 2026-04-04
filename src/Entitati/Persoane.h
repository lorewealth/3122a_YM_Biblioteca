#include <string>

class Persoana
{
protected:
    std::string nume;
    std::string prenume;
    std::string dataNasterii;
    std::string dataDecis;

public:
    Persoana(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& dataDecis);
    ~Persoana() = default;
    virtual std::string afisarea();
    std::string getNume();
    std::string getPrenume();
    std::string getDataNasterii();
    std::string getDataDecis();
};
