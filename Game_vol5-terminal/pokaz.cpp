#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#define MAX 8
#define PVP 0
#define PVCOMP 1
#include "pokaz.h"

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
