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

		int numeroDePartie = 1;

		config _config;

		audio _audio;

        int diff=0;
        int mapMod=0;
        int joueurs=0;
        float volume_son=0;
        float volume_audio=0;

        /// AUDIO
        std::vector<sf::SoundBuffer>sonsBuffers;
		std::vector<sf::Sound>sons;

        int modeDeJeu=0; /// 0 = Facile / 1 = Moyen / 2 = Difficile / 3 = Impossible

        sf::Vector2i globalPosition;

        ///objets
        la_map Map;

		sf::Texture texture_bouclier;
        sf::Texture texture_char;
        sf::Texture texture_dessus;
        sf::Texture texture_map;
        sf::Texture texture_munition;
		sf::Texture texture_explosion;
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

};

#endif // JEU_H
