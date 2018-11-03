#ifndef BlockCreator_hpp
#define BlockCreator_hpp

#include <stdint.h>

class Block
{
private:
    uint64_t currentBlock = 0;
    const char *textPosPointer;

public:
    Block(const char *plainText);
    uint64_t getBlock();
    uint64_t nextBlock();
};

#endif //BlockCreator_hpp