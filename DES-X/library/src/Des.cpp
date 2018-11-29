#include "Des.hpp"

uint64_t Des::encrypt(const char *plainText, uint64_t key)
{
    uint64_t IPtext = initialPermutation();
    uint32_t rightText = static_cast<uint32_t>(IPtext);
    uint32_t leftText = static_cast<uint32_t>(IPtext >> 32);

cout << "Left text:\t";
printBits(leftText, 32, 4);

cout << "Right text:\t";
printBits(rightText, 32, 4);

    uint64_t temp = expansionPermutation(rightText);

cout << "Expansion permutation:\t";
printBits(temp, 48, 6);

    return 0;
}

uint64_t Des::decrypt(const char *plainText, uint64_t key)
{
    return 0;
}