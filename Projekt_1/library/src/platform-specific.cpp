#include "platform-specific.hpp"

#ifdef _WIN32
void cls()
{
    system("cls");
}
void wait(unsigned int timeInMs)
{
    Sleep(timeInMs);
}
#endif 