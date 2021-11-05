#include <stdio.h>

/*
Inicjalizacja tablicy:

    int tablica[]={1,2,3,4,5,6,7,0,0,0,0};
    int tablica[5]={1,2,3,4,5};
    int tablica[5]={1};  pozostale to 0
    int tablica[6]={[2]=2,[5]=32}; Wszystko przed bedzie 0



    Działania na wskaźnikach







*/

/*
int main()
{
    
    int urna[5] = {100,200,300,400,500};
    int *wsk1, *wsk2, *wsk3;
    wsk1=urna;
    wsk2=&urna[2];



    printf("Wartosc wskaznika, wskazywana wartosc, adres wskaznika");
    printf("wsk1 = %p, *wsk1 = %d, &wsk1 = %p", wsk1, *wsk1, &wsk1);





int zippo[4][2]= {{1,2},{8,9},{3,4},{5,6}};

printf(" zippo= %p, zippo +1 = %p \n\n",zippo, zippo+1);
printf("zippo[0] = %p, zippo[0]+1= %p\n\n",zippo[0],zippo[0]+1);
printf("*zippo = %p, *zippo+1=%p",*zippo, *zippo +1);
printf("zippo[0][0] = %d\n",zippo[0][0]);
printf("*zippo[0] = %d\n",*zippo[0]);
printf("**zippo = %d\n",**zippo);
printf("zippo[2][1] = %d\n",zippo[2][1]);
printf("*(*(zippo+2)+1) = %d\n",*(*(zippo+2)+1));




    return 0;
}
*/

/*
int main()
{
    int ref[]={1,4,5,6};
    int *wsk;
    int indeks;

    for(indeks=0, wsk=ref; indeks<4; indeks++, wsk++)
    {
        printf("%d %d \n",ref[indeks], *wsk);

    }

    return 0;
}
*/



/*
ZADANIE 1
*/


/*
#define MIESIACE 12
#define LATA 5



int main()
{

    const float deszcz[LATA][MIESIACE]=
    {
        {4.4,1.1,2.1,8.4,7.5,9.6,7.4,6.5,4.8,9.2,5.5,4.1},
        {4.4,1.1,2.1,8.4,7.5,9.6,7.4,6.5,4.8,9.2,5.5,4.1},
        {4.4,1.1,2.1,8.4,7.5,9.6,7.4,6.5,4.8,9.2,5.5,4.1},
        {4.4,1.1,2.1,8.4,7.5,9.6,7.4,6.5,4.8,9.2,5.5,4.1},
        {4.4,1.1,2.1,8.4,7.5,9.6,7.4,6.5,4.8,9.2,5.5,4.1},
    };

    int rok, miesiac;
    float podsuma, suma;
    printf("ROK     OPADY (w calach)\n");

    for(rok=0, suma=0; rok<LATA; rok++)
    {
        for(miesiac=0, podsuma=0; miesiac<MIESIACE; miesiac++)
        {
            podsuma+=*(*(deszcz+rok)+miesiac);
        }

        printf("%5d %12.1f \n",2000+rok,podsuma);
        suma+=podsuma;
    }

    printf("\nRoczna srednia wynosi %.1f cale\n\n", suma/LATA);
    printf("SREDNIE MIESIECZNE: \n\n");
    printf("Sty Lut Mar Kwi Maj Cze Lip Sie Wrz Paz");
    printf(" Lis Gru\n");

    for(miesiac = 0; miesiac<MIESIACE; miesiac++)
    {
        for(rok = 0, podsuma = 0; rok<LATA; rok ++)
            podsuma+= *(*(deszcz+rok)+miesiac);
        printf("%4.1f",podsuma/LATA);
    }

    printf("\n");
    return 0;

}
*/

/*
ZADANIE 2
*/


/*
void kopiuj_tab(int *tab, int *cel, int n);
void kopiuj_wsk(int *tab, int *cel, int n);
void kopiuj_wsk2(int *tab, int *cel, int *wsk_koncowy);

int main()
{
    int tablica_1[]={1,2,3,4,5,6,7,8,9,74};
    int tablica_2[10];
    int tablica_3[10];

    kopiuj_tab(tablica_1,tablica_2,10);

    for(int i=0; i<10; i++)
    {
        printf(" tablica[%d]=%d,",i,tablica_2[i]);
    }

    printf("\n\n");

    kopiuj_wsk(tablica_1,tablica_3,10);

    for(int i=0; i<10; i++)
    {
        printf(" tablica[%d]=%d,",i,tablica_3[i]);
    }

    printf("\n\n");

    kopiuj_wsk2(tablica_1,tablica_3,tablica_1+10);

    for(int i=0; i<10; i++)
    {
        printf(" tablica[%d]=%d,",i,tablica_3[i]);
    }

    printf("\n\n");

    return 0;
}

void kopiuj_tab(int *tab, int *cel, int n)
{
    for(int i=0; i<n; i++)
        cel[i]=tab[i];

}

void kopiuj_wsk(int *tab, int *cel, int n)
{
    for(int i=0; i<n; i++)
        *(cel+i) = *(tab+i);

}


void kopiuj_wsk2(int *tab, int *cel, int *wsk_koncowy)
{
    for(int i=0; i<(wsk_koncowy-tab)/4;i++)  //wsk_koncowy-tab - dostajemy odległość w bajtach pomiedzy pierwszym a ostatnim elementem a int zajmuje 4 bajty wiec dzielimy to przez 4
        *(cel+i)=*(tab+i);
}

*/


