#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char strmapgraph[37][100]={"                                _____                                         _____",
                           "                                    /     \\                                   /     \\            ",
                           "                              _____/       \\_____                            /       \\            ",
                           "                             /     \\       /     \\                           \\       /             ",
                           "         _____              /       \\_____/       \\_____                      \\_____/         ",
                           "        /     \\             \\       /     \\       /     \\                     /     \\             ",
                           "  _____/       \\_____        \\_____/       \\_____/       \\_____         _____/       \\_____        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\      ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\   ",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /      ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\ ",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /      ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /      ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /      ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /      ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/        ",
                           " /     \\       /     \\       /     \\       /     \\       /     \\       /     \\       /            ",
                           "/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       ",
                           "\\       /     \\       /     \\       /     \\       /     \\       /     \\       /     \\             ",
                           " \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\_____/       \\        ",
                           "       \\       /                   \\       /     \\       /     \\       /     \\       /            ",
                           "        \\_____/                     \\_____/       \\_____/       \\_____/       \\_____/      ",
                           "                                          \\       /     \\       /                                ",
                           "                                           \\_____/       \\_____/                             ",
                           "                                                 \\       /                                        ",
                           "                                                  \\_____/                                  "};

int map[9][13];
bool mapl[9][13];
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
void mapPrint(){
    char cardsMap[8][2]={"JW","WG","IL","JS","SH","JB","MS","SG"};
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,8 );
    system("cls");
    int x=0,xx=-1;
    for (int i = 1; i <37 ; ++i) {
        for (int j = 0; j < 94; ++j) {
            //bug fix
            if(j==10 && i == 32) {
                if (mapl[7][1])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",7);
            }else if(j==12 && i == 32) {
                if (mapl[7][1])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",1);
            }else if((j==24 && i == 8) || (j==26 && i==8)) {
                printf("_");
            }else if((j==68 && i == 8) || (j==66 && i==8)) {
                printf("_");
            }else if((j==52 && i == 4) || (j==54 && i==4)) {
                printf("_");
            }else if(j==38 && i == 32) {
                if (mapl[7][5])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",7);
            }else if(j==40 && i == 32) {
                if (mapl[7][5])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",5);
            }else if(j==52 && i == 36) {
                if (mapl[8][7])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",8);
            }else if(j==54 && i == 36) {
                if (mapl[8][7])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",7);
            }else if(j==80 && i == 32) {
                if (mapl[7][11])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",7);
            }else if(j==82 && i == 32) {
                if (mapl[7][11])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",11);
                j++;
            }else if(j==80 && i == 4) {
                if (mapl[0][11])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",0);
            }else if(j==82 && i == 4) {
                if (mapl[0][11])    SetConsoleTextAttribute(hConsole, 15);
                printf("%d",11);
                j++;
            }
                //
            else if((j-3)%14==0 &&((i-6)%4==0) &&map[xx][((j+4)/7)-1]!=8 && xx>-1) {
                if(mapl[xx][((j+4)/7)-1]) SetConsoleTextAttribute(hConsole, 15);
                printf("%d",xx);
            }
            else if((j-5)%14==0 &&((i-6)%4==0) && map[xx][((j+2)/7)-1]!=8&& xx>-1) {
                if(mapl[xx][((j+2)/7)-1]) SetConsoleTextAttribute(hConsole, 15);
                printf("%d",((j+2)/7)-1);
                if(((j-5)/7)>9) j++;
            }
            else if((j-10)%14==0 && (i%4==0 )&& map[xx][(j-10)/7]!=8&& xx>-1) {
                if(mapl[xx][((j+4)/7)-1]) SetConsoleTextAttribute(hConsole, 15);
                printf("%d",xx);
            }
            else if((j-12)%14==0 && (i%4==0)&& map[xx][(j-12)/7]!=8&& xx>-1) {
                if(mapl[xx][((j+2)/7)-1]) SetConsoleTextAttribute(hConsole, 15);
                printf("%d",(j-5)/7);
                if(((j-5)/7)>9) j++;
            }
            else  printf("%c",strmapgraph[i][j]);

            SetConsoleTextAttribute(hConsole, 8);
            if((j-4)%14==0 && (i%4==0 && i>0)){
                if(map[x][(j-4)/7]==8){
                    //printf("\",map[x][(j-4)/7]);
                }else if(map[x][(j-4)/7]==1){
                    SetConsoleTextAttribute(hConsole, 238);
                    printf("\b#");
                }else if(map[x][(j-4)/7]==2){
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("\b*");
                }else if(map[x][(j-4)/7]==3){
                    printf("\b*");
                }else if(map[x][(j-4)/7]==4){
                    SetConsoleTextAttribute(hConsole, 18);
                    printf("\b@");
                }else if(map[x][(j-4)/7]==5){
                    printf("\b@");
                }else if(map[x][(j-4)/7]==6){
                    printf("\b\bEX");
                }else if(map[x][(j-4)/7]==7){
                    printf("\b\bEX");
                }else if(map[x][(j-4)/7]>10){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\b\b%c%c",cardsMap[map[x][(j-4)/7]-11][0],cardsMap[map[x][(j-4)/7]-11][1]);
                }
            }
            if((j-11)%14==0 && ((i+6)%4==0)){
                if(map[x][(j-4)/7]==8){
                    //printf("\",map[x][(j-4)/7]);
                }else if(map[x][(j-4)/7]==1){
                    SetConsoleTextAttribute(hConsole, 238);
                    printf("\b#");
                }else if(map[x][(j-4)/7]==2){
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("\b*");
                }else if(map[x][(j-4)/7]==3){
                    printf("\b*");
                }else if(map[x][(j-4)/7]==4){
                    SetConsoleTextAttribute(hConsole, 18);
                    printf("\b@");
                }else if(map[x][(j-4)/7]==5){
                    printf("\b@");
                }else if(map[x][(j-4)/7]==6){
                    printf("\b\bEX");
                }else if(map[x][(j-4)/7]==7){
                    printf("\b\bEX");
                }else if(map[x][(j-4)/7]>10){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\b\b%c%c",cardsMap[map[x][(j-4)/7]-11][0],cardsMap[map[x][(j-4)/7]-11][1]);
                }
            }
        }if((i+1)%4==0) xx++;
        if((i)%4==0) x++;
        SetConsoleTextAttribute(hConsole, 8);
        printf("\n");
    }

}

