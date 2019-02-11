#include <SFML/Graphics.hpp>

void pokaz_tabl_w_terminalu(char ***mapa, bool ktory_gracz, char kolor);
void pokaz_tabl_w_sfml(sf::RenderWindow &okno, char **plansza, bool tymczas_gracz,char tymczas_kolor);
void pokaz_podp_w_sfml(sf::RenderWindow &okno, char **plansza, bool **podpowiedzi, char tymczas_gracz, char tymczas_kolor);
void pokaz_podp_w_terminalu(char ***mapa, bool ***mapaPodp, bool ktory_gracz, char kolor);
void pokaz_pom_bool(bool **tab);
void pokaz_pom_int(int **tab);
