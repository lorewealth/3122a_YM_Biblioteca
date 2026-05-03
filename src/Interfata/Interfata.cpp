#include "Interfata.h"
#include <string>
#include <sstream>
#include <limits>
#include "CarteTehnica.h"
#include "CarteFictiune.h"
#include "CarteDigitala.h"
#include "CarteAudio.h"

Interfata::Interfata(Biblioteca *biblioteca) : biblioteca(biblioteca){};

void Interfata::IInitializarea()
{
    while (true)
    {
        Utilitati::curataConsola();
        std::cout << "~~~~~~~~~~~~~~~~~~~~Biblioteca~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Selectati metoda de a intra in sistema bibliotecii:\n";
        std::cout << "L. Log in\n";
        std::cout << "I. Inregistrarea\n";
        std::cout << "Q. Iesirea din sistem\n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Selectati: ";
        
        std::string optiune;
        std::cin >> optiune;
        char optVal = toupper(optiune[0]);
        switch (optVal)
        {
            case 'L':
                ILogin();
                break;
            case 'I':
                IRegistrarea();
                break;
            case 'Q':
                exit(0);
            default:
                break;
        }

        if (utilizator != nullptr)
        {
            IMeniu();
        }
    }
}

void Interfata::ILogin()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Logarea~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        std::cout << "Username: ";
        std::cin >> username;

        if (!Utilitati::esteUsernameValid(username))
            std::cout << "Username invalid! Folositi doar litere, cifre, '_' sau '-'.\n";
        else if (!biblioteca->existaUtilizator(username))
            std::cout << "Utilizatorul nu exista! Reintroduceti username-ul:\n";
        else break;
    }
    while(true);

    do
    {
        std::cout << "Parola: ";
        std::cin >> parola;
    
        if (!biblioteca->verificLoginare(username, parola))
            std::cout << "Parola invalida!\n";
        else break;
    }
    while(true);
        

    utilizator = biblioteca->getPersoana(username);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    biblioteca->incarcaCartileDinBD();
    biblioteca->incarcaImprumuturileDinBD();
    biblioteca->incarcaUtilizatoriiDinBD();
}

void Interfata::IRegistrarea()
{
    std::string nume;
    std::string prenume;
    std::string dataDeNastere;
    double salariu = 0.0;

    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Registrarea~~~~~~~~~~~~~~~~~~~\n";
    do {
        std::cout << "Username: ";
        std::cin >> username;

        if (!Utilitati::esteUsernameValid(username))
            std::cout << "Username invalid! Folositi doar litere, cifre, '_' sau '-'.\n";
        else if (biblioteca->existaUtilizator(username))
            std::cout << "Utilizatorul exista deja! Alegeti alt username.\n";
        else break;
    } while (true);

    do
    {
        std::cout << "Parola: ";
        std::cin >> parola;
        if (parola.size() < 8)
            std::cout << "Parola invalida! Parola trebuie sa fie de cel putin 8 caractere.\n";
        else break;
    }
    while(true);

    do {
        std::cout << "Nume: ";
        std::cin >> nume;
        if (!Utilitati::esteNumePrenumeValid(nume))
            std::cout << "Nume invalid! Folositi doar litere.\n";
        else break;
    } while (true);

    do {
        std::cout << "Prenume: ";
        std::cin >> prenume;
        if (!Utilitati::esteNumePrenumeValid(prenume))
            std::cout << "Prenume invalid! Folositi doar litere.\n";
        else break;
    } while (true);
    
    std::cout << "Ziua de nastere (DD-MM-YYYY): ";
    std::cin >> dataDeNastere;
    
    std::cout << "Selectati cine sunteti in biblioteca:";
    std::cout << "\nc. Client";
    std::cout << "\nb. Bibliotecar";
    std::cout << "\na. Administrator";
    std::cout << "\nSelectati: ";

    std::string statusSelectat;
    std::cin >> statusSelectat;
    char statusChar = tolower(statusSelectat[0]);
    std::string statusStr;
    
    switch (statusChar)
    {
        case 'c':
            statusStr = "Client";
            break;
        case 'b':
            std::cout << "Salariul: ";
            std::cin >> salariu;
            statusStr = "Bibliotecar";
            break;
        case 'a':
            std::cout << "Salariul: ";
            std::cin >> salariu;
            statusStr = "Administrator";
            break;
        default:
            break;
    }

    if(biblioteca->adaugaUtilizator(Utilitati::trim(username), parola, Utilitati::trim(nume), Utilitati::trim(prenume), Utilitati::trim(dataDeNastere), statusStr, salariu)) {
        std::cout << "Inregistrarea a fost efectuata cu succes!\n";
    }
    std::cout << "Apasati tasta Enter pentru a continua...";
    std::cin.ignore();
    std::cin.get();
}

