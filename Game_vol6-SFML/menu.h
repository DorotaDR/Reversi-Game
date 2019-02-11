#include <SFML/Graphics.hpp>

struct gra
{
    bool tryb;
    char kolor;
    bool gracz;
    bool stan;
    FILE *plik;
    int nr_pliku;
};

struct daneOkna{
    sf::RenderWindow * uOkno;
    sf::Event * uEvent;
};
int menu1(daneOkna oknoAplikacji, struct gra *dane_menu);
int menu2(daneOkna oknoAplikacji, struct gra *dane_menu);
int menu3(daneOkna oknoAplikacji, struct gra *dane_menu);
int menu4(daneOkna oknoAplikacji, struct gra *dane_menu, char ***tab);
int menu5(daneOkna oknoAplikacji, struct gra *dane_menu);

void obslugaEventu(daneOkna oknoAplikacji);


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
