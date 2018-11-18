#include "DES.hpp"

void DES::encrypt()
{
    int64_t ciphertextTemp;
    int64_t roundKey;
    ciphertextTemp = permutationInitial_64_64();
    roundKey = permutedChoice_I_64_56();

}

void DES::round()
{
// Splitting the plaintext and key into left and right sides.
    lText = leftCircularShift(split(leftSide, textComp));
    rText = leftCircularShift(split(rightSide, textComp));
    lKey = leftCircularShift(split(leftSide, keyComp));
    rKey = leftCircularShift(split(rightSide, keyComp));

// Working on the key
    int64_t tempKey_48 = permutedChoice_II_28_28_48();
// Working on the text
    int64_t tempText_48 = expansionPermutation_32_48();
// XOR
    tempText_48 = tempKey_48 ^ tempText_48;


}