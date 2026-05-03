#include <string>
#include <cctype>
#include <ctime>

#pragma once

class Utilitati{
public:
    static void curataConsola();
    static bool esteUsernameValid(const std::string& s);
    static bool esteNumePrenumeValid(const std::string& s);
    static std::string trim(const std::string& s);
    static std::string dataAzi();
};
