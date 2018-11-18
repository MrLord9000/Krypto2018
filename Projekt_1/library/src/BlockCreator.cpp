#include "BlockCreator.hpp"

Block::Block(const char *plainText)
{
    textPosPointer = plainText; // Set pointer to the beginning of passed string
/*  ============================================================================
 *  Load the first block into currentBlock                                      */
    nextBlock();
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

