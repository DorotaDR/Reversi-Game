#include <SFML/Graphics.hpp>
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

#define MENU_DELAY 200000 //Zapobiega przełączaniu się "menów" pod rząd//


/*int menu1(daneOkna oknoAplikacji, struct gra *dane_menu)
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
        wybor=menu1(oknoAplikacji, &(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==1)
            menu2(oknoAplikacji, &(*dane_menu));
        if(wybor==2)
            menu5(oknoAplikacji, &(*dane_menu));
        if(wybor==3)
            (*dane_menu).stan=false;
    }
    return wybor;

}
*/

/*MENU1()

Funkcja zacina mi siê - okno przesta³o odpowiadaæ.
Nie za bardzo wiem jak to naprawiæ.
+Nie pamietam jaki mial byc drugi argument funkcji.

Struktura i wskaŸniki sprawi³y mi nie ma³y problem - rozkmine jak to zapisac. Chyba jest dobrze.

*/


int menu1(daneOkna oknoAplikacji, gra * dane_menu){

    usleep(MENU_DELAY);

    using std::cout;
    using std::endl;

    Przycisk NowaGra;
    Przycisk WczytajGre;
    Przycisk ZakonczGre;

    sf::Texture TNowaGra;
    sf::Texture TWczytajGre;
    sf::Texture TZakonczGre;

    TNowaGra.loadFromFile("textures/NowaGra.png");
    TWczytajGre.loadFromFile("textures/WczytajGre.png");
    TZakonczGre.loadFromFile("textures/ZakonczGre.png");

    NowaGra.ustawPrzycisk(220,50,200, 100, TNowaGra );
    WczytajGre.ustawPrzycisk(220, 190, 200, 100, TWczytajGre);
    ZakonczGre.ustawPrzycisk(220, 330, 200, 100, TZakonczGre);





    while ((*oknoAplikacji.uOkno).isOpen()){




        //Wyświetlanie//
        (*oknoAplikacji.uOkno).clear();
        NowaGra.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        WczytajGre.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        ZakonczGre.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        (*oknoAplikacji.uOkno).display();


        //if ((*oknoAplikacji.uEvent).type==sf::Event::MouseButtonPressed ){

//Kawa³ek z kursu//

        while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) )
        {
            if( (*oknoAplikacji.uEvent).type == sf::Event::Closed )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::KeyPressed && (*oknoAplikacji.uEvent).key.code == sf::Keyboard::Escape )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::MouseButtonPressed && (*oknoAplikacji.uEvent).mouseButton.button == sf::Mouse::Middle )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

//--------------------------------------------------//
        //Sprawdzanie czy klikniêto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {

            sf::Vector2i klik=sf::Mouse::getPosition(*oknoAplikacji.uOkno);


            if (NowaGra.czyKlikniety(klik)){
                while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) ){cout<<"Czyszczenie kolejki."<<endl;}
                menu2(oknoAplikacji, &(*dane_menu));
                return 1;
            }
            if (WczytajGre.czyKlikniety(klik)){
                menu5(oknoAplikacji, &(*dane_menu));
                return 2;
            }
            if (ZakonczGre.czyKlikniety(klik)){
                (*oknoAplikacji.uOkno).close();
                return 3;
            }
        }

        }//while od sprawdzania eventu;

    }
}

/*
int menu2(daneOkna oknoAplikacji, struct gra *dane_menu)
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
        wybor=menu2(oknoAplikacji, &(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==1)
        {
            (*dane_menu).tryb=PVCOMP;
            menu3(oknoAplikacji, &(*dane_menu));
        }
        if(wybor==2)
            (*dane_menu).tryb=PVP;
        if(wybor==3)
            menu1(oknoAplikacji, &(*dane_menu));
    }
    return wybor;
}
*/

int menu2(daneOkna oknoAplikacji, gra * dane_menu){

    usleep(MENU_DELAY);

    using std::cout;
    using std::endl;

    Przycisk Pvcomp;
    Przycisk Pvp;
    Przycisk Wstecz;

    sf::Texture TPvcomp;
    sf::Texture TPvp;
    sf::Texture TWstecz;

    TPvcomp.loadFromFile("textures/PVCOMP.png");
    TPvp.loadFromFile("textures/PVP.png");
    TWstecz.loadFromFile("textures/Wstecz.png");

    Pvcomp.ustawPrzycisk(220,50,200, 100, TPvcomp );
    Pvp.ustawPrzycisk(220, 190, 200, 100, TPvp);
    Wstecz.ustawPrzycisk(220, 330, 200, 100, TWstecz);





    while ((*oknoAplikacji.uOkno).isOpen()){



        //Wyświetlanie//
        (*oknoAplikacji.uOkno).clear();
        Pvcomp.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Pvp.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Wstecz.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        (*oknoAplikacji.uOkno).display();


        //if ((*oknoAplikacji.uEvent).type==sf::Event::MouseButtonPressed ){

     //Kawa³ek z kursu//

        while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) )
        {
            if( (*oknoAplikacji.uEvent).type == sf::Event::Closed )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::KeyPressed && (*oknoAplikacji.uEvent).key.code == sf::Keyboard::Escape )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::MouseButtonPressed && (*oknoAplikacji.uEvent).mouseButton.button == sf::Mouse::Middle )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