/*
ZADANIE 3
*/

/*
int najwieksza_liczba(int *tab, int n);

int main()
{
    int tablica_1[]={1,2,3,4,5,6,7,8,9,74};
    const int rozmiar = (sizeof tablica_1) / (sizeof tablica_1[0]);
    int tmp =0;
    tmp=najwieksza_liczba(tablica_1,rozmiar);
    printf("Najwieksza liczba z tablicy to: %d\n",tmp);

    return 0;
}

int najwieksza_liczba(int *tab, int n)
{
    int najwi_liczba = *tab;

    for(int i=1; i<n; i++)
    {
        if(najwi_liczba<tab[i])
            najwi_liczba=tab[i];
    }

    return najwi_liczba;
}
*/



/*
ZADANIE 4
*/

/*
int najwieksza_liczba(int *tab, int n);

int main()
{
    int tablica_1[]={1,2,3,4,5,6,7,8,9,74};
    const int rozmiar = (sizeof tablica_1) / (sizeof tablica_1[0]);
    int tmp =0;
    tmp=najwieksza_liczba(tablica_1,rozmiar);
    printf("Najwiekszy indeks z tablicy to: %d\n",tmp);

    return 0;
}

int najwieksza_liczba(int *tab, int n)
{
    int najwi_liczba = *tab;

    for(int i=1; i<n; i++)
    {
        if(najwi_liczba<tab[i])
            najwi_liczba=i;
    }

    return najwi_liczba;
}
*/


/*
ZADANIE 5
*/

/*
int najwieksza_liczba(int *tab, int n);

int main()
{
    int tablica_1[]={1,2,3,4,5,6,7,8,9,74};
    const int rozmiar = (sizeof tablica_1) / (sizeof tablica_1[0]);
    int tmp =0;
    tmp=najwieksza_liczba(tablica_1,rozmiar);
    printf("Roznica pomiedzy najwieksza a najmniejsza wartoscia w tablicy to: %d\n",tmp);

    return 0;
}

int najwieksza_liczba(int *tab, int n)
{
    int najwi_liczba = *tab;
    int najmn_liczba = *tab;

    for(int i=1; i<n; i++)
    {
        if(najwi_liczba<tab[i])
            najwi_liczba=*(tab+i);
        
        if(najmn_liczba>tab[i])
            najmn_liczba=*(tab+i);
    }

    return najwi_liczba-najmn_liczba;
}

*/



/*
ZADANIE 6
*/


/*
void odwracanie_tablic(double *tab, int n);

int main()
{
    double tablica_1[]={1,2,3,4,5,6,7,8,9,74};
    const int rozmiar = (sizeof tablica_1) / (sizeof tablica_1[0]);
    
    printf("Tablica wejsciowa: ");
    for(int i=0; i<rozmiar;i++)
        printf("%f, ",tablica_1[i]);

    printf("\n\n");
    odwracanie_tablic(tablica_1, rozmiar);
  
   printf("Tablica wyjsciowa: ");
    for(int i=0; i<rozmiar;i++)
        printf("%f, ",tablica_1[i]);

     printf("\n\n");

    return 0;
}

void odwracanie_tablic(double *tab, int n)
{
    double tab_pom[n];

    for(int i=0; i<n; i++)
    {
        tab_pom[i]=tab[i];
    }

    for(int i=0; i<n; i++)
    {
        tab[i]=tab_pom[n-i-1];
    }
}
*/



/*
ZADANIE 8
*/

