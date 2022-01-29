
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