//--------------------------------------------------//

        //Sprawdzanie czy klikniêto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {

            sf::Vector2i klik=sf::Mouse::getPosition(*oknoAplikacji.uOkno);


            if (Pvcomp.czyKlikniety(klik)){
                (*dane_menu).tryb=PVCOMP;
                menu3(oknoAplikacji, &(*dane_menu));
                return 1;
            }
            if (Pvp.czyKlikniety(klik)){
                (*dane_menu).tryb=PVP;
                return 2;
            }
            if (Wstecz.czyKlikniety(klik)){
                 menu1(oknoAplikacji, &(*dane_menu));
                return 3;
            }
        }

        }//while od sprawdzania eventu;

    }
}



/*int menu3(daneOkna oknoAplikacji, struct gra *dane_menu)
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
        wybor=menu3(oknoAplikacji, &(*dane_menu));
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
            menu2(oknoAplikacji, &(*dane_menu));
    }
    return wybor;
}*/

int menu3(daneOkna oknoAplikacji, struct gra *dane_menu){

    usleep(MENU_DELAY);

    using std::cout;
    using std::endl;

    Przycisk BialyWybor;
    Przycisk CzarnyWybor;
    Przycisk Wstecz;

    sf::Texture TBialyWybor;
    sf::Texture TCzarnyWybor;
    sf::Texture TWstecz;

    TBialyWybor.loadFromFile("textures/BialyWybor.png");
    TCzarnyWybor.loadFromFile("textures/CzarnyWybor.png");
    TWstecz.loadFromFile("textures/Wstecz.png");

    BialyWybor.ustawPrzycisk(220,50,200, 100, TBialyWybor );
    CzarnyWybor.ustawPrzycisk(220, 190, 200, 100, TCzarnyWybor);
    Wstecz.ustawPrzycisk(220, 330, 200, 100, TWstecz);





    while ((*oknoAplikacji.uOkno).isOpen()){



        //Wyœwietlanie//
        (*oknoAplikacji.uOkno).clear();
        BialyWybor.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        CzarnyWybor.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Wstecz.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        (*oknoAplikacji.uOkno).display();


        //if ((*oknoAplikacji.uEvent).type==sf::Event::MouseButtonPressed ){

     //Kawa3ek z kursu//

        while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) )
        {
            if( (*oknoAplikacji.uEvent).type == sf::Event::Closed )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::KeyPressed && (*oknoAplikacji.uEvent).key.code == sf::Keyboard::Escape )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::MouseButtonPressed && (*oknoAplikacji.uEvent).mouseButton.button == sf::Mouse::Middle )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }



    }

        //Sprawdzanie czy kliknieto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {

            sf::Vector2i klik=sf::Mouse::getPosition(*oknoAplikacji.uOkno);


            if (BialyWybor.czyKlikniety(klik)){

                (*dane_menu).kolor='B';
                return 1;
            }
            if (CzarnyWybor.czyKlikniety(klik)){
                (*dane_menu).kolor='C';
                return 2;
            }
            if (Wstecz.czyKlikniety(klik)){
                 menu2(oknoAplikacji, &(*dane_menu));
                return 3;
            }
        }

        }//while od sprawdzania eventu;

    }



