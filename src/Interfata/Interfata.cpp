#include "Interfata.h"
#include <string>

Interfata::Interfata(BazaDeDate *db) : db(db){};

void Interfata::IInitializarea()
{
    std::string optiunea;
    char optVal;
    do
    {
        Utilitati::curataConsola();
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~Biblioteca~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\nSelectati metoda de a intra in sistema bibliotecii:";
        std::cout << "\nL. Log in";
        std::cout << "\nI. Inregistrarea";
        std::cout << "\nQ. Iesirea din sistem";
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\nSelectati: ";

        std::cin >> optiunea;
        optVal = toupper(optiunea[0]);
    }
    while(optVal != 'L' && optVal != 'I' && optVal != 'Q');

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
            break;
        default:
            break;
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
        else if (!db->existaUtilizator(username))
            std::cout << "Utilizatorul nu exista! Reintroduceti username-ul:\n";
        else break;
    }
    while(true);

    do
    {
        std::cout << "Parola: ";
        std::cin >> parola;
    
        if (!db->verificLoginare(username, parola))
            std::cout << "Parola invalida!\n";
        else break;
    }
    while(true);
        

    utilizator = db->getPersoana(username);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    if (!utilizator)
    {
        std::cout << "Eroare la incarcarea datelor utilizatorului!\n";
        IInitializarea();
        return;
    }

    if(utilizator->getStatus() == "Client")
        IClient();
    else if(utilizator->getStatus() == "Bibliotecar")
        IBibliotecar();
    else if(utilizator->getStatus() == "Administrator")
        IAdministrator();
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
        else if (db->existaUtilizator(username))
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

    db->adaugaUtilizator(Utilitati::trim(username), parola, Utilitati::trim(nume), Utilitati::trim(prenume), Utilitati::trim(dataDeNastere), statusStr, salariu);
    std::cout << "Utilizator inregistrat cu succes!\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    ILogin();
}

void Interfata::IClient()
{
    Utilitati::curataConsola();
    std::cout << "~~~~~~~~~~~~~~~~~~~Meniul Clientului~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Utilizator: " << utilizator->afisarea() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Carti disponibile";
    std::cout << "\n2. Imprumutati o carte";
    std::cout << "\n3. Returnati o carte";
    std::cout << "\n4. Cartile imprumutate";
    std::cout << "\n5. Iesiti din cont";
    std::cout << "\nSelectati: ";
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
    std::cout << "Utilizator: " << utilizator->afisarea() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Adaugati o carte";
    std::cout << "\n2. Sterge o carte";
    std::cout << "\n3. Vizualizati cartile";
    std::cout << "\n4. Cartile imprumutate de utilizatori";
    std::cout << "\n5. Iesiti din cont";
    std::cout << "\nSelectati: ";
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
            
            break;
        case '5':
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
    std::cout << "Utilizator: " << utilizator->afisarea() << "\n";
    std::cout << "Ce doriti sa faceti?\n";
    std::cout << "\n1. Promoveaza utilizator";
    std::cout << "\n2. Demoveaza utilizator";
    std::cout << "\n3. Sterge utilizator";
    std::cout << "\n4. Vizualizeaza toti utilizatorii";
    std::cout << "\n5. Iesiti din cont";
    std::cout << "\nSelectati: ";
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
            
            break;
        case '5':
            ILogOut();
            break;
        default:
            break;
    }
}

void Interfata::ILogOut()
{
    utilizator = nullptr;
    IInitializarea();
}