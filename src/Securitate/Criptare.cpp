#include "Criptare.h"

std::string Criptare::criptare(const std::string &parola) {
  const size_t HASH_LEN = 32;
  const size_t SALT_LEN = 16;
  const uint32_t T_COST = 2;
  const uint32_t M_COST = 1 << 16;
  const uint32_t PARALELISM = 1;

  std::vector<uint8_t> salt(SALT_LEN);
  RAND_bytes(salt.data(), SALT_LEN);

  std::vector<uint8_t> hash(HASH_LEN);
  char codificat[256];

  argon2id_hash_encoded(T_COST, M_COST, PARALELISM,
                    parola.c_str(), parola.size(),
                    salt.data(), SALT_LEN, HASH_LEN,
                    codificat, sizeof(codificat));

  return std::string(codificat);
}

bool Criptare::verificaParola(const std::string &parola, const std::string &codificat) {
  return argon2id_verify(codificat.c_str(), parola.c_str(), parola.size()) == ARGON2_OK;
}
