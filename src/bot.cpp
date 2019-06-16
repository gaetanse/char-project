#include "../include/bot.h"

#define PI 3.14159265

bot::bot(int id, int diff)
{
	numero = id;
	difficulte = diff;
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprit_cannon.setScale(2,2);
    sprit_cannon.setPosition(32,32);
    sprit_cannon.setOrigin(sf::Vector2f(15,20));
	sprite3.setScale(3, 3);
	sprite3.setOrigin(sf::Vector2f(16, 16));

	if (difficulte == 1) {
		vitesse_tire = 1;
	}
	else if (difficulte == 2) {
		vitesse_tire = 1.5;
	}
	else if (difficulte == 3) {
		vitesse_tire = 2.0;
	}

	if (numero == 0) {
		sprite.setColor(sf::Color::Yellow);
		sprit_cannon.setColor(sf::Color::Yellow);
	}
	else if (numero == 1) {
		sprite.setColor(sf::Color::Green);
		sprit_cannon.setColor(sf::Color::Green);
	}
	else if (numero == 2) {
		sprite.setColor(sf::Color::Red);
		sprit_cannon.setColor(sf::Color::Red);
		a_bouclier = true; 
		vitesse_a = 3;
		vitesse_b = 3;
	}
	else if (numero == 3) {
		sprite.setColor(sf::Color::Magenta);
		sprit_cannon.setColor(sf::Color::Magenta); 
		a_bouclier = true;
		vitesse_a = 2;
		vitesse_b = 2;
	}
	else if (numero == 4) {
		sprite.setColor(sf::Color::Transparent);
		sprit_cannon.setColor(sf::Color::Transparent);
		a_bouclier = true;
		vitesse_a = 1;
		vitesse_b = 1;
	}
}

sf::Vector2f bot::getPosition_bouclier() {
	return sprite3.getPosition();
}

int bot::check_col(sf::Vector2f test) {

	if (getPosition().x > test.x - 64 && getPosition().x < test.x + 64) {
		if (getPosition().y > test.y - 64 &&  getPosition().y < test.y  + 64) {
			return 1;
		}
	}

}

sf::Vector2f bot::orentation() { return sprit_cannon.getPosition(); }

void bot::donner_texture(sf::Texture& texture) {
	sprite.setTexture(texture);
}
void bot::donner_texture_2(sf::Texture& texture) {
	sprit_cannon.setTexture(texture);
}

int bot::getX() { return x; }
int bot::getY() { return y; }

void bot::spawn() {

	x = rand() % 30;
	y = rand() % 17;

	sprite.setPosition(sf::Vector2f(x*64+32,y*64+32));

}

bool bot::est_dans_la_liste(int nb) {

	for (int a = 0; a < liste_chemin.size(); a++) {
		if (liste_chemin.at(a) == nb)
			return true;
	}

	return false;

}

int bot::testMapDeCase(int v) {

	if (v == 2)
		v = 3;

	std::cout << v << std::endl;

	return v;

}

#define vitesse_de_tire_1 5.0 
#define vitesse_de_tire_2 4.5 
#define vitesse_de_tire_3 4.0 
#define vitesse_de_tire_4 3.5 
#define vitesse_de_tire_5 3.0 
#define vitesse_de_tire_6 2.5 

bool bot::tirer() {
	if (numero == 0) {
		if (t_reload.Wait_Temps(vitesse_de_tire_1-vitesse_tire))
			return true;
		else
			return false;
	}
	else if (numero == 1) {
		if (t_reload.Wait_Temps(vitesse_de_tire_2 - vitesse_tire))
			return true;
		else
			return false;
	}
	else if (numero == 2) {
		if (t_reload.Wait_Temps(vitesse_de_tire_3 - vitesse_tire))
			return true;
		else
			return false;
	}
	else if (numero == 3) {
		if (t_reload.Wait_Temps(vitesse_de_tire_4 - vitesse_tire))
			return true;
		else
			return false;
	}
	else if (numero == 4) {
		if (t_reload.Wait_Temps(vitesse_de_tire_5 - vitesse_tire))
			return true;
		else
			return false;
	}
	else if (numero == 5) {
		if (t_reload.Wait_Temps(vitesse_de_tire_6 - vitesse_tire))
			return true;
		else
			return false;
	}
}
sf::Vector2f bot::getPosition(){
    return sprite.getPosition();
}
void bot::tournerLeViseur(sf::Vector2f LeVector){


	float result=0;

	if (rotation > 360)
		rotation = 0;
	else
		rotation++;

			if (numero == 0) {
				result = rotation;
			}
			else {
				result = atan2(LeVector.y - sprit_cannon.getPosition().y, LeVector.x - sprit_cannon.getPosition().x) * 180 / PI + 90;
			}
			sprit_cannon.setRotation(result);
}
void bot::affichage(sf::RenderWindow &window){
	/*
	if (t_bouclier.Wait_Temps(1))
		if (mana < 100)
			mana += 20;*/

	if (bouclierb) {

		if (rotate < 360)
			rotate += 7;
		else
			rotate = 0;

		if (t_bouclier_load.Wait_Temps(0.01))
			sprite3.setRotation(rotate);


		sprite3.setPosition(sprite.getPosition().x, sprite.getPosition().y);
		window.draw(sprite3);

	}

window.draw(sprite);
sprit_cannon.setPosition(sprite.getPosition().x-1,sprite.getPosition().y);
window.draw(sprit_cannon);

}

bot::~bot()
{
    //dtor
}
