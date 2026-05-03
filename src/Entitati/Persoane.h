#include <string>
#include <vector>

#pragma once

enum class Status { Client, Bibliotecar, Administrator};

class Persoana
{
protected:
    std::string nume;
    std::string prenume;
    std::string dataNasterii;
    std::string username;
    Status status;
public:
    Persoana(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::string& username, const Status& status);
    virtual ~Persoana() = default;
    virtual std::string afisare();
    std::string getNume() const { return nume; }
    std::string getPrenume() const { return prenume; }
    std::string getDataNasterii() const { return dataNasterii; }
    std::string getStatus() const;
    std::string getUsername() const;
};
