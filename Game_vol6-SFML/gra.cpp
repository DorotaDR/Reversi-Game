#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "pokaz.h"
#include "zapisz.h"
#include "komorka_sprawdz_licz.h"
#include "wartosc_pocz.h"
#include "aktualizuj.h"
#include "menu.h"
#include "gra.h"

#include"info_klik_tab.h"


#define MAX 8
#define PVP 0
#define PVCOMP 1
using namespace std;
void int_w_bool(int ***tab1, bool ***tab2)
{
    int i,j;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab2)[i][j]=false;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            if((*tab1)[i][j]!=0)
                (*tab2)[i][j]=true;
}
bool graj_w_gre(daneOkna oknoAplikacji, struct gra *dane_menu)
{
    char **plansza;
    bool **do_zbicia;
    int **wartosci;
    bool **gdzie_postawic;
    bool licznik;
    int x, y;
    int flaga;
    int x_max, y_max;
    char dany_kolor;
    wartosc_pocz_plansza(&plansza);
    wartosc_pocz_bool(&do_zbicia);
    wartosc_pocz_int(&wartosci);
    wartosc_pocz_bool(&gdzie_postawic);
    flaga=2;
    if((*dane_menu).stan==false)
        return false;
    if((*dane_menu).tryb==PVP)
    {
        licznik=false;
        while(flaga==2)
        {


            if(licznik==true)
            {
                (*dane_menu).gracz=true;
                (*dane_menu).kolor='B';
            }
            else
            {
                (*dane_menu).gracz=false;
                (*dane_menu).kolor='C';
            }
            if(licz_kolor(&plansza, &x, &y)==64)
            {
                flaga=3;
                break;
            }

            if(wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, 'B')==0 && wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, 'C')==0)
            {
                flaga=4;
                break;
            }
            if(wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, (*dane_menu).kolor)==0)
            {
                licznik=!licznik;
                continue;
            }
            wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, (*dane_menu).kolor);
            int_w_bool(&wartosci, &gdzie_postawic);
            pokaz_podp_w_sfml(*oknoAplikacji.uOkno, plansza, gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
            //system("cls");
            //pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);

            //--------------------------SPRAWDZANIE KLIKNIECIA NA PLANSZY---------------------------//

            for(;;)
            {

            pokaz_podp_w_sfml(*oknoAplikacji.uOkno, plansza, gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
            if(info_klik_plansza(oknoAplikacji, &x, &y, 5)==true)

            {
                if(sprawdz_komorke(&plansza, x, y, (*dane_menu).kolor)==true)
                break;
            }
            }

            //printf("\n\nPodaj wspolrzedne punktu gdzie chcesz postawic swoj pionek:\n\n");
            //if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
            //{
              //  while(getchar()!='\n')
               //     continue;
               // flaga=0;
               // break;
            //}
            while(x<1 || x>8 || y<1 || y>8)
            {
                system("cls");
                pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                printf("\n\nWyszedles poza tablice. Jeszcze raz:\n\n");
                if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                {
                    while(getchar()!='\n')
                        continue;
                    flaga=0;
                    break;
                }
            }
            if(flaga==0)
                break;
            while(sprawdz_komorke(&plansza, x, y, (*dane_menu).kolor)==false)
            {
                system("cls");
                pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                printf("\n\nNie mozna postawic tu pionka. Jeszcze raz:\n\n");
                if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                {
                    while(getchar()!='\n')
                        continue;
                    flaga=0;
                    break;
                }
                while(x<1 || x>8 || y<1 || y>8)
                {
                    system("cls");
                    pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                    printf("\n\nWyszedles poza tablice. Jeszcze raz:\n\n");
                    if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                    {
                        while(getchar()!='\n')
                            continue;
                        flaga=0;
                        break;
                    }
                }
                if(flaga==0)
                    break;
            }
            if(flaga==0)
                break;
            zlicz_liczbe_zbitych(&plansza, x, y, (*dane_menu).kolor, &do_zbicia);
            aktualizuj_stan_planszy(&plansza, x, y, (*dane_menu).kolor, &do_zbicia);
            licznik=!licznik;
        }
        if(flaga==0)
            menu4(oknoAplikacji, &(*dane_menu), &plansza);
    }
    else
    {
        dany_kolor=(*dane_menu).kolor;
        licznik=true;
        while(flaga==2)
        {
            if(licznik==true)
            {
                (*dane_menu).gracz=true;
                (*dane_menu).kolor='C';
            }
            else
            {
                (*dane_menu).gracz=false;
                (*dane_menu).kolor='B';
            }
            if(licz_kolor(&plansza, &x, &y)==64)
            {
                flaga=3;
                break;
            }
            if(wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, 'B')==0 && wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, 'C')==0)
            {
                flaga=4;
                break;
            }
            if(wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, (*dane_menu).kolor)==0)
            {
                licznik=!licznik;
                continue;
            }
            wartosc_planszy(&plansza, &wartosci, &x_max, &y_max, (*dane_menu).kolor);
            int_w_bool(&wartosci, &gdzie_postawic);

            pokaz_podp_w_sfml(*oknoAplikacji.uOkno, plansza, gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
            //system("cls");
            //pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
            if((*dane_menu).kolor!=dany_kolor)
            {
                zlicz_liczbe_zbitych(&plansza, x_max, y_max, (*dane_menu).kolor, &do_zbicia);
                aktualizuj_stan_planszy(&plansza, x_max, y_max, (*dane_menu).kolor, &do_zbicia);
                licznik=!licznik;
                usleep(999999);
                usleep(999999);
                usleep(999999);
            }
            else
            {


            for(;;)
            {

            pokaz_podp_w_sfml(*oknoAplikacji.uOkno, plansza, gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
            if(info_klik_plansza(oknoAplikacji, &x, &y, 5)==true)

            {
                if(sprawdz_komorke(&plansza, x, y, (*dane_menu).kolor)==true)
                break;
            }
            }


            /*
                printf("\n\nPodaj wspolrzedne punktu gdzie chcesz postawic swoj pionek:\n\n");
                if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                {
                    while(getchar()!='\n')
                        continue;
                    flaga=0;
                    break;
                }*/
                while(x<1 || x>8 || y<1 || y>8)
                {
                    system("cls");
                    pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                    printf("\n\nWyszedles poza tablice. Jeszcze raz:\n\n");
                    if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                    {
                        while(getchar()!='\n')
                            continue;
                        flaga=0;
                        break;
                    }
                }
                if(flaga==0)
                    break;
                while(sprawdz_komorke(&plansza, x, y, (*dane_menu).kolor)==false)
                {
                    system("cls");
                    pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                    printf("\n\nNie mozna postawic tu pionka. Jeszcze raz:\n\n");
                    if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                    {
                        while(getchar()!='\n')
                            continue;
                        flaga=0;
                        break;
                    }
                    while(x<1 || x>8 || y<1 || y>8)
                    {
                        system("cls");
                        pokaz_podp_w_terminalu(&plansza, &gdzie_postawic, (*dane_menu).gracz, (*dane_menu).kolor);
                        printf("\n\nWyszedles poza tablice. Jeszcze raz:\n\n");
                        if(scanf("%d", &x)!=1 || scanf("%d", &y)!=1)
                        {
                            while(getchar()!='\n')
                                continue;
                            flaga=0;
                            break;
                        }
                    }
                    if(flaga==0)
                        break;
                }
                if(flaga==0)
                    break;
                zlicz_liczbe_zbitych(&plansza, x, y, (*dane_menu).kolor, &do_zbicia);
                aktualizuj_stan_planszy(&plansza, x, y, (*dane_menu).kolor, &do_zbicia);
                licznik=!licznik;
            }
        }
        if(flaga==0)
            menu4(oknoAplikacji, &(*dane_menu), &plansza);
        if(flaga==3 || flaga==4)
        {
            licz_kolor(&plansza, &x, &y);
            printf("\n\n########Koniec gry########\n\n");
            printf("\n\nWynik:    Bialy=%d     Czarny=%d\n\n", x, y);
            if(x==y)
                printf("\n\nRemis\n\n");
            if(x>y)
                printf("\n\nWygral gracz bialy\n\n");
            if(x<y)
                printf("\n\nWygral gracz czarny.\n\n");
            while(getchar()!='\n')
                continue;
            getchar();
            menu1(oknoAplikacji, &(*dane_menu));
        }
    }
    return true;
}

