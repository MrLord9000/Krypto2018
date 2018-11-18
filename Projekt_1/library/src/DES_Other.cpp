#include "DES.hpp"

DES::DES(std::string plainText) 
: Block(plainText.c_str()) { }

/* ==SPLIT_64===================================================================
 * Simple function which takes a 64bit or 56bit input and returns its 
 * left or right half.
 * It uses two enum types "Sides" and "Component" for easy and understanadable
 * implementation.
 */
uint32_t DES::split(Sides side, Component comp)
{
    uint64_t temp;
    short bitMove;
    switch(comp)    // Check for enum type "Component" to set temp and bitMove accordingly.
    {
        case textComp:
            temp = currentBlock;
            bitMove = 32;
        break;

        case keyComp:
            temp = key;
            bitMove = 28;
        break;
    }
    switch(side)    // Check for enum type "Sides" to split the output either to left or right side.
    {
        // WARNING! Even though key is 56 bit, it is still stored in a 64 bit variable.
        // The leftmost bits should be handled with care and at best deleted to prevent errors.
        case rightSide:
            return static_cast<uint32_t>(temp);
        break;

        case leftSide:
            temp = temp >> bitMove;
            return static_cast<uint32_t>(temp);
        break;
    }
    return 0;
}
// ================================================================================================

uint32_t DES::leftCircularShift(uint32_t key28bit)
{
// Round-specific shift values
    const uint8_t shift[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    uint8_t shiftValue = shift[roundCount];
    bitset<28> keyCopy = bitset<28>(key28bit);
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

uint32_t S_boxes()
{
    
}