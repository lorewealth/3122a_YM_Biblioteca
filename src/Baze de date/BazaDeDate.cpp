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
        CREATE TABLE IF NOT EXISTS carti(
            id     INTEGER PRIMARY KEY AUTOINCREMENT,
            tip    TEXT NOT NULL,
            titlu  TEXT NOT NULL,
            autor  TEXT NOT NULL,
            ISBN   TEXT NOT NULL,
            anul   INTEGER NOT NULL,
            stare TEXT NOT NULL,
            genuri TEXT,
            durata_min INTEGER,
            dimensiuneMB REAL,
            domeniu TEXT,
            format TEXT,
            nrPagini INTEGER
        );
        CREATE TABLE IF NOT EXISTS imprumuturi(
            id     INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            isbn TEXT NOT NULL,
            dataImprumutului TEXT NOT NULL,
            dataReturnarii TEXT,
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

Persoana* BazaDeDate::getPersoana(const std::string& username)
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
                return new Client(nume, prenume, dataDeNastere, username, status);
            }
            else if (status == Status::Bibliotecar) {
                return new Bibliotecar(nume, prenume, dataDeNastere, username, status, salariu);
            }
            else if (status == Status::Administrator) {
                return new Administrator(nume, prenume, dataDeNastere, username, status, salariu);
            }
        }
    }
    catch (const SQLite::Exception&) {}
    return nullptr;
}

