#ifndef CSMOLMENU_CSMOLLIB_H
#define CSMOLMENU_CSMOLLIB_H

/*colors*/

#define CSMOLMENU_COLOR_BLACK       0
#define CSMOLMENU_COLOR_DARKBLUE    0x1
#define CSMOLMENU_COLOR_DARKGREEN   0x2
#define CSMOLMENU_COLOR_DARKCYAN    0x2 | 0x1
#define CSMOLMENU_COLOR_DARKRED     0x4
#define CSMOLMENU_COLOR_DARKMAGENTA 0x4 | 0x1
#define CSMOLMENU_COLOR_DARKYELLOW  0x4 | 0x2
#define CSMOLMENU_COLOR_DARKGRAY    0x4 | 0x2 | 0x1

#define CSMOLMENU_COLOR_GRAY        0x8
#define CSMOLMENU_COLOR_BLUE        0x8 | 0x1
#define CSMOLMENU_COLOR_GREEN       0x8 | 0x2
#define CSMOLMENU_COLOR_CYAN        0x8 | 0x2 | 0x1
#define CSMOLMENU_COLOR_RED         0x8 | 0x4
#define CSMOLMENU_COLOR_MAGENTA     0x8 | 0x4 | 0x1
#define CSMOLMENU_COLOR_YELLOW      0x8 | 0x4 | 0x2
#define CSMOLMENU_COLOR_WHITE       0x8 | 0x4 | 0x2 | 0x1

/*functions*/

#ifdef __cplusplus
extern "C" {
#endif
    void csm_toggleOffset(void);
    void csm_setOffset(int xCoord, int yCoord);
    void csm_setColor(unsigned short colorBg, unsigned short colorFg);
    void csm_optionAdd(char* text);
    int csm_select(void);
#ifdef __cplusplus
}
#endif

#endif //CSMOLMENU_CSMOLLIB_H
