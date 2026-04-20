#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "imgui-SFML.h"
#include "imgui.h"
#include "Criptare.h"


class Interfata
{
private:
    unsigned int lungimea;
    unsigned int inaltimea;
    std::string denumirea;

    sf::RenderWindow window;
    sf::Clock deltaCeas;
    ImGuiWindowFlags flags;

    inline static char bufferUsername[15] = "";
    inline static char bufferPassword[64] = "";


public:
    Interfata(unsigned int lungimea, unsigned int inaltimea, const std::string& denumirea);
    ~Interfata();
    int initializarea();
    void ruleaza();
    void Login();
    std::string getUsername() const;
    std::string getPassword() const;
};
