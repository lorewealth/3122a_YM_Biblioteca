#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "Exceptie.h"
#include "Persoane.h"
#include "Interfata.h"
#include <string>
#include <iostream>

/*
 *   Carte* CitireaCarte();
 * Carte* carte1 = new CarteTehnica("DEEA2", "Test", "----?---?", 2000, "Inginerie Electronica");
*/
int main()
{
    try
    {
        Interfata interfata(1680, 700, "Biblioteca");
        if(interfata.initializarea() == -1) throw Exceptie("Initializarea interfatei", "Nu a fost initializat cu succes");
        interfata.ruleaza();
    }
    catch(const Exceptie& e)
    {
        e.afisare();
    }
    return 0;
}

Carte* CitireaCarte()
{
    char optiuneaChar;
    std::string optiuneaString;
    do
    {

        std::cout << "------------------Carte------------------\n";
        std::cout << "T. Tehnica\n";
        std::cout << "F. Fictiune\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Selectati: ";

        std::cin >> optiuneaString;
        if(optiuneaString.length() > 1) { return nullptr; }
        optiuneaChar = std::toupper(optiuneaString[0]);

    }
    while (optiuneaChar != 'F' && optiuneaChar != 'T');

    switch(optiuneaChar)
    {
        case 'T':
        {
            std::string titlu = "";
            std::string autor = "";
            std::string ISBN = "";
            std::string domeniu = "";
            int anul = 0;

            std::cout << "Titlu cartii: ";
            std::getline(std::cin >> std::ws, titlu);

            std::cout << "Autorul cartii: ";
            std::getline(std::cin >> std::ws, autor);

            std::cout << "Anul publicarii: ";
            std::cin >> anul;

            std::cout << "ISBN-ul cartii: ";
            std::getline(std::cin >> std::ws, ISBN);

            std::cout << "Din ce domeniu este carte: ";
            std::getline(std::cin >> std::ws, domeniu);

            return new CarteTehnica(titlu, autor, ISBN, anul, domeniu);
        }
        case 'F':
        {
            std::string titlu = "";
            std::string autor = "";
            std::string ISBN = "";
            int anul = 0;
            int nrDeGenre = 0;
            std::vector<std::string> genre;

            std::cout << "Titlu cartii: ";
            std::getline(std::cin >> std::ws, titlu);

            std::cout << "Autorul cartii: ";
            std::getline(std::cin >> std::ws, autor);

            std::cout << "ISBN-ul cartii: ";
            std::getline(std::cin >> std::ws, ISBN);

            std::cout << "Anul publicarii: ";
            std::cin >> anul;

            std::cout << "Cate genre vreti sa adaugati: ";
            std::cin >> nrDeGenre;

            std::string genrul;
            for(int i = 0; i < nrDeGenre; i++)
            {
                std::cout << "Genrul[" << i + 1 << "]: ";
                std::getline(std::cin >> std::ws, genrul);
                genre.push_back(genrul);
            }

            return new CarteFictiune(titlu, autor, ISBN, anul, genre);
        }
        default:
            std::cout << "Nu ati selectat optiunea valida\n";
            break;
    }
    return nullptr;
}

//Temporar mutat
void mutat_()
{
    // char optiuneaChar;
    // std::string optiuneaString;
    // Biblioteca biblioteca;
    // Carte* carte = nullptr;
    // Persoana pers("Ion", "Ionescu", "04.04.2000", "---");
    // // std::cout << pers.afisarea();

    // do
    // {
    //     try{

    //         std::cout << "------------MENU------------\n";
    //         std::cout << "C. Citirea cartei\n";
    //         std::cout << "A. Afisarea cartei introduse\n";
    //         std::cout << "S. Salvarea cartii\n";
    //         std::cout << "D. Stergerea cartii\n";
    //         std::cout << "L. Afisarea cartilor\n";
    //         std::cout << "U. Introducerea utilizator(WIP)\n";
    //         std::cout << "X. Terminarea aplicatiei\n";
    //         std::cout << "----------------------------\n";

    //         std::cout << "Selectati: ";
    //         std::cin >> optiuneaString;

    //         if(optiuneaString.length() > 1)
    //         {
    //             throw Exceptie("Selectarea optiunei din meniu" ,"Optiunea selectata are o lungime mare\n");
    //         }

    //         optiuneaChar = std::toupper(optiuneaString[0]);

    //         switch(optiuneaChar)
    //         {
    //             case 'C':
    //                 carte = CitireaCarte();
    //                 break;
    //             case 'A':
    //                 if(carte == nullptr) throw Exceptie("Afisarea cartei" ,"Nu ati citit cartea");

    //                 std::cout << carte->afisare();
    //                 break;
    //             case 'S':
    //                 if(carte == nullptr) throw Exceptie("Salvarea cartei" ,"Nu ati introdus o noua carte!");

    //                 biblioteca.addCarte(carte);
    //                 std::cout << "Cartea a fost salvata\n";

    //                 carte = nullptr;
    //                 break;
    //             case 'D':
    //             {
    //                 if(biblioteca.getCartile().size() == 0) throw Exceptie("Stergerea Cartii", "Nu ati introdus nici o carte in biblioteca");
    //                 int id = 0;

    //                 std::cout << "Introduceti id dupa care va fi cautat carte: ";
    //                 std::cin >> id;

    //                 biblioteca.stergeCarte(id);
    //                 std::cout << "Cartea a fost stersa cu succes\n";
    //                 break;
    //             }
    //             case 'L':
    //                 if(biblioteca.getCartile().size() == 0) throw Exceptie("Afisarea Listei", "Nu ati initializat lista");

    //                 for(auto carte : biblioteca.getCartile())
    //                 {
    //                     std::cout << carte->afisare();
    //                 }
    //                 break;
    //             case 'X':
    //                 std::cout << "Iesirea din aplicatie...\n";
    //                 delete carte;
    //                 break;
    //             default:
    //                 std::cout << "Nu ati selectat optiunea valida\n";
    //                 break;
    //         }
    //     }
    //     catch(Exceptie e)
    //     {
    //         std::cerr << e.afisare();
    //     }
    //     catch(...)
    //     {
    //         std::cerr << "Un error neinitializat\n";
    //     }
    // }
    // while (optiuneaChar != 'X');
}
