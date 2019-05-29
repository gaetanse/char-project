#ifndef GESTIONSF_H
#define GESTIONSF_H

#include "librairies.h"

class gestionSf
{
    public:
        gestionSf();
        ~gestionSf();
        void donne(int sprite,int rectangle,int text);
        void creerSprite(std::string textureNom,sf::Vector2f position,sf::Vector2f taille);
        void creerRectangle(sf::Vector2f position,sf::Vector2f taille,sf::Color couleur,float contour,sf::Color contourColor);
        void creerTexte(std::string texte,sf::Vector2f position,unsigned int taille,sf::Color couleur);
        void modifText(unsigned int num,std::string texte);
        void affichage(sf::RenderWindow &win);
        void resetText();
        void resetRect();
        std::string getText(int val);
        void modifRect(unsigned int num,sf::Vector2f taille,sf::Vector2f pos);
        void modifRectV2(int choix,sf::Color couleur);
        long getTextSize();
        void setPos_sprite(int num,sf::Vector2f pos);

void supprime_sprite(int a){
    sprites.erase(sprites.begin()+a);
}

        sf::Sprite getSprite(int num);

   // void modifRect(unsigned int num,sf::Vector2f taille);

    private:

        bool qualite=true;
        std::vector<sf::Sprite>sprites;
        std::vector<sf::Texture>textures;
        std::vector<sf::Text>texts;
        std::vector<sf::RectangleShape>rectangles;
        sf::Font font;
};

#endif // GESTIONSF_H
