#include "../include/joueur.h"

#include <math.h>       /* atan2 */
#define PI 3.14159265

joueur::joueur(int nb)
{
	id = nb;
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprite2.setScale(2,2);
    sprite2.setOrigin(sf::Vector2f(15,20));
	sprite3.setScale(3, 3);
	sprite3.setOrigin(sf::Vector2f(16, 16));
	sprite4.setScale(1, 1);
	sprite4.setOrigin(sf::Vector2f(8, 8));
	sprite4.setPosition(sf::Vector2f(250, 250));

	if (id == 0) {
		sprite.setColor(sf::Color(255,255,255));
		sprite2.setColor(sf::Color(255, 255, 255));
		sprite3.setColor(sf::Color(255, 255, 255));
		sprite4.setColor(sf::Color(255, 255, 255));
	}
	else if (id == 1) {
		sprite.setColor(sf::Color(245,245,245));
		sprite2.setColor(sf::Color(245, 245, 245));
		sprite3.setColor(sf::Color(245, 245, 245));
		sprite4.setColor(sf::Color(245, 245, 245));

	}
	else if (id == 2) {
		sprite.setColor(sf::Color(235, 235, 235));
		sprite2.setColor(sf::Color(235, 235, 235));
		sprite3.setColor(sf::Color(235, 235, 235));
		sprite4.setColor(sf::Color(235, 235, 235));

	}
	else if (id == 3) {
		sprite.setColor(sf::Color(225, 225, 225));
		sprite2.setColor(sf::Color(225, 225, 225));
		sprite3.setColor(sf::Color(225, 225, 225));
		sprite4.setColor(sf::Color(225, 225, 225));

	}

}

void joueur::affichage(sf::RenderWindow &window){

	if (t_bouclier.Wait_Temps(1))
		if(mana<100)
			mana+=25;

	if (mana > 100)
		mana = 100;

	if (bouclierb) {

		if (rotate < 360)
			rotate+=7;
		else
			rotate = 0;

		if (t_bouclier_load.Wait_Temps(0.01))
			sprite3.setRotation(rotate);

	}

window.draw(sprite);
sprite2.setPosition(sprite.getPosition().x-1,sprite.getPosition().y);
sprite3.setPosition(sprite.getPosition().x, sprite.getPosition().y);
window.draw(sprite2);
window.draw(sprite4);
if (bouclierb) {
	window.draw(sprite3);
}
	

}

void joueur::diriger_canon(sf::Vector2i position){
    float result = atan2 (sprite4.getPosition().y-sprite2.getPosition().y , sprite4.getPosition().x-sprite2.getPosition().x ) * 180 / PI + 90;
    sprite2.setRotation(result);
}

sf::Vector2f joueur::getPosition(){
    return sprite.getPosition();
}

sf::Vector2f joueur::getPosition_bouclier() {
	return sprite3.getPosition();
}


int joueur::deplacement_normal(int touche,float time_r){

sf::Vector2f movement(0.f, 0.f);

///gauche
if(touche==71){

    //if(sprite.getPosition().x>32){

    /// 270 alors on se déplace
  //  if(sprite.getRotation()==270)
     //       movement.x -= vitesse;
       // else
         //   if((sprite.getRotation()<=90||sprite.getRotation()>270))
                sprite.rotate(-vitesse_tourner);
       //     else
           //     sprite.rotate(vitesse_tourner);

  //  }

}
///droite
if(touche==72){

   // if(sprite.getPosition().x<fenetre_x){
                sprite.rotate(vitesse_tourner);


  //  }

}

if(touche==73){

        ///bon #bonne chance pour les environs 40 if a faire # en double ... avancer / reculer

        if(sprite.getRotation()==0){
            movement.y -= vitesse;
        }
        else if (sprite.getRotation()==10) {
            movement.y -= (vitesse + 450);
            movement.x += (vitesse - 400);
        }
        else if (sprite.getRotation()==20) {
            movement.y -= (vitesse + 400);
            movement.x += (vitesse - 350);
        }
        else if(sprite.getRotation()==90){
            movement.x += vitesse;
        }
        else if(sprite.getRotation()==180){
            movement.y += vitesse;
        }
        else if(sprite.getRotation()==270){
            movement.x -= vitesse;
        }

}
if(touche==74){



        if(sprite.getRotation()==0){
            movement.y += vitesse;
        }
        else if(sprite.getRotation()>0&&sprite.getRotation()<90){
            movement.y += vitesse;
            movement.x -= vitesse;
        }
        else if(sprite.getRotation()==90){
            movement.x -= vitesse;
        }
        else if(sprite.getRotation()>90&&sprite.getRotation()<180){
            movement.y -= vitesse;
            movement.x -= vitesse;
        }
        else if(sprite.getRotation()==180){
            movement.y -= vitesse;
        }
        else if(sprite.getRotation()>180&&sprite.getRotation()<270){
            movement.y -= vitesse;
            movement.x += vitesse;
        }
        else if(sprite.getRotation()==270){
            movement.x += vitesse;
        }
        else if(sprite.getRotation()>270){
            movement.y += vitesse;
            movement.x += vitesse;
        }

}
sprite.move(movement*time_r);
return 1;
}

