#include "BazaDeDate.h"

// constructor
BazaDeDate::BazaDeDate(const std::string &fisier) : db(fisier, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)
{
    creeazaTabeluri();
}

//creearea tabelului
void BazaDeDate::creeazaTabeluri()
{
    db.exec(R"(
        CREATE TABLE IF NOT EXISTS utilizatori(
            id      INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE,
            parola   TEXT NOT NULL,
            nume     TEXT NOT NULL,
            prenume  TEXT NOT NULL,
            dataDeNastere TEXT NOT NULL,
            status  TEXT NOT NULL,
            salariu  REAL DEFAULT 0
        );
    )");
    try {
        db.exec("ALTER TABLE utilizatori RENAME COLUMN pozitia TO status;");
    } catch (...) {
        // Ignoram eroarea daca coloana 'status' exista deja sau 'pozitia' nu exista
    }
    db.exec(R"(
        CREATE TABLE IF NOT EXISTS carti(
            id     INTEGER PRIMARY KEY AUTOINCREMENT,
            tip    TEXT NOT NULL,
            titlu  TEXT NOT NULL,
            autor  TEXT NOT NULL,
            ISBN   TEXT NOT NULL,
            anul   INTEGER NOT NULL,
            cantitate INTEGER NOT NULL,
            stare TEXT NOT NULL
        );
        CREATE TABLE IF NOT EXISTS imprumuturi(
            id     INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            isbn TEXT NOT NULL,
            dataImprumutului TEXT NOT NULL,
            dataReturnarii TEXT NOT NULL,
            FOREIGN KEY(username) REFERENCES utilizatori(username),
            FOREIGN KEY(isbn) REFERENCES carti(ISBN)
        );
    )");
}

void BazaDeDate::adaugaUtilizator(const std::string& username, const std::string& parola,
                                   const std::string& nume, const std::string& prenume,
                                   const std::string& dataDeNastere, const std::string& status, double salariu)
{
    std::string parolaCriptata = Criptare::criptare(parola);
    SQLite::Statement ins(db, "INSERT INTO utilizatori(username, parola, nume, prenume, dataDeNastere, status, salariu) VALUES(?,?,?,?,?,?,?)");
    ins.bind(1, username);
    ins.bind(2, parolaCriptata);
    ins.bind(3, nume);
    ins.bind(4, prenume);
    ins.bind(5, dataDeNastere);
    ins.bind(6, status);
    ins.bind(7, salariu);
    ins.exec();
}

bool BazaDeDate::existaUtilizator(const std::string& username)
{
    SQLite::Statement q(db, "SELECT COUNT(*) FROM utilizatori WHERE username = ?");
    q.bind(1, username);
    q.executeStep();
    return q.getColumn(0).getInt() > 0;
}

bool BazaDeDate::verificLoginare(const std::string& username, const std::string& parola)
{
    SQLite::Statement q(db, "SELECT parola FROM utilizatori WHERE username = ?");
    q.bind(1, username);
    q.executeStep();
    return Criptare::verificaParola(parola, q.getColumn(0).getString());
}

std::unique_ptr<Persoana> BazaDeDate::getPersoana(const std::string& username)
{
    try {
        SQLite::Statement q(db, "SELECT nume, prenume, dataDeNastere, status, salariu FROM utilizatori WHERE username = ?");
        q.bind(1, username);
        
        if (q.executeStep()) {
            std::string nume    = q.getColumn(0).getString();
            std::string prenume = q.getColumn(1).getString();
            std::string dataDeNastere = q.getColumn(2).getString();
            std::string statusStr  = q.getColumn(3).getString();
            double      salariu = q.getColumn(4).getDouble();

            Status status;
            if (statusStr == "Client") status = Status::Client;
            else if (statusStr == "Bibliotecar") status = Status::Bibliotecar;
            else if (statusStr == "Administrator") status = Status::Administrator;
            else return nullptr;

            if (status == Status::Client) {
                return std::make_unique<Client>(nume, prenume, dataDeNastere, status);
            }
            else if (status == Status::Bibliotecar) {
                return std::make_unique<Bibliotecar>(nume, prenume, dataDeNastere, status, salariu);
            }
            else if (status == Status::Administrator) {
                return std::make_unique<Administrator>(nume, prenume, dataDeNastere, status, salariu);
            }
        }
    }
    catch (const SQLite::Exception&) {}
    return nullptr;
}