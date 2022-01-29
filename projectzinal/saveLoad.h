void save(int i0,int j0){
    char text[20];
    char strmaptmp[128];
    sprintf(text, "%d", savecount);
    FILE *fp;
    strmaptmp[0]='\0';
    strcat(strmaptmp,strmap);
    strcat(strmaptmp,strmapname);
    strcat(strmaptmp,text);
    strcat(strmaptmp,".txt");
    savecount++;
    //printf("%s +++",strmaptmp);
    //delay(5);
    fp = fopen(strmaptmp, "w");
    fprintf(fp,"%d\n",mapelements);
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
    for (int i = 0; i < mrjackshercount; ++i) {
        fprintf(fp,"%d ",mrjacksher[i]);
    }
    fprintf(fp,"\n");
    fprintf(fp,"%d",savecount);

    //  delay(10000);
    fclose(fp);

    //  getchar();
}
void save2(int i0,int j0){
    //char text[20];
    char strmaptmp[128];
    //sprintf(text, "%d", savecount);
    FILE *fp;
    strmaptmp[0]='\0';
    strcat(strmaptmp,strmap);
    strcat(strmaptmp,strmapname);
    //strcat(strmaptmp,text);
    strcat(strmaptmp,".bin");
    savecount++;
    //printf("%s +++",strmaptmp);
    //delay(5);
    fp = fopen(strmaptmp, "wb");
    //fprintf(fp,"76\n");
    int num=mapelements;
    fwrite(&num, sizeof(int), 1, fp);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            if(mapsakht[i][j]){
                //fprintf(fp,"%d %d %d\n",i,j,mapsakht[i][j]);
                fwrite(&i, sizeof(int), 1, fp);
                fwrite(&j, sizeof(int), 1, fp);
                fwrite(&mapsakht[i][j], sizeof(int), 1, fp);
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            if(map[i][j]>10){
                //fprintf(fp,"%d %d %d\n",i,j,map[i][j]);
                fwrite(&i, sizeof(int), 1, fp);
                fwrite(&j, sizeof(int), 1, fp);
                fwrite(&map[i][j], sizeof(int), 1, fp);
            }
        }
    }
    //fprintf(fp,"%d\n",jwlightcount);
    fwrite(&jwlightcount, sizeof(int), 1, fp);
    for (int i = 0; i < jwlightcount; ++i) {
        //printf("%d %d %d\n",jwlight[i][0],jwlight[i][1],jwlight[i][2]);
        //fprintf(fp,"%d %d\n",jwlight[i][0],jwlight[i][1]);
        fwrite(&jwlight[i][0], sizeof(int), 1, fp);
        fwrite(&jwlight[i][1], sizeof(int), 1, fp);
    }
    //fprintf(fp,"%d %d\n",i0,j0);
    fwrite(&i0, sizeof(int), 1, fp);
    fwrite(&j0, sizeof(int), 1, fp);
    //fprintf(fp,"%d\n",jack.n);
    fwrite(&jack.n, sizeof(int), 1, fp);
    //fprintf(fp,"%d\n",suscardsremain);
    fwrite(&suscardsremain, sizeof(int), 1, fp);
    for (int i = 0; i < suscardsremain; ++i) {
        //fprintf(fp,"%d ",suscards[i]);
        fwrite(&suscards[i], sizeof(int), 1, fp);
    }      // fprintf(fp,"\n");
    //fprintf(fp,"1\n");
    num =1;
    fwrite(&num, sizeof(int), 1, fp);
    if(i0%2==0){
        for (int i = 0; i < 4; ++i) {
            //fprintf(fp,"%d ",handplay[i]);
            fwrite(&handplay[i], sizeof(int), 1, fp);
        }//   fprintf(fp,"\n");
        struct seris * tmpseris=seris2;
        for (int i = 0; i < 4; ++i) {
            //fprintf(fp,"%d ",tmpseris->n);
            fwrite(&tmpseris->n, sizeof(int), 1, fp);
            tmpseris = tmpseris->nxt;
        }
    }else{
        for (int i = 0; i < 4; ++i) {
            //fprintf(fp,"%d ",handplay[i]);
            fwrite(&handplay[i], sizeof(int), 1, fp);
        }
    }
    //fprintf(fp,"\n");
    //fprintf(fp,"%d\n",mrjackshercount);
    fwrite(&mrjackshercount, sizeof(int), 1, fp);
    for (int i = 0; i < mrjackshercount; ++i) {
        //fprintf(fp,"%d ",mrjacksher[i]);
        fwrite(&mrjacksher[i], sizeof(int), 1, fp);
    }
    //fprintf(fp,"\n");
    //fprintf(fp,"%d",savecount);
    fwrite(&savecount, sizeof(int), 1, fp);
    //  delay(10000);
    fclose(fp);

    //  getchar();
}

