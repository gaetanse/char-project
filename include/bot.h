#ifndef BOT_H
#define BOT_H

#include "librairies.h"
#include "la_map.h"
#include "pathfinding.h"
#include "temps.h"
#include <math.h>

class bot
{
    public:
        bot(int id);
        ~bot();
        void affichage(sf::RenderWindow &window);
        void diriger_canon(sf::Vector2i);
        sf::Vector2f getPosition();
        void tournerLeViseur(sf::Vector2f LeVector);
		bool est_dans_la_liste(int nb);
		bool tirer();
		int testMapDeCase(int v);
		void spawn();
		void deplace(float temp_recup);
		int check_col(sf::Vector2f test);

		int getX();
		int getY();

		sf::Vector2f orentation();
		void cherche_joueur(sf::Vector2f joueur, la_map Map);

		void donner_texture(sf::Texture& texture);
		void donner_texture_2(sf::Texture& texture);


		void setSpawn(int y, int x) {

			sprite.setPosition(sf::Vector2f(x * 64 + 32, y * 64 + 32));

		}

    private:

	int numero = 0;

    pathfinding path;
    temps t_reload;
    int max_munition=0;

    sf::Sprite sprite;
    sf::Sprite sprit_cannon;

    temps t_anime;
    int dejafait=0;

    int x=0;
    int y=0;

    std::vector<int>liste_chemin;
    std::vector<int>best_chemin;
    std::vector<int>test_chemin;
    std::vector<bool>bool_chemin;
    std::vector<int>nb_chemin;

};

#endif // BOT_H
