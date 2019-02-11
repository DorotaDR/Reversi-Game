/*#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//####################################################################################################################//
//KLASA PRZYCISK - wielozadaniowa, mo�na wyswietla� przyciski o dowolnym rozmiarze, z tekstur� lub przezroczyste.//
//Obs�uguje offset przy sprawdzaniu klikni�cia ( definiowany z osobna do ka�dego przycisku ).//
//Przekazuj� j� razem z programem testowym, kt�ry pokazuje jej mo�liwo�ci.//
//W razie b�ed�w/problem�w - pisz :).//
//�ycz� mi�ej pracy :D.//
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

    //Konstruktor domy�lny ( i jedyny zreszt� :) )//

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

    fTex = true;//Skoro jest tekstura, to trzeba to zapisa�//
}

void ustawPrzycisk(int wspX, int wspY, int szer, int wys)
{
    //pOkno = okno;
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;

    fTex = false;//Skoro nie ma tekstury, to trzeba to zapisa�//
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

    fTex = true;//Skoro jest tekstura, to trzeba to zapisa�//
}

void ustawPrzycisk(int wspX, int wspY, int szer, int wys, int offset)
{
    pWspX = wspX;
    pWspY = wspY;
    pSzer = szer;
    pWys = wys;

    pOffset = offset;

    fTex = false;//Skoro nie ma tekstury, to trzeba to zapisa�//
}


//--------------------------------------------------------------------------------//

//WY�WIETLANIE PRZYCISKU//

void wyswietlPrzycisk(sf::RenderWindow &okno)
{
    //Wy�wietlanie przycisku//

    if(fTex==true)
    {
        sf::Sprite obrazekPrzycisku;
        obrazekPrzycisku.setTexture( tekstura );
        obrazekPrzycisku.setPosition(pWspX,pWspY);
        okno.draw(obrazekPrzycisku);
    }
}
//------------------------------------------------------------------//

//SPRAWDZANIE KLIKNI�CIA//

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

    //Wczytywanie tekstur do pami�ci//
    sf::Texture tekstura;//T�o//
    tekstura.loadFromFile( "DrewnianeTlo.png" );

    sf::Texture tekstura1;//Przyk�adowy przycisk//
    tekstura1.loadFromFile("PionekPodpowiedz.png");

    //Sprawy zwi�zane z ustawianiem wy�wietlania planszy//(r�wnie dobrze mo�na by�o zrobic to klas� Przycisk, traktuj�c t�o jako przycisk 640x480 px)//
    sf::Sprite obrazek;
    obrazek.setTexture( tekstura );
    obrazek.setPosition(0,0);


    //Tworzenie przycisku//
    Przycisk przyc1;
    przyc1.ustawPrzycisk(200,200,50,50,tekstura1);//Ustawianie przycisku//

    //Tworzenie kilku testowych przycisk�w//

    Przycisk przycTest[8];

    //Ustawianie przycisk�w//

    int lA = 0;
    for(lA=0;lA<8;lA++)
    {
        przycTest[lA].ustawPrzycisk(20 + lA*50, 40, 50, 50, 5, tekstura1);
    }


    //G��wna p�tla wy�wietlania//
    while( oknoAplikacji.isOpen() )
    {
        //Kawa�ek z kursu//
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



        //Sprawdzanie czy klikni�to przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            //Sprawdzanie pozycji myszki wzgledem okna programu w czasie klikni�cia//
            sf::Vector2i pozMyszy = sf::Mouse::getPosition( oknoAplikacji );

            //Sprawdzanie, kt�ry przycisk na planszy zosta� wci�ni�ty//

            for(int lC=0; lC<8; lC++)
            {
                if(przycTest[lC].czyKlikniety(pozMyszy) == true)
                {
                    cout<<"Klikni�to przycisk: "<<lC<<endl;
                    //Wy�wietla sie w terminalu kilkadziesi�t razy, bo program
                    //dzia�a w szybkiej p�tli. Za wolno si� puszcza przycisk myszki
                    //i odczytuje kilka razy jedno klikni�cie.
                    //Mo�na by da� jakie� op�nienie, ale po co,
                    //jak i tak program bedzie wstrzymywany na czas oblicze� :).//

                }
            }
        }
        //---------------------------------------------//


    //Rysowanie po ekranie//
    oknoAplikacji.clear( sf::Color::Black );
    //Wy�wietlanie t�a ( planszy )//
    oknoAplikacji.draw( obrazek );

    //PRZYCISKI TRZEBA WY�WIETLA� PO WY�WIETLENIU PLANSZY//
    //(niby oczywiste  -ale i tak uda�o mi sie to wcze�niej zepsu� :P)//


    //-------------------------------------------------------------//
    przyc1.wyswietlPrzycisk(oknoAplikacji);//WY�WIETLANIE PRZYCISKU//
    //-------------------------------------------------------------//

    //Wy�wietlanie testowych przycisk�w//

    for(int lB=0; lB<8; lB++)
    {
        przycTest[lB].wyswietlPrzycisk(oknoAplikacji);
    }


        oknoAplikacji.display();
    }
    return 0;
}*/
