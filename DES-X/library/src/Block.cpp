#include "Block.hpp"

Block::Block(const char *plainText)
{
    textPosPointer = plainText; // Set pointer to the beginning of passed string
/*  ============================================================================
 *  Load the first block into currentBlock                                      */
 //   nextBlock();
    currentBlock = 0x123456789ABCDEF;
}

uint64_t Block::nextBlock()
{
    for (int i = 0; i < 8; i++)
    {
        currentBlock += static_cast<uint8_t>(*textPosPointer); // Converting single character to 8 bit int value
        currentBlock = currentBlock << 8; // Shifting the binary representation of the char to make room for another one.
        textPosPointer += 1; // Moving the pointer to next character in string.
        /* NOTE: this pointer is a private member of this class and should be handled with care
         * because the nextBlock function depends on it's persistence.
         */
    }
}

uint64_t Block::initialPermutation()
{
    bitset<64> permutation;
    bitset<64> original = static_cast<bitset<64>>(currentBlock);

    const unsigned short permPositions[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                                              60, 52, 44, 36, 28, 20, 12, 4, 
                                              62, 54, 46, 38, 30, 22, 14, 6, 
                                              64, 56, 48, 40, 32, 24, 16, 8,
                                              57, 49, 41, 33, 25, 17,  9, 1, 
                                              59, 51, 43, 35, 27, 19, 11, 3, 
                                              61, 53, 45, 37, 29, 21, 13, 5, 
                                              63, 55, 47, 39, 31, 23, 15, 7};

    for(int i = 0, j = 63; i < 64; i++, j--)
    {
        permutation[j] = original[ inv(permPositions[i]) ];
    }

    return permutation.to_ullong();
}