/*
#define KOLUMNY 10
void kopiuj_wsk2(int (*tab)[KOLUMNY], int (*cel)[KOLUMNY], int wiersze);

int main()
{
    int tablica_1[9][10]=
    {
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
        {1,2,3,4,5,6,7,8,9,74},
    };
    

    int tablica_3[9][10];
   
    kopiuj_wsk2(tablica_1,tablica_3,9);

    for(int j=0; j<9;j++)
    {
        for(int i=0; i<KOLUMNY; i++)
        {
            printf(" tablica[%d][%d]=%d,",j,i,tablica_3[j][i]);
        }

    printf("\n");
    }

    return 0;
}




void kopiuj_wsk2(int (*tab)[KOLUMNY], int (*cel)[KOLUMNY], int wiersze)
{
    for(int i=0; i<wiersze;i++)  //wsk_koncowy-tab - dostajemy odległość w bajtach pomiedzy pierwszym a ostatnim elementem a int zajmuje 4 bajty wiec dzielimy to przez 4
    {
        for(int j=0; j<KOLUMNY;j++)
        {
            *(*(cel+i)+j)=*(*(tab+i)+j);
        }
    }    
}

*/


/*
ZADANIE 9
*/



/*
void kopiuj_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny], double cel[wiersze][kolumny]);

int main()
{
    double tablica_1[][5]=
    {
        {1,2,3,4,5},
        {0,4,5,6,7},
        {6,5,4,4,9},
    };

    double tablica_2[3][5];

    
   
    kopiuj_VLA(3,5,tablica_1,tablica_2);

    for(int j=0; j<3;j++)
    {
        for(int i=0; i<5; i++)
        {
            printf(" tablica[%d][%d]=%f,",j,i,tablica_2[j][i]);
        }

    printf("\n");
    }




    return 0;
}


void kopiuj_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny], double cel[wiersze][kolumny])
{
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0;j<kolumny;j++)
        {
            cel[i][j]=tab[i][j];
        }
    }
}

*/


/*
ZADANIE 10
*/

/*
void sumowanie_tablic(int *tab_1, int *tab_2, int *wynik, int rozmiar);


int main()
{
    int tab_1[]={1,3,87,52,36,48,59};
    int tab_2[]={1,3,87,52,36,48,59};
    int tab_3[7];

    sumowanie_tablic(tab_1,tab_2,tab_3, (sizeof tab_1)/(sizeof tab_1[0]));

    for(int i=0; i<(sizeof tab_1)/(sizeof tab_1[0]); i++)
    {
      printf(" tablica[%d]=%d,",i,tab_3[i]);
    }

    return 0;
}

void sumowanie_tablic(int *tab_1, int *tab_2, int *wynik, int rozmiar)
{
    for(int i=0; i<rozmiar; i++)
        *(wynik+i)=*(tab_1+i)+*(tab_2+i);
}

*/


/*
ZADANIE 13
*/


void srednia_rzedu(int rzedy, int kolumny,double tab[rzedy][kolumny]);
void srednia_macierzy(int rzedy, int kolumny,double tab[rzedy][kolumny]);
void najwieksza_wartosc(int rzedy, int kolumny,double tab[rzedy][kolumny]);


int main()
{
    while(1)
    {   
        int rzedy=0;
        int kolumny=0;
        double tmp=0;

        printf("Podaj liczbę rzędów oraz liczbę kolumn macierzy.\n");
        printf("Liczba rzedow: ");
        scanf("%d",&rzedy);
        printf("Liczba kolumn: ");
        scanf("%d",&kolumny);

        double tab_1[rzedy][kolumny];

        for(int i=0; i<rzedy; i++)
        {
            for(int j=0; j<kolumny; j++)
            {   
                printf("Wartosc dla macierzy o wsporzednych [%d][%d] to:", i,j);
                scanf("%lf",&tmp);
                tab_1[i][j]=tmp;
            }
        }

        printf("\n");
        srednia_rzedu(rzedy,kolumny,tab_1);
        srednia_macierzy(rzedy,kolumny,tab_1);

    }

    return 0;
}

void srednia_rzedu(int rzedy, int kolumny,double tab[rzedy][kolumny])
{
    double srednia=0;

    for(int i=0; i<rzedy; i++)
    {
        srednia=0;

        for(int j=0; j<kolumny; j++)
        {
            srednia+=tab[i][j];
        }

        srednia/=kolumny;
        printf("Srednia dla rzedu %d wynosi %lf\n",i,srednia);

    }
    printf("\n\n");
}


void srednia_macierzy(int rzedy, int kolumny,double tab[rzedy][kolumny])
{
    double srednia=0;

    for(int i=0; i<rzedy; i++)
    {
        for(int j=0; j<kolumny; j++)
        {
            srednia+=tab[i][j];
        }

    }
    srednia/=(kolumny*rzedy);
    printf("Srednia dla macierzy wynosi %lf\n",srednia);
    printf("\n\n");
}



void najwieksza_wartosc(int rzedy, int kolumny,double tab[rzedy][kolumny]);





