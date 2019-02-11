struct gra
{
    bool tryb;
    char kolor;
    bool gracz;
    bool stan;
    FILE *plik;
    int nr_pliku;
};
int menu1(struct gra *dane_menu);
int menu2(struct gra *dane_menu);
int menu3(struct gra *dane_menu);
int menu4(struct gra *dane_menu, char ***tab);
int menu5(struct gra *dane_menu);
