#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "komorka_sprawdz_licz.h"
#include "wartosc_pocz.h"
bool sprawdz_komorke(char ***tab, int wsp_x, int wsp_y, char kolor)
{
    char drugi;
    int i,j;
    int global_licznik=0;
    int licznik=0;
    if((*tab)[wsp_x-1][wsp_y-1]=='B' || (*tab)[wsp_x-1][wsp_y-1]=='C')
    {
        return false;
    }
    if(kolor=='B')
        drugi='C';
    else
        drugi='B';
    for(i=wsp_x-2, j=wsp_y-1; i!=-1;i--)        /*N*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(i==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-1, j=wsp_y; j!=8;j++)        /*E*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(j==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x, j=wsp_y-1; i!=8;i++)      /*S*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(i==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-1, j=wsp_y-2; j!=-1;j--)        /*W*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(j==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-2, j=wsp_y; i!=-1 && j!=8; i--, j++)        /*NE*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(i==0 || j==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x, j=wsp_y; j!=8 && i!=8; j++, i++)        /*SE*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(j==7 || i==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x, j=wsp_y-2; i!=8 && j!=-1; i++, j--)        /*SW*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(i==7 || j==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-2, j=wsp_y-2; j!=-1 && i!=-1; j--, i--)        /*NW*/
    {
        if((*tab)[i][j]==kolor)
            break;
        if(j==0 || i==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    if(global_licznik==0)
        return false;
    else
        return true;
}
int licz_kolor(char ***tab, int *bial, int *czar)
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
    return *bial+*czar;
}
int zlicz_liczbe_zbitych(char ***tab1, int wsp_x, int wsp_y, char kolor, bool ***tab2)
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
    for(licznik=0, i=wsp_x-2, j=wsp_y-1; i!=-1;i--)        /*N*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(i==0)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-1; i!=-1; i--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-1; i!=-1; i--)
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
    for(licznik=0, i=wsp_x-1, j=wsp_y; j!=8;j++)        /*E*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(j==7)
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y; j!=8;j++)
                (*tab2)[i][j]=false;
            break;
        }
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
    for(licznik=0, i=wsp_x, j=wsp_y-1; i!=8;i++)      /*S*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(i==7)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-1; i!=8;i++)
                (*tab2)[i][j]=false;
            break;
        }
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
    for(licznik=0, i=wsp_x-1, j=wsp_y-2; j!=-1;j--)        /*W*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(j==0)
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y-2; j!=-1;j--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-1, j=wsp_y-2; j!=-1;j--)
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
    for(licznik=0, i=wsp_x-2, j=wsp_y; i!=-1 && j!=8; i--, j++)        /*NE*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(i==0 || j==7)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y; i!=-1 && j!=8; i--, j++)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y; i!=-1 && j!=8; i--, j++)
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
        if((*tab1)[i][j]==kolor)
            break;
        if(j==7 || i==7)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y; j!=8 && i!=8; j++, i++)
                (*tab2)[i][j]=false;
            break;
        }
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
    for(licznik=0, i=wsp_x, j=wsp_y-2; i!=8 && j!=-1; i++, j--)        /*SW*/
    {
        if((*tab1)[i][j]==kolor)
            break;
        if(i==7 || j==0)
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-2; i!=8 && j!=-1; i++, j--)
                (*tab2)[i][j]=false;
            break;
        }
        if((*tab1)[i][j]==' ')
        {
            licznik=0;
            for(i=wsp_x, j=wsp_y-2; i!=8 && j!=-1; i++, j--)
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
        if((*tab1)[i][j]==kolor)
            break;
        if(j==0 || i==0)
        {
            licznik=0;
            for(i=wsp_x-2, j=wsp_y-2; j!=-1 && i!=-1; j--, i--)
                (*tab2)[i][j]=false;
            break;
        }
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
int wartosc_planszy(char ***tab1, int ***tab2, int *wsp_x, int *wsp_y, char kolor)
{
    int i,j, max_value;
    bool **temp;
    wartosc_pocz_bool(&temp);
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            (*tab2)[i][j]=0;
    for(i=0;i<MAX;i++)
            for(j=0;j<MAX;j++)
                if(sprawdz_komorke(&(*tab1), i+1, j+1, kolor)==true)
                    (*tab2)[i][j]=zlicz_liczbe_zbitych(&(*tab1), i+1, j+1, kolor, &temp);
    max_value=(*tab2)[0][0];
    *wsp_x=*wsp_y=1;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(max_value<(*tab2)[i][j])
            {
                max_value=(*tab2)[i][j];
                *wsp_x=i+1;
                *wsp_y=j+1;
            }
        }
    }
    return max_value;
}



