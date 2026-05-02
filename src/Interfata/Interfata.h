#include <iostream>
#include "BazaDeDate.h";
#include "Database.h"

class Interfata{
private:
    BazaDeDate *db;
public:
    Interfata(BazaDeDate *db);
    ~Interfata() = default;
    static void Initializarea();
    static void Login();
    static void Registrarea();
    static void Meniu();
};
