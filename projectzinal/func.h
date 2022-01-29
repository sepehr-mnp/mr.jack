#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "saveLoad.h"
#include "map.h"
#include "cards.h"
#include "move.h"
#include "menu.h"
void mrjackalert(char a[],int jack){
    char strs[1000];
    char str[256]="C:\\Users\\NP\\CLionProjects\\zinali\\curl\\curl.exe  http://mrjackgame.freehost.io/tel.php?id=",jck[2];
    sprintf(jck, "%d", jack);
    strcat(str,jck);
    strcat(str,a);
    printf("%s",str);
    FILE *fp = _popen(str,"r");
    fgets(strs,1000,fp);
    printf("%s ",strs);
    _pclose(fp);
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