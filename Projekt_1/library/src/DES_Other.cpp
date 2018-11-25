#include "DES.hpp"


// +++++ Class constructor ++++++
DES::DES(std::string plainText) 
: Block(plainText.c_str()) { }

/* ==Split======================================================================================
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

/* ==Left Circular Shift===========================================================================
 *  Shifts the bits left depending on a fixed value assigned to specific round number.
 */
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
// ================================================================================================

/* ==S-Box control function========================================================================
 *  Performs the 6 S-box operations and stores it's output in the "output" variable.
 */
uint32_t DES::S_boxes(uint64_t input)
{
    bitset<32> output = 0;
    bitset<6> S_temp;

    for(int i = 0; i < 8; i++)
    {
        S_temp = static_cast<bitset<6>>(input);
        output |= bitset<32>(S_box(S_temp, i));
        output <<= 4;
        input >>= 6;
    }
    
    return output.to_ulong();
}
// ================================================================================================

uint32_t DES::S_box(bitset<6> input, short n)
{
    // Converting the 6 bit input into table positions.
    bitset<4> column = bitset<4>(input.to_ulong() >> 1) ;
    bitset<2> row = bitset<2>(input[5]);
    row <<= 1;
    row |= bitset<2>(input[0]);

    const unsigned short s_box_table[8][4][16] = {
                                  { {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
                                    { 0, 15,  7,  4, 14,  2, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10},
                                    { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
                                    {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13}},
                                  { {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
                                    { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
                                    { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
                                    {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9}},
                                  { {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
                                    {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
                                    {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
                                    { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12}},
                                  { { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
                                    {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
                                    {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
                                    { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14}},
                                  { { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
                                    {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
                                    { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
                                    {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3}},
                                  { {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
                                    {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
                                    { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
                                    { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},},
                                  { { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
                                    {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
                                    { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
                                    { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12}},
                                  { {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
                                    { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
                                    { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
                                    { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}}
                                };
    return static_cast<uint32_t>(s_box_table[n][row.to_ulong()][column.to_ullong()]);
}