void api(){
    // printf("http://mrjackgame.freehost.io/tel.php?t&id=136307890&ghhh=ghhh");

    //char id[16] ;
    //int in;
    //scanf("%s",&id);
    //scanf("%d",&in);
    //mrjackalert(id,in);

    //FILE *fp = _popen("C:\\Users\\NP\\CLionProjects\\zinali\\curl\\curl.exe  http://mrjackgame.freehost.io/tel.php?id=4136307890","r");
    //fgets(str,1000,fp);
    //printf("%s ",str);
    //_pclose(fp);

}

int main(void){
    map[0][0]=8;
    map[7][0]=8;
    map[8][0]=8;
    map[0][1]=8;
    map[3][1]=8;
    map[4][1]=8;
    map[8][1]=8;
    map[0][2]=8;
    map[7][2]=8;
    map[8][2]=8;
    map[0][3]=8;
    map[1][3]=8;
    map[7][3]=8;
    map[8][3]=8;
    map[7][4]=8;
    map[8][4]=8;
    map[8][5]=8;
    map[8][6]=8;
    map[0][7]=8;
    map[0][8]=8;
    map[8][8]=8;
    map[0][9]=8;
    map[1][9]=8;
    map[8][9]=8;
    map[0][10]=8;
    map[7][10]=8;
    map[8][10]=8;
    map[8][11]=8;
    map[0][12]=8;
    map[6][12]=8;
    map[7][12]=8;
    map[8][12]=8;
    int num=28;
    FILE * fp;
    char strmaptmp[128],strmapname[32];
    strmaptmp[0]='\0';
    strcat(strmaptmp,"C:\\Users\\NP\\CLionProjects\\projectzinal\\");
    gets(strmapname);
    strcat(strmaptmp,strmapname);
    strcat(strmaptmp,".txt");
    fp = fopen(strmaptmp, "w");
    int chararr={11,12,13,14,15,16,17,18},elements[14]={6,2,6,2,2,2,1,1,1,1,1,1,1,1};
    while(num){
        int posx,posy,inp;
        mapPrint();
        printf("0) on light * remain: %d\n1) off light * remain: %d\n2) open tunnel * remain: %d\n3) closed tunnel * remain: %d\n4) open exit * remain: %d  \n5) closed exit * remain: %d\n6) JW * remain: %d\n7) WG * remain: %d\n8) IL * remain: %d\n9) JS * remain: %d\n10) SH * remain: %d\n11) JB * remain: %d\n12) MS * remain: %d\n13) SG * remain: %d\n",elements[0],elements[1],elements[2],elements[3],elements[4],elements[5],elements[6],elements[7],elements[8],elements[9],elements[10],elements[11],elements[12],elements[13]);
        scanf("%d %d %d",&posx,&posy,&inp);

        if(map[posx][posy]==0 && elements[inp]>0){
            elements[inp]--;
            map[posx][posy]=inp+(inp>5?5:2);
            num--;
        }
    }
    int posx,posy,inp,housecount=0;
    do {
        mapPrint();
        scanf("%d %d %d",&posx,&posy,&inp);
        if(map[posx][posy]==0 && inp==1){
            map[posx][posy]=1;
            housecount++;
        }
    } while (inp!=0);
    fprintf(fp,"%d\n",28+32+housecount);
    fprintf(fp,"0 0 8\n"
               "7 0 8\n"
               "8 0 8\n"
               "0 1 8\n"
               "8 1 8\n"
               "0 2 8\n"
               "7 2 8\n"
               "8 2 8\n"
               "0 3 8\n"
               "1 3 8\n"
               "7 3 8\n"
               "8 3 8\n"
               "7 4 8\n"
               "8 4 8\n"
               "8 5 8\n"
               "8 6 8\n"
               "0 7 8\n"
               "0 8 8\n"
               "8 8 8\n"
               "0 9 8\n"
               "1 9 8\n"
               "8 9 8\n"
               "0 10 8\n"
               "7 10 8\n"
               "8 10 8\n"
               "8 11 8\n"
               "0 12 8\n"
               "6 12 8\n"
               "7 12 8\n"
               "8 12 8\n");

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            if(map[i][j]){
                fprintf(fp,"%d %d %d\n",i,j,map[i][j]);
            }
        }
    }
    fprintf(fp,"0\n"
               "0 0\n"
               "11\n"
               "0\n"
               "0\n"
               "0\n"
               "0");
    fclose(fp);

    getchar();
    scanf("");
    return 0;
}