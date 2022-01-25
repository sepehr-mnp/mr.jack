#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

void jackUpdate() {
    int n = jack.n;
    switch (n) {
        case 0:
            jack.posx = sh.posx;
            jack.posy = sh.posy;
            break;
        case 1:
            jack.posx = jw.posx;
            jack.posy = jw.posy;
            break;
        case 2:
            jack.posx = js.posx;
            jack.posy = js.posy;
            break;
        case 3:
            jack.posx = il.posx;
            jack.posy = il.posy;
            break;
        case 4:
            jack.posx = ms.posx;
            jack.posy = ms.posy;
            break;
        case 5:
            jack.posx = sg.posx;
            jack.posy = sg.posy;
            break;
        case 6:
            jack.posx = wg.posx;
            jack.posy = wg.posy;
            break;
        case 7:
            jack.posx = jb.posx;
            jack.posy = jb.posy;
            break;
    }
}

void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);

}

int * pos(int character) {
    int posx,posy;
    if (character == 0) {
        posx = sh.posx;
        posy = sh.posy;
    } else if (character == 1) {
        posx = jw.posx;
        posy = jw.posy;
    } else if (character == 2) {
        posx = js.posx;
        posy = js.posy;
    } else if (character == 3) {
        posx = il.posx;
        posy = il.posy;
    } else if (character == 4) {
        posx = ms.posx;
        posy = ms.posy;
    } else if (character == 5) {
        posx = sg.posx;
        posy = sg.posy;
    } else if (character == 6) {
        posx = wg.posx;
        posy = wg.posy;
    } else if (character == 7) {
        posx = jb.posx;
        posy = jb.posy;
    }
    int * arr = malloc(sizeof (int)*2);
    arr[0]=posx;
    arr[1]=posy;
    return arr;
}