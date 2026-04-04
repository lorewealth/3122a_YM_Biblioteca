#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include "imgui_internal.h"


class Interfata
{
private:
    int lungimea;
    int inaltimea;
    std::string denumirea;

    sf::RenderWindow window;
    sf::Clock deltaCeas;
    ImGuiWindowFlags flags;

public:
    Interfata(int lungimea, int inaltimea, const std::string& denumirea);
    ~Interfata();
    int initializarea();
    void ruleaza();
};
