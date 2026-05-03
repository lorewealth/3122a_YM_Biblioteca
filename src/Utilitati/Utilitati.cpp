#include "Utilitati.h"
#include <algorithm>

void Utilitati::curataConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

std::string Utilitati::trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

bool Utilitati::esteUsernameValid(const std::string& s) {
    if (s.empty()) return false;
    return std::all_of(s.begin(), s.end(), [](unsigned char c) {
        return std::isalnum(c) || c == '_' || c == '-';
    });
}

bool Utilitati::esteNumePrenumeValid(const std::string& s) {
    if (s.empty()) return false;
    return std::all_of(s.begin(), s.end(), [](unsigned char c) {
        return std::isalpha(c) || c == '-';
    });
}

std::string Utilitati::dataAzi() {
    time_t now = time(0);
    tm* t = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return std::string(buffer);
}