#include "Key.hpp"

Key::Key()
{
    srand( time(0) );   // Pseudo-random for key generation 
                        // Warining! This is not secure and definitely not recommended
//    keyGen();
    key = 0xF5F3FF12F3FAFFAF;
    paritySet();
}

void Key::keyGen()
{
    key = 0;
    bool isKeyInvalid = false;
    do
    {
        // This loop is introduced to automatically re-generate the key if one is weak or invalid
        for(int i = 0; i < 4; i++)
        {
            key = key << 16;
            key += rand();
        }
        paritySet();
        isKeyInvalid = checkForWeakKey();
    } while(isKeyInvalid);
}

bool Key::checkForWeakKey()
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

/* ==PARITY_SET===================================================================================
 * 
 */
void Key::paritySet()
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