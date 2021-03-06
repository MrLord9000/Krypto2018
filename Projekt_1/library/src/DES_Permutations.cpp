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
        permutation[i] = original[ convBE(permPositions[i], 64) ];
    }
    return permutation.to_ullong();
}
// =============================================================================



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

uint32_t DES::permutation_32_32(uint32_t input)
{
    bitset<32> permutation;
    bitset<32> original = static_cast<bitset<32>>(input);
    
    const unsigned short permPositions[48] = {16,  7, 20, 21, 29, 12, 28, 17,
                                               1, 15, 23, 26,  5, 18, 31, 10,
                                               2,  8, 24, 14, 32, 27,  3,  9,
                                              19, 13, 30,  6, 22, 11,  4, 25};

    for(int i = 0; i < 32; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();
}

uint64_t DES::inverseInitialPermutation_64_64(uint64_t input)
{
    bitset<64> permutation;
    bitset<64> original = static_cast<bitset<64>>(input);
    
    const unsigned short permPositions[64] = {  40,	8,	48,	16,	56,	24,	64,	32,
                                                39,	7,	47,	15,	55,	23,	63,	31,
                                                38,	6,	46,	14,	54,	22,	62,	30,
                                                37,	5,	45,	13,	53,	21,	61,	29,
                                                36,	4,	44,	12,	52,	20,	60,	28,
                                                35,	3,	43,	11,	51,	19,	59,	27,
                                                34,	2,	42,	10,	50,	18,	58,	26,
                                                33,	1,	41,	9,	49,	17,	57,	25};

    for(int i = 0; i < 64; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation.to_ullong();
}