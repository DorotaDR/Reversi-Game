/*#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//####################################################################################################################//
//KLASA PRZYCISK - wielozadaniowa, mo¿na wyswietlaæ przyciski o dowolnym rozmiarze, z tekstur¹ lub przezroczyste.//
//Obs³uguje offset przy sprawdzaniu klikniêcia ( definiowany z osobna do ka¿dego przycisku ).//
//Przekazujê j¹ razem z programem testowym, który pokazuje jej mo¿liwoœci.//
//W razie b³edów/problemów - pisz :).//
//¯yczê mi³ej pracy :D.//
//####################################################################################################################//
class Przycisk{


private:
    sf::Texture tekstura;
    sf::RenderWindow pOkno;
    int pWspX;
    int pWspY;
    int pSzer;
    int pWys;

    int pOffset;

    bool fTex;

public:

    //Konstruktor domyœlny ( i jedyny zreszt¹ :) )//

    Przycisk(): pWspX(0), pWspY(0), pSzer(0), pWys(0), pOffset(0), fTex(false)
    {
        ;
    }

    //--------------------------------------------//



//_____________________________________________METODY______________________________________________//

//USTAWIANIE PRZYCISKU//

void ustawPrzycisk(int wspX, int wspY, int szer, int wys, sf::Texture &tex1)
{
    //pOkno = okno;
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;
    tekstura = tex1;

    fTex = true;//Skoro jest tekstura, to trzeba to zapisaæ//
}

void ustawPrzycisk(int wspX, int wspY, int szer, int wys)
{
    //pOkno = okno;
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;

    fTex = false;//Skoro nie ma tekstury, to trzeba to zapisaæ//
}


void ustawPrzycisk(int wspX, int wspY, int szer, int wys, int offset, sf::Texture &tex1)
{
    //pOkno = okno;
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;
    tekstura = tex1;

    pOffset = offset;

    fTex = true;//Skoro jest tekstura, to trzeba to zapisaæ//
}

void ustawPrzycisk(int wspX, int wspY, int szer, int wys, int offset)
{
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;

    pOffset = offset;

    fTex = false;//Skoro nie ma tekstury, to trzeba to zapisaæ//
}


//--------------------------------------------------------------------------------//

//WYŒWIETLANIE PRZYCISKU//

void wyswietlPrzycisk(sf::RenderWindow &okno)
{
    //Wyœwietlanie przycisku//

    if(fTex==true)
    {
        sf::Sprite obrazekPrzycisku;
        obrazekPrzycisku.setTexture( tekstura );
        obrazekPrzycisku.setPosition(pWspX,pWspY);
        okno.draw(obrazekPrzycisku);
    }
}
//------------------------------------------------------------------//

//SPRAWDZANIE KLIKNIÊCIA//

bool czyKlikniety(sf::Vector2i &wekt)
{
    int minX;
    int maxX;
    int minY;
    int maxY;

    int pozMyszX = wekt.x;
    int pozMyszY = wekt.y;

    minX = pWspX+pOffset;
    maxX = pWspX+pSzer - pOffset;

    minY = pWspY+pOffset;
    maxY = pWspY+pWys - pOffset;

    if((pozMyszX<maxX && pozMyszX>minX) && (pozMyszY<maxY && pozMyszY> minY))
    {
        return true;
    }
    return false;
}

//-----------------------------------------------------------//

};//KONIEC KLASY ( Nareszcie... )//

//####################################################################################################################//






//PROGRAM TESTOWY-----------------------------------------------------------------------------------------------------//
int main()
{
    string nazwa  = "box.png";
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 640, 480, 32 ), "Kurs SFML - http://cpp0x.pl" );

    //Wczytywanie tekstur do pamiêci//
    sf::Texture tekstura;//T³o//
    tekstura.loadFromFile( "DrewnianeTlo.png" );

    sf::Texture tekstura1;//Przyk³adowy przycisk//
    tekstura1.loadFromFile("PionekPodpowiedz.png");

    //Sprawy zwi¹zane z ustawianiem wyœwietlania planszy//(równie dobrze mo¿na by³o zrobic to klas¹ Przycisk, traktuj¹c t³o jako przycisk 640x480 px)//
    sf::Sprite obrazek;
    obrazek.setTexture( tekstura );
    obrazek.setPosition(0,0);


    //Tworzenie przycisku//
    Przycisk przyc1;
    przyc1.ustawPrzycisk(200,200,50,50,tekstura1);//Ustawianie przycisku//

    //Tworzenie kilku testowych przycisków//

    Przycisk przycTest[8];

    //Ustawianie przycisków//

    int lA = 0;
    for(lA=0;lA<8;lA++)
    {
        przycTest[lA].ustawPrzycisk(20 + lA*50, 40, 50, 50, 5, tekstura1);
    }


    //G³ówna pêtla wyœwietlania//
    while( oknoAplikacji.isOpen() )
    {
        //Kawa³ek z kursu//
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();

        }
        //-------------------//



        //Sprawdzanie czy klikniêto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            //Sprawdzanie pozycji myszki wzgledem okna programu w czasie klikniêcia//
            sf::Vector2i pozMyszy = sf::Mouse::getPosition( oknoAplikacji );

            //Sprawdzanie, który przycisk na planszy zosta³ wciœniêty//

            for(int lC=0; lC<8; lC++)
            {
                if(przycTest[lC].czyKlikniety(pozMyszy) == true)
                {
                    cout<<"Klikniêto przycisk: "<<lC<<endl;
                    //Wyœwietla sie w terminalu kilkadziesi¹t razy, bo program
                    //dzia³a w szybkiej pêtli. Za wolno siê puszcza przycisk myszki
                    //i odczytuje kilka razy jedno klikniêcie.
                    //Mo¿na by daæ jakieœ opóŸnienie, ale po co,
                    //jak i tak program bedzie wstrzymywany na czas obliczeñ :).//

                }
            }
        }
        //---------------------------------------------//


    //Rysowanie po ekranie//
    oknoAplikacji.clear( sf::Color::Black );
    //Wyœwietlanie t³a ( planszy )//
    oknoAplikacji.draw( obrazek );

    //PRZYCISKI TRZEBA WYŒWIETLAÆ PO WYŒWIETLENIU PLANSZY//
    //(niby oczywiste  -ale i tak uda³o mi sie to wczeœniej zepsuæ :P)//


    //-------------------------------------------------------------//
    przyc1.wyswietlPrzycisk(oknoAplikacji);//WYŒWIETLANIE PRZYCISKU//
    //-------------------------------------------------------------//

    //Wyœwietlanie testowych przycisków//

    for(int lB=0; lB<8; lB++)
    {
        przycTest[lB].wyswietlPrzycisk(oknoAplikacji);
    }


        oknoAplikacji.display();
    }
    return 0;
}*/