int joueur::deplacement_complexe(int touche,float time_r){

	sf::Vector2f movement(0.f, 0.f);



	if (sf::Joystick::isConnected(id))
	{


		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		float x2 = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
		float y2 = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);

		if (x > 0.1) {


			if (sprite.getRotation() == 270)
				movement.x -= vitesse;
			else
				if ((sprite.getRotation() <= 90 || sprite.getRotation() > 270))
					sprite.rotate(-vitesse_tourner);
				else
					sprite.rotate(vitesse_tourner);
		}

		 else if (x < 0.1) {
			if (sprite.getRotation() == 90)
				movement.x += vitesse;
			else
				if (sprite.getRotation() >= 270 || sprite.getRotation() < 90)
					sprite.rotate(vitesse_tourner);
				else
					sprite.rotate(-vitesse_tourner);

		}
		 if (y > 0.1) {
			 if (sprite.getRotation() == 0)
				 movement.y -= vitesse;
			 else
				 if (sprite.getRotation() <= 180)
					 sprite.rotate(-vitesse_tourner);
				 else
					 sprite.rotate(vitesse_tourner);

		}

		 else if (y < 0.1) {
			 if (sprite.getRotation() == 180)
				 movement.y += vitesse;
			 else
				 if (sprite.getRotation() <= 180)
					 sprite.rotate(vitesse_tourner);
				 else if (sprite.getRotation() >= 180)
					 sprite.rotate(-vitesse_tourner);

		}

	}

if(touche==71){///gauche
    //if(sprite.getPosition().x>0){
        if(sprite.getRotation()==270)
            movement.x -= vitesse;
        else
            if((sprite.getRotation()<=90||sprite.getRotation()>270))
                sprite.rotate(-vitesse_tourner);
            else
                sprite.rotate(vitesse_tourner);
   // }
}
if(touche==72){///droite
    //if(sprite.getPosition().x<fenetre_x){
        if(sprite.getRotation()==90)
            movement.x += vitesse;
        else
            if(sprite.getRotation()>=270||sprite.getRotation()<90)
                sprite.rotate(vitesse_tourner);
            else
                sprite.rotate(-vitesse_tourner);
   // }
}
if(touche==73){///haut
   // if(sprite.getPosition().y>32){
        if(sprite.getRotation()==0)
            movement.y -= vitesse;
        else
            if(sprite.getRotation()<=180)
                sprite.rotate(-vitesse_tourner);
            else
                sprite.rotate(vitesse_tourner);
   // }
}
if(touche==74){///bas
   // if(sprite.getPosition().y<fenetre_y-32){
        if(sprite.getRotation()==180)
            movement.y += vitesse;
        else
            if(sprite.getRotation()<=180)
                sprite.rotate(vitesse_tourner);
            else if(sprite.getRotation()>=180)
                sprite.rotate(-vitesse_tourner);
  //  }
}
sprite.move(movement*time_r);

return 1;

}


joueur::~joueur()
{
    //dtor
}
