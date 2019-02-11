#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "zapisz.h"
bool zapisz(char ***tab, char kolor, bool tryb, bool ktory_gracz, FILE *wskaznik)
{
    int i,j;
    if((wskaznik=fopen("saved/plik1.txt", "w"))==NULL)
    {
        fprintf(stderr, "\n\nNieudalo sie otwozyc pliku, w ktorym mozna by zapisac stan gry.\n\n");
        return false;
    }
    fprintf(wskaznik, "PLANSZA\n\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
            fprintf(wskaznik, "%c", (*tab)[i][j]);
        fprintf(wskaznik, "\n");
    }
    fprintf(wskaznik, "\n\nKOLOR\n\n%c\n\n", kolor);
    fprintf(wskaznik, "TRYB\n\n%d\n\n", tryb);
    fprintf(wskaznik, "GRACZ\n\n%d\n\n", ktory_gracz);
    if(fclose(wskaznik)==EOF)
        fprintf(stderr, "\n\nNieudalo sie poprawnie zamknac pliku, w ktorym zapisano stan gry");
    return true;
}
