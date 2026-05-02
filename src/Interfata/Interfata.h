#include <iostream>
#include "BazaDeDate.h";
#include "Database.h"

class Interfata
{
    private:
        SQLite::Database *db;
    public:
        Interfata();
        ~Interfata() = default;
        static void Initializarea();
        static void Login();
        static void Registrarea();
        static void Meniu();
};