/*int menu4(daneOkna oknoAplikacji, struct gra *dane_menu, char ***tab)
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
        wybor=menu4(oknoAplikacji, &(*dane_menu), &(*tab));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==5)
            menu1(oknoAplikacji, &(*dane_menu));
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
            menu1(oknoAplikacji, &(*dane_menu));
        }

    }
    return wybor;
}
*/
/*
Funkcja nietestowana, bo nie ma zapisu. Powinna działać, bo jest na zasadzie kopiuj wklej i zamień.

Potrzebne grafiki:
    -ZapisanePoprawnie.png
    -NieZapisanePoprawnie.png
    -Plik1.png (2..., 3..., 4... też)
    -Wstecz.png

*/
int menu4(daneOkna oknoAplikacji, struct gra *dane_menu, char ***tab){

    usleep(MENU_DELAY);

    using std::cout;
    using std::endl;

    Przycisk Plik1;
    Przycisk Plik2;
    Przycisk Plik3;
    Przycisk Plik4;
    Przycisk Wstecz;
    Przycisk Komunikat;

    sf::Texture TPlik1;
    sf::Texture TPlik2;
    sf::Texture TPlik3;
    sf::Texture TPlik4;
    sf::Texture TWstecz;
    sf::Texture TKomunikat;

    TPlik1.loadFromFile("textures/Plik1.png");
    TPlik2.loadFromFile("textures/Plik2.png");
    TPlik3.loadFromFile("textures/Plik3.png");
    TPlik4.loadFromFile("textures/Plik4.png");
    TWstecz.loadFromFile("textures/Wstecz.png");


    Plik1.ustawPrzycisk(70,50,200, 100, TPlik1 );
    Plik2.ustawPrzycisk(370, 50, 200, 100, TPlik2);
    Plik3.ustawPrzycisk(70,190,200, 100, TPlik3 );
    Plik4.ustawPrzycisk(370, 190, 200, 100, TPlik4);
    Wstecz.ustawPrzycisk(220, 330, 200, 100, TWstecz);

    while ((*oknoAplikacji.uOkno).isOpen()){

        //Wyświetlanie//
        (*oknoAplikacji.uOkno).clear();
        Plik1.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Plik2.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Plik3.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Plik4.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        Wstecz.wyswietlPrzycisk(*oknoAplikacji.uOkno);
        (*oknoAplikacji.uOkno).display();


        //if ((*oknoAplikacji.uEvent).type==sf::Event::MouseButtonPressed ){

     //Kawa³ek z kursu//

        while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) )
        {
            if( (*oknoAplikacji.uEvent).type == sf::Event::Closed )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::KeyPressed && (*oknoAplikacji.uEvent).key.code == sf::Keyboard::Escape )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::MouseButtonPressed && (*oknoAplikacji.uEvent).mouseButton.button == sf::Mouse::Middle )
                 {
                     (*oknoAplikacji.uOkno).close();
                     return 0;
                 }



    }

        //Sprawdzanie czy klikniêto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {

            sf::Vector2i klik=sf::Mouse::getPosition(*oknoAplikacji.uOkno);

            if (Plik1.czyKlikniety(klik) || Plik2.czyKlikniety(klik) || Plik3.czyKlikniety(klik) ||Plik4.czyKlikniety(klik)){


            if (Plik1.czyKlikniety(klik)) {
                (*dane_menu).nr_pliku=1;
            }

            if (Plik2.czyKlikniety(klik)) {
                (*dane_menu).nr_pliku=2;
            }

            if (Plik3.czyKlikniety(klik)) {
                (*dane_menu).nr_pliku=3;
            }

            if (Plik4.czyKlikniety(klik)) {
                (*dane_menu).nr_pliku=4;
            }
            if(zapisz(&(*tab), (*dane_menu).kolor, (*dane_menu).tryb, (*dane_menu).gracz, (*dane_menu).plik)==true)
            {
                (*oknoAplikacji.uOkno).clear();
                TKomunikat.loadFromFile("ZapisanoPoprawnie.png");
                Komunikat.ustawPrzycisk(180, 115, 280, 250, 5, TKomunikat);
                Komunikat.wyswietlPrzycisk(*oknoAplikacji.uOkno);
                if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
                {
                    sf::Vector2i klik2=sf::Mouse::getPosition(*oknoAplikacji.uOkno);
                    if(Komunikat.czyKlikniety(klik2)){
                        menu1(oknoAplikacji,  &(*dane_menu));
                    }
                }
            }
            else
            {
                (*oknoAplikacji.uOkno).clear();
                TKomunikat.loadFromFile("NieZapisanoPoprawnie.png");
                Komunikat.ustawPrzycisk(180, 115, 280, 250, 5, TKomunikat);
                Komunikat.wyswietlPrzycisk(*oknoAplikacji.uOkno);
                if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
                {
                    sf::Vector2i klik2=sf::Mouse::getPosition(*oknoAplikacji.uOkno);
                    if(Komunikat.czyKlikniety(klik2)){
                        menu1(oknoAplikacji,  &(*dane_menu));
                    }
                }
            }
            if (Wstecz.czyKlikniety(klik)){
                 menu1(oknoAplikacji, &(*dane_menu));
                return 1;
            }
        }

        }//while od sprawdzania eventu;

    }
        }



int menu5(daneOkna oknoAplikacji, struct gra *dane_menu)
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
        wybor=menu5(oknoAplikacji, &(*dane_menu));
    }
    else
    {
        while(getchar()!='\n')
            continue;
        if(wybor==5)
            menu1(oknoAplikacji, &(*dane_menu));
        else
        {
            system("cls");
            printf("Opcja chwilowo niedostepna.\n\n");
            while(getchar()!='\n')
                continue;
            menu5(oknoAplikacji, &(*dane_menu));
        }
    }
    return wybor;
}
