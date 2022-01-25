#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int map[9][13],mapsakht[9][13];
bool mapl[9][13];
int maplights[8][3],mapil[4][3],mapjb[8][3];

struct jack{
    int n,posx,posy;
}jack;
struct sh{
    int posx,posy,n;
}sh;

struct jw{
    int posx,posy,n;
}jw;
struct js{
    int posx,posy,n;
}js;
struct il{
    int posx,posy,n;
}il;
struct ms{
    int posx,posy,n;
}ms;
struct sg{
    int posx,posy,n;
}sg;
struct wg{
    int posx,posy,n;
}wg;
struct jb{
    int posx,posy,n;
}jb;
struct seris{
    int n;
    struct seris * nxt;
};
struct seris * seris1,*seris2;
//file save
int i0=0,j0=0;
int mrjacksher[4],mrjackshercount=0;
char cards[8][2]={"SH","JW","JS","IL","MS","SG","WG","JB"};
int suscards[7],handplay[4],handplay2[4];
int suscardsremain=7;
bool importedHand=0;
char strmapname[16],strmap[128];
int jwlight[13][2],jwlightcount=0;
void save(int i0,int j0){
    FILE *fp;
    fp = fopen(strmap, "w");
    fprintf(fp,"76\n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            if(mapsakht[i][j]){
                fprintf(fp,"%d %d %d\n",i,j,mapsakht[i][j]);
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            if(map[i][j]>10){
                fprintf(fp,"%d %d %d\n",i,j,map[i][j]);
            }
        }
    }
    fprintf(fp,"%d\n",jwlightcount);
    for (int i = 0; i < jwlightcount; ++i) {
        //printf("%d %d %d\n",jwlight[i][0],jwlight[i][1],jwlight[i][2]);
        fprintf(fp,"%d %d\n",jwlight[i][0],jwlight[i][1]);
    }
    fprintf(fp,"%d %d\n",i0,j0);
    fprintf(fp,"%d\n",jack.n);
    fprintf(fp,"%d\n",suscardsremain);
    for (int i = 0; i < suscardsremain; ++i) {
        fprintf(fp,"%d ",suscards[i]);
    }       fprintf(fp,"\n");
    fprintf(fp,"1\n");
    if(i0%2==0){
        for (int i = 0; i < 4; ++i) {
            fprintf(fp,"%d ",handplay[i]);
        }   fprintf(fp,"\n");
        struct seris * tmpseris=seris2;
        for (int i = 0; i < 4; ++i) {
            fprintf(fp,"%d ",tmpseris->n);
            tmpseris = tmpseris->nxt;
        }
    }else{
        for (int i = 0; i < 4; ++i) {
            fprintf(fp,"%d ",handplay[i]);
        }
    }
    fprintf(fp,"\n");
    fprintf(fp,"%d\n",mrjackshercount);
    for (int i = 0; i < 4; ++i) {
        fprintf(fp,"%d ",mrjacksher[i]);
    }
  //  delay(10000);
            fclose(fp);
  //  getchar();
}