void Interfata::IClient()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Meniul Clientului~~~~~~~~~~~~~~~~~~~\n";
    std::cout << utilizator->afisare() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Carti disponibile";
    std::cout << "\n2. Imprumutati o carte";
    std::cout << "\n3. Returnati o carte";
    std::cout << "\n4. Cartile imprumutate";
    std::cout << "\n5. Iesiti din cont";
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Selectati: ";
    std::string optiune;
    std::cin >> optiune;
    char optVal = tolower(optiune[0]);
    switch (optVal)
    {
        case '1':
            IAfisareaCartilor();
            break;
        case '2':
            IImprumutaCarte();
            break;
        case '3':
            IReturneazaCarte();
            break;
        case '4':
            IAfisareImprumuturi();
            break;
        case '5':
            ILogOut();
            break;
        default:
            break;
    }
}

void Interfata::IBibliotecar()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Meniul Bibliotecarului~~~~~~~~~~~~~~~~~~~\n";
    std::cout << utilizator->afisare() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Adaugati o carte";
    std::cout << "\n2. Sterge o carte";
    std::cout << "\n3. Vizualizati cartile";
    std::cout << "\n4. Vizualizati utilizatorii";
    std::cout << "\n5. Cartile imprumutate de utilizatori";
    std::cout << "\n6. Iesiti din cont";
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Selectati: ";

    std::string optiune;
    std::cin >> optiune;
    char optVal = tolower(optiune[0]);
    switch (optVal)
    {
        case '1':
            IAdaugareCarte();
            break;
        case '2':
            IStergereCarte();
            break;
        case '3':
            IAfisareaCartilor();
            break;
        case '4':
            IAfisareUtilizatori();
            break;
        case '5':
            IAfisareImprumuturi();
            break;
        case '6':
            ILogOut();
            break;
        default:
            break;
    }
}

void Interfata::IAdministrator()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Meniul Administratorului~~~~~~~~~~~~~~~~~~~\n";
    std::cout << utilizator->afisare() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Promoveaza utilizator";
    std::cout << "\n2. Demoveaza utilizator";
    std::cout << "\n3. Sterge utilizator";
    std::cout << "\n4. Vizualizeaza utilizatorii";
    std::cout << "\n5. Iesiti din cont";
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Selectati: ";
    std::string optiune;
    std::cin >> optiune;
    char optVal = tolower(optiune[0]);
    switch (optVal)
    {
        case '1':
            
            break;
        case '2':
            
            break;
        case '3':
            
            break;
        case '4':
            IAfisareUtilizatori();
            break;
        case '5':
            ILogOut();
            break;
        default:
            break;
    }
}

