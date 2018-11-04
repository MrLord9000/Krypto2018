#include "algorithmDES.hpp"

DataEncryptionStandard::DataEncryptionStandard(int64_t mainBlock)
{
    block = mainBlock;

    keyGen();
}

void DataEncryptionStandard::keyGen()
{
    key = 0;
    srand( time(0) );   // Pseudo-random for key generation
                        // Warining! This is not secure and definitely not recommended
    for(int i = 0; i < 4; i++)
    {
        key = key << 16;
        key += rand();
    }
    std::cout << "\nKlucz przed kontrolą parzystości: " << bitset<64>(key);
    paritySet();
}

bitset<64> DataEncryptionStandard::permutationInitial_64_64()
{
    bitset<64> permutation;
    // Maybe you should convert it earlier in the constructor and hold it as a bitset?
    bitset<64> original = static_cast<bitset<64>>(block);

    const unsigned short permPositions[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                                              60, 52, 44, 36, 28, 20, 12, 4, 
                                              62, 54, 46, 38, 30, 22, 14, 6, 
                                              64, 56, 48, 40, 32, 24, 16, 8,
                                              57, 49, 41, 33, 25, 17,  9, 1, 
                                              59, 51, 43, 35, 27, 19, 11, 3, 
                                              61, 53, 45, 37, 29, 21, 13, 5, 
                                              63, 55, 47, 39, 31, 23, 15, 7};

    for(int i = 0; i < 64; i++)
    {
        permutation[i] = original[ permPositions[i] ];
    }
    return permutation;
}

void DataEncryptionStandard::paritySet()
{
    bitset<64> temp = static_cast<bitset<64>>(key);
    int bitCounter = 0;
    for(int i = 0; i < 64; i++)
    {
        if( ( (i+1)%8 ) == 0 )
        {
            if(bitCounter % 2 == 0) temp[i] = 1;
            else                    temp[i] = 0;
            bitCounter = 0;
            std::cout << "\n Reset bitCounter! Bit parzystości nr " << i+1 << " dla n " << i << " : " << temp[i];
        }
        else
        {
            if(temp[i] == 1) 
            {
                bitCounter++;
                std::cout << "\nZwiększono bitCounter do " << bitCounter;
            }
        }
    }
    key = temp.to_ullong();
}

uint64_t DataEncryptionStandard::getKey()
{
    return key;
}