void mapInput(){
    int lightcount=0,ilcount=0,jbcount=0;
    FILE *fp;
    strcat(strmap,"C:\\Users\\NP\\CLionProjects\\projectzinal\\saves\\");
    strcat(strmap,strmapname);
    printf("%s",strmap);
    fp = fopen(strmap, "r");
    if(fp==NULL){
        fp = fopen("C:\\Users\\NP\\CLionProjects\\projectzinal\\map.txt", "r");
    }
    int n;
    fscanf(fp,"%d",&n);
    printf("%d\n",n);
    for (int i = 0; i < n; ++i) {
        int x,y,m;
        fscanf(fp,"%d %d %d",&x,&y,&m);
        printf("%d %d %d\n",x,y,m);
        map[x][y]=m;
        if(m<10) mapsakht[x][y]=m;
        if(m==2 || m==3) {
            maplights[lightcount][0]=x;
            maplights[lightcount][1]=y;
            maplights[lightcount][2]=(m==2?1:0);
            lightcount++;
        }else if(m==6 || m==7) {
            mapil[ilcount][0]=x;
            mapil[ilcount][1]=y;
            mapil[ilcount][2]=(m==7?1:0);
            ilcount++;
        }else if(m==4 || m==5) {
            mapjb[jbcount][0]=x;
            mapjb[jbcount][1]=y;
            mapjb[jbcount][2]=(m==5?1:0);
            jbcount++;
        }
        if(m>10){
            switch (m) {
                case 11:
                    jw.posx = x;
                    jw.posy = y;
                    jw.n=3;
                    break;
                case 12:
                    wg.posx = x;
                    wg.posy = y;
                    wg.n=3;
                    break;
                case 13:
                    il.posx = x;
                    il.posy = y;
                    il.n=3;
                    break;
                case 14:
                    js.posx = x;
                    js.posy = y;
                    js.n = 3;
                    break;
                case 15:
                    sh.posx = x;
                    sh.posy = y;
                    sh.n=3;
                    break;
                case 16:
                    jb.posx = x;
                    jb.posy = y;
                    jb.n=3;
                    break;
                case 17:
                    ms.posx = x;
                    ms.posy = y;
                    ms.n=4;
                    break;
                case 18:
                    sg.posx = x;
                    sg.posy = y;
                    sg.n=3;
                    break;
            }
        }
    }
    fscanf(fp,"%d",&n);
    jwlightcount=n;
    for (int i = 0; i < n; ++i) {
        fscanf(fp,"%d %d",&jwlight[i][0],&jwlight[i][1]);
    }
    fscanf(fp,"%d %d",&i0,&j0);
    printf(" %d %d ",i0,j0);
    fscanf(fp,"%d",&jack.n);
    fscanf(fp,"%d",&n);
    if(n>0){
    suscardsremain=n;
    for (int i = 0; i < n; ++i) {
        fscanf(fp,"%d",&suscards[i]);
    }
    }   fscanf(fp,"%d",&n);
    if (n){
        importedHand=1;

        for (int i = 0; i < 4; ++i) {
            fscanf(fp, "%d", &handplay[i]);
        }
        if(i0%2==0){
            seris2 =malloc(sizeof (struct seris));
            struct seris * tmpseris=seris2;
            for (int i = 0; i < 4; ++i) {
                fscanf(fp, "%d", &(tmpseris->n));
                tmpseris->nxt = malloc(sizeof (struct seris));
                tmpseris = tmpseris->nxt;
            }
        }
    }
    fscanf(fp,"%d",&n);
    mrjackshercount=n;
    for (int i = 0; i < n; ++i) {
        fscanf(fp,"%d",&(mrjacksher[i]));
    }
    printf("\n%d %d %d %d",mrjacksher[0],mrjacksher[1],mrjacksher[2],mrjacksher[3]);
    delay(5);

}
void mapPrint(){
    char cardsMap[8][2]={"JW","WG","IL","JS","SH","JB","MS","SG"};
    system("cls");
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,8 );
    for (int i = 0; i < 9; ++i) {
        SetConsoleTextAttribute(hConsole, 12);
        printf("%d",i);
        SetConsoleTextAttribute(hConsole, 8);
        for (int j = 1; j < 13; j+=2) {
            if (map[i][j]==8) printf("         ");
            else if(map[i][j]==1) {
                printf("        ");
                SetConsoleTextAttribute(hConsole, 10);
                printf("#");
            }else {
                if(mapl[i][j])  SetConsoleTextAttribute(hConsole, 15);
                if(map[i][j]==2) {
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("        *");
                }
                else if(map[i][j]==3) printf("        *");
                else if(map[i][j]>10) printf("       %c%c", cardsMap[map[i][j]-11][0],cardsMap[map[i][j]-11][1]);
                else printf("        %d", map[i][j]);
            }SetConsoleTextAttribute(hConsole, 8);
        }  printf("\n");
        SetConsoleTextAttribute(hConsole, 12);
        printf("  %d",i);
        SetConsoleTextAttribute(hConsole, 8);
        printf("  ");
        for (int j = 0; j < 13; j+=2) {
            if (map[i][j]==8) printf("         ");
            else if(map[i][j]==1) {
                SetConsoleTextAttribute(hConsole, 10);
                printf("#");
                SetConsoleTextAttribute(hConsole, 8);
                printf("        ");
            }else {
                if(mapl[i][j])  SetConsoleTextAttribute(hConsole, 15);
                if(map[i][j]==2) {
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("*        ");
                }
                else if(map[i][j]==3) printf("*        ");
                else if(map[i][j]>10) printf("%c%c       ", cardsMap[map[i][j]-11][0],cardsMap[map[i][j]-11][1]);
                else printf("%d        ", map[i][j]);
            }SetConsoleTextAttribute(hConsole,8 );
        }
        printf("\n");
    }
    printf("     ");
    SetConsoleTextAttribute(hConsole, 12);
    for (int i = 0; i < 10; ++i) {
if(i%2) printf("%d    ",i);
       else printf("%d   ",i);
    }
    printf("10  11  12\n");        SetConsoleTextAttribute(hConsole, 8);
    printf("-3 for menu\n");
}
void mapLight(){
    for (int i = 0; i < 9; ++i) 
        for (int j = 0; j < 13; j++)
            mapl[i][j]=FALSE;
    for (int i = 0; i < jwlightcount; ++i) {
        mapl[jwlight[i][0]][jwlight[i][1]]=1;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; j++) {
            if(map[i][j]==2 || map[i][j]>10){
                if(i>0) mapl[i-1][j]=TRUE;
                if(i<8) mapl[i+1][j]=TRUE;
                if(j%2){
                    if(j>0 && i>0)mapl[i-1][j-1]=TRUE;
                    if(j>0 && i<8) mapl[i][j-1]=TRUE;
                    if(j<12 && i>0) mapl[i-1][j+1]=TRUE;
                    if(j<12 && i<8) mapl[i][j+1]=TRUE;
                }else{
                    if(j>0 && i>0)mapl[i][j-1]=TRUE;
                    if(j>0 && i<8) mapl[i+1][j-1]=TRUE;
                    if(j<12 && i>0) mapl[i][j+1]=TRUE;
                    if(j<12 && i<8) mapl[i+1][j+1]=TRUE;
                }
            }
        }
    }
}
void mapLightShow(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; j++) {
            printf("%d ",mapl[i][j]);
        }
        printf("\n");
    }
}

