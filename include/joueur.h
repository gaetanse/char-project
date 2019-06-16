#ifndef JOUEUR_H
#define JOUEUR_H

#include "librairies.h"
#include "temps.h"
#include "fenetre.h"
#include "munition.h"

#define tirerID 0
#define bouclierID 1

class joueur
{
    public:
        joueur(int nb);
        ~joueur();

        int deplacement_normal(int touche,float time_r);
        void deplacement_complexe(int touche,float time_r);
        void affichage(sf::RenderWindow &window);
        void diriger_canon(sf::Vector2i);

		void respawn() {};

        sf::Vector2f getPosition();
		sf::Vector2f getPosition_bouclier();


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
void donner_texture_3(sf::Texture &texture){
    sprite3.setTexture(texture);
}

void moveViseur(fenetre& f) {

#define vitesseJoystick 20

	if (sf::Joystick::isConnected(id))
	{

		float x = sf::Joystick::getAxisPosition(id, sf::Joystick::U);
		float y = sf::Joystick::getAxisPosition(id, sf::Joystick::V);

		
		if (x > 1&& sprite4.getPosition().x<f.getLargeur()) {
			sprite4.move(sf::Vector2f(vitesseJoystick, 0));

		}
		else if (x < 0 && sprite4.getPosition().x >0) {
			sprite4.move(sf::Vector2f(-vitesseJoystick, 0));

		}

		if (y > 1 && sprite4.getPosition().y < f.getHauteur()) {
			sprite4.move(sf::Vector2f(0, vitesseJoystick));

		}
		else if (y < -0.01 && sprite4.getPosition().y > 0) {
			sprite4.move(sf::Vector2f(0, -vitesseJoystick));
			std::cout << y;

		}

			//globalPosition = sf::Mouse::getPosition();
			//float x = globalPosition.x - 15; float y = globalPosition.y - 15;
			//sf.setPos_sprite(0, sf::Vector2f(x, y));
			//sf::Vector2f test = sf::Vector2f(x, y);

	//	}

	}
	else{

		if (f.getEvent().type == sf::Event::MouseMoved) {

		sf::Vector2i globalPosition = sf::Mouse::getPosition();
		float x = globalPosition.x - 15; float y = globalPosition.y - 15;
		sprite4.setPosition(sf::Vector2f(x,y));
	/*	sf.setPos_sprite(0, sf::Vector2f(x, y));
		sf::Vector2f test = sf::Vector2f(x, y);*/

	}

	}


}

void donner_texture_4(sf::Texture& texture) {
	sprite4.setTexture(texture);
}

sf::Vector2f getPosViseur() { return sprite4.getPosition(); }

    bool tirer(){

		if (sf::Joystick::isConnected(id))
		{

			if (t_reload.Wait_Temps(0.5)) {
				if (sf::Joystick::isButtonPressed(id, tirerID)) {
					return true;
				}
				return false;
			}
			return false;

		}
		else {

		if (t_reload.Wait_Temps(0.5)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return true;
			}
			return false;
		}
		return false;

		}

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

			sprite.setPosition(sf::Vector2f(x * 64 + 32, y * 64 + 32));

        }

		void setSpawn(int y, int x) {

			sprite.setPosition(sf::Vector2f(x * 64 + 32, y * 64 + 32));

		}

        void spawn_milieu(){

            sprite.setPosition(sf::Vector2f(fenetre_x/2,fenetre_y/3));


        }

		int getX() { return x; }
		int getY() { return y; }

		int getBval() { return mana; }

		void bouclier() {


			if (sf::Joystick::isConnected(id))
			{

				if (sf::Joystick::isButtonPressed(id, bouclierID)) {
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

			else
			{

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

			
		}

		bool get_bouclierb() { return bouclierb; }

    private:

		int id = 0;
		int numero_joueur=0;

    sf::Sprite sprite;
    sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
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

	float rotate = 0;
	temps t_bouclier_load;
	temps t_bouclier;
	int mana = 100;
	bool bouclierb = false;

};

#endif // JOUEUR_H
