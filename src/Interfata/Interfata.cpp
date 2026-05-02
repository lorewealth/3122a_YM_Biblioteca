#include "Interfata.h"

void Interfata::Intro()
{
    std::string optiunea;
    do
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~Biblioteca~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\nSelectati metoda de a intra in sistema bibliotecii:";
        std::cout << "\nl. Log in:";
        std::cout << "\ni. Inregistrarea";
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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
    std::string username, parola;
    system("clear");
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~Log in~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Introdu username-ul tau: ";
    std::cin >> username;
    std::cout << "Introdu parola ta: ";
    std::cin >> parola;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Interfata::Registrarea()
{

}
