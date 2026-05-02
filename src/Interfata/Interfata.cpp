#include "Interfata.h"
#include <string>

void Interfata::Initializarea()
{
    std::string optiunea;
    do
    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~Biblioteca~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Selectati metoda de a intra in sistema bibliotecii:";
        std::cout << "l. Log in:";
        std::cout << "i. Inregistrarea";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Selectati: ";

        std::cin >> optiunea;
    }
    while(optiunea[0] != 'l' && optiunea[0] != 'i');

    switch (optiunea[0])
    {
        case 'l':
            Login();
            break;
        case 'i':
            Registrarea();
            break;
        default:
            break;
    }

}

void Interfata::Login()
{

}

void Interfata::Registrarea()
{
    std::string username;
    std::string parola;
    std::string nume;
    std::string prenume;


    system("clear");
    std::cout << "~~~~~~~~~~~~~~~~~~~Registrarea~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Username: ";
    std::cin >> username;
    if()
    std::cout << "Parola: ";
    std::cin >> parola;
    std::cout << "Nume: ";
    std:
}
