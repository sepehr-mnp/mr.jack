void mapPrint2(){
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
                    SetConsoleTextAttribute(hConsole, 34);
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
                    printf("\b\bex");
                }else if(map[x][(j-4)/7]>10){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\b\b%c%c",cardsMap[map[x][(j-4)/7]-11][0],cardsMap[map[x][(j-4)/7]-11][1]);
                }
            }
            if((j-11)%14==0 && ((i+6)%4==0)){
                if(map[x][(j-4)/7]==8){
                    //printf("\",map[x][(j-4)/7]);
                }else if(map[x][(j-4)/7]==1){
                    SetConsoleTextAttribute(hConsole, 34);
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
                    printf("\b\bex");
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
