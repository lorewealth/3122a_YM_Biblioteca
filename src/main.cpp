#include "CarteTehnica.h"

int main(){

    Carte* carte = new CarteTehnica("Introducere in DEEA2", "Ion Ionut", "978-3-16-148410-0", "Inginerie");
    CarteTehnica* carteTehnica1 = dynamic_cast<CarteTehnica*>(carte);

    std::cout << carteTehnica1;
    std::cout << carteTehnica1 -> getAutor();
    carteTehnica1 -> setAutor();
    std::cout << carteTehnica1 -> getAutor();

    // std::cout << carteTehnica1;

    delete carte;

    return 0;
}