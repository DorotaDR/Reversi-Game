/*
Funkcja sprawdza czy na planszy coś kliknięto i zamienia te dane w współrzędne tablicy (kolejność tablica[x][y]) :)
Należy przekazac funkcji okno aplikacji, wskaxnik na x i wskaxnik na y, ktore zostana zamienione i offset - czyli odległość nieaktywna od krawedzi jednego pola  :)



Testowana

*/
#include <SFML/Graphics.hpp>
#include "menu.h"

#define X_PLANSZY 20
#define Y_PLANSZY 40

bool info_klik_plansza (daneOkna &oknoAplikacji, int *x,int *y, int offset){

    //sf::Vector2i klik;
    //if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        //klik = sf::Mouse::getPosition(okno);            // tu mozliwa zmiana nazwy okno
    //else{
      //  sf::Vector2i zero(0,0);
       // klik=zero;
       // return false;
   // }

   //Kawa³ek z kursu//

        while( (*oknoAplikacji.uOkno).pollEvent( (*oknoAplikacji.uEvent) ) )
        {
            if( (*oknoAplikacji.uEvent).type == sf::Event::Closed )
                 {
                     (*oknoAplikacji.uOkno).close();
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::KeyPressed && (*oknoAplikacji.uEvent).key.code == sf::Keyboard::Escape )
                 {
                     (*oknoAplikacji.uOkno).close();
                 }

            if( (*oknoAplikacji.uEvent).type == sf::Event::MouseButtonPressed && (*oknoAplikacji.uEvent).mouseButton.button == sf::Mouse::Middle )
                 {
                     (*oknoAplikacji.uOkno).close();
                 }

//--------------------------------------------------//

        //Sprawdzanie czy klikniêto przycisk myszki//
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {

            sf::Vector2i klik=sf::Mouse::getPosition(*oknoAplikacji.uOkno);

    for (int j=0; j<8; j++){                    // Czytanie dostarczonej tablicy i wyświetlanie pionków.
            for (int i=0; i<8; i++){


                if (klik.x > i*50+X_PLANSZY+offset && klik.x < (i+1)*50+X_PLANSZY-offset &&
                    klik.y > j*50+Y_PLANSZY+offset && klik.y < (j+1)*50+Y_PLANSZY-offset){
                    *x=j+1;
                    *y=i+1;
                    return true;
                    }
        }

    }

        }

}

return false;
}

