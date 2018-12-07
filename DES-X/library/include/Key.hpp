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
    void generateRoundKeys();
    void generateBaseKeys();

// ----- Permutations ------
    uint64_t permutedChoiceI();
    uint64_t permutedChoiceII(uint32_t leftIn, uint32_t rightIn);
    uint32_t leftCircularShift(uint32_t input, unsigned short roundTemp = 0);

public:
// ----- Constructors -----
    Key();
    Key(uint64_t key);
    Key(uint64_t keys[3]);
// ----- Getters/Setters -----
    uint64_t getKey(uint8_t n) { return roundKeys[n]; }
    void getBaseKeys(uint64_t keys[3]);
    uint64_t getBaseKey(uint8_t n) { return baseKeys[n]; }
    void setBaseKey(uint64_t key) { baseKeys[1] = key; }
    void setBaseKeys(uint64_t base[3]);
    
};



#endif