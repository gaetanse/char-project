#ifndef JEU_H
#define JEU_H

#include "librairies.h"
#include "fenetre.h"
#include "gestionSf.h"
#include "temps.h"
#include "joueur.h"
#include "la_map.h"
#include "munition.h"
#include "bot.h"
#include "explosion.h"
#include "audio.h"
#include "config.h"

class jeu
{
    public:
        jeu(int difficulte,int mapMode,int nbjoueurs,float son,float musique);
        ~jeu();

    void boucle(fenetre &f);
	void start();

    private:

		bool testqdqzd = false;

		int nb = 0;

		float temps_recup = 0;

		unsigned int numeroDePartie = 1;

		//config _config;

		audio _audio;

		/// INFOS RECUPERER
        int diff=0;
        int mapMod=0;
        int joueurs=0;
        float volume_son=0;
        float volume_audio=0;

		bool estMort = false;

		int vie = 0;

        sf::Vector2i globalPosition;

        ///objets
        la_map Map;

		sf::Texture texture_bouclier;
        sf::Texture texture_char;
        sf::Texture texture_dessus;
        sf::Texture texture_map;
        sf::Texture texture_munition;
		sf::Texture texture_explosion;
		sf::Texture texture_viseur;
        sf::Image test_map;

        sf::View view1;

        temps t_animMun;

        gestionSf sf;
        std::vector<joueur>liste_player;
        std::vector<munition>liste_munition;
        std::vector<bot>liste_bot;
		std::vector<explosion>liste_explosions;
       // joueur j1;
        bool fin=false;
        sf::Clock frameClock;

        float vitesse_char=0;

		temps timer_spawn;

        ///jeu
        bool finDePartie=true;
		std::vector<string>listes_son;



		int num_x = 0, num_y = 0;
		int num_2x = 0, num_2y = 0;
		int num_3x = 0, num_3y = 0;


};

#endif // JEU_H
