#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "wartosc_pocz.h"
void wartosc_pocz_plansza(char ***tab)
{
    int i, j;
    (*tab)=(char**) malloc(MAX*sizeof(char*));
    if((*tab)==NULL)
    {
        printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<MAX;i++)
    {
        (*tab)[i]=(char*) malloc(MAX*sizeof(char));
        if((*tab)[i]==NULL)
        {
            printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n\n");
            for(j=0;j<i;j++)
                free((*tab)[j]);
            free(*tab);
            exit(EXIT_FAILURE);
        }
    }
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab)[i][j]=' ';
    (*tab)[3][3]=(*tab)[4][4]='B';
    (*tab)[3][4]=(*tab)[4][3]='C';
}
void wartosc_pocz_bool(bool ***tab)
{
    int i, j;
    (*tab)=(bool**) malloc(MAX*sizeof(bool*));
    if((*tab)==NULL)
    {
        printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<MAX;i++)
    {
        (*tab)[i]=(bool*) malloc(MAX*sizeof(bool));
        if((*tab)[i]==NULL)
        {
            printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n\n");
            for(j=0;j<i;j++)
                free((*tab)[j]);
            free(*tab);
            exit(EXIT_FAILURE);
        }
    }
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab)[i][j]=false;
}
void wartosc_pocz_int(int ***tab)
{
    int i, j;
    (*tab)=(int**) malloc(MAX*sizeof(int*));
    if((*tab)==NULL)
    {
        printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<MAX;i++)
    {
        (*tab)[i]=(int*) malloc(MAX*sizeof(int));
        if((*tab)[i]==NULL)
        {
            printf("\n\nNieudana alokacja pamieci.\nKoniec programu.\n\n");
            for(j=0;j<i;j++)
                free((*tab)[j]);
            free(*tab);
            exit(EXIT_FAILURE);
        }
    }
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab)[i][j]=0;
}
