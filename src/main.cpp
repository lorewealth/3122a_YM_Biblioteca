#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "Exceptie.h"
#include "Persoane.h"
#include "Interfata.h"
#include <string>
#include <iostream>
#include "BazaDeDate.h"

int main()
{
    BazaDeDate("Date.sqlite");
    Interfata::Initializarea();


    return 0;
}
