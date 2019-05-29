#ifndef OPTION_H
#define OPTION_H

#include "librairies.h"
#include "fenetre.h"
#include "gestionSf.h"

class option
{
    public:
        option();
        virtual ~option();

        void boucle(fenetre &fenetre);

    private:

        gestionSf sf;
        bool fin=false;
        bool deplacement_complexe=false;
        sf::Color couleur_pointeur;

};

#endif // OPTION_H
