#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "pokaz.h"

#define BIAL 'B'
#define CZAR 'C'
#define PODP 'P'

#define X_PLANSZY 20
#define Y_PLANSZY 40

#define X_PODP 450
#define Y_PODP 200

#define X_K_KOLOR 450
#define Y_K_KOLOR 350

#define X_M_KOLO 500
#define Y_M_KOLO 380

void pokaz_tabl_w_terminalu(char ***mapa, bool ktory_gracz, char kolor)
{
    using std::cout;
    using std::endl;
    const char pBialy={'B'};
    const char pCzarny={'C'};
    const char pPusty={' '};
    const char znBialy={'B'};
    const char znCzarny={'C'};
    const char znPusty={' '};
    const char znBlad={'!'};
    int lA={0};
    int lB={0};
    bool flagaBleduDanych={false};
    cout<<" ---------------------------------"<<endl;
    for(lA=0;lA<8;lA++)
    {
        for(lB=0;lB<8;lB++)
        {
            cout<<" | ";
            if((*mapa)[lA][lB]==pBialy)
                cout<<znBialy;
                else if((*mapa)[lA][lB]==pCzarny)
                    cout<<znCzarny;
                        else if((*mapa)[lA][lB]==pPusty)
                            cout<<znPusty;
                                else
                                    {
                                        cout<<znBlad;
                                        flagaBleduDanych = true;
                                    }
        }
        cout<<" |"<<endl;
        cout<<" ---------------------------------"<<endl;
    }
    cout<<" ---------------------------------"<<endl;
    cout<<"   Kolej na gracza: ";
        if(ktory_gracz == true)
            cout<<2;
            else if(ktory_gracz == false)
            cout<<1;
            else
            {
                cout<<znBlad;
                flagaBleduDanych = true;
            }
        cout<<" (Kolor: ";
        if(kolor == pBialy)
            cout<<"B)"<<endl;
            else if(kolor == pCzarny)
                cout<<"C)"<<endl;
                else
                {
                    cout<<znBlad<<")"<<endl;
                    flagaBleduDanych = true;
                }
    cout<<" ---------------------------------"<<endl;
    cout<<endl;
    if(flagaBleduDanych == true)
    {
        cout<<"Wystapil blad danych wejsciowych,\nzostal oznaczony w miejscu wystapienia przez: "<<znBlad<<endl;
        cout<<" ---------------------------------"<<endl;
    }
}
void pokaz_podp_w_terminalu(char ***mapa, bool ***mapaPodp, bool ktory_gracz, char kolor)
{
    using std::cout;
    using std::endl;
    const char pBialy={'B'};
    const char pCzarny={'C'};
    const char pPusty={' '};
    const bool fPodp={true};
    const char znBialy={'B'};
    const char znCzarny={'C'};
    const char znPusty={' '};
    const char znBlad={'!'};
    const char znPodp={'*'};
    const char znBladPodp={'?'};
    int lA={0};
    int lB={0};
    bool flagaBleduDanych={false};
    cout<<" ---------------------------------"<<endl;
    for(lA=0;lA<8;lA++)
    {
        for(lB=0;lB<8;lB++)
        {
            cout<<" | ";
            if(((*mapa)[lA][lB]==pBialy || (*mapa)[lA][lB]==pCzarny) && (*mapaPodp)[lA][lB]==fPodp)
            {
                cout<<znBladPodp;
                flagaBleduDanych = true;
            }
            else if((*mapa)[lA][lB]==pBialy)
                cout<<znBialy;
                else if((*mapa)[lA][lB]==pCzarny)
                    cout<<znCzarny;
                        else if((*mapa)[lA][lB]==pPusty && (*mapaPodp)[lA][lB]!=fPodp)
                            cout<<znPusty;
                            else if((*mapaPodp)[lA][lB]==fPodp)
                                cout<<znPodp;
                                else
                                    {
                                        cout<<znBlad;
                                        flagaBleduDanych = true;
                                    }
        }
        cout<<" |"<<endl;
        cout<<" ---------------------------------"<<endl;
    }
    cout<<" ---------------------------------"<<endl;
    cout<<"   Kolej na gracza: ";
        if(ktory_gracz == true)
            cout<<2;
            else if(ktory_gracz == false)
            cout<<1;
            else
            {
                cout<<znBlad;
                flagaBleduDanych = true;
            }
        cout<<" (Kolor: ";
        if(kolor == pBialy)
            cout<<"B)"<<endl;
            else if(kolor == pCzarny)
                cout<<"C)"<<endl;
                else
                {
                    cout<<znBlad<<")"<<endl;
                    flagaBleduDanych = true;
                }
    cout<<" ---------------------------------"<<endl;
    cout<<endl;
    if(flagaBleduDanych == true)
    {
        cout<<"Wystapil blad danych wejsciowych,\nzostal oznaczony w miejscu wystapienia przez: "<<znBlad<<endl;
        cout<<"Lub blad danych podpowiedzi,\nzostal oznaczony w miejscu wystapienia przez: "<<znBladPodp<<"."<<endl;
        cout<<" ---------------------------------"<<endl;
    }

}