int BazaDeDate::adaugaCarte(Carte* carte)
{
    try {
        std::string tipStr;
        std::string stareStr = "";
        std::string genuriStr = "";
        int durata_min = 0;
        double dimensiuneMB = 0.0;
        std::string domeniuStr = "";
        std::string formatStr = "";

        int nrPagini = 0;
        if (auto f = dynamic_cast<CarteFictiune*>(carte)) {
            tipStr = "Fictiune";
            stareStr = (f->getStare() == Stare::Buna ? "Buna" : (f->getStare() == Stare::Normala ? "Normala" : "Rea"));
            nrPagini = f->getNrPagini();
            for (const auto& g : f->getGenre()) genuriStr += g + ",";
            if (!genuriStr.empty()) genuriStr.pop_back();
        } else if (auto t = dynamic_cast<CarteTehnica*>(carte)) {
            tipStr = "Tehnica";
            stareStr = (t->getStare() == Stare::Buna ? "Buna" : (t->getStare() == Stare::Normala ? "Normala" : "Rea"));
            nrPagini = t->getNrPagini();
            domeniuStr = t->getDomeniu();
        } else if (auto d = dynamic_cast<CarteDigitala*>(carte)) {
            tipStr = "Digitala";
            formatStr = d->getFormat();
            dimensiuneMB = d->getMarime();
        } else if (auto a = dynamic_cast<CarteAudio*>(carte)) {
            tipStr = "Audio";
            formatStr = a->getFormat();
            durata_min = static_cast<int>(a->getDurata());
        }

        SQLite::Statement ins(db, "INSERT INTO carti(tip, titlu, autor, ISBN, anul, stare, genuri, durata_min, dimensiuneMB, domeniu, format, nrPagini) VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
        ins.bind(1, tipStr);
        ins.bind(2, carte->getTitlu());
        ins.bind(3, carte->getAutor());
        ins.bind(4, carte->getISBN());
        ins.bind(5, carte->getAnul());
        ins.bind(6, stareStr);
        ins.bind(7, genuriStr);
        ins.bind(8, durata_min);
        ins.bind(9, dimensiuneMB);
        ins.bind(10, domeniuStr);
        ins.bind(11, formatStr);
        ins.bind(12, nrPagini);
        
        return ins.exec();
    }
    catch (const SQLite::Exception&) {
        return 1;
    }
}

int BazaDeDate::stergeCarte(const std::string& isbn)
{
    try{
        SQLite::Statement del(db, "DELETE FROM carti WHERE ISBN = ?");
        del.bind(1, isbn);
        return del.exec();
    }
    catch (const SQLite::Exception&)
    {
        return 1;
    }
}

bool BazaDeDate::verificaISBN(const std::string& isbn)
{
    SQLite::Statement q(db, "SELECT COUNT(*) FROM carti WHERE ISBN = ?");
    q.bind(1, isbn);
    q.executeStep();
    return q.getColumn(0).getInt() > 0;
}

std::unordered_map<std::string, Carte*> BazaDeDate::IncarcaCartileDinBD()
{
    std::unordered_map<std::string, Carte*> Cartile;
    SQLite::Statement q(db, "SELECT * FROM carti");

    while(q.executeStep())
    {
        std::string tipStr = q.getColumn(1).getString();
        std::string titlu = q.getColumn(2).getString();
        std::string autor = q.getColumn(3).getString();
        std::string ISBN = q.getColumn(4).getString();
        int         anul = q.getColumn(5).getInt();
        std::string stareStr = q.getColumn(6).getString();
        std::string genuriStr = q.getColumn(7).getString();
        int         durata_min = q.getColumn(8).getInt();
        double      dimensiuneMB = q.getColumn(9).getDouble();
        std::string domeniuStr = q.getColumn(10).getString();
        std::string formatStr = q.getColumn(11).getString();
        int nrPagini = q.getColumn(12).getInt();

        Stare stare;
        if(stareStr == "Buna") stare = Stare::Buna;
        else if(stareStr == "Normala") stare = Stare::Normala;
        else stare = Stare::Rea;
        
        if(tipStr == "Fictiune")
        {
            std::vector<std::string> genuri;
            std::stringstream ss(genuriStr);
            std::string segment;
            while(std::getline(ss, segment, ','))
            {
                genuri.push_back(Utilitati::trim(segment));
            }
            Cartile[ISBN] = new CarteFictiune(titlu, autor, ISBN, anul, genuri, Tip::Fictiune, nrPagini, stare);
        }
        else if(tipStr == "Tehnica")
        {
            Cartile[ISBN] = new CarteTehnica(titlu, autor, ISBN, anul, domeniuStr, Tip::Tehnica, nrPagini, stare);
        }
        else if(tipStr == "Digitala")
        {
            Cartile[ISBN] = new CarteDigitala(titlu, autor, ISBN, anul, formatStr, Tip::Digitala, dimensiuneMB);
        }
        else if(tipStr == "Audio")
        {
            Cartile[ISBN] = new CarteAudio(titlu, autor, ISBN, anul, formatStr, Tip::Audio, (double)durata_min);
        }
    }
    return Cartile;
}

std::unordered_map<std::string, std::vector<Imprumut>> BazaDeDate::IncarcaImprumuturileDinBD()
{
    std::unordered_map<std::string, std::vector<Imprumut>> imprumuturiList;
    SQLite::Statement q(db, R"(
        SELECT i.username, i.isbn, c.titlu, i.dataImprumutului, i.dataReturnarii
        FROM imprumuturi i
        JOIN carti c ON i.isbn = c.ISBN
        WHERE i.dataReturnarii IS NULL
    )");

    while(q.executeStep())
    {
        Imprumut imprumut;
        std::string username    = q.getColumn(0).getString();
        imprumut.ISBN           = q.getColumn(1).getString();
        imprumut.titlu          = q.getColumn(2).getString();
        imprumut.dataDeImprumut = q.getColumn(3).getString();
        imprumut.dataReturnare  = q.getColumn(4).getString();
        
        imprumuturiList[username].push_back(imprumut);
    }
    return imprumuturiList;
}

std::unordered_map<std::string, Persoana*> BazaDeDate::IncarcaUtilizatoriiDinBD()
{
    std::unordered_map<std::string, Persoana*> utilizatoriList;
    SQLite::Statement q(db, "SELECT * FROM utilizatori");
    while(q.executeStep())
    {
        std::string username =  q.getColumn(1).getString();
        std::string nume = q.getColumn(3).getString();
        std::string prenume = q.getColumn(4).getString();
        std::string dataDeNastere = q.getColumn(5).getString();
        std::string statusStr = q.getColumn(6).getString();
        double salariu = q.getColumn(7).getDouble();
        Status status;
        if(statusStr == "Client")
        {
            status = Status::Client;
            utilizatoriList[username] = new Client(nume, prenume, dataDeNastere, username, status);
        }
        else if(statusStr == "Bibliotecar")
        {
            status = Status::Bibliotecar;
            utilizatoriList[username] = new Bibliotecar(nume, prenume, dataDeNastere, username, status, salariu);
        }
        else if(statusStr == "Administrator")
        {
            status = Status::Administrator;
            utilizatoriList[username] = new Administrator(nume, prenume, dataDeNastere, username, status, salariu);
        }
    }
    return utilizatoriList;
}

bool BazaDeDate::imprumutaCarte(const std::string& username, const std::string& isbn) 
{
    try {
        if (!verificaISBN(isbn)) {
            std::cout << "Cartea nu exista!\n";
            return false;
        }

        SQLite::Statement check(db, "SELECT COUNT(*) FROM imprumuturi WHERE username = ? AND isbn = ? AND dataReturnarii IS NULL");
        check.bind(1, username);
        check.bind(2, isbn);
        check.executeStep();
        if (check.getColumn(0).getInt() > 0) {
            std::cout << "Ai deja aceasta carte imprumutata!\n";
            return false;
        }

        SQLite::Statement ins(db, "INSERT INTO imprumuturi(username, isbn, dataImprumutului) VALUES(?,?,?)");
        ins.bind(1, username);
        ins.bind(2, isbn);
        ins.bind(3, Utilitati::dataAzi());
        ins.exec();
        return true;
    }
    catch (const SQLite::Exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
        return false;
    }
}

bool BazaDeDate::esteImprumutata(const std::string& isbn)
{
    try {
        SQLite::Statement q(db, "SELECT COUNT(*) FROM imprumuturi WHERE isbn = ? AND (dataReturnarii IS NULL OR dataReturnarii = '')");
        q.bind(1, isbn);
        if (q.executeStep()) {
            return q.getColumn(0).getInt() > 0;
        }
    } catch (const SQLite::Exception&) {
        return false;
    }
    return false;
}

bool BazaDeDate::returneazaCarte(const std::string& username, const std::string& isbn) 
{
    try {
        SQLite::Statement upd(db, "UPDATE imprumuturi SET dataReturnarii = ? WHERE username = ? AND isbn = ? AND dataReturnarii IS NULL");
        upd.bind(1, Utilitati::dataAzi());
        upd.bind(2, username);
        upd.bind(3, isbn);
        upd.exec();
        return true;
    }
    catch (const SQLite::Exception&)
    {
        return false;
    }
}
