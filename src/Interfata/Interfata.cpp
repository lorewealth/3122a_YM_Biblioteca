#include "Interfata.h"

Interfata::Interfata(int lungimea, int inaltimea, const std::string& denumirea)
                    : lungimea(lungimea), inaltimea(inaltimea), denumirea(denumirea)
                    {
                        flags = ImGuiWindowFlags_NoTitleBar |
                                ImGuiWindowFlags_NoMove     |
                                ImGuiWindowFlags_NoResize   |
                                ImGuiWindowFlags_NoCollapse |
                                ImGuiWindowFlags_NoBackground;
                    }

Interfata::~Interfata()
{
    ImGui::SFML::Shutdown();
}

int Interfata::initializarea()
{
    window.create(sf::VideoMode(lungimea, inaltimea), denumirea);
    window.setFramerateLimit(60);

    if(!ImGui::SFML::Init(window)) return -1;

    return 0;
}

void Interfata::ruleaza()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaCeas.restart());

        if(ImGui::BeginMainMenuBar())
        {
            if(ImGui::BeginMenu("Fisier: "))
            {
                if(ImGui::MenuItem("Iesire")) window.close();
                ImGui::EndMenu();
            }
            ImGui::TextDisabled("| Biblioteca v0.1");
            ImGui::EndMainMenuBar();
        }
        ImGui::SetNextWindowPos(ImVec2(0, 20));
        ImGui::SetNextWindowSize(ImVec2(lungimea, inaltimea-20));

        ImGui::Begin("Cartea: ", nullptr, flags);

        ImGui::TextColored(ImVec4(1,1,0,1), "Detalii carte selectat");
        ImGui::Separator();

        ImGui::TextUnformatted("--Nu implementat text--");

        ImGui::End();

        window.clear(sf::Color(45, 45, 45));
        ImGui::SFML::Render(window);
        window.display();
    }

}
