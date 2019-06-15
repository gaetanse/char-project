#include "../include/bot.h"

#define PI 3.14159265

bot::bot(int id)
{
	numero = id;
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprit_cannon.setScale(2,2);
    sprit_cannon.setPosition(32,32);
    sprit_cannon.setOrigin(sf::Vector2f(15,20));
	sprite3.setScale(3, 3);
	sprite3.setOrigin(sf::Vector2f(16, 16));
	if (numero == 0) {
		sprite.setColor(sf::Color::Yellow);
		sprit_cannon.setColor(sf::Color::Yellow);
		bouclierb = false;
	}
	else if (numero == 1) {
		sprite.setColor(sf::Color::Green);
		sprit_cannon.setColor(sf::Color::Green);
		bouclierb = false;
	}
	else if (numero == 2) {
		sprite.setColor(sf::Color::Red);
		sprit_cannon.setColor(sf::Color::Red);
		//bouclierb = true;
	}
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

bool bot::tirer() {
	if (numero == 0) {
		if (t_reload.Wait_Temps(3.0))
			return true;
		else
			return false;
	}
	else if (numero == 1) {
		if (t_reload.Wait_Temps(2.0))
			return true;
		else
			return false;
	}
	else if (numero == 2) {
		if (t_reload.Wait_Temps(1.0))
			return true;
		else
			return false;
	}
}
sf::Vector2f bot::getPosition(){
    return sprite.getPosition();
}
void bot::tournerLeViseur(sf::Vector2f LeVector){
            float result = atan2 ( LeVector.y-sprit_cannon.getPosition().y , LeVector.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
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

void bot::diriger_canon(sf::Vector2i position){
    float result = atan2 ( position.y-sprit_cannon.getPosition().y , position.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
    sprit_cannon.setRotation(result);
}

bot::~bot()
{
    //dtor
}
