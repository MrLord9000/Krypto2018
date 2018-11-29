#ifndef KEY_HPP
#define KEY_HPP

#include <random>
#include <ctime>

#include "Misc.hpp"

class Key
{
private:
// ----- Variables -----
    uint64_t baseKeys[3];
    uint64_t roundKeys[16];
// ----- Generators -----
    void generateBaseKeys();
    uint64_t generateRoundKeys();
// ----- Permutations ------
    uint64_t permutedChoiceI();
    uint64_t permutedChoiceII(uint32_t leftIn, uint32_t rightIn);
    uint32_t leftCircularShift(uint32_t input, unsigned short roundTemp = 0);

public:
// ----- Constructors -----
    Key();
// ----- Getters/Setters -----
    uint64_t getKey(uint8_t n) { return roundKeys[n]; }
    uint64_t getBaseKey(uint8_t n) { return baseKeys[n]; }

    
};



#endif