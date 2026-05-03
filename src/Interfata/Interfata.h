#include <iostream>
#include <memory>
#include "BazaDeDate.h"
#include "Utilitati.h"

class Interfata{
private:
    inline static std::string username;
    inline static std::string parola;
    BazaDeDate *db;
    std::unique_ptr<Persoana> utilizator;
public:
    Interfata(BazaDeDate *db);
    ~Interfata() = default;
    void IInitializarea();
    void ILogin();
    void IRegistrarea();
    void IClient();
    void IBibliotecar();
    void IAdministrator();
    void ILogOut();
    void IAfisareImprumuturi();
    void IAfisareUtilizatori();
    void IAdaugareCarte();
    void IStergereCarte();
    void IPromovareUtilizator();
    void IDemovareUtilizator();
    void IStergereUtilizator();
};
