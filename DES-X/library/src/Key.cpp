#include "Key.hpp"

Key::Key()
{
    generateBaseKey();
}

void Key::generateBaseKey()
{
    mt19937 generator( time(0) );
    uniform_int_distribution<uint64_t> rand_uniform;
    baseKey = rand_uniform(generator);
}

uint64_t Key::generateRoundKeys()
{
    uint64_t tempKey = permutedChoiceI();

    uint32_t rightKey = static_cast<uint32_t>(tempKey) & 0xfffffff;
    uint32_t leftKey = static_cast<uint32_t>(tempKey >> 28) & 0xfffffff;

    for(int i = 0; i < 16; i++)
    {
            leftKey = leftCircularShift(leftKey, i);
            rightKey = leftCircularShift(rightKey, i);
            
            roundKeys[i] = permutedChoiceII(leftKey, rightKey);
    }
    
    return 0;
}


uint64_t Key::permutedChoiceI() //WORKING!
{
    bitset<56> permutation;
    bitset<64> original = static_cast<bitset<64>>(baseKey);

    const unsigned short permPositions[56] = {57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18,
                                              10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36,
                                              63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22,
                                              14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12, 4};

    for(int i = 0, j = 55; i < 56; i++, j--)
    {
        permutation[j] = original[ inv(permPositions[i]) ];
    }

    return permutation.to_ullong();
}

uint64_t Key::permutedChoiceII(uint32_t leftIn, uint32_t rightIn) //ALSO WORKING!!!
{
    bitset<48> permutation;
    bitset<56> original = bitset<56>(leftIn);
               original <<= 28;
               original |= bitset<56>(rightIn);

    const unsigned short permPositions[48] = {14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
                                              23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
                                              41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                                              44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

    for(int i = 0, j = 47; i < 48; i++, j--)
    {
        permutation[j] = original[ inv(permPositions[i], 56) ];
    }

    return permutation.to_ullong();
}

uint32_t Key::leftCircularShift(uint32_t input, unsigned short roundTemp)
{
    const uint8_t shift[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    uint8_t shiftValue = shift[roundTemp];
    bitset<28> keyCopy = bitset<28>(input);
    bool overflowBit;
    while(shiftValue)
    {
        overflowBit = keyCopy[27];
        keyCopy <<= 1;
        keyCopy[0] = overflowBit;
        shiftValue--;
    }
    return keyCopy.to_ulong();
}