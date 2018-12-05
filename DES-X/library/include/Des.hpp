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
    CryptMode whatToDo;
    Des(const char *plainText = nullptr) : Block(plainText) {}
    Des(uint64_t block) : Block(block) {}
    uint64_t encrypt();
    uint64_t decrypt();

};

#endif