#ifndef MENU_H
#define MENU_H

#include "librairies.h"
#include "fenetre.h"
#include "gestionSf.h"
#include "joueur.h"

class menu
{
    public:
        menu();
        ~menu();

        void boucle(fenetre &f);

    private:


        int difficulte=1;
        int mapMode=1;
        int joueurs=1;
        float son=25;
        float musique=25;
        sf::Vector2i globalPosition;

        joueur le_joueur;
        sf::Texture texture_char;
        sf::Texture texture_dessus;

        gestionSf sf;
        bool fin=false;
        unsigned int choix=0;

};

#endif // MENU_H
