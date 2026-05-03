#include <iostream>
#include "Utilitati.h"
#include "CarteFizica.h"
#include "Biblioteca.h"

class Interfata{
private:
    inline static std::string username;
    inline static std::string parola;
    Persoana* utilizator;
    Biblioteca* biblioteca;
public:
    Interfata(Biblioteca *biblioteca);
    ~Interfata() = default;
    void IInitializarea();
    void ILogin();
    void IRegistrarea();
    void IClient();
    void IBibliotecar();
    void IAdministrator();
    void ILogOut();
    void IMeniu();

    void IAfisareImprumuturi();
    void IAfisareUtilizatori();
    void IAfisareaCartilor();
    void IAdaugareCarte();
    void IStergereCarte();
    
    void IPromovareUtilizator();
    void IDemovareUtilizator();
    void IStergereUtilizator();
    void IImprumutaCarte();
    void IReturneazaCarte();
};
