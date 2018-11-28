#include "Others.hpp"


/* ==Split======================================================================================
 * Simple function which takes a 64bit or 56bit input and returns its 
 * left or right half.
 * It uses two enum types "Sides" and "Component" for easy and understanadable
 * implementation.
 *
uint32_t split(Sides side, Component comp, uint64_t input)
{
    short bitMove;
    switch(comp)    // Check for enum type "Component" to set temp and bitMove accordingly.
    {
        case textComp:
            bitMove = 32;
        break;

        case keyComp:
            bitMove = 28;
        break;
    }
    switch(side)    // Check for enum type "Sides" to split the output either to left or right side.
    {
        // WARNING! Even though key is 56 bit, it is still stored in a 64 bit variable.
        // The leftmost bits should be handled with care and at best deleted to prevent errors.
        case rightSide:
            return static_cast<uint32_t>(input);
        break;

        case leftSide:
            temp = temp >> bitMove;
            return static_cast<uint32_t>(input);
        break;
    }
    return 0;
}
 */
// ================================================================================================

void bit_cout(uint64_t input, short bits)
{
    bitset<64> temp = bitset<64>(input);
    for(int i = bits - 1; i >= 0; i--)
    {
        cout << temp[i];
        if(i % 8 == 0) cout << " ";
    }
    cout << endl;
}