#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "licz.h"
void licz_kolor(char ***tab, int *bial, int *czar)
{
    int i,j;
    *bial=*czar=0;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if((*tab)[i][j]=='B')
                (*bial)++;
            if((*tab)[i][j]=='C')
                (*czar)++;
        }
    }
}
int zlicz_liczbe_zbitych(char ***tab1, unsigned wsp_x, unsigned wsp_y, char kolor, bool ***tab2)
{
    int i,j;
    char drugi;
    int licznik;
    int global_licznik=0;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab2)[i][j]=false;
    if(kolor=='B')
        drugi='C';
    else
        drugi='B';
    for(licznik=0, i=wsp_x-1, j=wsp_y-2; j!=-1;j--)        /*N*/
    {
        if(j==0)
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y-2; j!=-1; j--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y-2; j!=-1; j--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x, j=wsp_y-1; i!=8;i++)        /*E*/
    {
        if(i==7)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-1; i!=8;i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-1; i!=8;i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x-1, j=wsp_y; j!=8;j++)      /*S*/
    {
        if(j==7)
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y; j!=8;j++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y; j!=8;j++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x-2, j=wsp_y-1; i!=-1;i--)        /*W*/
    {
        if(i==0)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-1; i!=-1;i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-1; i!=-1;i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x, j=wsp_y-2; j!=-1 && i!=8; j--, i++)        /*NE*/
    {
        if(j==0 || i==7)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-2; j!=-1 && i!=8; j--, i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-2; j!=-1 && i!=8; j--, i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x, j=wsp_y; j!=8 && i!=8; j++, i++)        /*SE*/
    {
        if(j==7 || i==7)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y; j!=8 && i!=8; j++, i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y; j!=8 && i!=8; j++, i++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x-2, j=wsp_y; j!=8 && i!=-1; j++, i--)        /*SW*/
    {
        if(j==7 || i==0)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y; j!=8 && i!=-1; j++, i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y; j!=8 && i!=-1; j++, i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    for(licznik=0, i=wsp_x-2, j=wsp_y-2; j!=-1 && i!=-1; j--, i--)        /*NW*/
    {
        if(j==0 || i==0)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-2; j!=-1 && i!=-1; j--, i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==kolor)
            break;
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-2; j!=-1 && i!=-1; j--, i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==drugi)
        {
            (*tab2)[i][j]=true;
            licznik++;
        }
    }
    global_licznik+=licznik;
    return global_licznik;
}

