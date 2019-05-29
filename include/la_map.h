#ifndef LA_MAP_H
#define LA_MAP_H

#include "librairies.h"
#include "fenetre.h"

#define x_taille 30
#define y_taille 17

class la_map
{
    public:
        la_map();
        ~la_map();
        void charger(int numero);
        void afficher(fenetre &fenetre);
        void charger_texture(sf::Texture &texture);
        int get_block(sf::Vector2f position);
        int get_block_2(int y,int x);
        int get_num(sf::Vector2f position);

    private:

        int mapDonne[y_taille][x_taille];
        sf::Sprite sprite;
        std::vector<bool>liste_blocks;

};

#endif // LA_MAP_H
