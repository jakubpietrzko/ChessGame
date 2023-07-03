#include <stdio.h>
#include <math.h>
#define PRZEGRANA -10000
#define WYGRANA 10000
#define PUSTE 12

int czy_szachowane(char plansza[8][8], int x,int y,int tryb)
{
    if(!tryb)
    {
       if(plansza[x+1][y+1]==5 || plansza[x-1][y+1]==5 )
       {return 1;}
       int i=1;
       while((y+i<=7)&&(plansza[x][y+i]==12 || i==1))
       {if(plansza[x][y+i]==1 || plansza[x][y+i]==2)
           {
               return 1;
           }
           if(i==1 && plansza[x][y+i]==0)
           {return 1;}
           if(plansza[x][y+i]!=12)
           {break;}
           i++;
       }
        i=1;
        while((y-i>=0)&&(plansza[x][y-i]==12 || i==1))
        {if(plansza[x][y-i]==1 || plansza[x][y-i]==2)
            {
                return 1;
            }
            if(i==1 && plansza[x][y-i]==0)
            {return 1;}
            if(plansza[x][y-i]!=12)
            {break;}
            i++;
        }
       i=1;
        while(x+i<=7 && plansza[x+i][y]==12 || i==1)
        {if(plansza[x+i][y]==1 || plansza[x+1][y]==2)
            {
                return 1;
            }
            if(i==1 && plansza[x+1][y]==0)
            {return 1;}
            if(plansza[x+1][y]!=12)
            {break;}
            i++;
        }
        i=1;
        while(x-i>=0 && plansza[x-i][y]==12 || i==1)
        {if(plansza[x-i][y]==1 || plansza[x-i][y]==2)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y]==0)
            {return 1;}
            if(plansza[x-i][y]!=12)
            {break;}
            i++;
        }
        if(plansza[x+1][y+2]==4 || plansza[x-1][y+2]==4 || plansza[x+1][y-2]==4 || plansza[x-1][y-2]==4 || plansza[x+2][y+1]==4 || plansza[x+2][y-1]==4 || plansza[x-2][y+1]==4 || plansza[x-2][y-1]==4)
        {return 1;}
        i=1;
        while(y-i>=0 && x-i >=0 && plansza[x-i][y-i]==12 || i==1)
        {if(plansza[x-i][y-i]==1 || plansza[x-i][y-i]==3)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y-i]==0)
            {return 1;}
            if(plansza[x-i][y-i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y+i<=7 && x-i >=0 && plansza[x-i][y+i]==12 || i==1)
        {if(plansza[x-i][y+i]==1 || plansza[x-i][y+i]==3)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y+i]==0)
            {return 1;}
            if(plansza[x-i][y+i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y-i>=0 && x+i <=7 && plansza[x+i][y-i]==12 || i==1)
        {if(plansza[x+i][y-i]==1 || plansza[x+i][y-i]==3)
            {
                return 1;
            }
            if(i==1 && plansza[x+i][y-i]==0)
            {return 1;}
            if(plansza[x+i][y-i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y+i<=7 && x+i <=7 && plansza[x+i][y+i]==12 || i==1)
        {if(plansza[x+i][y+i]==1 || plansza[x+i][y+i]==3)
            {
                return 1;
            }
            if(i==1 && plansza[x+i][y+i]==0)
            {return 1;}
            if(plansza[x+i][y+i]!=12)
            {break;}
            i++;
        }
        return 0;
    }
    else
    {
        if(plansza[x-1][y-1]==5 || plansza[x+1][y-1]==5 )
        {return 1;}
        int i=1;
        while((y+i<=7)&&(plansza[x][y+i]==12 || i==1))
        {if(plansza[x][y+i]==7 || plansza[x][y+i]==8)
            {
                return 1;
            }
            if(i==1 && plansza[x][y+i]==6)
            {return 1;}
            if(plansza[x][y+i]!=12)
            {break;}
            i++;
        }
        i=1;
        while((y-i>=0)&&(plansza[x][y-i]==12 || i==1))
        {if(plansza[x][y-i]==7 || plansza[x][y-i]==8)
            {
                return 1;
            }
            if(i==1 && plansza[x][y-i]==6)
            {return 1;}
            if(plansza[x][y-i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(x+i<=7 && plansza[x+i][y]==12 || i==1)
        {if(plansza[x+i][y]==7 || plansza[x+1][y]==8)
            {
                return 1;
            }
            if(i==1 && plansza[x+1][y]==6)
            {return 1;}
            if(plansza[x+1][y]!=12)
            {break;}
            i++;
        }
        i=1;
        while(x-i>=0 && plansza[x-i][y]==12 || i==1)
        {if(plansza[x-i][y]==7 || plansza[x-i][y]==8)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y]==6)
            {return 1;}
            if(plansza[x-i][y]!=12)
            {break;}
            i++;
        }
        if(plansza[x+1][y+2]==4 || plansza[x-1][y+2]==4 || plansza[x+1][y-2]==4 || plansza[x-1][y-2]==4 || plansza[x+2][y+1]==4 || plansza[x+2][y-1]==4 || plansza[x-2][y+1]==4 || plansza[x-2][y-1]==4)
        {return 1;}
        i=1;
        while(y-i>=0 && x-i >=0 && plansza[x-i][y-i]==12 || i==1)
        {if(plansza[x-i][y-i]==7 || plansza[x-i][y-i]==9)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y-i]==6)
            {return 1;}
            if(plansza[x-i][y-i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y+i<=7 && x-i >=0 && plansza[x-i][y+i]==12 || i==1)
        {if(plansza[x-i][y+i]==7 || plansza[x-i][y+i]==9)
            {
                return 1;
            }
            if(i==1 && plansza[x-i][y+i]==6)
            {return 1;}
            if(plansza[x-i][y+i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y-i>=0 && x+i <=7 && plansza[x+i][y-i]==12 || i==1)
        {if(plansza[x+i][y-i]==7 || plansza[x+i][y-i]==9)
            {
                return 1;
            }
            if(i==1 && plansza[x+i][y-i]==6)
            {return 1;}
            if(plansza[x+i][y-i]!=12)
            {break;}
            i++;
        }
        i=1;
        while(y+i<=7 && x+i <=7 && plansza[x+i][y+i]==12 || i==1)
        {if(plansza[x+i][y+i]==7 || plansza[x+i][y+i]==9)
            {
                return 1;
            }
            if(i==1 && plansza[x+i][y+i]==6)
            {return 1;}
            if(plansza[x+i][y+i]!=12)
            {break;}
            i++;
        }
        return 0;
    }
}
int MAX_KIER[]={8,8,4,4,8,3,8,8,4,4,8,3,0};
int MAX_ODL[]={2,8,8,8,2,2,2,8,8,8,2,2,0};
int WX[12][8]={{0,1,1,1,0,-1,-1,-1},{0,1,1,1,0,-1,-1,-1},{0,1,0,-1},{1,1,-1,-1},{1,2,2,1,-1,-2,-2,-1},{-1,0,1},{0,1,1,1,0,-1,-1,-1},{0,1,1,1,0,-1,-1,-1},{0,1,0,-1},{1,1,-1,-1},{1,2,2,1,-1,-2,-2,-1},{-1,0,1} };
int WY[12][8]={{-1,-1,0,1,1,1,0,-1},{-1,-1,0,1,1,1,0,-1},{-1,0,1,0},{-1,1,1,-1},{-2,-1,1,2,2,1,-1,-2},{-1,-1,-1},{-1,-1,0,1,1,1,0,-1},{-1,-1,0,1,1,1,0,-1},{-1,0,1,0},{-1,1,1,-1},{-2,-1,1,2,2,1,-1,-2},{1,1,1} };
void ruch2(char plansza[8][8])
{
    if(plansza[2][5]==4)
    {
        plansza[3][3]=12;
        plansza[3][4]=11;
    }
    else if(plansza[2][4]==5)
    {
        plansza[3][3]=12;
        plansza[2][4]=11;
    }
    else if(plansza[3][4]==5 || plansza[5][4]==5 || plansza[7][5]==4)
    {
        plansza[2][2]=plansza[1][0];
        plansza[1][0]=12;
    }
    else if(plansza[4][4]==5)
    {
        plansza[4][4]=plansza[3][3];
        plansza[3][3]=12;
    }

    else if(plansza[6][4]==5)
    {
        plansza[6][4]=plansza[2][0];
        plansza[2][0]=12;
    }

    else
    {
        plansza[4][3]=plansza[4][1];
        plansza[4][1]=12;
    }
}
//przyjmujÄc: 0-krĂłl, 1-hetman, 2-wieĹźa, 3-goniec, 4-skoczek,
//5-pionek, 6-krĂłl_k, 7-hetman_k, 8-wieĹźa_k, 9-goniec_k,
//10-skoczek_k, 11-pionek_k, 12-pole puste
int depth(char plansza[8][8],int r)
{
    long long int Wk=0,Hk=0,Sk=0,Gk=0,Kk=0,Pk=0,W=0,H=0,S=0,G=0,K=0,P=0;
    if(r<20)
    {return 6;}
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(plansza[i][j]==0){
                K+=1;
            }
            if(plansza[i][j]==1){
                H+=1;
            }
            if(plansza[i][j]==2){
                W+=1;
            }
            if(plansza[i][j]==3){
                G+=1;
            }
            if(plansza[i][j]==4){
               S+=1;
            }
            if(plansza[i][j]==5){
                P+=1;
            }
            if(plansza[i][j]==6){
                Kk+=1;
            }
            if(plansza[i][j]==7){
                Hk+=1;
            }
            if(plansza[i][j]==8){
                Wk+=1;
            }
            if(plansza[i][j]==9){
                Gk+=1;
            }
            if(plansza[i][j]==10)
            {
                Sk+=1;
            }
            if(plansza[i][j]==11)
            {
                Pk+=1;
            }
        }

    }
    long long int fk=((Wk+Gk)*4*8)+(Sk*8)+8*Kk+(Pk*3*2)+(Hk*8*8);
    long long int fg=((W+G)*4*8)+(S*8)+K*8+(P*3*2)+(H*8*8);
        if(r>60 || fk*fg*fk*fg*fk*fg*fk*fg<3*pow(10,10))
        {

            printf("g8\n");
            return 8;
        }
    return 6;
}
double ocena(char plansza[8][8],int r,int rks)
{
    double wynik=0;
    double wart[13]={PRZEGRANA,-9,-5,-3,-3,-1,WYGRANA,9,5,3,3,1,0};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
         wynik+=wart[plansza[i][j]];
        }
    }
    if(plansza[1][0]!=10 && plansza[0][2]!=10)
    {
        wynik+=0.01;

    }
    if((r<16 && plansza[0][0]==8)|| rks==1)
    {
        wynik+=0.1;
    }
    if((r<16 && plansza[7][0]==8) || rks==1)
    {
        wynik+=0.1;
    }
    if(plansza[6][0]!=10 && plansza[7][2]!=10)
    {
        wynik+=0.01;
    }
    if(plansza[3][0]==6)
    {
        wynik+=0.1;
    }
    if(plansza[4][0]==7)
    {
        wynik+=0.01;
    }
    if(rks)
    {
        wynik+=0.5;

    }
    if(plansza[2][0]!=9)
    {wynik+=0.01;}
    if(plansza[5][0]!=9)
    {wynik+=0.01;}
    if(plansza[2][7]!=3)
    {wynik-=0.01;}
    if(plansza[5][7]!=3)
    {wynik-=0.01;}
    if(plansza[2][7]!=3)
    {wynik+=0.01;}
    if(plansza[1][7]!=4 && plansza[0][5]!=4)
    {
        wynik-=0.01;
    }
    if(r<16 && plansza[0][7]==2 )
    {
        wynik-=0.1;
    }
    if(r<16 && plansza[7][7]==2 )
    {
        wynik-=0.1;
    }
    if(plansza[6][7]!=4 && plansza[7][5]!=4)
    {
        wynik-=0.01;
    }
    return wynik;
}
void wypisz(char plansza[8][8])
{   for(int i=0; i<8; i++)
    {
        for(int j=0; j<8;j++)
        {
            if(plansza[j][i]==12){
                printf(" 0  ");
            }
            if(plansza[j][i]==0){
                printf(" K  ");
            }
            if(plansza[j][i]==1){
                printf(" H  ");
            }
            if(plansza[j][i]==2){
                printf(" W  ");
            }
            if(plansza[j][i]==3){
                printf(" G  ");
            }
            if(plansza[j][i]==4){
                printf(" S  ");
            }
            if(plansza[j][i]==5){
                printf(" p  ");
            }
            if(plansza[j][i]==6){
                printf(" Kk ");
            }
            if(plansza[j][i]==7){
                printf(" Hk ");
            }
            if(plansza[j][i]==8){
                printf(" wk ");
            }
            if(plansza[j][i]==9){
                printf(" gk ");
            }
            if(plansza[j][i]==10){
                printf(" sk ");
            }
            if(plansza[j][i]==11){
                printf(" pk ");
            }

        }
        printf("\n");
    }
    printf("\n");
}
double najlepszy_ruch(char plansza[8][8],int tryb,int *x, int *y,int *o,int *k,int r,double wart_obecna,int rk,int rg,int rpwg,int rlwg,int rlwk,int rpwk,int rks)
{

    int px,py,dir,dist,dx,dy,kpom,opom,xpom,ypom;
    double wmax=2*PRZEGRANA,wmin=2*WYGRANA;
    double wynik=ocena(plansza,r,rks);
    if(tryb==0|| 2*wynik>WYGRANA ||2*wynik<PRZEGRANA)
    {
        return wynik;}
    if(tryb%2==0)
    {
        for(px=0; px<8;px++) //dwie pętle sprawdzaja kazde pole oraz if szukajacy figur komputera
        {
            for(py=0; py<8;py++)
            {
                if(plansza[px][py]>=6 && plansza[px][py]<12)
                {
                    if(plansza[px][py]==6 && rk==1 && (rlwk||rpwk) && px==3 && py==0)
                    {

                        if(rpwk && plansza[4][0]==12 &&plansza[5][0]==12 && plansza[6][0]==12 && czy_szachowane(plansza,px,py,tryb) && czy_szachowane(plansza,4,0,tryb) && czy_szachowane(plansza,5,0,tryb))
                        {
                            plansza[3][0]=12;
                            plansza[7][0]=12;
                            plansza[5][0]=6;
                            plansza[4][0]=8;
                            rpwk=0;
                            rk=0;
                            rks=1;
                            int fig_akt=6;
                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);

                            if (wmax < wynik) {
                                wmax =wynik;
                                *x = px;
                                *y = py;
                                *o = 2;
                                *k = 2;
                            }
                            rk=1;
                            rpwk=1;
                            rks=0;
                            plansza[3][0]=6;
                            plansza[7][0]=8;
                            plansza[5][0]=12;
                            plansza[4][0]=12;
                            if(wmax>wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                            {return wmax;}


                        }
                        if(rlwk && plansza[2][0]==12 &&plansza[1][0]==12  && czy_szachowane(plansza,px,py,tryb) && czy_szachowane(plansza,2,0,tryb) && czy_szachowane(plansza,1,0,tryb))
                        {
                            plansza[3][0]=12;
                            plansza[0][0]=12;
                            plansza[1][0]=6;
                            plansza[2][0]=8;
                            rlwk=0;
                            rk=0;
                            rks=1;
                            int fig_akt=6;
                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);
                            if (wmax < wynik) {
                                wmax =wynik;
                                *x = px;
                                *y = py;
                                *o = 2;
                                *k = 6;
                            }
                            rk=1;
                            rlwk=1;
                            rks=0;
                            plansza[3][0]=6;
                            plansza[0][0]=8;
                            plansza[1][0]=12;
                            plansza[2][0]=12;
                            if(wmax>wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                            {return wmax;}


                        }

                    }
                    for(dir=0;dir<MAX_KIER[plansza[px][py]];dir++)
                    {
                        for (dist = 1; dist < MAX_ODL[plansza[px][py]]; dist++)
                        {
                            dx=(dist-1)*WX[plansza[px][py]][dir];
                            dy=(dist-1)*WY[plansza[px][py]][dir];
                            if(dist>=2 && plansza[px+dx][py+dy]!=PUSTE)
                            {
                                break;
                            }
                            dx=dist*WX[plansza[px][py]][dir];
                            dy=dist*WY[plansza[px][py]][dir];
                            if(0<=px+dx && px+dx<8 && 0<=py+dy && py+dy<8)
                            {
                                if(plansza[px][py]!=11 || ((dx==0 && plansza[px + dx][py + dy]==PUSTE)|| (dx!=0 && plansza[px + dx][py + dy]<6))){
                                    if(plansza[px + dx][py + dy]<6 || plansza[px + dx][py + dy] ==PUSTE) {
                                        int cobylo = plansza[px+dx][py+dy];
                                        int fig_akt=plansza[px][py];
                                        plansza[px + dx][py + dy] = plansza[px][py];
                                        plansza[px][py] = PUSTE;

                                        if(plansza[px][py]==6)
                                        {
                                            rk=0;
                                        }
                                        if(plansza[px+dx][py+dy]==11 && py+dy==7)
                                        {
                                            plansza[px+dx][py+dy]=7;
                                        }
                                        wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);

                                        if (wmax < wynik) {
                                            wmax = wynik;
                                            *x = px;
                                            *y = py;
                                            *o = dist;
                                            *k = dir;
                                        }

                                        plansza[px][py]=fig_akt;
                                        plansza[px+dx][py+dy]=cobylo;
                                        if(wmax>wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                                        {return wmax;}


                                        if(fig_akt==11 && py==1 && plansza[px][py+1]==12 &&plansza[px][py+2]==12 && dx==0)
                                        {
                                            dy=2;
                                            int cobylo = plansza[px+dx][py+dy];
                                            int fig_akt=plansza[px][py];
                                            plansza[px + dx][py + dy] = plansza[px][py];
                                            plansza[px][py] = PUSTE;
                                            if(plansza[px+dx][py+dy]==11 && py+dy==7)
                                            {
                                                plansza[px+dx][py+dy]=7;
                                            }
                                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);

                                            if (wmax < wynik) {
                                                wmax = wynik;
                                                *x = px;
                                                *y = py;
                                                *o = dist;
                                                *k = dir;
                                            }
                                            rk=1;
                                            plansza[px][py]=fig_akt;
                                            plansza[px+dx][py+dy]=cobylo;
                                            if(wmax>wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                                            {return wmax;}
                                        }
                                    }
                                }
                            }

                        }
                    }


                }
            }
        }
        return wmax;
    }
    if(tryb%2)
    {
        for(px=0; px<8;px++) //dwie pętle sprawdzaja kazde pole oraz if szukajacy figur gracza
        {
            for(py=0; py<8;py++)
            {
                if(plansza[px][py]<6)
                {
                    if(plansza[px][py]==0 && rg==1 && (rlwg||rpwg) && px==3 && py==7)
                    {
                        if(rpwg && plansza[4][7]==12 && plansza[5][7]==12 && plansza[6][7]==12 && czy_szachowane(plansza,px,py,tryb) && czy_szachowane(plansza,4,7,tryb) && czy_szachowane(plansza,5,7,tryb))
                        {
                            plansza[3][7]=12;
                            plansza[7][7]=12;
                            plansza[5][7]=0;
                            plansza[4][7]=2;
                            rpwg=0;
                            rg=0;


                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);


                            if (wmin > wynik) {
                                wmin = wynik;
                                *x = px;
                                *y = py;
                                *o = 2;
                                *k = 2;
                            }
                            rg=1;
                            rpwg=1;

                            plansza[3][7]=0;
                            plansza[7][7]=2;
                            plansza[5][7]=12;
                            plansza[4][7]=12;

                            if(wmin<wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                            {return wmin;}


                        }
                        if(rlwg && plansza[2][7]==12 &&plansza[1][7]==12  && czy_szachowane(plansza,px,py,tryb) && czy_szachowane(plansza,2,7,tryb) && czy_szachowane(plansza,1,7,tryb))
                        {
                            plansza[3][7]=12;
                            plansza[7][7]=12;
                            plansza[1][7]=0;
                            plansza[2][7]=2;
                            rpwg=0;
                            rg=0;


                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmax,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);


                            if (wmin > wynik) {
                                wmin = wynik;
                                *x = px;
                                *y = py;
                                *o = 2;
                                *k = 6;
                            }
                            rg=1;
                            rpwg=1;

                            plansza[3][7]=0;
                            plansza[7][7]=2;
                            plansza[1][7]=12;
                            plansza[2][7]=12;
                            if(wmin<wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                            {return wmin;}


                        }

                    }
                    for(dir=0;dir<MAX_KIER[plansza[px][py]];dir++)
                    {
                        for (dist = 1; dist < MAX_ODL[plansza[px][py]]; dist++)
                        {
                            dx=(dist-1)*WX[plansza[px][py]][dir];
                            dy=(dist-1)*WY[plansza[px][py]][dir];
                            if(dist>=2 && plansza[px+dx][py+dy]!=PUSTE)
                            {
                                break;
                            }
                            dx=dist*WX[plansza[px][py]][dir];
                            dy=dist*WY[plansza[px][py]][dir];
                            if(0<=px+dx && px+dx<8 && 0<=py+dy && py+dy<8)
                            {
                                if(plansza[px][py]!=5 || ((dx==0 && plansza[px + dx][py + dy]==PUSTE)|| (dx!=0 && plansza[px + dx][py + dy]>=6 && plansza[px+dx][py+dy]!=12))){
                                    if(plansza[px + dx][py + dy]>=6 || plansza[px + dx][py + dy] ==PUSTE) {
                                        int cobylo = plansza[px+dx][py+dy];
                                        int fig_akt=plansza[px][py];
                                        plansza[px + dx][py + dy] = plansza[px][py];
                                        plansza[px][py] = PUSTE;
                                        if(plansza[px+dx][py+dy]==5 && py+dy==0)
                                        {
                                            plansza[px+dx][py+dy]=1;
                                        }
                                        wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmin,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);


                                        if (wmin > wynik) {
                                            wmin = wynik;
                                            *x = px;
                                            *y = py;
                                            *o = dist;
                                            *k = dir;
                                        }
                                        plansza[px][py]=fig_akt;
                                        plansza[px+dx][py+dy]=cobylo;
                                        if(wmin<wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                                        {
                                            return wmin;
                                        }

                                        if(fig_akt==5 && py==6 && plansza[px][py-1]==12 &&plansza[px][py-2]==12 && dx==0)
                                        {
                                            dy=-2;
                                            int cobylo = plansza[px+dx][py+dy];
                                            int fig_akt=plansza[px][py];
                                            plansza[px + dx][py + dy] = plansza[px][py];
                                            plansza[px][py] = PUSTE;
                                            if(plansza[px+dx][py+dy]==5 && py+dy==0)
                                            {
                                                plansza[px+dx][py+dy]=1;
                                            }
                                            wynik = najlepszy_ruch(plansza, tryb - 1, &xpom, &ypom, &opom, &kpom,r+1,wmin,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);

                                            if (wmin > wynik) {
                                                wmin = wynik;
                                                *x = px;
                                                *y = py;
                                                *o = dist;
                                                *k = dir;
                                            }
                                            plansza[px][py]=fig_akt;
                                            plansza[px+dx][py+dy]=cobylo;
                                            if(wmin<wart_obecna && tryb!=8 && tryb!=6 && tryb!=4)
                                            {
                                                return wmin;
                                            }
                                        }

                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
        return wmin;
    }

}
int main() {
    //przyjmujÄc: 0-krĂłl, 1-hetman, 2-wieĹźa, 3-goniec, 4-skoczek,
//5-pionek, 6-krĂłl_k, 7-hetman_k, 8-wieĹźa_k, 9-goniec_k,
//10-skoczek_k, 11-pionek_k, 12-pole puste


char plansza[8][8]={8,11,12,12,12,12,5,2,
                    10,11,12,12,12,12,5,4,
                    9,11,12,12,12,12,5,3,
                    6,11,12,12,12,12,5,0,
                    7,11,12,12,12,12,5,1,
                    9,11,12,12,12,12,5,3,
                    10,11,12,12,12,12,5,4,
                    8,11,12,12,12,12,5,2,};
  /* char plansza[8][8]={ 8,11,12,12,12,12,5,2,
                        12,11,12,12,12,12,5,4,
                        12,11,10,12,12,12,5,3,
                        6,12,12,11,12,12,5,0,
                        7,11,9,12,12,12,5,1,
                        9,11,12,12,12,12,5,3,
                        10,11,12,12,12,12,12,4,
                        8,11,12,12,12,12,5,2,};*/
    wypisz(plansza);
   printf( "czesc! grasz poprzez wpisywanie najpierw numeru kolumny i wiersza na ktorych twoj pionek obecnie stoi,\n a pozniej w ten sam sposob na jakie pole ma sie przeniesc \n(numeracja od 0-7,ruch e5 to przykladowo:3 [enter] 6[enter] 3[enter] 4 [enter]\n");
    int x,y,o,k,dx,dy,x2,y2,czy,rk=1,rg=1,rlwg=1,rpwg=1,rlwk=1,rpwk=1,rks=0;
int r=1;
while(r<140)
{   if(r==1)
    {plansza[3][3]=11; plansza[3][1]=12;}
    else if(r==2)
    {
        ruch2(plansza);
    }
    else{
        najlepszy_ruch(plansza, depth(plansza,r),&x,&y,&o,&k,r,-2000,rk,rg,rpwg,rlwg,rlwk,rpwk,rks);
    dx=o*WX[plansza[x][y]][k];
    dy=o*WY[plansza[x][y]][k];
        plansza[x + dx][y + dy] = plansza[x][y];

    if(plansza[x][y]==6 && (dx == 2 || dx== -2))
    {
        if(dx==-2)
        {
            plansza[0][0]=PUSTE;
            plansza[2][0]=8;
            rks=1;
        }
        if(dx==2)
        {
            plansza[7][0]=PUSTE;
            plansza[4][0]=8;
            rks=1;
        }
    }
        plansza[x][y] = PUSTE;

        if(plansza[3][0]==12)
        {
            rk=0;
        }
        if(plansza[0][0]!=8)
        {
            rlwk=0;
        }
        if(plansza[7][0]!=8)
        {
            rpwk=0;
        }
    if(plansza[x+dx][y+dy]==11 && y+dy==7)
    {
        plansza[x+dx][y+dy]=7;
    }}r++;
    printf("ruch komputera!\n");
    wypisz(plansza);
  //  czy= najlepszy_ruch(plansza,2,&x,&y,&o,&k,r);
   // if(czy>=WYGRANA)
   // { printf("przzegrales");
    //    /*return 1;*/}
    printf("twoj ruch!");
    scanf("%d%d%d%d",&x,&y,&x2,&y2);
    plansza[x2][y2]=plansza[x][y];
  
    if(x==3 && y==7 && x2==5 && y2==7 && rg)
    {
        plansza[4][7]=2;
        plansza[7][7]=PUSTE;
        rg=0;
    }
    if(x==3 && y==7 && x2==1 && y2==7 && rg)
    {
        plansza[2][7]=2;
        plansza[0][7]=PUSTE;
        rg=0;
    }
    plansza[x][y]=PUSTE;
    if(plansza[3][7]==12)
    {
        rg=0;
    }
    if(plansza[0][7]!=2)
    {
        rlwg=0;
    }
    if(plansza[7][7]!=2)
    {
        rpwg=0;
    }
    if(plansza[x2][y2]==5 && y2==0)
    {
        plansza[x2][y2]=1;
    }
    wypisz(plansza);
  //  czy = najlepszy_ruch(plansza,2,&x,&y,&o,&k,r);
  //  if(czy<=PRZEGRANA)
    //{ printf("wygrales");
        /*return 0;*///}


}

}
