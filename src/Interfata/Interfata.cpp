#include "Interfata.h"
#include "imgui.h"
#include "imgui_internal.h"
#include <climits>
#include <cmath>
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

        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

        ImGui::Begin("Login", nullptr, flags);

        {
            ImVec2 locDisponibil = ImGui::GetContentRegionAvail();

            float lungContent = 400;
            float inaltContent = 120;

            float pozX = (locDisponibil.x - lungContent) * 0.5;
            float pozY = (locDisponibil.y - inaltContent) * 0.5;

            if(pozX < 0) pozX = 0;
            if(pozY < 0) pozY = 0;

            ImGui::SetCursorPos(ImVec2(pozX, pozY));
            Login(pozX, lungContent);

        }

        ImGui::End();

        window.clear(sf::Color(45, 45, 45));
        ImGui::SFML::Render(window);
        window.display();
    }

}

void Interfata::Login(float pozX, float lungContent)
{

    ImGui::BeginGroup();

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

    float lungimeButon = 120;
    ImGui::SetCursorPosX(pozX + (lungContent - lungimeButon) * 0.5);
    if(ImGui::Button("Log in", ImVec2(lungimeButon, 0)))
    {
        if(Interfata::getUsername() == "lorewealth" && Criptare::decriptare(Interfata::getPassword()) == "12345")
        {
            loginStatus = 1;
        }
        else
        {
            loginStatus = 2;
        }

    }

    if (loginStatus == 1) ImGui::TextColored(ImVec4(0, 1, 0, 1), "Hello, lorewealth!");
    else if (loginStatus == 2) ImGui::TextColored(ImVec4(1, 0, 0, 1), "Invalid username or password.");

    ImGui::EndGroup();

}

std::string Interfata::getUsername() const { return std::string(bufferUsername); }
std::string Interfata::getPassword() const
{
    return std::string(Criptare::criptare(bufferPassword));
}
