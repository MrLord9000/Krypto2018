#include "Des.hpp"

uint64_t Des::encrypt(const char *plainText, uint64_t key)
{
    uint64_t IPtext = initialPermutation();
    uint32_t rightText = static_cast<uint32_t>(IPtext);
    uint32_t leftText = static_cast<uint32_t>(IPtext >> 32);

    uint32_t leftCopy;
    for(int i = 0; i < 16; i++)
    {
        leftCopy = leftText;
        leftText = rightText;
        rightText = feistelFunction(rightText, i) ^ leftCopy;
    }

    IPtext = 0;
    IPtext = static_cast<uint64_t>(rightText);
    IPtext <<= 32;
    IPtext |= static_cast<uint64_t>(leftText);

    return inverseInitialPermutation(IPtext);
}

uint64_t Des::decrypt(const char *plainText, uint64_t key)
{
    return 0;
}