void Interfata::IAdaugareCarte()
{
    std::string optiunea;
    char optiuneaValida;
    Carte* carte = nullptr;

    std::string titlu, autor, isbn, domeniu, format;
    int anul, nrPagini;
    std::vector<std::string> genres;

    do
    {
        Utilitati::curataConsola();
        std::cout << "~~~~~~~~~~~~~~~~~Adaugarea cartii~~~~~~~~~~~~~~~~~\n";
        std::cout << "Care carte vreti sa adaugati: ";
        std::cout << "\nT. Carte tehnica";
        std::cout << "\nF. Carte fictiune";
        std::cout << "\nD. Carte digitala";
        std::cout << "\nA. Carte audio";
        std::cout << "\nQ. Iesirea";
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Selectati: ";
        std::cin >> optiunea;
        optiuneaValida = toupper(optiunea[0]);
    }
    while(optiuneaValida != 'T' && optiuneaValida != 'F' && optiuneaValida != 'D' && optiuneaValida != 'A' && optiuneaValida != 'Q');

    if (optiuneaValida == 'Q') return;

    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~Adaugarea cartii~~~~~~~~~~~~~~~~~\n";
    std::cout << "Titlu: ";
    std::getline(std::cin >> std::ws, titlu);
    std::cout << "Autor: ";
    std::getline(std::cin >> std::ws, autor);
    std::cout << "Anul: ";
    std::cin >> anul;

    Stare stareSelectata = Stare::Buna;
    if (optiuneaValida == 'T' || optiuneaValida == 'F') {
        std::cout << "Selectati starea cartii (B - Buna, N - Normala, R - Rea): ";
        std::string stareOpt;
        std::cin >> stareOpt;
        char stareVal = toupper(stareOpt[0]);
        switch(stareVal) {
            case 'B': stareSelectata = Stare::Buna; break;
            case 'N': stareSelectata = Stare::Normala; break;
            case 'R': stareSelectata = Stare::Rea; break;
            default: stareSelectata = Stare::Buna; break;
        }
        std::cout << "Numar pagini: ";
        std::cin >> nrPagini;
    }

    switch (optiuneaValida)
    {
        case 'T':
            std::cout << "Domeniul: ";
            std::getline(std::cin >> std::ws, domeniu);
            isbn = biblioteca->creazaISBN();
            carte = new CarteTehnica(titlu, autor, isbn, anul, domeniu, Tip::Tehnica, nrPagini, stareSelectata);
            break;
        case 'F':
        {
            std::cout << "Genurile (separate prin virgula): ";
            std::string genresStr;
            std::getline(std::cin >> std::ws, genresStr);
            std::stringstream ss(genresStr);
            std::string segment;
            while(std::getline(ss, segment, ',')) {
                genres.push_back(Utilitati::trim(segment));
            }
            isbn = biblioteca->creazaISBN();
            carte = new CarteFictiune(titlu, autor, isbn, anul, genres, Tip::Fictiune, nrPagini, stareSelectata);
            break;
        }
        case 'D':
            double marime;
            std::cout << "Formatul (e.g. PDF, EPUB): ";
            std::getline(std::cin >> std::ws, format);
            std::cout << "Marime (MB): ";
            std::cin >> marime;
            isbn = biblioteca->creazaISBN();
            carte = new CarteDigitala(titlu, autor, isbn, anul, format, Tip::Digitala, marime);
            break;
        case 'A':
        {
            double durata;
            std::cout << "Formatul (e.g. MP3, WAV): ";
            std::getline(std::cin >> std::ws, format);
            std::cout << "Durata (minute): ";
            std::cin >> durata;
            isbn = biblioteca->creazaISBN();
            carte = new CarteAudio(titlu, autor, isbn, anul, format, Tip::Audio, durata);
            break;
        }
    }

    if(carte && biblioteca->adaugaCarte(carte))
        std::cout << "Cartea a fost adaugata cu succes!\n";
    else
        std::cout << "Eroare la adaugarea cartii!\n";

    delete carte;
}

void Interfata::IStergereCarte()
{
    std::string isbn;
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Stergerea Cartii~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "ISBN-ul cartii: ";
    std::cin >> isbn;
    if (biblioteca->stergeCarte(isbn))
        std::cout << "Cartea a fost stearsa cu succes!\n";
    else
        std::cout << "Eroare la stergerea cartii!\n";

    biblioteca->reseteazaCartileMemorie();
    biblioteca->incarcaCartileDinBD();
}

