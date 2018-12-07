#include "Des.hpp"

const char *Des::encrypt()
{
    string output;
    do
    {
        uint64_t IPtext = initialPermutation();
        uint32_t rightText = static_cast<uint32_t>(IPtext);
        uint32_t leftText = static_cast<uint32_t>(IPtext >> 32);

        uint32_t leftCopy;
        for(int i = 0, j = 15; i < 16; i++, j--)
        {
            leftCopy = leftText;
            leftText = rightText;
            rightText = feistelFunction(rightText, i) ^ leftCopy;
        }

        IPtext = 0;
        IPtext = static_cast<uint64_t>(rightText);
        IPtext <<= 32;
        IPtext |= static_cast<uint64_t>(leftText);
        IPtext = inverseInitialPermutation(IPtext);

        output.append(getCurrentBlockStr(IPtext));
    } while(!nextBlock());
    
    return output.c_str();
}

const char *Des::decrypt()
{
    string output;
    do
    {
        uint64_t IPtext = initialPermutation();
        uint32_t rightText = static_cast<uint32_t>(IPtext);
        uint32_t leftText = static_cast<uint32_t>(IPtext >> 32);

        uint32_t leftCopy;
        for(int i = 0, j = 15; i < 16; i++, j--)
        {
            leftCopy = leftText;
            leftText = rightText;
            rightText = feistelFunction(rightText, j) ^ leftCopy;
        }

        IPtext = 0;
        IPtext = static_cast<uint64_t>(rightText);
        IPtext <<= 32;
        IPtext |= static_cast<uint64_t>(leftText);
        IPtext = inverseInitialPermutation(IPtext);

        output.append(getCurrentBlockStr(IPtext));
    } while(!nextBlock());
    

    return output.c_str();
}
