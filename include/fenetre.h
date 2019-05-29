#ifndef FENETRE_H
#define FENETRE_H

#include "librairies.h"

class fenetre
{
    public:
        fenetre();
        ~fenetre();
        sf::RenderWindow &getWin();
        sf::Event &getEvent();
        float getLargeur();
        float getHauteur();
        void close(){
            renderWindow.close();
        }

    private:

        sf::Event event;
        float largeur=0;
        float hauteur=0;
        sf::RenderWindow renderWindow;

};

#endif // FENETRE_H
