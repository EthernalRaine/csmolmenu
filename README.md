csmolmenu - a C99 version of thiccmenu

---

Additional Libraries used:
- stb_ds - Dynamic Array for C99

---

Usage: 

```c
#include <csmollib.h>
#include <stdio.h>

int main() {
    csm_setColor(CSMOLMENU_COLOR_DARKGRAY, CSMOLMENU_COLOR_GRAY);
    csm_optionAdd("1. Say Hi");
    csm_optionAdd("2. Say Bye");

    switch (csm_select()) {
        case 1:
            printf("hi!\n");
            break;
        
        case 2:
            printf("bye!\n");
            break;
    }
    
    return 0;
}
```

---

Credits:
```diff
- Originally Written by EinTim23
+ Rewritten by Luna (transferred from my old github akiiinee)
```