bool mapInput(bool undo){
    int lightcount=0,ilcount=0,jbcount=0;
    char strmaptmp[128];
    strmaptmp[0]='\0';
    FILE *fp;
    strcat(strmaptmp,strmap);
    strcat(strmaptmp,strmapname);
    if(undo) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 13; ++j) {
                map[i][j]=0;
            }
        }
        char text[20];
        sprintf(text, "%d", savecount);
        strcat(strmaptmp,text);
    }
    strcat(strmaptmp,".txt");
    //printf("%s***+",strmaptmp);
    //delay(5);
    fp = fopen(strmaptmp, "r");
    if(fp==NULL && undo==0){
        char stringmap[128]="C:\\Users\\NP\\CLionProjects\\projectzinal\\";
        strcat(stringmap,stringmapname);
        strcat(stringmap,".txt");
        fp = fopen(stringmap, "r");
    }else if(fp==NULL && undo==1){
        return 0;
    }
    int n;
    fscanf(fp,"%d",&n);
    mapelements=n;
    printf("%d\n",n);
    for (int i = 0; i < n; ++i) {
        int x,y,m;
        fscanf(fp,"%d %d %d",&x,&y,&m);
        //     printf("%d %d %d\n",x,y,m);
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
    }fscanf(fp,"%d",&savecount);
    fclose(fp);
    return 1;
}

bool mapInput2(bool undo){
    int lightcount=0,ilcount=0,jbcount=0;
    char strmaptmp[128];
    strmaptmp[0]='\0';
    FILE *fp;
    strcat(strmaptmp,strmap);
    strcat(strmaptmp,strmapname);
    if(undo) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 13; ++j) {
                map[i][j]=0;
            }
        }
        char text[20];
        sprintf(text, "%d", savecount);
        strcat(strmaptmp,text);
    }
    strcat(strmaptmp,".bin");
    //printf("%s***+",strmaptmp);
    //delay(5);
    fp = fopen(strmaptmp, "rb");
    if(fp==NULL && undo==0){
        fp = fopen("C:\\Users\\NP\\CLionProjects\\projectzinal\\map.txt", "r");
    }else if(fp==NULL && undo==1){
        return 0;
    }
    int n;
    fread(&n, sizeof(int), 1, fp);
    mapelements=n;
    printf("%d\n",n);
    for (int i = 0; i < n; ++i) {
        int x,y,m;
        //fscanf(fp,"%d %d %d",&x,&y,&m);
        fread(&x, sizeof(int), 1, fp);
        fread(&y, sizeof(int), 1, fp);
        fread(&m, sizeof(int), 1, fp);

        //     printf("%d %d %d\n",x,y,m);
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
    //fscanf(fp,"%d",&n);
    fread(&n, sizeof(int), 1, fp);
    jwlightcount=n;
    for (int i = 0; i < n; ++i) {
        fscanf(fp,"%d %d",&jwlight[i][0],&jwlight[i][1]);
    }
    //fscanf(fp,"%d %d",&i0,&j0);
    fread(&i0, sizeof(int), 1, fp);
    fread(&j0, sizeof(int), 1, fp);
    printf(" %d %d ",i0,j0);
    //fscanf(fp,"%d",&jack.n);
    //fscanf(fp,"%d",&n);
    fread(&jack.n, sizeof(int), 1, fp);
    fread(&n, sizeof(int), 1, fp);

    if(n>0){
        suscardsremain=n;
        for (int i = 0; i < n; ++i) {
            //fscanf(fp,"%d",&suscards[i]);
            fread(&suscards[i], sizeof(int), 1, fp);
        }
    }   //fscanf(fp,"%d",&n);
    fread(&n, sizeof(int), 1, fp);
    if (n){
        importedHand=1;

        for (int i = 0; i < 4; ++i) {
            //fscanf(fp, "%d", &handplay[i]);
            fread(&handplay[i], sizeof(int), 1, fp);
        }
        if(i0%2==0){
            seris2 =malloc(sizeof (struct seris));
            struct seris * tmpseris=seris2;
            for (int i = 0; i < 4; ++i) {
                //fscanf(fp, "%d", &(tmpseris->n));
                fread(&(tmpseris->n), sizeof(int), 1, fp);
                tmpseris->nxt = malloc(sizeof (struct seris));
                tmpseris = tmpseris->nxt;
            }
        }
    }
    //fscanf(fp,"%d",&n);
    fread(&n, sizeof(int), 1, fp);
    mrjackshercount=n;
    for (int i = 0; i < n; ++i) {
        //fscanf(fp,"%d",&(mrjacksher[i]));
        fread(&(mrjacksher[i]), sizeof(int), 1, fp);
    }//fscanf(fp,"%d",&savecount);
    fread(&savecount, sizeof(int), 1, fp);
    return 1;
}
