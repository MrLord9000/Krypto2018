#include "DES.hpp"

/* ==INITIAL_PERMUTATION_64BIT_in_64BIT_out=====================================
 *
 * This permutation is basically checked and working - but only cursorily.
 * Further verification may be needed if problems occur.
 */
uint64_t DES::permutationInitial_64_64()
{
    bitset<64> permutation;
    // Maybe you should convert it earlier in the constructor and hold it as a bitset?
    bitset<64> original = static_cast<bitset<64>>(currentBlock);

    const unsigned short permPositions[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                                              60, 52, 44, 36, 28, 20, 12, 4, 
                                              62, 54, 46, 38, 30, 22, 14, 6, 
                                              64, 56, 48, 40, 32, 24, 16, 8,
                                              57, 49, 41, 33, 25, 17,  9, 1, 
                                              59, 51, 43, 35, 27, 19, 11, 3, 
                                              61, 53, 45, 37, 29, 21, 13, 5, 
                                              63, 55, 47, 39, 31, 23, 15, 7};

    for(int i = 0; i < 64; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();
}
// =============================================================================

uint64_t DES::permutedChoice_I_64_56()
{
    bitset<64> permutation;
    bitset<64> original = static_cast<bitset<64>>(key);

    const unsigned short permPositions[56] = {57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18,
                                              10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36,
                                              63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22,
                                              14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12, 4};

    for(int i = 0; i < 56; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();
}

uint64_t DES::permutedChoice_II_28_28_48()
{
    bitset<48> permutation;
    bitset<56> original = static_cast<bitset<56>>(lKey);
    original <<= 28;
    original |= static_cast<bitset<56>>(rKey);

    const unsigned short permPositions[48] = {14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
                                              23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
                                              41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                                              44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

    for(int i = 0; i < 48; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();                                  
}

uint64_t DES::expansionPermutation_32_48()
{
    bitset<48> permutation;
    bitset<32> original = static_cast<bitset<32>>(rText);
    
    const unsigned short permPositions[48] = {32,  1,  2,  3,  4,  5,
                                               4,  5,  6,  7,  8,  9,
                                               8,  9, 10, 11, 12, 13,
                                              12, 13, 14, 15, 16, 17,
                                              16, 17, 18, 19, 20, 21,
                                              20, 21, 22, 23, 24, 25,
                                              24, 25, 26, 27, 28, 29,
                                              25, 29, 30, 31, 32,  1};

    for(int i = 0; i < 48; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();
}