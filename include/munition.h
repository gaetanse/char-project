#ifndef MUNITION_H
#define MUNITION_H

#include "librairies.h"
#include "temps.h"

class munition
{
    public:
        munition(int speed);
        ~munition();

        bool getInvul(){
            return invulnerable;
        }

        void donner_texture(sf::Texture &texture){
            sprite.setTexture(texture);
        }

        void affichage(sf::RenderWindow &window){
            window.draw(sprite);
        }


		bool check_col(sf::Vector2f test) {
			if (test.y >= getPosition().y && test.y <= getPosition().y + 15) {
				if (test.x >= getPosition().x && test.x <= getPosition().x + 15) {
					//std::cout << test.x << " / " << test.y << " ---- " << getPosition().x << " / " << getPosition().y << std::endl;
					return true;
				}
				return false;
			}
			return false;
		}

        void bouger(float temps_recup){

		#define time_need 0.15

            if(invul.Wait_Temps(time_need+bonus))
                invulnerable=false;

            sf::Vector2f vitesse = globalPosition - position_dep;
            test = vitesse /  ( static_cast<float>(sqrt(pow(vitesse.x,2)+pow(vitesse.y,2))));
            float speed = 600;
            sprite.move(test*temps_recup*speed);

        }

        sf::Vector2f getPosition(){
            return sprite.getPosition();
        }



        void donner_pos_des_h(sf::Vector2f depart,sf::Vector2f arriver){

            position_dep=depart;
            sprite.setPosition(depart);
            globalPosition = arriver;
          //  std::cout << "{ " << globalPosition.y << " / ";
          /*  if(globalPosition.x<0)
                globalPosition.x+=globalPosition.x+globalPosition.x;
            if(globalPosition.y<0)
                globalPosition.y+=globalPosition.y+globalPosition.y;*/


          //  std::cout << position_dep.y << std::endl;

          //  std::cout << globalPosition.y << " }" << std::endl;
//
        }

        void donner_pos_des(sf::Vector2f depart,sf::Vector2f arriver){

            position_dep=depart;
            sprite.setPosition(depart);
            globalPosition = arriver;
          //  std::cout << "{ " << globalPosition.y << " / ";
          /*  if(globalPosition.x<0)
                globalPosition.x+=globalPosition.x+globalPosition.x;
            if(globalPosition.y<0)
                globalPosition.y+=globalPosition.y+globalPosition.y;*/


          //  std::cout << position_dep.y << std::endl;

          //  std::cout << globalPosition.y << " }" << std::endl;
//
        }

        bool changer_sens(){

			if (vie_avant_casser == 1) {
				globalPosition = position_dep;
				position_dep = -globalPosition;
				vie_avant_casser--;

				change = true;

				if (sens)
					sens = false;
				else
					sens = true;

				return true;

			}
			else {
				return false;
			}




        }

        int getVie(){
            return vie_avant_casser;
        }

		bool get_est_e() { return est_enemie; }

    private:
		sf::Vector2f test;
		bool change=false;
        temps degat;
        temps invul;
        sf::Vector2f globalPosition;
        sf::Sprite sprite;
        int vie_avant_casser=1;
        sf::Vector2f position_ari;
        sf::Vector2f position_dep;
        bool sens=true;
        bool invulnerable=true;
		float speed = 600;
		float bonus = 0;
		bool est_enemie = false;
};

#endif // MUNITION_H
