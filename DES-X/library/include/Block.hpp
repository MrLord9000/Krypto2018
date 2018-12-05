#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Misc.hpp"

class Block
{
private:
    uint64_t currentBlock = 0;
    const char *textPosPointer;

protected:
    uint64_t initialPermutation();

public:
    Block(const char *plainText = nullptr);
    Block(uint64_t block);
    bool nextBlock();
    string getCurrentBlockStr(uint64_t input = 0);
    uint64_t getCurrentBlockInt();
};

#endif 
