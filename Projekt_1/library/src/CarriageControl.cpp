#include "CarriageControl.hpp"

#ifdef _WIN32

#include <windows.h>
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#elif linux

#include <unistd.h>
#include <term.h>

void gotoxy(int x, int y)
{
    int err;
    if( !cur_term )
        if( setupterm( NULL, STDOUT_FILENO, &err ) == ERR )
            return;
    putp( tparm( tigetstr( "cup" ), y, x, 0, 0, 0, 0, 0, 0, 0 ) );
}

#endif