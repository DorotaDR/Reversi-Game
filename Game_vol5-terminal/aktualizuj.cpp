#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "aktualizuj.h"
void aktualizuj_stan_planszy(char ***tab1, unsigned wsp_x, unsigned wsp_y, char kolor, bool ***tab2)
{
    int i,j;
    (*tab1)[wsp_x-1][wsp_y-1]=kolor;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if((*tab2)[i][j]==true)
                (*tab1)[i][j]=kolor;
        }
    }
}

