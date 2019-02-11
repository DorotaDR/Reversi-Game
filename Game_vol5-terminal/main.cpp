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
#define MAX 8
#define PVP 0
#define PVCOMP 1
using namespace std;
int main(void)
{
    struct gra dane_menu;
    dane_menu.stan=true;
    menu1(&dane_menu);
    while(graj_w_gre(&dane_menu)==true)
        continue;
    return 0;
}
