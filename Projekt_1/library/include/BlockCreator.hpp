#ifndef BlockCreator_hpp
#define BlockCreator_hpp

#include <stdint.h>

class Block
{
protected:
    uint64_t currentBlock = 0;

private:
    const char *textPosPointer;

public:
    Block(const char *plainText);
    uint64_t getBlock();
    uint64_t nextBlock();
};

#endif //BlockCreator_hpp