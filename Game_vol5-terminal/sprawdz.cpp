#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "sprawdz.h"

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
    for(i=wsp_x-1, j=wsp_y-2; j!=-1;j--)        /*N*/
    {
        if(j==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x, j=wsp_y-1; i!=8;i++)        /*E*/
    {
        if(i==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-1, j=wsp_y; j!=8;j++)      /*S*/
    {
        if(j==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-2, j=wsp_y-1; i!=-1;i--)        /*W*/
    {
        if(i==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x, j=wsp_y-2; j!=-1 && i!=8; j--, i++)        /*NE*/
    {
        if(j==0 || i==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
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
        if(j==7 || i==7)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
        if((*tab)[i][j]==' ')
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==drugi)
            licznik++;
    }
    global_licznik+=licznik;
    for(i=wsp_x-2, j=wsp_y; j!=8 && i!=-1; j++, i--)        /*SW*/
    {
        if(j==7 || i==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
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
        if(j==0 || i==0)
        {
            licznik=0;
            break;
        }
        if((*tab)[i][j]==kolor)
            break;
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

