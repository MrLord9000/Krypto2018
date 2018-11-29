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

#ifdef _WIN32
void cls()
{
    system("cls");
    //  TODO - add linux support
}
void wait(unsigned int timeInMs)
{
    Sleep(timeInMs);
    //  TODO - add linux support
}
void UTF_8()
{
    system("chcp 65001 > nul"); // Warning! This is not recommended and should be changed in near future.
}
#endif 