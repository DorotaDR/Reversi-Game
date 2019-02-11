#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "menu.h"
#include "zapisz.h"
int menu1(struct gra *dane_menu)
{
    int wybor;
    system("cls");
    printf("Wybiez opcje:\n\n");
    printf("1) Rozpocznij nowa gre.\n\n");
    printf("2) Wczytaj zapisany stan gry.\n\n");
    printf("3) Zakoncz gre.\n\n");
    if(scanf("%d", &wybor)!=1 || (wybor!=1 && wybor!=2 && wybor!=3))
    {
        while(getchar()!='\n')
            continue;
        wybor=menu1(&(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==1)
            menu2(&(*dane_menu));
        if(wybor==2)
            menu5(&(*dane_menu));
        if(wybor==3)
            (*dane_menu).stan=false;
    }
    return wybor;

}
int menu2(struct gra *dane_menu)
{
    int wybor;
    system("cls");
    printf("Wybiez opcje:\n\n");
    printf("1) Single Player (PVCOMP).\n\n");
    printf("2) Two Player (PVP).\n\n");
    printf("3) Cofnij (Jakas strzalka w SFML).\n\n");
    if(scanf("%d", &wybor)!=1 || (wybor!=1 && wybor!=2 && wybor!=3))
    {
        while(getchar()!='\n')
            continue;
        wybor=menu2(&(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==1)
        {
            (*dane_menu).tryb=PVCOMP;
            menu3(&(*dane_menu));
        }
        if(wybor==2)
            (*dane_menu).tryb=PVP;
        if(wybor==3)
            menu1(&(*dane_menu));
    }
    return wybor;
}
int menu3(struct gra *dane_menu)
{
    int wybor;
    system("cls");
    printf("Wybiez opcje:\n\n");
    printf("1) Pionek bialy\n\n");
    printf("2) Pionek czarny\n\n");
    printf("3) Cofnij (Jakas strzalka w SFML).\n\n");
    if(scanf("%d", &wybor)!=1 || (wybor!=1 && wybor!=2 && wybor!=3))
    {
        while(getchar()!='\n')
            continue;
        wybor=menu3(&(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==1)
            (*dane_menu).kolor='B';
        if(wybor==2)
            (*dane_menu).kolor='C';
        if(wybor==3)
            menu2(&(*dane_menu));
    }
    return wybor;
}
int menu4(struct gra *dane_menu, char ***tab)
{
    int wybor;
    system("cls");
    printf("Wybiez opcje:\n\n");
    printf("1) Zapisz stan gry w pliku 1\n\n");
    printf("2) Zapisz stan gry w pliku 2\n\n");
    printf("3) Zapisz stan gry w pliku 3\n\n");
    printf("4) Zapisz stan gry w pliku 4\n\n");
    printf("5) Wyjdz bez zapisywania.\n\n");
    if(scanf("%d", &wybor)!=1 || (wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5))
    {
        while(getchar()!='\n')
            continue;
        wybor=menu4(&(*dane_menu), &(*tab));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==5)
            menu1(&(*dane_menu));
        else
        {
            (*dane_menu).nr_pliku=wybor;
            if(zapisz(&(*tab), (*dane_menu).kolor, (*dane_menu).tryb, (*dane_menu).gracz, (*dane_menu).plik)==true)
            {
                system("cls");
                printf("Udalo sie poprawnie zapisac stan gry w pliku 1.\n\n");
                while(getchar()!='\n')
                    continue;
            }
            else
            {
                system("cls");
                printf("Nie udalo sie poprawnie zapisac stanu gry w pliku 1.\n\n");
                while(getchar()!='\n')
                    continue;
            }
            menu1(&(*dane_menu));
        }

    }
    return wybor;
}
int menu5(struct gra *dane_menu)
{
    int wybor;
    system("cls");
    printf("Wybiez opcje:\n\n");
    printf("1) Wczytaj stan gry z pliku 1\n\n");
    printf("2) Wczytaj stan gry z pliku 2\n\n");
    printf("3) Wczytaj stan gry z pliku 3\n\n");
    printf("4) Wczytaj stan gry z pliku 4\n\n");
    printf("5) Cofnij (Jakas strzalka w SFML).\n\n");
    if(scanf("%d", &wybor)!=1 || (wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5))
    {
        while(getchar()!='\n')
            continue;
        wybor=menu5(&(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==5)
            menu1(&(*dane_menu));
        else
        {
            system("cls");
            printf("Opcja chwilowo niedostepna.\n\n");
            while(getchar()!='\n')
                continue;
            menu5(&(*dane_menu));
        }
    }
    return wybor;
}
