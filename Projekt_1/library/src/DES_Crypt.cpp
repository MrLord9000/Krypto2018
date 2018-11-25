#include "DES.hpp"

uint64_t DES::encrypt()
{
    uint64_t ciphertextTemp;
    uint64_t roundKey;
    ciphertextTemp = permutationInitial_64_64();
    roundKey = permutedChoice_I_64_56();

// Splitting the plaintext and key into left and right sides.
    lText = split(leftSide, textComp, ciphertextTemp);
    rText = split(rightSide, textComp, ciphertextTemp);
    lKey = split(leftSide, keyComp, roundKey);
    rKey = split(rightSide, keyComp, roundKey);

    while(roundCount < 16)
    {
        round();
    }

    uint32_t tempLeft = lText;
    lText = rText;
    rText = tempLeft;

    ciphertextTemp = lText;
    ciphertextTemp <<= 32;
    ciphertextTemp += rText;

    return ciphertextTemp;
}

void DES::round()
{
    lKey = leftCircularShift(lKey);
    rKey = leftCircularShift(rKey);
// Working on the key
    int64_t tempKey_48 = permutedChoice_II_28_28_48();
// Working on the text
    int64_t tempText_48 = expansionPermutation_32_48();
// XOR
    tempText_48 = tempKey_48 ^ tempText_48;

    uint32_t text_32 = S_boxes(tempText_48);

    text_32 = permutation_32_32(text_32);

    text_32 = text_32 ^ lText;

    lText = rText;
    rText = text_32;
    roundCount++;
}