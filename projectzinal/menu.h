#include <time.h>
bool tel=0;
char id[16] ;

void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);

}


int startMenu(){
    system("cls");
    printf("0) start new game \n1)tel ver\n2)rewind\n3)load\n4)choice: ");
    int choice;
    scanf("%d",&choice);
    bool t =FALSE;
    switch (choice) {
        case 1:
            tel=1;
            printf("\ngo to @Mrjackgamebot bot in telegram.\nstart it.\nget your chat id.\nid:");
            scanf("%s",&id);
            return 1;
            break;
        case 2:
            do{
                mapLight();
                mapPrint();
                t = mapInput(1);
                if(t==0)
                    printf("^^^ %d ^^^",t);
                delay(5);
            }while(t);
            return 0;
            break;
        case 3:
            return 2;
        default:
            return 1;
    }
}
int menu(int i,int j){
    system("cls");
    printf("0) resume \n1)save\n2)undo\n");
    int choice;
    scanf("%d",&choice);
    char strmaptmp[128];
    int tmpsaveacount = savecount-1;
    switch (choice) {
        case 0:
            break;
        case 1:
            save2(i,j);
            break;
        case 2:
            strmaptmp[0]='\0';
            FILE *fp;
            strcat(strmaptmp,strmap);
            strcat(strmaptmp,strmapname);
            char text[20];

            savecount-=2;
            mapInput(1);
            sprintf(text, "%d", tmpsaveacount);
            strcat(strmaptmp,text);
            strcat(strmaptmp,".txt");
            remove(strmaptmp);
            mapLight();
            mapPrint();
            return -1;
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
