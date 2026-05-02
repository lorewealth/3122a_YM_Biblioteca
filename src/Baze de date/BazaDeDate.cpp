#include "BazaDeDate.h"
#include "../Entitati/Clienti.h"
#include "../Entitati/Angajati.h"

// Constructor
BazaDeDate::BazaDeDate(const std::string& fisier) : db(fisier, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)
{
    creeazaTabeluri();
}

// Creare tabele la prima rulare
void BazaDeDate::creeazaTabeluri()
{
    db.exec(R"(
        CREATE TABLE IF NOT EXISTS utilizatori(
            id      INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE,
            parola   TEXT NOT NULL,
            nume     TEXT NOT NULL,
            prenume  TEXT NOT NULL,
            rol      TEXT NOT NULL,
            salariu  REAL DEFAULT 0
        );
        CREATE TABLE IF NOT EXISTS carti(
            id     INTEGER PRIMARY KEY AUTOINCREMENT,
            titlu  TEXT NOT NULL,
            autor  TEXT NOT NULL,
            ISBN   TEXT NOT NULL,
            anul   INTEGER NOT NULL
        );
    )");
}

// ── Utilizatori ──────────────────────────────────────────────────────────────

void BazaDeDate::adaugaUtilizator(const std::string& username, const std::string& parola,
                                   const std::string& nume, const std::string& prenume,
                                   const std::string& rol, double salariu)
{
    std::string parolaCriptata = Criptare::criptare(parola);
    SQLite::Statement ins(db, "INSERT INTO utilizatori(username, parola, nume, prenume, rol, salariu) VALUES(?,?,?,?,?,?)");
    ins.bind(1, username);
    ins.bind(2, parolaCriptata);
    ins.bind(3, nume);
    ins.bind(4, prenume);
    ins.bind(5, rol);
    ins.bind(6, salariu);
    ins.exec();
}

bool BazaDeDate::existaUtilizator(const std::string& username)
{
    SQLite::Statement q(db, "SELECT COUNT(*) FROM utilizatori WHERE username = ?");
    q.bind(1, username);
    q.executeStep();
    return q.getColumn(0).getInt() > 0;
}

// // Returneaza rolul daca credentialele sunt corecte, altfel "EROARE"
// std::string BazaDeDate::verificLoginare(const std::string& username, const std::string& parola)
// {
//     try {
//         SQLite::Statement q(db, "SELECT parola, rol FROM utilizatori WHERE username = ?");
//         q.bind(1, username);
//         if (q.executeStep()) {
//             if (Criptare::verificaParola(parola, q.getColumn(0).getString()))
//                 return q.getColumn(1).getString();
//         }
//         return "EROARE";
//     }
//     catch (const SQLite::Exception&) {
//         return "EROARE";
//     }
// }

// // Construieste obiectul polimorfic corespunzator rolului
// Persoana* BazaDeDate::getPersoana(const std::string& username)
// {
//     try {
//         SQLite::Statement q(db, "SELECT nume, prenume, rol, salariu FROM utilizatori WHERE username = ?");
//         q.bind(1, username);
//         if (q.executeStep()) {
//             std::string nume    = q.getColumn(0).getString();
//             std::string prenume = q.getColumn(1).getString();
//             std::string rol     = q.getColumn(2).getString();
//             double      salariu = q.getColumn(3).getDouble();

//             if (rol == "Client")
//                 return new Client(username, nume, prenume);
//             else
//                 return new Angajat(username, nume, prenume, rol, salariu);
//         }
//     }
//     catch (const SQLite::Exception&) {}
//     return nullptr;
// }

// // ── Carti ────────────────────────────────────────────────────────────────────

// void BazaDeDate::adaugaCarte(const std::string& titlu, const std::string& autor,
//                               const std::string& isbn, int anul)
// {
//     SQLite::Statement ins(db, "INSERT INTO carti(titlu, autor, ISBN, anul) VALUES(?,?,?,?)");
//     ins.bind(1, titlu);
//     ins.bind(2, autor);
//     ins.bind(3, isbn);
//     ins.bind(4, anul);
//     ins.exec();
// }

// std::vector<InfoCarte> BazaDeDate::getToateCartile()
// {
//     std::vector<InfoCarte> lista;
//     SQLite::Statement q(db, "SELECT id, titlu, autor, ISBN, anul FROM carti");
//     while (q.executeStep()) {
//         InfoCarte c;
//         c.id    = q.getColumn(0).getInt();
//         c.titlu = q.getColumn(1).getString();
//         c.autor = q.getColumn(2).getString();
//         c.isbn  = q.getColumn(3).getString();
//         c.anul  = q.getColumn(4).getInt();
//         lista.push_back(c);
//     }
//     return lista;
// }

// bool BazaDeDate::stergeCarte(int id)
// {
//     SQLite::Statement del(db, "DELETE FROM carti WHERE id = ?");
//     del.bind(1, id);
//     del.exec();
//     return db.getChanges() > 0;
// }
