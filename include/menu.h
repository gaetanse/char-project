#ifndef MENU_H
#define MENU_H

#include "librairies.h"
#include "fenetre.h"
#include "gestionSf.h"
#include "joueur.h"
#include "config.h"
#include "audio.h"

class menu
{
    public:
        menu();
        ~menu();

        void boucle(fenetre &f);

    private:

		config _config;

        int difficulte=1;
        int mapMode=1;
        int joueurs=1;
        float son=25;
        float musique=25;
        sf::Vector2i globalPosition;

        gestionSf sf;
        bool fin=false;
        unsigned int choix=0;

};

#endif // MENU_H
