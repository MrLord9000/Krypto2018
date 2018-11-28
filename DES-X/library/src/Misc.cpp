#include "Misc.hpp"

void printBits(uint64_t input, short bits, short groups)
{
    bitset<64> temp = bitset<64>(input);
    for(int i = bits - 1; i >= 0; i--)
    {
        cout << temp[i];
        if(i % groups == 0) cout << " ";
    }
    cout << endl;
}

int inv(unsigned short input, unsigned short bitsSize)
{
    return bitsSize - input;
}