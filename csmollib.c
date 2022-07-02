#define STB_DS_IMPLEMENTATION

#include "csmollib.h"
#include "inc/stb_ds.h"

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/* Structs */

typedef struct csmstruct_color2w {
    unsigned short fg;
    unsigned short bg;
} csmstruct_color2w ;

/* Globals */
char** csmconfig_options = NULL;
int csmconfig_toggleOffset = 0;
COORD csmconfig_offsetCoords;
csmstruct_color2w csmconfig_consoleColors;

/* Helpers */

#define csmhelper_setConsoleColors(w, f, b) (w).fg = f; (w).bg = b;

#define csmhelper_makeCoordStruct(c, x, y) (c).X = x; (c).Y = y

#define csmhelper_setCursorPosition(c) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c)

#define csmhelper_setTextColor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)

COORD csmhelper_getCursorPosition(HANDLE consoleHandle) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);
    return csbi.dwCursorPosition;
}

/*====================================================================================*/

/* Library */

void csm_toggleOffset(void) {
    if (csmconfig_toggleOffset == 1)
        csmconfig_toggleOffset = 0;
    if (csmconfig_toggleOffset == 0)
        csmconfig_toggleOffset = 1;
}

void csm_setOffset(int xCoord, int yCoord) {
    csmhelper_makeCoordStruct(csmconfig_offsetCoords, xCoord, yCoord);
}

void csm_setColor(unsigned short colorFg, unsigned short colorBg) {
    csmhelper_setConsoleColors(csmconfig_consoleColors, colorFg, colorBg);
}

void csm_optionAdd(char* text) {
    arrpush(csmconfig_options, text);
}

int csm_select(void) {
    int* setDS = NULL;
    int pressedKey = 0;
    int counter = 0;

    for (int ix = 0; ix < arrlen(csmconfig_options); ix++) {
        if (ix == 0)
            arrpush(setDS, (int)csmconfig_consoleColors.fg);
        else
            arrpush(setDS, (int)csmconfig_consoleColors.bg);
    }

    do {
        for (int iy = 0; iy < arrlen(csmconfig_options); iy++) {
            if (csmconfig_toggleOffset == 1) {
                csmconfig_offsetCoords.Y = (short)(csmconfig_offsetCoords.Y + iy);
                csmhelper_setCursorPosition(csmconfig_offsetCoords);
            }
            else {
                csmhelper_makeCoordStruct(csmconfig_offsetCoords, 0, 0 + iy);
                csmhelper_setCursorPosition(csmconfig_offsetCoords);
            }

            csmhelper_setTextColor(setDS[iy]);
            printf("%s\n", csmconfig_options[iy]);
        }

        pressedKey = _getch();

        if (pressedKey == 72 && (counter > 0 && counter <= arrlen(csmconfig_options)))
            counter--;
        if (pressedKey == 80 && (counter >= 0 && counter < arrlen(csmconfig_options) - 1))
            counter++;
        if (pressedKey == '\r')
            return counter + 1;

        for (int ij = 0; ij < arrlen(csmconfig_options); ij++)
            setDS[ij] = csmconfig_consoleColors.bg;
        setDS[counter] = csmconfig_consoleColors.fg;
    } while (1);
}