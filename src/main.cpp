#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "Exceptie.h"
#include "Interfata.h"
#include <string>
#include "BazaDeDate.h"

int main()
{
    BazaDeDate db("BibliotecaDB.db");
    Biblioteca biblioteca(&db);
    Interfata interfata(&biblioteca);

    interfata.IInitializarea();

    return 0;
}
