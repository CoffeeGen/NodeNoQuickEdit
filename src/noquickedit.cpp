// src/noquickedit.cpp

#include "noquickedit.h"

using namespace std;

int disable( ) {
    HANDLE hInput;
    DWORD prevMode;
    hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &prevMode);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ( prevMode & ~ENABLE_QUICK_EDIT_MODE ) );
    return 0;
}