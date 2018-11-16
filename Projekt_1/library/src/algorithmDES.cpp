#include "algorithmDES.hpp"

DataEncryptionStandard::DataEncryptionStandard(std::string plainText) 
: Block(plainText.c_str())
{
    keyGen();
}

void DataEncryptionStandard::keyGen()
{
    key = 0;
    srand( time(0) );   // Pseudo-random for key generation
                        // Warining! This is not secure and definitely not recommended
    bool isKeyInvalid = false;
    do
    {
        // This loop is introduced to automatically re-generate the key if one is weak or invalid
        for(int i = 0; i < 4; i++)
        {
            key = key << 16;
            key += rand();
        }
        std::cout << "\nKlucz przed kontrolą parzystości: " << bitset<64>(key);
        paritySet();
        isKeyInvalid = checkForWeakKey();
    } while(isKeyInvalid);
    
}

bool DataEncryptionStandard::checkForWeakKey()
{
    // Patterns of weak and half-weak keys copied from wikipedia.
    // Used in two loops below to check whether the generated key is weak.
    const uint64_t weakKeys[] =     {0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF00000000, 0x00000000FFFFFFFF};
    const uint64_t halfWeakKeys[] = {0x01FE01FE01FE01FE, 0xFE01FE01FE01FE01, 0x1FE01FE00EF10EF1, 0xE01FE01FF10EF10E,
                                     0x01E001E001F101F1, 0xE001E001F101F101, 0x1FFE1FFE0EFE0EFE, 0xFE1FFE1FFE0EFE0E,
                                     0x011F011F010E010E, 0x1F011F010E010E01, 0xE0FEE0FEF1FEF1FE, 0xFEE0FEE0FEF1FEF1};

    for(int i = 0; i < 4; i++)
    {
        if(weakKeys[i] == key) 
        {
            return true;
        }
    }
    for(int i = 0; i < 12; i++)
    {
        if(halfWeakKeys[i] == key)
        {
            return true;
        }
    }
    return false;
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
        }
        else
        {
            if(temp[i] == 1) 
            {
                bitCounter++;
            }
        }
    }
    key = temp.to_ullong();
}

uint64_t DataEncryptionStandard::getKey()
{
    return key;
}

/* ==INITIAL_PERMUTATION_64BIT_in_64BIT_out===============================
 *
 * This permutation is basically checked and working - but only cursorily.
 * Further verification may be needed if problems occur.
 */
bitset<64> DataEncryptionStandard::permutationInitial_64_64()
{
    bitset<64> permutation;
    // Maybe you should convert it earlier in the constructor and hold it as a bitset?
    bitset<64> original = static_cast<bitset<64>>(currentBlock);

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

uint32_t DataEncryptionStandard::split(Sides lr)
{
    uint64_t temp_test = key;
    std::cout << "\nKlucz: " << temp_test;
    std::cout << "\nBinarnie: " << bitset<64>(temp_test);
    std::cout << "\nPrawa strona: " << bitset<32>(static_cast<uint32_t>(temp_test));
    temp_test = temp_test >> 32;
    std::cout << "\nLewa strona: " << bitset<32>(static_cast<uint32_t>(temp_test));
    switch(lr)
    {
        case rightSide:
            return static_cast<uint32_t>(temp_test);
        break;

        case leftSide:
            return 0;
        break;
    }
    return 0;
}