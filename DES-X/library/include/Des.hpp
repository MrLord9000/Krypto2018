#ifndef DES_HPP
#define DES_HPP

#include "Block.hpp"
#include "Key.hpp"

class Des : public Key, public Block
{
private:
    uint32_t feistelFunction(uint32_t input, uint8_t roundNo);
    uint64_t expansionPermutation(uint32_t input);
    uint32_t permutation(uint32_t input);
    uint32_t S_boxes(uint64_t input);
    uint32_t S_box(bitset<6> input, short n);
public:
    Des(const char *plainText = nullptr) : Block(plainText) {}
    uint64_t encrypt(const char *plainText = nullptr, uint64_t key = 0);
    uint64_t decrypt(const char *plainText, uint64_t key);

};

#endif