void Interfata::IAfisareaCartilor()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~Cartile disponibile in biblioteca~~~~~~~~~~~~~~~~~\n";
    biblioteca->afisareaCartilor();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Apasati tasta Enter pentru a iesi: ";
    std::cin.get();    
    std::cin.get();
}

void Interfata::IAfisareImprumuturi()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~Imprumuturile din biblioteca~~~~~~~~~~~~~~~~~\n";
    if(dynamic_cast<Client*>(utilizator))
    {
        biblioteca->afisareaImprumuturilor(username);
    }
    else if(dynamic_cast<Bibliotecar*>(utilizator) || dynamic_cast<Administrator*>(utilizator))
    {
        biblioteca->afisareaImprumuturilor();
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Apasati tasta Enter pentru a iesi: ";
    std::cin.get();    
    std::cin.get();
}

void Interfata::IAfisareUtilizatori(){
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~Utilizatorii din biblioteca~~~~~~~~~~~~~~~~~\n";
    biblioteca->afisareaUtilizatorilor();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Apasati tasta Enter pentru a iesi: ";
    std::cin.get();
    std::cin.get();
}

void Interfata::IImprumutaCarte() {
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Imprumut carte~~~~~~~~~~~~~~~~~~~\n";

    auto& carti = biblioteca->getCartile();
    std::vector<std::string> isbns;
    int nr = 0;
    for (auto& it : carti) {
        if(biblioteca->esteImprumutata(it.second->getISBN()))
            continue;
        else{   
            std::cout << "[" << ++nr << "] " << it.second->getTitlu() 
                    << " - " << it.second->getAutor() << "\n";
            isbns.push_back(it.second->getISBN());
        }
    }

    if(nr == 0){
        std::cout << "Nu exista carti disponibile pentru imprumut!\n";
        std::cout << "Apasati tasta Enter pentru a iesi: ";
        std::cin.get();
        std::cin.get();
        return;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    int selectat;
    std::cout << "Selectati numarul cartii: ";
    std::cin >> selectat;

    if (selectat < 1 || selectat > (int)isbns.size()) {
        return;
    }

    std::string isbn = isbns[selectat - 1];
    if (biblioteca->imprumutaCarte(username, isbn))
        std::cout << "Carte imprumutata cu succes!\n";
    else
        std::cout << "Eroare la imprumutul cartii!\n";
}

void Interfata::IReturneazaCarte() 
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Returnare carte~~~~~~~~~~~~~~~~~~~\n";

    auto& imprumuturi = biblioteca->getImprumuturi(username);
    
    if (imprumuturi.empty()) {
        std::cout << "Nu ai carti imprumutate!\n";
        std::cout << "Apasati tasta Enter pentru a iesi: ";
        std::cin.get();    
        std::cin.get();
        return;
    }

    int nr = 1;
    for (auto& imp : imprumuturi)
        std::cout << "[" << nr++ << "] " << imp.titlu << " - imprumutat pe " << imp.dataDeImprumut << "\n";

    int selectat;
    std::cout << "Selectati numarul cartii de returnat: ";
    std::cin >> selectat;

    if (selectat < 1 || selectat > (int)imprumuturi.size()) {
        return;
    }

    std::string isbn = imprumuturi[selectat - 1].ISBN;
    if (biblioteca->returneazaCarte(username, isbn))
        std::cout << "Carte returnata cu succes!\n";
    else
        std::cout << "Eroare la returnarea cartii!\n";
}

void Interfata::IMeniu()
{
    while (utilizator != nullptr)
    {
        if (utilizator->getStatus() == "Client")
            IClient();
        else if (utilizator->getStatus() == "Bibliotecar")
            IBibliotecar();
        else if (utilizator->getStatus() == "Administrator")
            IAdministrator();
    }
}

void Interfata::ILogOut()
{
    utilizator = nullptr;
}