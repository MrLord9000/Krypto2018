#include "Des.hpp"

uint64_t Des::encrypt(const char *plainText, uint64_t key)
{
    uint64_t IPtext = initialPermutation();
    uint32_t rightText = static_cast<uint32_t>(IPtext);
    uint32_t leftText = static_cast<uint32_t>(IPtext >> 32);

cout << "Left text:\t";
printBits(leftText, 32, 4);

cout << "Right text:\t";
printBits(rightText, 32, 4);

    //uint64_t temp = expansionPermutation(rightText);



//     uint64_t temp = feistelFunction(rightText, 0);

// cout << "Feistel:\t";
// printBits(temp, 32, 4);

//     temp = temp ^ leftText;

// cout << "XOR:\t";
// printBits(temp, 32, 4);
    uint64_t leftCopy;
    for(int i = 0; i < 16; i++)
    {
        leftCopy = leftText;
        leftText = rightText;
        rightText = feistelFunction(rightText, i) ^ leftCopy;
        cout << "TU JEST KONIEC RUNDY " << i + 1 << endl;
    }

    leftCopy = leftText;
    leftText = rightText;
    rightText = leftCopy;

    IPtext = leftText;
    IPtext <<= 32;
    IPtext += rightText;

    cout << "Koncze szyfrowanie!\n";

    return inverseInitialPermutation(IPtext);
}

uint64_t Des::decrypt(const char *plainText, uint64_t key)
{
    return 0;
}