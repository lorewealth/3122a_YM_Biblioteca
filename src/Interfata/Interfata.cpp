#include "Interfata.h"
#include "imgui.h"
#include "imgui_internal.h"
#include <optional>

Interfata::Interfata(unsigned int lungimea, unsigned int inaltimea, const std::string& denumirea)
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
    window.create(sf::VideoMode({lungimea, inaltimea}), denumirea);
    window.setFramerateLimit(60);

    if(!ImGui::SFML::Init(window)) return -1;

    return 0;
}

void Interfata::ruleaza()
{
    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->template is<sf::Event::Closed>())
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

        Login();

        ImGui::End();

        window.clear(sf::Color(45, 45, 45));
        ImGui::SFML::Render(window);
        window.display();
    }

}

void Interfata::Login()
{
    if (ImGui::BeginTable("Log in", 2, ImGuiTableFlags_SizingFixedFit))
    {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::AlignTextToFramePadding();
        ImGui::Text("Username:");

        ImGui::TableSetColumnIndex(1);
        ImGui::SetNextItemWidth(300);
        ImGui::InputText("##User", bufferUsername, IM_ARRAYSIZE(bufferUsername));

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::AlignTextToFramePadding();
        ImGui::Text("Password:");

        ImGui::TableSetColumnIndex(1);
        ImGui::SetNextItemWidth(300);
        ImGui::InputText("##Password", bufferPassword, IM_ARRAYSIZE(bufferPassword), ImGuiInputTextFlags_Password);

        ImGui::EndTable();
    }
}

std::string Interfata::getUsername() const { return std::string(bufferUsername); }
std::string Interfata::getPassword() const
{
    return std::string(Criptare::criptare(bufferPassword));
}
