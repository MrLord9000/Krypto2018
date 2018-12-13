#include "Block.hpp"


Block::Block(const char *plainText)
{
    textPosPointer = plainText; // Set pointer to the beginning of passed string
/*  ============================================================================
 *  Load the first block into currentBlock                                      */
    nextBlock();
}

bool Block::nextBlock()
{
    bool textEnd = false;
    currentBlock = 0;
    if(*textPosPointer != '\0')
    {
        for (int i = 0; i < 8; i++)
        {
            currentBlock = currentBlock << 8; // Shifting the binary representation of the char to make room for another one.
            if(*textPosPointer != '\0' && !textEnd)
            {
                currentBlock += static_cast<uint8_t>(*textPosPointer); // Converting single character to 8 bit int value   
            }
            else
            {
                currentBlock += static_cast<uint8_t>(' ');
                textEnd = true;
            }
            textPosPointer += 1; // Moving the pointer to next character in string.
        }
    }
    cout << "Next block: " << currentBlock << "\n"; 
    return textEnd;
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

string Block::getCurrentBlockStr(uint64_t input)
{
    string temp;
    uint64_t copy;
    if(input == 0) copy = currentBlock;
    else copy = input;
    
    for(int i = 0, j = 56; i < 8; i++, j -= 8)
    {
        temp.push_back(static_cast<char>(copy >> j));
    }
    return temp;
}

uint64_t Block::getCurrentBlockInt()
{
    return currentBlock;
}