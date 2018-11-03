#include "platform-specific.hpp"

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