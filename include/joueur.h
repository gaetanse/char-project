#ifndef JOUEUR_H
#define JOUEUR_H

#include "librairies.h"
#include "temps.h"
#include "fenetre.h"
#include "munition.h"

class joueur
{
    public:
        joueur();
        ~joueur();

        int deplacement_normal(int touche,float time_r);
        int deplacement_complexe(int touche,float time_r);
        void affichage(sf::RenderWindow &window);
        void diriger_canon(sf::Vector2i);

        void respawn(){}

           int check_col(sf::Vector2f test){

            if(test.x>getPosition().x&&test.x<getPosition().x+16){
                if(test.y>getPosition().y&&test.y<getPosition().y+16){
                    return 1;
                }
            }

        }

        sf::Vector2f getPosition();


void donnerTaille_fenetre(fenetre &fenetre){

    fenetre_x=fenetre.getLargeur();
    fenetre_y=fenetre.getHauteur();

}

int getNum(){return numero_joueur;}

void donner_texture(sf::Texture &texture){
    sprite.setTexture(texture);
}
void donner_texture_2(sf::Texture &texture){
    sprite2.setTexture(texture);
}

    bool tirer(){

		if (t_reload.Wait_Temps(1.0)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return true;
			}
			return false;
		}
		return false;

		/*
        if(t_reload.Wait_Temps(1)==1)
            if(max_munition<1)
                max_munition++;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&max_munition>0){
                max_munition--;
                return true;
            }

            return false;
			*/
        }

        int testMapDeCase(int v){

        std::cout << "random:" << v << std::endl;

        if(v==2)
            v=3;


        return v;

        }

        void spawn(){


            x = rand() % 30;
            y = rand() % 17;

            std::cout << x << " / " << y << std::endl;

            sprite.setPosition(sf::Vector2f(x*64,y*64));


        }

        void spawn_milieu(){

            sprite.setPosition(sf::Vector2f(fenetre_x/2,fenetre_y/3));


        }

    private:

    int numero_joueur=0;

    sf::Sprite sprite;
    sf::Sprite sprite2;
    int vie=5;
    int fenetre_x=0;
    int fenetre_y=0;

    int x=0;
    int y=0;

    float vitesse=500;
    int vitesse_tourner=10;

    float sens_x=0;
    float sens_y=0;

    temps t_reload;
    int max_munition=0;

    float ancienne_pos_cannon=0;

};

#endif // JOUEUR_H
