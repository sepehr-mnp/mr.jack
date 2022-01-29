
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
//
        posx=posx0;
        posy=posy0;
        //
        do {

            int b = ((posy % 2) ? -1 : 1), possibleMovesCount = 0, possibleMoves[12][2];
            printf("possible moves:");
            if ((map[posx + 1][posy] == 0 || (map[posx + 1][posy] >= 4 && map[posx + 1][posy] <= 7) ||
                (map[posx + 1][posy] == 1 && ms1) || map[posx + 1][posy] > 10) && posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8){
                possibleMoves[possibleMovesCount][0] = posx + 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if ((map[posx - 1][posy] == 0 || (map[posx - 1][posy] >= 4 && map[posx - 1][posy] <= 7) ||
                (map[posx - 1][posy] == 1 && ms1) || map[posx - 1][posy] > 10)  && posy>=0 && posy<=12 && posx-1>=0 && posx-1<=8){
                possibleMoves[possibleMovesCount][0] = posx - 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if ((map[posx][posy + 1] == 0 || (map[posx][posy + 1] >= 4 && map[posx][posy + 1] <= 7) ||
                (map[posx][posy + 1] == 1 && ms1) || map[posx][posy + 1] > 10)  && posy+1>=0 && posy+1<=12 && posx>=0 && posx<=8){
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if ((map[posx][posy - 1] == 0 || (map[posx][posy - 1] >= 4 && map[posx][posy - 1] <= 7) ||
                (map[posx][posy - 1] == 1 && ms1) || map[posx][posy - 1] > 10)  && posy-1>=0 && posy-1<=12 && posx>=0 && posx<=8){
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy - 1;
                possibleMovesCount++;
            }
            if ((map[posx + b][posy + 1] == 0 || (map[posx + b][posy + 1] >= 4 && map[posx + b][posy + 1] <= 7) ||
                (map[posx + b][posy + 1] == 1 && ms1) || map[posx + b][posy + 1] > 10)  && posy+1>=0 && posy+1<=12 && posx+b>=0 && posx+b<=8){
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if ((map[posx + b][posy - 1] == 0 || (map[posx + b][posy - 1] >= 4 && map[posx + b][posy - 1] <= 7) ||
                (map[posx + b][posy - 1] == 1 && ms1) || map[posx + b][posy - 1] > 10)  && posy-1>=0 && posy-1<=12 && posx+b>=0 && posx+b<=8){
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy - 1;
                possibleMovesCount++;
            }if(map[posx][posy]==4){
                for (int i = 0; i < 8; ++i) {
                    if((mapjb[i][0]!=posx || mapjb[i][1]!=posy) && mapjb[i][2]==0){
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
                if(character!= jack.n && posx==jack.posx && posy==jack.posy && detctive){
                    system("cls");
                    printf("detective won!");
                    scanf("");
                }else if(detctive){
                    system("cls");
                    printf("jack won!");
                    scanf("");
                }
                getchar();
            }else{
            posx = possibleMoves[choice][0];
            posy = possibleMoves[choice][1];
            n--;}
        } while (n>0);
        if(map[posx][posy]==6){
            int mrjackposx0=jack.posx,mrjackposy0=jack.posy;
            jackUpdate();
            if(character==jack.n && mapl[mrjackposx0][mrjackposy0] ){
                system("cls");
                printf("jack won!");
                //delay(1000);
                scanf("");
            }
        }
        if (map[posx][posy] > 10 || (map[posx][posy]>=1 && map[posx][posy]<=3)) {
            jackUpdate();
            if(map[posx][posy] > 10 && character!= jack.n && posx==jack.posx && posy==jack.posy&& detctive){
                system("cls");
                printf("detective won!");
                scanf("");
            }else if(map[posx][posy] > 10 && (posx0!=posx || posy0!=posy) && detctive){
                system("cls");
                printf("jack won!");
                scanf("");
            }else{
                printf("invalid move\n");
            }
            getchar();

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

        posx=posx0;
        posy=posy0;
        //printf(" *%d* ",n);
        do {
            // n=n0;
            int b = ((posy % 2) ? -1 : 1), possibleMovesCount = 0, possibleMoves[6][2];
            printf("possible moves:");
            if (((map[posx + 1][posy] == 0 || (map[posx + 1][posy] >= 4 && map[posx + 1][posy] <= 7) ||
                 (map[posx + 1][posy] == 1 && ms1) || map[posx + 1][posy] > 10) && ((abs(posx+1-sg.posx)<abs(posx-sg.posx) ||
                                                                                     abs(posy-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+1-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                abs(posy-sg.posy)<=abs(posy-sg.posy))  )))&& posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8) {
                possibleMoves[possibleMovesCount][0] = posx + 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if (((map[posx - 1][posy] == 0 || (map[posx - 1][posy] >= 4 && map[posx - 1][posy] <= 7) ||
                 (map[posx - 1][posy] == 1 && ms1) || map[posx - 1][posy] > 10)&& ((abs(posx-1-sg.posx)<abs(posx-sg.posx) ||
                                                                                    abs(posy-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-1-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                               abs(posy-sg.posy)<=abs(posy-sg.posy)) ))) && posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8) {
                possibleMoves[possibleMovesCount][0] = posx - 1;
                possibleMoves[possibleMovesCount][1] = posy;
                possibleMovesCount++;
            }
            if (((map[posx][posy + 1] == 0 || (map[posx][posy + 1] >= 4 && map[posx][posy + 1] <= 7) ||
                 (map[posx][posy + 1] == 1 && ms1) || map[posx][posy + 1] > 10)&& ((abs(posx-sg.posx)<abs(posx-sg.posx) ||
                                                                                    abs(posy+1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                 abs(posy+1-sg.posy)<=abs(posy-sg.posy))  )))&& posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if (((map[posx][posy - 1] == 0 || (map[posx][posy - 1] >= 4 && map[posx][posy - 1] <= 7) ||
                 (map[posx][posy - 1] == 1 && ms1) || map[posx][posy - 1] > 10)&& ((abs(posx-sg.posx)<abs(posx-sg.posx) ||
                                                                                    abs(posy-1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                 abs(posy-1-sg.posy)<=abs(posy-sg.posy))  )))&& posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8) {
                possibleMoves[possibleMovesCount][0] = posx;
                possibleMoves[possibleMovesCount][1] = posy - 1;
                possibleMovesCount++;
            }
            if (((map[posx + b][posy + 1] == 0 || (map[posx + b][posy + 1] >= 4 && map[posx + b][posy + 1] <= 7) ||
                 (map[posx + b][posy + 1] == 1 && ms1) || map[posx + b][posy + 1] > 10)&& ((abs(posx+b-sg.posx)<abs(posx-sg.posx) ||
                                                                                            abs(posy+1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+b-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                         abs(posy+1-sg.posy)<=abs(posy-sg.posy))  )))&& posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8) {
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy + 1;
                possibleMovesCount++;
            }
            if (((map[posx + b][posy - 1] == 0 || (map[posx + b][posy - 1] >= 4 && map[posx + b][posy - 1] <= 7) ||
                 (map[posx + b][posy - 1] == 1 && ms1) || map[posx + b][posy - 1] > 10)&& ((abs(posx+b-sg.posx)<abs(posx-sg.posx) ||
                                                                                            abs(posy-1-sg.posy)<abs(posy-sg.posy) ) && ((abs(posx+b-sg.posx)<=abs(posx-sg.posx) &&
                                                                                                                                         abs(posy-1-sg.posy)<=abs(posy-sg.posy))  )))&& posy>=0 && posy<=12 && posx+1>=0 && posx+1<=8){
                possibleMoves[possibleMovesCount][0] = posx + b;
                possibleMoves[possibleMovesCount][1] = posy - 1;
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
        printf("select direction: 0)up 1)right-up 2)right-down 3)down 4)left-down 5)left-up ");
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
                if(maplights[i][2]==1) printf("%d) x:%d y:%d ",i,maplights[i][0],maplights[i][1]);
            }scanf("%d",&choice);
            printf("lights to turn on: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==0) printf("%d) x:%d y:%d ",i,maplights[i][0],maplights[i][1]);
            }
            maplights[choice][2]=0;
            map[maplights[choice][0]][maplights[choice][1]] = 3;
            scanf("%d",&choice);
            maplights[choice][2]=1;
            map[maplights[choice][0]][maplights[choice][1]] = 2;
            mapLight();
            mapPrint();
            movePose(2);
        }else{
            movePose(2);
            printf("lights to turn off: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==1) printf("%d) x:%d y:%d ",i,maplights[i][0],maplights[i][1]);
            }scanf("%d",&choice);
            printf("lights to turn on: ");
            for (int i = 0; i < 8; ++i) {
                if(maplights[i][2]==0) printf("%d) x:%d y:%d ",i,maplights[i][0],maplights[i][1]);
            }
            maplights[choice][2]=0;
            map[maplights[choice][0]][maplights[choice][1]] = 3;

            scanf("%d",&choice);

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
                    if(choice==1) jwlightcount=0;
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
                    if(choice==1) jwlightcount=0;
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
                if(i!=6 ){
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
                    jwlightcount=0;
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
