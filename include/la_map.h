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
		int get_id(sf::Vector2f position1, sf::Vector2f position2);
		void checkContour(sf::Vector2f position);
		void generationA();

		void set_block(int y, int x,int val) {

			if (y < y_taille && x < x_taille)
				mapDonne[y][x]=val+48;

		}

		void set_blockV2(int y, int x, int val, int taille, int sens) {

			for (int a = 0; a < taille; a++) {

				if(sens==0)
					if (y < y_taille && x-a < x_taille)
						mapDonne[y][x - a] = val + 48;
				 if (sens == 1)
					if (y-a < y_taille && x < x_taille)
						mapDonne[y-a][x] = val + 48;
				 if (sens == 2)
					if (y < y_taille && x+a < x_taille)
						mapDonne[y][x+a] = val + 48;
				 if (sens == 3)
					if (y+a < y_taille && x < x_taille)
						mapDonne[y+a][x] = val + 48;

			}


		}

    private:

		int mapDonne[y_taille][x_taille] = {0};
        sf::Sprite sprite;
        std::vector<bool>liste_blocks;

};

#endif // LA_MAP_H
