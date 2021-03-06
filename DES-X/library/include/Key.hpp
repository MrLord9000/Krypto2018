#ifndef KEY_HPP
#define KEY_HPP

#include <random>
#include <ctime>

#include "Misc.hpp"

class Key
{
public:
    uint64_t baseKey;
    uint64_t roundKeys[16];

    void generateBaseKey();
    uint64_t generateRoundKeys();

    uint64_t permutedChoiceI();
    uint64_t permutedChoiceII(uint32_t leftIn, uint32_t rightIn);
    uint32_t leftCircularShift(uint32_t input, unsigned short roundTemp = 0);
    uint64_t getKey(uint8_t n) { return roundKeys[n]; }
    Key();
};



#endif