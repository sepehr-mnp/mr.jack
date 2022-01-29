#include "func.h"


int main() {
    srand(time(NULL));
    printf("enter game name: ");
    gets(strmapname);
    int st = startMenu(0,0);
    if(!st) return 0;
    else if(st==2) mapInput2(0);
    else mapInput(0);
    save_starting_point:
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
   if(tel==0) showCardName(r);
else {
    mrjackalert(id,r);
       //printf("{{%d}}",r);

}
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
                    int t = menu(i,j);
                    if(t==-1) goto save_starting_point;
                    j -= 1;
                } else {
                 //    move(handplay[chrcter],1);
                    handplay[chrcter] = handplay[3 - j];
                    save(i,j+1);
                }
            } else {
                printf("jack select: ");
                scanf("%d", &chrcter);
                if (chrcter == -3) {
                    int t = menu(i,j);
                    if(t==-1) goto save_starting_point;
                    j -= 1;
                } else {
                   //move(handplay[chrcter],1);
                    handplay[chrcter] = handplay[3 - j];
                    save(i,j+1);
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
