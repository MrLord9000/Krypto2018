#ifndef DES_HPP
#define DES_HPP

#include "Block.hpp"
#include "Key.hpp"

enum CryptMode {encryptMode, decryptMode};

class Des : public Key, public Block
{
private:
    uint32_t feistelFunction(uint32_t input, uint8_t roundNo);
    uint64_t expansionPermutation(uint32_t input);
    uint32_t permutation(uint32_t input);
    uint64_t inverseInitialPermutation(uint64_t input);
    uint32_t S_boxes(uint64_t input);
    uint32_t S_box(bitset<6> input, short n);
public:
    Des(const char *plainText) : Block(plainText) {}
    Des(const char *plainText, uint64_t key) : Block(plainText), Key(key) {}
    Des(const char *plainText, uint64_t keys[3]) : Block(plainText), Key(keys) {}
    const char *encrypt();
    const char *decrypt();

};

#endif