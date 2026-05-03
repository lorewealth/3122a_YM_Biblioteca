#include "Biblioteca.h"
#include <algorithm>

Biblioteca::Biblioteca(BazaDeDate *db):db(db){};

bool Biblioteca::adaugaUtilizator(const std::string& username, const std::string& parola, const std::string& nume, const std::string& prenume, const std::string& dataDeNastere, const std::string& status, double salariu)
{
    if (existaUtilizator(username)) return false;
    db->adaugaUtilizator(username, parola, nume, prenume, dataDeNastere, status, salariu);
    return true;
}

bool Biblioteca::existaUtilizator(const std::string& username)
{
    return db->existaUtilizator(username);
}

bool Biblioteca::verificLoginare(const std::string& username, const std::string& parola)
{
    return db->verificLoginare(username, parola);
}

Persoana* Biblioteca::getPersoana(const std::string& username)
{
    return db->getPersoana(username);
}

std::unordered_map<std::string, Carte*>& Biblioteca::getCartile() 
{
    return Cartile;
}

std::string Biblioteca::creazaISBN() 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);

    std::string isbn = "978";
    for (int i = 0; i < 9; i++)
        isbn += std::to_string(dist(gen));

    int sum = 0;
    for (int i = 0; i < 12; i++)
        sum += (isbn[i] - '0') * (i % 2 == 0 ? 1 : 3);
    
    int checkDigit = (10 - (sum % 10)) % 10;
    isbn += std::to_string(checkDigit);

    return isbn.substr(0, 3) + "-" +
           isbn.substr(3, 1) + "-" +
           isbn.substr(4, 2) + "-" +
           isbn.substr(6, 6) + "-" +
           isbn.substr(12, 1);
}
bool Biblioteca::adaugaCarte(Carte* carte) 
{
    if (db->verificaISBN(carte->getISBN())) return false;
    db->adaugaCarte(carte);
    reseteazaCartileMemorie();
    incarcaCartileDinBD();
    return true;
}
bool Biblioteca::stergeCarte(const std::string& isbn) 
{
    if(!db->verificaISBN(isbn)) return false;
    db->stergeCarte(isbn);
    reseteazaCartileMemorie();
    incarcaCartileDinBD();
    return true;
}

bool Biblioteca::imprumutaCarte(const std::string& username, const std::string& isbn) 
{
    if (Cartile.find(isbn) == Cartile.end()) {
        std::cout << "Cartea nu exista!\n";
        return false;
    }

    if (!db->imprumutaCarte(username, isbn))
        return false;

    Imprumuturi[username].push_back({Cartile[isbn]->getTitlu(), isbn, Utilitati::dataAzi(), ""});
    return true;
}

void Biblioteca::incarcaCartileDinBD() 
{
    Cartile = db->IncarcaCartileDinBD();
}

void Biblioteca::afisareaCartilor() 
{
    if(Cartile.size() == 0) {
        std::cout << "Nu exista carti in biblioteca.\n";
        return;
    }
    int contor = 1;
    for(auto& cartea : Cartile)
        std::cout << "[Nr: " << contor++ << "]" << cartea.second->afisare() << "\n";
}

void Biblioteca::incarcaUtilizatoriiDinBD() 
{
    Utilizatorii = db->IncarcaUtilizatoriiDinBD();
}

void Biblioteca::afisareaUtilizatorilor() 
{
    if(Utilizatorii.size() == 0) {
        std::cout << "Nu exista utilizatori in biblioteca.\n";
        return;
    }
    int contor = 1;
    for(auto& it : Utilizatorii)
        std::cout << "[Nr: " << contor++ << "]" << it.second->afisare() << '\n';
}

void Biblioteca::reseteazaCartileMemorie()
{
    for(auto& it:Cartile)
        delete it.second;
    Cartile.clear();
}

void Biblioteca::incarcaImprumuturileDinBD()
{
    Imprumuturi = db->IncarcaImprumuturileDinBD();
}

void Biblioteca::afisareaImprumuturilor(const std::string& username)
{
    if(Imprumuturi[username].empty()) {
        std::cout << "Nu ati imprumutat carti din biblioteca!\n";
        return;
    }
    int contor = 1;
    for(auto& it: Imprumuturi[username])
        std::cout << "\n[Nr: " << contor++ << "] | " << it.titlu << " | " << it.ISBN << " | " << it.dataDeImprumut << " | " << it.dataReturnare << std::endl;
}

bool Biblioteca::esteImprumutata(const std::string& isbn)
{
    return db->esteImprumutata(isbn);
}

void Biblioteca::afisareaImprumuturilor() 
{
    if (Imprumuturi.empty()) {
        std::cout << "Nu exista imprumuturi in biblioteca!\n";
        return;
    }
    
    int contor = 1;
    for (auto const& [username, imprumuturi] : Imprumuturi) {
        for (auto& it : imprumuturi) {
            std::cout << "[Nr: " << contor++ << "] | " 
                      << "Utilizator: " << username << " | "
                      << "Titlu: " << it.titlu << " | " 
                      << "ISBN: " << it.ISBN << " | " 
                      << "Data de imprumut: " << it.dataDeImprumut << " | " 
                      << "Data returnare: " << it.dataReturnare << '\n';
        }
    }
}

bool Biblioteca::returneazaCarte(const std::string& username, const std::string& isbn) 
{
    if (!db->returneazaCarte(username, isbn))
        return false;

    auto& lista = Imprumuturi[username];
    lista.erase(std::remove_if(lista.begin(), lista.end(),
        [&isbn](const Imprumut& i) { return i.ISBN == isbn; }), lista.end());
    return true;
}

std::vector<Imprumut>& Biblioteca::getImprumuturi(const std::string& username)
{
    return Imprumuturi[username];
}


Biblioteca::~Biblioteca() 
{
    for(auto& it:Cartile)
        delete it.second;
    for(auto& it:Utilizatorii)
        delete it.second;
}

