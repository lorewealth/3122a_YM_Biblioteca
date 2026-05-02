#include <string>
#include <vector>
#include <argon2.h>
#include <cstdint>
#include <openssl/rand.h>

class Criptare {
public:
  static std::string criptare(const std::string &parola);
  static bool verificaParola(const std::string &parola, const std::string &codificat);
};