void pokaz_tabl_w_sfml(sf::RenderWindow &okno, char **plansza, bool tymczas_gracz,char tymczas_kolor){


    sf::Clock stoper;
    sf::Sprite tlo;
    sf::Texture tex_tlo;
    tex_tlo.loadFromFile("textures/DrewnianeTlo.png");
    tlo.setTexture(tex_tlo);
    sf::Sprite pionek_bialy;
    sf::Texture tex_bialy;
    tex_bialy.loadFromFile("textures/PionekBialy.png");
    pionek_bialy.setTexture(tex_bialy);
    sf::Sprite pionek_czarny;
    sf::Texture tex_czarny;
    tex_czarny.loadFromFile("textures/PionekCzarny.png");
    pionek_czarny.setTexture(tex_czarny);

    if( okno.isOpen() )
    {
        sf::Event event;
        if( okno.pollEvent( event ) && event.type == sf::Event::Closed )
            okno.close();
    }

        tlo.setPosition(0,0);
        okno.draw(tlo);
        for (int x=0; x<8; x++){
            for (int y=0; y<8; y++){
                if (plansza[x][y]==BIAL){
                    pionek_bialy.setPosition( y*50+X_PLANSZY, x*50+Y_PLANSZY );
                    okno.draw( pionek_bialy );
                }
                if (plansza[x][y]==CZAR){
                    pionek_czarny.setPosition( y*50+X_PLANSZY, x*50+Y_PLANSZY );
                    okno.draw( pionek_czarny );
                }
            }
        }
        if (tymczas_gracz){
            pionek_bialy.setPosition(X_M_KOLO, Y_M_KOLO);
            okno.draw(pionek_bialy);
        }
        else{
            pionek_czarny.setPosition(X_M_KOLO, Y_M_KOLO);
            okno.draw(pionek_czarny);
        }
        okno.display();
    }

void pokaz_podp_w_sfml(sf::RenderWindow &okno, char **plansza, bool **podpowiedzi, char tymczas_gracz, char tymczas_kolor){


    sf::Clock stoper;
    sf::Sprite tlo;
    sf::Texture tex_tlo;
    tex_tlo.loadFromFile("textures/DrewnianeTlo.png");
    tlo.setTexture(tex_tlo);
    sf::Sprite pionek_bialy;
    sf::Texture tex_bialy;
    tex_bialy.loadFromFile("textures/PionekBialy.png");
    pionek_bialy.setTexture(tex_bialy);
    sf::Sprite pionek_czarny;
    sf::Texture tex_czarny;
    tex_czarny.loadFromFile("textures/PionekCzarny.png");
    pionek_czarny.setTexture(tex_czarny);
    sf::Sprite p_podp;
    sf::Texture tex_p_podp;
    tex_p_podp.loadFromFile("textures/PionekPodpowiedz.png");
    p_podp.setTexture(tex_p_podp);


    if( okno.isOpen() )
    {
        tlo.setPosition(0,0);
        okno.draw(tlo);
        for (int x=0; x<8; x++){
            for (int y=0; y<8; y++){
                if (plansza[x][y]==BIAL){
                    pionek_bialy.setPosition( y*50+X_PLANSZY, x*50+Y_PLANSZY);
                    okno.draw( pionek_bialy );
                }
                if (plansza[x][y]==CZAR){
                    pionek_czarny.setPosition( y*50+X_PLANSZY, x*50+Y_PLANSZY);
                    okno.draw( pionek_czarny );
                }
            }
        }
        for (int x=0; x<8; x++){
            for (int y=0; y<8; y++){
                if (podpowiedzi[x][y]==true){
                    p_podp.setPosition(y*50+X_PLANSZY, x*50+Y_PLANSZY);
                    okno.draw(p_podp);
                }
            }
        }
        if (tymczas_gracz){
            pionek_czarny.setPosition(X_M_KOLO, Y_M_KOLO);
            okno.draw(pionek_czarny);

        }
        else{
            pionek_bialy.setPosition(X_M_KOLO, Y_M_KOLO);
            okno.draw(pionek_bialy);
        }
        okno.display();
    }
}
void pokaz_pom_bool(bool **tab)
{
    int i,j;
    printf("\n\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
                printf("%d", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void pokaz_pom_int(int **tab)
{
    int i,j;
    printf("\n\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
                printf("%d", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