void showCardName(int n){
    printf("%c%c",cards[n][0],cards[n][1]);
}

void shuffle(struct seris * seris1,struct seris * seris2){
    int cards[8]={0,1,2,3,4,5,6,7};

    for (int i = 0; i < 4; ++i) {
        int r = rand()%(8-i);
        seris1->n= cards[r];
        cards[r]=cards[7-i];
        seris1->nxt=malloc(sizeof (struct seris));
        seris1 = seris1->nxt;
    }
    for (int i = 0; i < 4; ++i) {
        int r = rand()%(4-i);
        seris2->n= cards[r];
        cards[r]=cards[3-i];
        seris2->nxt=malloc(sizeof (struct seris));
        seris2 = seris2->nxt;
    }
}
void showShuffle(struct seris * seris){
    for (int i = 0; i < 4; ++i) {
        //showCardName(seris->n);
        handplay[i]=seris->n;
        seris=seris->nxt;
    }
    printf("\n");
}
bool movePose(int character){
    int choice,posx,posy,n,characters[8]={15,11,14,13,17,18,12,16};
    bool ms1=0;
    if(character==0){
         posx=sh.posx;
        posy=sh.posy;
        n=sh.n;
    }else if(character==1){
        posx=jw.posx;
        posy=jw.posy;
        n=jw.n;
    }else if(character==2){
        posx=js.posx;
        posy=js.posy;
        n=js.n;
    }else if(character==3){
        posx=il.posx;
        posy=il.posy;
        n=il.n;
    }else if(character==4){
        posx=ms.posx;
        posy=ms.posy;
        n=ms.n;
        ms1=1;
    }else if(character==5){
        posx=sg.posx;
        posy=sg.posy;
        n=sg.n;
    }else if(character==6){
        posx=wg.posx;
        posy=wg.posy;
        n=wg.n;
    }else if(character==7){
        posx=jb.posx;
        posy=jb.posy;
        n=jb.n;
    }
    int posx0=posx,posy0=posy,n0=n;
    bool valid=0;
    printf("%d\n",n);
    do {n=n0;
        do {
            int b = ((posy % 2) ? -1 : 1), possibleMovesCount = 0, possibleMoves[12][2];
            printf("possible moves:");
            if (map[posx + 1][posy] == 0 || (map[posx + 1][posy] >= 4 && map[posx + 1][posy] <= 7) ||
                (map[posx + 1][posy] == 1 && ms1) || map[posx + 1][posy] > 10) {
                possibleMoves[possibleMovesCount][0] = posx + 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if (map[posx - 1][posy] == 0 || (map[posx - 1][posy] >= 4 && map[posx - 1][posy] <= 7) ||
                (map[posx - 1][posy] == 1 && ms1) || map[posx - 1][posy] > 10) {
                possibleMoves[possibleMovesCount][0] = posx - 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if (map[posx][posy + 1] == 0 || (map[posx][posy + 1] >= 4 && map[posx][posy + 1] <= 7) ||
                (map[posx][posy + 1] == 1 && ms1) || map[posx][posy + 1] > 10) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if (map[posx][posy - 1] == 0 || (map[posx][posy - 1] >= 4 && map[posx][posy - 1] <= 7) ||
                (map[posx][posy - 1] == 1 && ms1) || map[posx][posy - 1] > 10) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy - 1;
                possibleMovesCount++;
            }
            if (map[posx + b][posy + 1] == 0 || (map[posx + b][posy + 1] >= 4 && map[posx + b][posy + 1] <= 7) ||
                (map[posx + b][posy + 1] == 1 && ms1) || map[posx + b][posy + 1] > 10) {
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if (map[posx + b][posy - 1] == 0 || (map[posx + b][posy - 1] >= 4 && map[posx + b][posy - 1] <= 7) ||
                (map[posx + b][posy - 1] == 1 && ms1) || map[posx + b][posy - 1] > 10) {
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }if(map[posx][posy]==4){
                for (int i = 0; i < 8; ++i) {
                    if(mapjb[i][0]!=posx && mapjb[i][1]!=posy && mapjb[i][2]==0){
                        possibleMoves[possibleMovesCount][0]=mapjb[i][0];
                        possibleMoves[possibleMovesCount][1]=mapjb[i][1];
                        possibleMovesCount++;
                    }
                }
            }
            for (int i = 0; i < possibleMovesCount; ++i) {
                printf("%d) x:%d y:%d * ", i, possibleMoves[i][0], possibleMoves[i][1]);
            }

            printf("\nenter where to move: ");
            scanf("%d", &choice);
            if (choice ==-1) break;
            else if(choice==-2){
                jackUpdate();
                if(character!= jack.n && possibleMoves[choice][0]==jack.posx && possibleMoves[choice][1]==jack.posy){
                    printf("detective won!");
                }else{
                    printf("jack won!");
                }
                getchar();
            }
            posx = possibleMoves[choice][0];
            posy = possibleMoves[choice][1];
            n--;
        } while (n>0);
        if(map[posx][posy]==6){
            jackUpdate();
            if(character==jack.n){
                system("cls");
                printf("jack won!");
                delay(1000);
                scanf("");
            }
        }
        if (map[posx][posy] > 10 || (map[posx][posy]>=1 && map[posx][posy]<=3)) {
            jackUpdate();
            if(character!= jack.n && posx==jack.posx && posy==jack.posy){
                printf("detective won!");
            }else{
                printf("jack won!");
            }
            getchar();
            printf("invalid move\n");
        } else {
            printf("valid move\n");
            valid=1;
            if(character==0){
                sh.posx=posx;
                sh.posy=posy;
            }else if(character==1){
                jw.posx=posx;
                jw.posy=posy;
            }else if(character==2){
                js.posx=posx;
                js.posy=posy;
            }else if(character==3){
                il.posx=posx;
                il.posy=posy;
            }else if(character==4){
                ms.posx=posx;
                ms.posy=posy;
            }else if(character==5){
                sg.posx=posx;
                sg.posy=posy;
            }else if(character==6){
                wg.posx=posx;
                wg.posy=posy;
            }else if(character==7){
                jb.posx=posx;
                jb.posy=posy;
            }
            map[posx][posy]=characters[character];
            map[posx0][posy0] = mapsakht[posx0][posy0];
            mapLight();
            mapPrint();
        }
    } while (!valid);
}

int moveNoTunel(int character,int ncount){
    int choice,posx,posy,n,characters[8]={15,11,14,13,17,18,12,16};
    bool ms1=0;
    if(character==0){
        posx=sh.posx;
        posy=sh.posy;
        n=sh.n;
    }else if(character==1){
        posx=jw.posx;
        posy=jw.posy;
        n=jw.n;
    }else if(character==2){
        posx=js.posx;
        posy=js.posy;
        n=js.n;
    }else if(character==3){
        posx=il.posx;
        posy=il.posy;
        n=il.n;
    }else if(character==4){
        posx=ms.posx;
        posy=ms.posy;
        n=ms.n-1;
        ms1=1;
    }else if(character==5){
        posx=sg.posx;
        posy=sg.posy;
        n=sg.n;
    }else if(character==6){
        posx=wg.posx;
        posy=wg.posy;
        n=wg.n;
    }else if(character==7){
        posx=jb.posx;
        posy=jb.posy;
        n=jb.n;
    }
    int posx0=posx,posy0=posy;
    bool valid=0;
    n=ncount;
    int n0 = n;

    printf("%d\n",n);
    do {
        n=n0;
        //printf(" *%d* ",n);
        do {
           // n=n0;
            int b = ((posy % 2) ? -1 : 1), possibleMovesCount = 0, possibleMoves[6][2];
            printf("possible moves:");
            if ((map[posx + 1][posy] == 0 || (map[posx + 1][posy] >= 4 && map[posx + 1][posy] <= 7) ||
                (map[posx + 1][posy] == 1 && ms1) || map[posx + 1][posy] > 10) && ((abs(posx+1-sg.posx)<abs(posx-sg.posx) ||
                    abs(posy-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+1-sg.posx)<=abs(posx-sg.posx) &&
                                                               abs(posy-sg.posy)<=abs(posy-sg.posy))  ))) {
                possibleMoves[possibleMovesCount][0] = posx + 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if ((map[posx - 1][posy] == 0 || (map[posx - 1][posy] >= 4 && map[posx - 1][posy] <= 7) ||
                (map[posx - 1][posy] == 1 && ms1) || map[posx - 1][posy] > 10)&& ((abs(posx-1-sg.posx)<abs(posx-sg.posx) ||
                                                                                   abs(posy-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-1-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                              abs(posy-sg.posy)<=abs(posy-sg.posy)) )))  {
                possibleMoves[possibleMovesCount][0] = posx - 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if ((map[posx][posy + 1] == 0 || (map[posx][posy + 1] >= 4 && map[posx][posy + 1] <= 7) ||
                (map[posx][posy + 1] == 1 && ms1) || map[posx][posy + 1] > 10)&& ((abs(posx-sg.posx)<abs(posx-sg.posx) ||
                                                                                   abs(posy+1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                              abs(posy+1-sg.posy)<=abs(posy-sg.posy))  ))) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if ((map[posx][posy - 1] == 0 || (map[posx][posy - 1] >= 4 && map[posx][posy - 1] <= 7) ||
                (map[posx][posy - 1] == 1 && ms1) || map[posx][posy - 1] > 10)&& ((abs(posx-sg.posx)<abs(posx-sg.posx) ||
                                                                                   abs(posy-1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                abs(posy-1-sg.posy)<=abs(posy-sg.posy))  ))) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy - 1;
                possibleMovesCount++;
            }
            if ((map[posx + b][posy + 1] == 0 || (map[posx + b][posy + 1] >= 4 && map[posx + b][posy + 1] <= 7) ||
                (map[posx + b][posy + 1] == 1 && ms1) || map[posx + b][posy + 1] > 10)&& ((abs(posx+b-sg.posx)<abs(posx-sg.posx) ||
                                                                                           abs(posy+1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+b-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                        abs(posy+1-sg.posy)<=abs(posy-sg.posy))  ))) {
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if ((map[posx + b][posy - 1] == 0 || (map[posx + b][posy - 1] >= 4 && map[posx + b][posy - 1] <= 7) ||
                (map[posx + b][posy - 1] == 1 && ms1) || map[posx + b][posy - 1] > 10)&& ((abs(posx+b-sg.posx)<abs(posx-sg.posx) ||
                                                                                           abs(posy-1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+b-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                        abs(posy-1-sg.posy)<=abs(posy-sg.posy))  ))){
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            for (int i = 0; i < possibleMovesCount; ++i) {
                printf("%d) x:%d y:%d * ", i, possibleMoves[i][0], possibleMoves[i][1]);
            }

            printf("\nenter wher to move: ");
            scanf("%d", &choice);
            if (choice < 0) break;
            posx = possibleMoves[choice][0];
            posy = possibleMoves[choice][1];
            n--;
        } while (n>0);
        if (map[posx][posy] > 10 || (map[posx][posy]>=1 && map[posx][posy]<=3)) {
            printf("invalid move\n");
        } else {
            printf("valid move\n");
            valid=1;
            if(character==0){
                sh.posx=posx;
                sh.posy=posy;
            }else if(character==1){
                jw.posx=posx;
                jw.posy=posy;
            }else if(character==2){
                js.posx=posx;
                js.posy=posy;
            }else if(character==3){
                il.posx=posx;
                il.posy=posy;
            }else if(character==4){
                ms.posx=posx;
                ms.posy=posy;
            }else if(character==5){
                sg.posx=posx;
                sg.posy=posy;
            }else if(character==6){
                wg.posx=posx;
                wg.posy=posy;
            }else if(character==7){
                jb.posx=posx;
                jb.posy=posy;
            }
            map[posx][posy]=characters[character];
            map[posx0][posy0] = mapsakht[posx0][posy0];
            mapLight();
            mapPrint();
        }
    } while (!valid);
    return n0-n;
}


int sussherlick(int mrjack) {
    int r = rand()%suscardsremain;
    showCardName(suscards[r]);
    if(mrjack){
        mrjacksher[mrjackshercount]=r;
        mrjackshercount++;
    }
    suscards[r]=suscards[suscardsremain-1];
    suscardsremain--;
 }
void move(int c,bool mrjack){
    if(c==0){//sh
        movePose(0);
        sussherlick(mrjack);
        printf(" is innocent!\n");
    }else if(c==1){//jw
        movePose(1);
        int dir;
        jwlightcount=0;
        scanf("%d",&dir);
        if(dir==0)
            for (int i = jw.posx-1; i >= 0; --i){
                if(map[i][jw.posy]==0 || map[i][jw.posy]>10 || (map[i][jw.posy]>=4 && map[i][jw.posy]<=7)) {
                    mapl[i][jw.posy] = 1;
                    jwlight[jwlightcount][0]= i;
                    jwlight[jwlightcount][1]=jw.posy;
                    jwlightcount++;
                }else break;}
        else if(dir==1)
            for (int i = 1; i <13; ++i){
                if(map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy+i]==0 || map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy+i]>10 || (map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy+i]>=4 && map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy+i]<=7)){
                    mapl[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy+i] = 1;
                    jwlight[jwlightcount][0]=jw.posx-i+(i+((jw.posy+1)%2))/2;
        jwlight[jwlightcount][1]=jw.posy + i;
        jwlightcount++;}
                else break;}
        else if(dir==2)
            for (int i = 1; i <13; ++i){
                if(map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy+i]==0 || map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy+i]>10 || (map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy+i]>=4 && map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy+i]<=7)) {
                    //printf("%d  %d",jw.posx+i-(jw.posy%2)*(i+1)/2,jw.posy+i);
                    mapl[jw.posx + i - (i+((jw.posy)%2))/2][jw.posy + i] = 1;
                    jwlight[jwlightcount][0]=jw.posx + i - (i+((jw.posy)%2))/2;
                    jwlight[jwlightcount][1]=jw.posy + i;
                    jwlightcount++;
                }else {
                    //printf("*%d**%d***",i,map[jw.posx+i-(jw.posy%2)][jw.posy+i]);
                    break;
                }
            }
        else if(dir==3)
            for (int i = jw.posx+1; i <= 8; ++i){
                if(map[i][jw.posy]!=1 && map[i][jw.posy]!=8)
                    mapl[i][jw.posy] = 1;
                else {
                    break;
                }}
        else if(dir==4)
            for (int i = 1; i <13; ++i)
                if(map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy-i]==0 || map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy-i]>10 || (map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy-i]>=4 && map[jw.posx+i-(i+((jw.posy)%2))/2][jw.posy-i]<=7)) {
                    mapl[jw.posx + i -(i+((jw.posy)%2))/2][jw.posy - i] = 1;
                    jwlight[jwlightcount][0]=jw.posx + i -(i+((jw.posy)%2))/2;
                    jwlight[jwlightcount][1]=jw.posy - i;
                    jwlightcount++;
                }else {
                    break;
                }
        else if(dir==5){
            for (int i = 1; i <13; ++i){
                if(map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy-i]==0 || map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy-i]>10 || (map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy-i]>=4 && map[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy-i]<=7)){
                    mapl[jw.posx-i+(i+((jw.posy+1)%2))/2][jw.posy-i] = 1;
                    jwlight[jwlightcount][0]=jw.posx-i+(i+((jw.posy+1)%2))/2;
                    jwlight[jwlightcount][1]=jw.posy - i;
                    jwlightcount++;}
                else break;}}
        mapLight();
       mapPrint();
    }else if(c==2){//js
        printf("first move or ability?: 0)move 1)ability\n");
        int choice;
        scanf("%d",&choice);
        if(choice){
            printf("lights to turn off: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==1) printf("%d ",i);
            }scanf("%d",&choice);
            maplights[choice][2]=0;
            map[maplights[choice][0]][maplights[choice][1]] = 3;
            printf("lights to turn on: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==0) printf("%d ",i);
            }scanf("%d",&choice);
            maplights[choice][2]=1;
            map[maplights[choice][0]][maplights[choice][1]] = 2;
            mapLight();
            mapPrint();
            movePose(2);
        }else{
            movePose(2);
            printf("lights to turn off: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==1) printf("%d ",i);
            }scanf("%d",&choice);
            maplights[choice][2]=0;
            map[maplights[choice][0]][maplights[choice][1]] = 3;
            printf("lights to turn on: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==0) printf("%d ",i);
            }scanf("%d",&choice);
            maplights[choice][2]=1;
            map[maplights[choice][0]][maplights[choice][1]] = 2;
            mapLight();
            mapPrint();
        }

    }else if(c==3){//il
        movePose(3);
        printf("which exit to open: ");
        for (int i = 0; i < 4; ++i) {
            if(mapil[i][2]){
                printf("%d) x:%d y:%d ",i,mapil[i][0],mapil[i][1]);
            }
        }int choice;
        scanf("%d",&choice);
        printf("\nwhich exit to close: ");
        for (int i = 0; i < 4; ++i) {
            if(!mapil[i][2]){
                printf("%d) x:%d y:%d ",i,mapil[i][0],mapil[i][1]);
            }
        }mapil[choice][2]=0;
        map[mapil[choice][0]][mapil[choice][1]]=6;
        scanf("%d",&choice);
        mapil[choice][2]=1;
        map[mapil[choice][0]][mapil[choice][1]]=7;
        mapPrint();
    }else if(c==4){//ms
        movePose(4);
    }else if(c==5){//sg
        printf("first move or ability?: 0)move 1)ability\n");
        int choice;
        scanf("%d",&choice);
        int mcount=3;
        if(choice) {
            while(mcount){
                printf("characters to move: ");
                for (int i = 0; i < 8; ++i) {
                    if(i!=5){
                    printf("%d) ", i);
                    showCardName(i);
                    printf(" ");
                    }
                }if(choice==5) continue;
                else{
                    scanf("%d", &choice);
                    mcount -= moveNoTunel(choice, mcount);
                }
            }
            movePose(5);
        }else{
            movePose(5);
            while(mcount){
                printf("characters to move: ");
                for (int i = 0; i < 8; ++i) {
                    if(i!=5){
                        printf("%d) ", i);
                        showCardName(i);
                        printf(" ");
                    }
                }if(choice==5) continue;
                else{
                    scanf("%d", &choice);
                    mcount -= moveNoTunel(choice, mcount);
                }
            }
        }
    }else if(c==6){//wg
        printf("move or ability?: 0)move 1)ability\n");
        int choice;
        scanf("%d",&choice);
        if(choice){
            printf("replace with: ");
            for (int i = 0; i < 8; ++i) {
                if(i!=6 && i!=2){
                    printf("%d) ", i);
                    showCardName(i);
                    printf(" ");
                }
            }
            printf(": ");
            scanf("%d",&choice);
            int tmpx,tmpy;
            switch (choice){
                case 0:
                    map[sh.posx][sh.posy]=12;
                    map[wg.posx][wg.posy]=15;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = sh.posx;
                    wg.posy = sh.posy;
                    sh.posx = tmpx;
                    sh.posy = tmpy;
                    break;
                case 1:
                    map[jw.posx][jw.posy]=12;
                    map[wg.posx][wg.posy]=11;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = jw.posx;
                    wg.posy = jw.posy;
                    jw.posx = tmpx;
                    jw.posy = tmpy;
                    break;
                case 2:
                    map[js.posx][js.posy]=12;
                    map[wg.posx][wg.posy]=14;
                    int tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = js.posx;
                    wg.posy = js.posy;
                    js.posx = tmpx;
                    js.posy = tmpy;
                    break;
                case 3:
                    map[il.posx][il.posy]=12;
                    map[wg.posx][wg.posy]=13;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = il.posx;
                    wg.posy = il.posy;
                    il.posx = tmpx;
                    il.posy = tmpy;
                    break;
                case 4:
                    map[ms.posx][ms.posy]=12;
                    map[wg.posx][wg.posy]=17;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = ms.posx;
                    wg.posy = ms.posy;
                    ms.posx = tmpx;
                    ms.posy = tmpy;
                    break;
                case 5:
                    map[sg.posx][sg.posy]=12;
                    map[wg.posx][wg.posy]=18;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = sg.posx;
                    wg.posy = sg.posy;
                    sg.posx = tmpx;
                    sg.posy = tmpy;
                    break;
                case 7:
                    map[jb.posx][jb.posy]=12;
                    map[wg.posx][wg.posy]=16;
                    tmpx=wg.posx,tmpy=wg.posy;
                    wg.posx = jb.posx;
                    wg.posy = jb.posy;
                    jb.posx = tmpx;
                    jb.posy = tmpy;
                    break;
            }mapPrint();
        }else movePose(6);
    }else if(c==7){//jb
        printf("first move or ability?: 0)move 1)ability\n");
        int choice;
        scanf("%d",&choice);
        if(choice){
            printf("tunel to open: ");
            for (int i = 0; i < 8; ++i) {
                if(mapjb[i][2]){
                    printf("%d) x:%d y:%d ",i,mapjb[i][0],mapjb[i][1]);
                }
            }
            scanf("%d",&choice);
            printf("tunel to close: ");
            for (int i = 0; i < 8; ++i) {
                if (!mapjb[i][2]) {
                    printf("%d) x:%d y:%d ", i, mapjb[i][0], mapjb[i][1]);
                }
            }mapjb[choice][2]=0;
            map[mapjb[choice][0]][mapjb[choice][1]]=4;
            scanf("%d",&choice);
            mapjb[choice][2]=1;
            map[mapjb[choice][0]][mapjb[choice][1]]=5;
            movePose(7);
        }else{
            movePose(7);
            printf("tunel to open: ");
            for (int i = 0; i < 8; ++i) {
                if(mapjb[i][2]){
                    printf("%d) x:%d y:%d ",i,mapjb[i][0],mapjb[i][1]);
                }
            }
            scanf("%d",&choice);
            printf("tunel to close: ");
            for (int i = 0; i < 8; ++i) {
                if (!mapjb[i][2]) {
                    printf("%d) x:%d y:%d ", i, mapjb[i][0], mapjb[i][1]);
                }
            }mapjb[choice][2]=0;
            map[mapjb[choice][0]][mapjb[choice][1]]=4;
            scanf("%d",&choice);
            mapjb[choice][2]=1;
            map[mapjb[choice][0]][mapjb[choice][1]]=5;
            mapPrint();
        }
    }
}
int menu(int i,int j){
    system("cls");
    printf("0) resume \n1)save\n2)exit discard\n");
    int choice;
    scanf("%d",&choice);
    switch (choice) {
        case 0:
            break;
        case 1:
            save(i,j);
            break;
        case 2:
            break;
        default:
            break;
    }
    mapPrint();
}
bool exist(int n){
    for (int i = 0; i < suscardsremain; ++i) {
        if(n==suscards[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
bool exist2(int n){
    for (int i = 0; i < mrjackshercount; ++i) {
        if(n==mrjacksher[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

int main() {
    srand(time(NULL));
    printf("enter game name: ");
    gets(strmapname);
    strcat(strmapname,".txt");
    printf("%s",strmapname);
    menu(0,0);
    mapInput();
    mapLight();
    mapPrint();
    //mapLightShow();
    int r =rand()%8,*b;
    if(jack.n>10) {
        jack.n =r;

        int i2 = 0;
        for (int i = 0; i < suscardsremain; ++i) {
            if (i != r) {
                suscards[i] = i2;
            } else suscards[i] = ++i2;
            i2++;
        }

    }
    else r=jack.n;
    showCardName(r);
  

    bool hand[4];
    int i = i0;
    for (i; i < 8; ++i) {
        if(i%2==0) {
            if (importedHand==0){
                seris1= malloc(sizeof (struct seris));
             seris2 = malloc(sizeof (struct seris));
            shuffle(seris1,seris2);
           showShuffle(seris1);
            }
            hand[0] =1;hand[1] =0;hand[2] =0;hand[3] =1;
            importedHand=0;
        }else{
            hand[0] =0;hand[1] =1;hand[2] =1;hand[3] =0;
            if (importedHand==0) showShuffle(seris2);
            importedHand=0;
        }int chrcter,j=j0;
        for (j ; j < 4; ++j) {
            for (int k = 0; k < 4 - j; ++k) {
                printf("%d)%d ", k, handplay[k]);
                showCardName(handplay[k]);
                printf(" * ");
            }
            printf("\n");
            printf("i:%d j:%d\n",i,j);
            if (hand[j]) {
                printf("suses: ");
                for (int k = 0; k < 8; ++k) {
                    if ((exist(k) || k == jack.n )&& (exist2(k)==0)) {
                        showCardName(k);
                        printf(" ");
                    }
                }
                printf("\n");
                printf("detective select: ");
                scanf("%d", &chrcter);
                if (chrcter == -3) {
                    menu(i,j);
                    j -= 1;
                } else {
                     move(handplay[chrcter],1);
                    handplay[chrcter] = handplay[3 - j];
                }
            } else {
                printf("jack select: ");
                scanf("%d", &chrcter);
                if (chrcter == -3) {
                    menu(i,j);
                    j -= 1;
                } else {
                    move(handplay[chrcter],1);
                    handplay[chrcter] = handplay[3 - j];
                }
            }
        }j0=0;
        jackUpdate();
        if(mapl[jack.posx][jack.posy]){
            printf("jack is visible!\n");

        }else{
            printf("jack is invisible!\n");

        }
        int tmp[suscardsremain],tmpcount=0;
        for (int j = 0; j < suscardsremain; ++j) {
            b=pos(suscards[j]);
            if(mapl[jack.posx][jack.posy] == mapl[b[0]][b[1]]){
                tmp[tmpcount]=suscards[j];
                tmpcount++;
            }
        }suscardsremain=tmpcount;
        for (int j = 0; j < suscardsremain; ++j) {
            suscards[j]=tmp[j];
        }
    }
    getchar();
    return 0;
}
