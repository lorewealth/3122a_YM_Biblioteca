#include <string>
#include <cctype>

class Utilitati{
public:
    static void curataConsola();
    static bool esteUsernameValid(const std::string& s);
    static bool esteNumePrenumeValid(const std::string& s);
    static std::string trim(const std::string& s);
};
