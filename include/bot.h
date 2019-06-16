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
        bot(int id,int diff);
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

		int get_numero() { return numero; }


		void bouclier() {


			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (mana > 0) {
					bouclierb = true;
					//if (t_bouclier.Wait_Temps(0.05)) {
					mana--;
					//}
				}
				else {
					bouclierb = false;
				}
			}
			else {
				bouclierb = false;
			}

		}

		bool get_a_bouclier() { return a_bouclier; }

		void timer() {
			if (munition_bouclier > 0) {
				if (t_bouclier_load.Wait_Temps(vitesse_a)) {
					munition_bouclier--;
					bouclierb = true;
				}
			}
		}

		void timer2() {
			if(bouclierb){
				if (t_bouclier_load2.Wait_Temps(vitesse_b)) {
					bouclierb = false;
				}
			}
			else {
				t_bouclier_load2.reset();
			}
		}

		void set_bouclierb() {
			if (munition_bouclier > 0) {
				munition_bouclier--;
				bouclierb = true;
			}
		}

		bool get_bouclierb() { return bouclierb; }
		void donner_texture_3(sf::Texture& texture) {
			sprite3.setTexture(texture);
			sprite3.setColor(sf::Color::Red);
		}

    private:

		int difficulte = 0;
		float vitesse_tire = 0;

		bool timerok = false;
		float rotate = 0;
		temps t_bouclier_load2;
		temps t_bouclier_load;
		temps t_bouclier;
		int mana = 100;
		int munition_bouclier = 5;
		bool bouclierb = false;
		sf::Sprite sprite3;

		float vitesse_a = 0;
		float vitesse_b = 0;

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

	bool a_bouclier = false;

	float rotation = 0;

};

#endif // BOT_H
